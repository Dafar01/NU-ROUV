#include <SPI.h>
#include <Wire.h>
#include <LoRa.h>
#include <Servo.h>

Servo escFor1;
Servo escFor2;

#define ESC_PIN 5
#define ESC_PIN1 6
#define PumpFor 7
#define PumpLeft 8
#define PumpRight 4
#define sinkPin 2
#define surfacePin 3

// Define variables for controlling relay timings
unsigned long pumpActivationTime = 0;
const unsigned long pumpActivationDuration = 1000; // Adjust as needed
unsigned long previousMillis = 0; // Variable to store the last time the syringe action was performed
const long interval = 3000;       // Interval between syringe actions (in milliseconds)

int checking = -1;
int joyValy1, joyValy2, joyValx1, joyValx2, sink, surface;

void setup() {
  Serial.begin(9600);

  escFor1.attach(ESC_PIN, 1000, 2000);
  escFor1.write(0);
  delay(2000);
  escFor2.attach(ESC_PIN1, 1000, 2000);
  escFor2.write(0);
  delay(2000);

  pinMode(PumpFor, OUTPUT);
  pinMode(PumpLeft, OUTPUT);
  pinMode(PumpRight, OUTPUT);
  pinMode(sinkPin, OUTPUT);
  pinMode(surfacePin, OUTPUT);

  while (!Serial);
  Serial.println("LoRa Receiver");
  if (!LoRa.begin(433E6)) { // or 915E6
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  delay(3000);
}

void loop() {
  Serial.println("back to loop");
  if (LoRa.parsePacket()) {
    while (LoRa.available()) {
      checking = LoRa.read();
      joyValy1 = LoRa.read();
      joyValy2 = LoRa.read();
      joyValx1 = LoRa.read();
      joyValx2 = LoRa.read();
      sink     = LoRa.read();
      surface  = LoRa.read();

      if (checking == 1) { // Mode for controlling BLDC motors
        controlBLDCMotors();
        Serial.println("going to BLDC");
      } else { // Mode for controlling water pumps
        controlWaterPumps();
        Serial.println("going to pumps");
        // controlSyringes();
      }
    }
  }
}

void controlBLDCMotors() {
  Serial.println("Controlling BLDC motors...");
  escFor1.write(joyValy1); // Control BLDC motor 1 with joystick Y1 value
  escFor2.write(joyValy2); // Control BLDC motor 2 with joystick Y2 value
  
  // Turn off water pumps
  digitalWrite(PumpFor, LOW);
  digitalWrite(PumpLeft, LOW);
  digitalWrite(PumpRight, LOW);
}

void controlWaterPumps() {
  Serial.println("Controlling water pumps...");

  // Turn off BLDC motors
  escFor1.write(90);
  escFor2.write(90);

  unsigned long currentMillis = millis();

  // Control water pumps
  if (joyValx1 < 80) {
    if (currentMillis - pumpActivationTime >= pumpActivationDuration) {
      digitalWrite(PumpFor, HIGH);
      pumpActivationTime = currentMillis;
      Serial.println("Forward engaged");
    }
  } else {
    digitalWrite(PumpFor, LOW);
  }

  if (joyValx2 < 80) {
    if (currentMillis - pumpActivationTime >= pumpActivationDuration) {
      digitalWrite(PumpRight, HIGH);
      pumpActivationTime = currentMillis;
      Serial.println("Right engaged");
    }
  } else {
    digitalWrite(PumpRight, LOW);
  }

  if (joyValx2 > 100) {
    if (currentMillis - pumpActivationTime >= pumpActivationDuration) {
      digitalWrite(PumpLeft, HIGH);
      pumpActivationTime = currentMillis;
      Serial.println("Left engaged");
    }
  } else {
    digitalWrite(PumpLeft, LOW);
  }

//-------------------------------------------

  if (sink == 0) {
    digitalWrite(surfacePin, LOW);
    digitalWrite(sinkPin, HIGH);
    Serial.println("sinking");

    // Check if it's time to turn off the sink
    if (currentMillis - previousMillis >= interval) {
      digitalWrite(sinkPin, LOW); // Turn off the sink
      Serial.println("sinking Turned off");
      previousMillis = currentMillis; // Save the current time for the next iteration
    }
  } else if (surface == 0) {
    digitalWrite(sinkPin, LOW);
    digitalWrite(surfacePin, HIGH);
    Serial.println("surface");

    // Check if it's time to turn off the surface
    if (currentMillis - previousMillis >= interval) {
      digitalWrite(surfacePin, LOW); // Turn off the surface
      Serial.println("surface Turned off");
      previousMillis = currentMillis; // Save the current time for the next iteration
    }
  } else {
    Serial.println("surface and sink off");
    digitalWrite(surfacePin, LOW);
    digitalWrite(sinkPin, LOW);
  }
}