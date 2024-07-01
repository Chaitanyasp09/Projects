# Fire & Smoke, Gas Detector with Alarm System

## Table of Contents

- [Project Overview](#project-overview)
- [Components Used](#components-used)
- [Working Environment](#working-environment)
- [Circuit Connection](#circuit-connection)
- [Final Project](#final-project)
- [Conclusion](#conclusion)

## Project Overview

The Fire & Smoke, Gas Detector with Alarm System aims to develop a cost-effective and reliable fire alarm system using Arduino Uno and various sensors. The system is designed to detect smoke, fire, and gas hazards, providing early warnings through alarms and alerts to help prevent potential fire incidents in both residential and commercial settings. By leveraging affordable sensors and Arduino technology, this project enhances safety measures and reduces risks associated with fire hazards.

## Components Used

- **MQ2 Gas Sensor:** 
  - Detects gases such as LPG, propane, methane, smoke, and carbon monoxide.
- **Flame Sensor:** 
  - Detects infrared light emitted by flames.
- **Arduino Uno:** 
  - Microcontroller board used for processing sensor data and controlling alarms.
- **Buzzer:** 
  - Produces audible alerts to indicate the detection of hazards.
- **LEDs:** 
  - Visual indicators of alarm status, indicating different levels or types of alerts.
- **Resistors and Connecting Wires:**
  - Essential for connecting the components to the Arduino board safely.

## Working Environment

- **IDE:** 
  - Arduino IDE, used for programming the Arduino Uno.
- **Simulation:** 
  - Tinkercad, used for circuit simulation and design.
- **Testing Tools:** 
  - Multimeter and breadboard for initial testing and debugging.

## Circuit Connection

Below is the circuit connection diagram that illustrates how the components are connected to the Arduino Uno and to each other to form the fire and smoke, gas detector system.

<img src="Images/connection.png" alt="Circuit Connection" width="500">

- **MQ2 Sensor:** 
  - Connect Vcc to 5V, GND to GND, and the output pin to an analog input pin on the Arduino.
- **Flame Sensor:** 
  - Connect Vcc to 5V, GND to GND, and the output pin to a digital input pin on the Arduino.
- **Buzzer:** 
  - Connect the positive terminal to a digital output pin on the Arduino (through a suitable resistor) and the negative terminal to GND.
- **LEDs:** 
  - Connect through suitable resistors to digital output pins on the Arduino, with the other terminal connected to GND.

## Final Project

Here is the image showing the final prototype of the fire and smoke, gas detector with an alarm system.

<img src="Images/final.png" alt="Final Model" width="500">

The final setup includes all components fully integrated, assembled, and tested for detecting and alerting fire hazards effectively.

## Conclusion

The fire and smoke, gas detector system developed here provides an effective and practical solution for early detection of fire, smoke, and gas hazards. Leveraging Arduino-based technology and affordable sensors, it demonstrates reliable performance in alerting potential hazards, enhancing safety, and reducing risks in various environments. This project underscores the practicality of integrating simple sensor-based solutions to address critical safety needs.
