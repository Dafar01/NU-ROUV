# NU ROUV

** ROUV stands for "Remotely Operated Underwater Vehicle **
<p align="center">
   <img width="596" height="842" src="https://github.com/user-attachments/assets/64320918-b146-4193-8704-49b4713897db">
</p>

This GitHub repo is for the published paper *NU - A Marine Life Monitoring and Exploration Submarine*. This milestone was also our capstone/graduation project at the American University of Kuwait (AUK).

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
- **LoRa SX1278 Module** (depends on your region)
- **11.1V 6000mAh Li-Po Battery**
- **Two 12V Brushless DC Waterproofed Motors**
- **Two 45A ESCs**
- **Four Water Pump Motors**
- **Two Peristaltic Pump Motors**
- **60 FPS 1080p Bullet Camera**
- **4-channel 12V Relay Modules**
- **Infrared Relay**
- **Fuse**
- **Scuba Diving Flashlights**

### Circuits
#### Controller Circuit
![Controller Circuit](https://github.com/user-attachments/assets/f7fccdf3-a923-4bd4-8e6a-0bee59289756)

#### Submarine Circuit
![Submarine Circuit](https://github.com/user-attachments/assets/e3dc443c-12c3-4df1-b6e7-6528d77c3b82)

### 3D Prints
All the 3D prints are available in the "3D Designs" folder.

## Software
The software implementation of both circuits and the machine learning pipeline are avaialble in the "Code" folder.

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
