# NU ROUV

For reference, ROUV stands for **"Remotely Operated Underwater Vehicle"**
<p align="center">
   <img src="https://github.com/user-attachments/assets/396c50a7-c8b1-4357-bbc6-5a27fbbe5a96">
</p>

This GitHub repo is for the to-be published paper *NU - A Marine Life Monitoring and Exploration Submarine System*. This milestone was also our capstone/graduation project at the American University of Kuwait (AUK).

# Description
NU is a marine life monitoring ROUV/submarine that is equipped with a machine learning pipeline capable of identifying and classifying 5 fish species in kuwait seas, while simultaneously flagging any species outside of the dataset as unknowns. NU also aims to cut down costs on ocean exploration expeditions, reduce disturbance and damage on marine life, and limit health risks imposed on divers due to diving.

## Key Features
- **Wireless Communication**: NU utilizes LoRa as its main communication technology, allowing it to be operated wirelessly in real-time using a controller without the need for a teather.
- **Machine Learning Pipeline**: NU is equipeed with a camera that transmits a live-feed to a laptop. The footage is then analyzed in real-time and the results are displayed on screen.
- **Two Modes of Transportation**: NU has two sets of motors, Brushless DC motors and water pump motors. The Brushless DC motors are used for long distance travelling, while the water pumps are used for precise movement and limiting disturbance on marine life.
- **Eco-friendly 3D Parts**: NU's body is fully 3D printed using biodegradable materials, eliminating the risk of pollution in case the submarine is lost during operation.

## Hardware

### Electrical Components
Below is a list of all the electrical components needed to implement NU:
- **Arduino UNO R3**
- **LoRa SX1278 433Mhz Module** (depends on your region)
- **11.1V 6000mAh Li-Po Battery**
- **Two 12V Brushless DC Waterproofed Motors**
- **Two 45A ESCs**
- **Four Water Pump Motors**
- **Two Peristaltic Pump Motors**
- **60 FPS 1080p Bullet Camera**
- **Two 4-channel 5V Relay Modules**
- **Infrared Relay**
- **Fuse**
- **Scuba Diving Flashlights**

### Circuits
#### Controller Circuit
![Controller Circuit](https://github.com/user-attachments/assets/f7fccdf3-a923-4bd4-8e6a-0bee59289756)

#### Submarine Circuit
![Submarine Circuit](https://github.com/user-attachments/assets/e3dc443c-12c3-4df1-b6e7-6528d77c3b82)

### 3D Designs
All the 3D STL files are available in the [STL files](/STL_files) folder.

#### Disclaimers
- For symmetry, 4 of the [Acrylic Tube Holder](/STL_files/Acrylic_Tube_Holder.STL) were printed. The acrylic tube used was roughly 30cms long and 10cms in diameter.
- A waterproof wire-gland is used with the [End Cap](/STL_files/End_Cap.STL) to pass the motor wires from inside the acrylic tube to the outside, hence the opening in the middle.
- The pillars designed in [the bottom part of the controller](/STL_files/Controller_Bottom.STL) are weak. Consider adding a fillet between the bottom of the case and the pillars, and between the top pillars and bottom pillars.

## Software
The software implementation of both circuits and the machine learning pipeline are avaialble in the [code](/code) folder.

## Demo
Demo videos of the motors operating as well as a montage of the NU's functionalities is available in the [videos](/videos) folder.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Authors
- Tarek Dafar
- Ahmed Hassan
- Faisal Hassan
- Abdullah AlGohary

## Supervisors
- Dr. Mounib Khanafer
- Eng. Ali Behiry
