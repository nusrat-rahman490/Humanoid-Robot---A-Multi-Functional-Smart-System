# Humanoid Robot - A Multi-Functional Smart System 🤖

## Overview
This project is a multi-functional humanoid robot developed using **Arduino Mega**.  
It integrates various automation and control features and is designed to perform multiple tasks with precision and adaptability.  

---

## Key Features
- Arduino Mega: Central microcontroller for processing and decision-making  
- L293D Motor Driver: Controls gear motors and servos  
- Servo & Gear Motors: Smooth and controlled movement of limbs  
- HC-05 Bluetooth Module: Remote control via smartphone or PC  
- Ultrasonic Sensor: Detect obstacles automatically  
- GSM Module (Optional): Send alerts via SMS  
- Power Management: Efficient energy usage  
- Additional Electronics: Transistors, resistors, capacitors, jumper wires for circuit stability  

---

### 2. Hardware Setup
- Connect **Arduino Mega** as the main controller.  
- Connect **gear motors** to the **L293D motor driver**:  
  - Motor 1 → Motor1 pins on L293D  
  - Motor 2 → Motor2 pins on L293D  
- Connect **servo motors** to Arduino PWM pins for limb movement.  
- Connect **HC-05 Bluetooth module**:  
  - TX → Arduino RX1 (pin 19)  
  - RX → Arduino TX1 (pin 18)  
- Connect **ultrasonic sensor**:  
  - Trigger → Arduino pin 7  
  - Echo → Arduino pin 6  
- Optional: Connect **GSM module** for SMS alerts.  
- Power the system using an appropriate **battery/power source**.  

---

### 3. Software Setup
- Install the **Arduino IDE** if not already installed.  
- Open `HumanoidRobot.ino` in Arduino IDE.  
- Select **Arduino Mega** under Tools → Board.  
- Select the correct **COM port**.  
- Upload the code to Arduino Mega.  

---

### 4. Bluetooth Control
- Connect your device to **HC-05**.  
- Send the following commands to control the robot:

| Command | Action           |
|---------|----------------|
| F       | Move Forward    |
| B       | Move Backward   |
| L       | Turn Left       |
| R       | Turn Right      |
| S       | Stop            |
| A       | Left arm up     |
| a       | Left arm down   |
| D       | Right arm up    |
| d       | Right arm down  |

---

### 5. Obstacle Detection
- The robot will automatically **stop** if an obstacle is detected within **20 cm**.  
- Ultrasonic sensor measures distance continuously to prevent collisions.  

---

### 6. GSM Alerts (Optional)
- Configure the GSM module to send SMS alerts for:  
  - Obstacle detection  
  - Battery low notifications  
  - Task completion  

---

### 7. Testing the Robot
- Power on the system.  
- Use a Bluetooth device to send commands.  
- Test servo and gear motor movements.  
- Place an obstacle in front to test automatic stopping.  
- Monitor the Serial Monitor for debug information.  

---

### Skills & Learning Outcomes
- Sensor integration and signal processing  
- Motor and servo control using L293D  
- Bluetooth communication for remote control  
- Obstacle detection and autonomous response  
- Modular and expandable robotic system design  

---

### Project Status
- **Ongoing** (Jan 2023 – Present)  
- Future work: GSM-based alerts, additional autonomous tasks, AI integration  

---

### License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
