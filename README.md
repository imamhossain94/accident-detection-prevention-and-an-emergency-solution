## Accident Detection Prevention and an Emergency Solution (ADPES)

Road accidents have become a significant concern in Bangladesh, with high-speed driving and unaware drivers being the primary factors in road accidents. Increasing vehicle use has resulted in increased traffic disorder, which has increased the number of road accidents. In the event of an accident, some people are unable to reach the hospital on time due to traffic jams, lack of ambulance, and lack of necessary information. Here is an automated Internet of Things (IoT) based accident prevention, detection, and emergency solution. The system is designed to send signals to the nearest hospital in case of an accident. It detects whether a driver has consumed alcohol or not. If the sensor detects alcohol, The car will automatically stop until the smell is gone. It also detects when the driver is asleep due to the ride and triggers the buzzer sound. When the car detects an object nearly 30 cm. away, it will stop moving. When an accident occurs, the system will send the accident location to the nearest hospital through SMS.

<p align="center">
  <img alt="Light" src="https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/cover.jpg" width="100%">
</p>


<div align="center">

[![Open Source Love svg1](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)](#)
[![GitHub Forks](https://img.shields.io/github/forks/saadhaxxan/Car_Game_Python_Pygame.svg?style=social&label=Fork&maxAge=2592000)](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/fork)
[![GitHub Issues](https://img.shields.io/github/issues/saadhaxxan/Car_Game_Python_Pygame.svg?style=flat&label=Issues&maxAge=2592000)](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/issues)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat&label=Contributions&colorA=red&colorB=black	)](#)

</div>


## Feature

:heavy_check_mark: Accident Detection
:heavy_check_mark: Accident Prevention
:heavy_check_mark: Emergency Solution

## How Does It Works

* Accident Prevention
    ```
    To Prevent accident we used four sensor
    * Ultrasonic:  When the sensor detects an object nearly 30 cm it will stop the car.
    * PIR: It is used to monitor the driver motion. If the driver moved out from its range the car will stop immediately.
    * MQ3: Checking whether the driver is alcoholic or not.
    * Bazzer: When the PIR sensor detects that the driver is in a sleep, It will make noise.
    ```
* Accident Detection
    ```
    To Detect an accident we used only one sensor
    * Vibrator sensor: If the car crash, it will produce a signal. Based on the signal we do an emergency solution.
    ```
* Emergency Solution
    ```
    In Emergency solution we used some modules and a server
    * GPS NEO 6M: Get car current location in Latitude and Longitude.
    * SIM 800L: Do a post request with Latitude and Longitude and then send an SMS into the responsed phone number.
    * Server: The server calculate the sortest path between hospitals and the accident occured location and return hospital details as response.
    ```
* <a href="https://github.com/imamhossain94/find-nearest-hospital-bd">Check the Server Repository</a>



## Module & Sensor Used

| S/N | Name/Model | Quantity | Type | Price | Image | Description
| :-- | :-- | :-- | :-- | :-- | :-- | :-- |
1 | Arduino UNO | 1 | Microcontroller | 750/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/arduino_uno.jpg) | Arduino Uno is a microcontroller board based on the ATmega328P (datasheet).
2 | 4WD Car Set | 1 | Car Chassis Kit | 550/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/car_casis.jpg) | Four-wheel drive (4WD) is a vehicle system that powers the front and rear wheel axles at the same speed to help gain traction, according to Car and Driver.
3 | L298N | 1 | Motor Driver | 140/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/l298n.jpg) | The L298N Motor Driver is a controller that uses an H-Bridge to easily control the direction and speed of up to 2 DC motors.
4 | SIM800L | 1 | Module | 280-400/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/sim_800_l.jpg) | SIM800L GSM/GPRS module is a miniature GSM modem, which can be integrated into a great number of IoT projects.
5 | GPS NEO 6M | 1 | Module | 600/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/gps_neo_6m.jpg) | The NEO-6M module includes one configurable UART interface for serial communication, but the default UART (TTL) baud rate here is 9,600.
6 | MQ3 | 1 | Sensor | 160/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/mq3.jpg) | Alcohol Sensor Module - MQ3. 4753. This module is made using Alcohol Gas Sensor MQ3. 
7 | Ultrasonic| 1 | Sensor | 100/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/sonar.jpg) | An ultrasonic sensor is an instrument that measures the distance to an object using ultrasonic sound waves.
8 | PIR | 1 | Sensor | 100/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/pir.jpg) | PIR sensors allow you to sense motion, almost always used to detect whether a human has moved in or out of the sensors range.
9 | HC-05 | 1 | Module | 270/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/hc05.jpg) | The HC-05 is a popular module which can add two-way (full-duplex) wireless functionality to your projects.
10 | Bazzer | 1 | piezo | 15/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/buzzer.jpg) | A buzzer or beeper is an audio signaling device, which may be mechanical, electromechanical, or piezoelectric (piezo for short).
11 | Vibrator | 1 | Module | 75/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/vibrator.jpg) | A vibration sensor is a device that measures the amount and frequency of vibration in a given system, machine, or piece of equipment. 
12 | Antena | 1 | Module | 90/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/sim800l_antena.jpg) | Antenna for SIM800L GSM Module.
13 | 3.7v Battery | 3 | Module | 150/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/li_ion_battery.jpg) | 18650 3.7 Volt lithium-ion rechargeable batteries are cylindrical batteries used in mainly for laptop battery packs, telephones, electronic cigarettes, flashlights and cordless power tools.
14 | 1x Battery Case | 1 | Module | 25/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/battery_holder_1.jpg) | The primary function of a battery holder is to keep cells fixed in place safely and securely while conveying power from the batteries to the device in question.
15 | 2x Battery Case | 1 | Module | 30/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/battery_holder_2.png) | The primary function of a battery holder is to keep cells fixed in place safely and securely while conveying power from the batteries to the device in question.
16 | 2x Battery Charger | 1 | Module | 120/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/li_ion_battery_charger.jpg) | Proper charging of Li-ion batteries enables the best performance and longest operational life to be obtained.
17 | Soldering Iron | 1 | Module | 150/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/soldering_iron.jpg) | Spool of solder. 1.6mm. A soldering iron is a hand tool used in soldering.
18 | Soldering LID | 1 | Module | 20/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/soldering_lid.jpg) | Soldering Lid.
19 | Rojon | 1 | Module | 8/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/soldering_rojon.jpg) | Soldering Rojon.
20 | Jumper Wire | 3 | Cable | 180/= | ![](https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/jumper_wire.jpg) | RF jumper cables - Jumper cables is a smaller and more bendable corrugated cable which is used to connect antennas and other components to network cabling.


## 🧑 Circuit Diagram
<p align="center">
  <img alt="Light" src="https://github.com/imamhossain94/accident-detection-prevention-and-an-emergency-solution/blob/main/images/circuit_diagram.jpg" width="100%">
</p>



## 🧑 Author

#### Md. Imam Hossain

You can also follow my GitHub Profile to stay updated about my latest projects:

[![GitHub Follow](https://img.shields.io/badge/Connect-imamhossain94-blue.svg?logo=Github&longCache=true&style=social&label=Follow)](https://github.com/imamhossain94)

If you liked the repo then kindly support it by giving it a star ⭐!

Copyright (c) 2021 MD. IMAM HOSSAIN
