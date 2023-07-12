## Sumo Robot Project

This readme file provides an overview of the Arduino code for a sumo robot. The code controls the movement and behavior of the robot using various sensors and motor drivers. The purpose of this document is to help you understand the functionality and usage of the code.

## Hardware Requirements

To use this code, you will need the following hardware components:
- Arduino board
- H-bridge motor driver (L298N)
- Ultrasonic sensor (HC-SR04)
- Infrared sensors (TCRT5000)
- Make sure you have the required hardware properly connected to your Arduino board before uploading the code.

## Pin Configuration

The code utilizes specific pins on the Arduino board for connecting the components. The following pin configuration is used:

#### Motor A (H-Bridge L298N)
- IN1: 8
- IN2: 7
- ENA: 9
#### Motor B (H-Bridge L298N)
- IN3: 5
- IN4: 4
- ENB: 3
##### Ultrasonic Sensor (HC-SR04)
- trig1: A0 (trigger pin)
- echo1: A1 (echo pin)
##### Infrared Sensors (TCRT5000)
- R_Sensor: A5 (right sensor)
- L_Sensor: A4 (left sensor)

Please ensure that you have connected the pins correctly according to this configuration.

## Setup

The setup() function is responsible for configuring the initial settings and pin modes. In this code, the following configurations are performed:

- Motor pins (IN1, IN2, IN3, IN4, ENA, ENB) are set as outputs.
- Serial communication is initiated at a baud rate of 9600 to monitor the results.
- Ultrasonic sensor pins (trig1, echo1) are set as output and input, respectively.
- Infrared sensor pins (R_Sensor, L_Sensor) are set as inputs.

## Loop

The loop() function is the main part of the code that runs repeatedly. It performs the following actions:

1) Distance Calculation: The code uses the ultrasonic sensor (HC-SR04) to calculate the distance to an object in front of the robot.
2) Distance Output: The calculated distance is printed on the serial monitor.
3) Robot Behavior:
- If the distance is less than 30 cm, the robot moves forward.
- If either of the infrared sensors detects an obstacle and the distance is less than 30 cm, the robot reverses its direction for 1 second.
- If none of the above conditions are met, the robot enters a search mode where it moves forward for 15 cycles, then rotates right for 5 cycles. This search behavior is 
  repeated.
- It's important to note that the code assumes a specific configuration and behavior for the sumo robot. Modifications may be required based on your specific hardware setup 
  and desired behavior.

## Usage

To use this code for your sumo robot, follow these steps:

- Connect the required hardware components as specified in the pin configuration section.
- Upload the code to your Arduino board.
- Open the serial monitor to monitor the distance and debug any issues.
- Ensure that the power supply and connections are properly set up to avoid any hardware damage.

## Troubleshooting

If you encounter any issues with the code or the sumo robot's behavior, consider the following troubleshooting steps:

- Check the hardware connections to ensure they are correct and secure.
- Verify that the pins in the code match your actual hardware configuration.
- Monitor the serial output for any error messages or unexpected behavior.
- Review the code logic and modify it according to your specific requirements.
- If the issues persist, consult the documentation or seek assistance from the relevant forums or communities for further support.

## Conclusion

This readme file provided an overview of the Arduino code for a sumo robot. It explained the hardware requirements, pin configuration, setup process, and the behavior of the robot. By following the instructions and troubleshooting steps, you should be able to use and customize this code for your own sumo robot project.
