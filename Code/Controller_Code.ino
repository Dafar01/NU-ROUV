#include <SPI.h>
#include <Wire.h>  // include libraries
#include <LoRa.h>

int joy1 = A0;  // Initialize pins
int joy2 = A1;
int joy3 = A2;
int joy4 = A3;
int sink = 2;
int surface = 3;
int mode = 4;
int modeTMP = 0;  // Varirables to be transmitted
int joyVal1;
int joyVal2;
int joyVal3;
int joyVal4;
int sinkVal;
int surfaceVal;
int modeVal;
void setup() {
  Serial.begin(9600);  // initialize serial
  pinMode(sink, INPUT);
  pinMode(surface, INPUT);
  pinMode(mode, INPUT);  // setup pins modes

  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa init failed. Check your connections.");
    while (true)
      ;
    // if failed, do nothing
  }
  Serial.println("LoRa init succeeded.");
}
void loop() {

  joyVal1 = analogRead(joy1);  // read values from joysticks
  joyVal2 = analogRead(joy2);
  joyVal3 = analogRead(joy3);
  joyVal4 = analogRead(joy4);
  sinkVal = digitalRead(sink);  // read values from buttons
  surfaceVal = digitalRead(surface);
  modeVal = digitalRead(mode);
  Serial.println(modeVal);
  if (modeVal == LOW) {
    delay(70);  // debounce
    if (modeTMP == 0) {
      modeTMP = 1;

      Serial.println("SWITHED TO 1");
    } else if (modeTMP == 1) {
      modeTMP = 0;
      Serial.println("SWITHED TO 0");
    }
  }
  Serial.print("MODE: ");
  Serial.print(modeTMP);
  Serial.println();
  joyVal1 = map(joyVal1, 0, 1023, 0, 180);  // map values from 0-1023 to 0-180
  joyVal2 = map(joyVal2, 0, 1023, 0, 180);
  joyVal3 = map(joyVal3, 0, 1023, 0, 180);
  joyVal4 = map(joyVal4, 0, 1023, 0, 180);
  Serial.print("Vy value: ");
  Serial.print(joyVal1);
  Serial.print(" | Vy value: ");
  Serial.print(joyVal2);
  Serial.println();
  Serial.print("Vx value: ");
  Serial.print(joyVal3);
  Serial.print(" | Vx value: ");
  Serial.print(joyVal4);
  Serial.println();

  if (sinkVal == LOW) {
    Serial.print("Sinking: ");
    Serial.print(sinkVal);
    Serial.println();
  }
  if (surfaceVal == LOW) {
    Serial.print("Surfacing: ");
    Serial.print(surfaceVal);
    Serial.println();
  }
  LoRa.beginPacket();  // start packet
  LoRa.write(modeTMP);
  LoRa.write(joyVal1);  // add payload
  LoRa.write(joyVal2);
  LoRa.write(joyVal3);
  LoRa.write(joyVal4);
  LoRa.write(sinkVal);
  LoRa.write(surfaceVal);
  LoRa.endPacket();  // finish packet and send it
}
