IR Remote Controlled Servo, DC Motor, and Relay System
Overview
This project demonstrates how to control a servo motor, a DC motor, and a relay using an infrared (IR) remote control. The system reads the IR signals from a remote and executes predefined actions based on the received commands. This can be useful for remote control applications in robotics, home automation, or any system requiring basic motor or relay control through IR signals.

Features
Control a servo motor with 0°, 90°, and 180° positions.
Turn an DC motor ON and OFF.
Switch a relay ON and OFF.
Utilizes IR remote control for all actions.
Simple interface for integration with Arduino-based systems.
Components Required
Arduino Board (e.g., Arduino Uno)
IR Receiver Module (e.g., TSOP38238 or similar)
IR Remote Control (any standard remote with at least 3 buttons)
Servo Motor (e.g., SG90)
DC Motor (with motor driver, e.g., L298N)
Relay Module (5V or 12V depending on your application)
Jumper Wires
Breadboard (optional)
Pin Connections
Component	Pin
IR Receiver	Pin 3
Servo Motor	Pin 4
DC Motor Driver IN1	Pin 5
Relay Module	Pin 6
Circuit Diagram
Connect the IR Receiver to pin 3 on the Arduino.
Connect the Servo Motor to pin 4 on the Arduino.
Connect the DC Motor control pin (IN1) to pin 5 on the Arduino (if using an H-Bridge like L298N).
Connect the Relay Module to pin 6 on the Arduino.
Note: Ensure proper power supply to motors and relay, based on their specifications.

Code Explanation
Libraries
Servo.h: Controls the servo motor.
IRremote.h: Manages IR signal decoding from the receiver.
Pins Setup
IR_RECEIVE_PIN: The pin connected to the IR receiver (Pin 3).
SERVO_PIN: The pin connected to the servo motor (Pin 4).
DC_MOTOR_PIN: The pin that controls the DC motor (Pin 5).
RELAY_PIN: The pin that controls the relay (Pin 6).
Main Functions
setup():

Initializes serial communication for debugging.
Sets up the IR receiver to start listening.
Attaches the servo motor to its respective pin.
Sets motor and relay pins as outputs.
loop():

The program continuously listens for IR signals.
Based on the decoded IR command, it triggers specific actions (e.g., turn the relay on, set servo position, control DC motor).
It uses a switch-case structure to handle different commands.
IR Command Mapping
Command 16: Relay ON
Command 17: Relay OFF
Command 18: DC Motor ON
Command 20: DC Motor OFF
Command 21: Servo to 0° position
Command 22: Servo to 90° position
Command 24: Servo to 180° position
You can map these IR codes to any buttons on your remote control by using the IrReceiver.decodedIRData.command value. You may also need to modify these values depending on the specific remote being used.

Debugging Output
The Serial.println() in the loop() function will print the IR command values to the serial monitor. This helps you identify the command sent by the remote.
How to Use
Upload the code to your Arduino board.
Connect the IR receiver to pin 3 on the Arduino.
Power the system, and the IR receiver will start listening for signals from your remote.
Press buttons on your IR remote:
Relay will toggle ON/OFF.
DC motor will toggle ON/OFF.
Servo will move to 0°, 90°, or 180° based on your button press.
Customization
You can easily modify the code for different IR command mappings or to control additional devices. For instance, if your remote has more buttons, you can add new case statements to the switch block to handle those buttons.

If you wish to control different components or change pin assignments, update the respective definitions at the beginning of the code.

Known Issues
The IR remote used in this project needs to send specific codes (e.g., 16, 17, 18, etc.). If you have a different remote, use the IRrecvDumpV2 example from the IRremote library to get the correct codes for your remote.
Troubleshooting
IR Receiver not working: Make sure the IR receiver is correctly connected to the specified pin (Pin 3) and that it's getting the correct voltage (typically 5V).
Servo not moving: Ensure the servo is properly connected to the correct pin (Pin 4) and that it's receiving sufficient power (typically 5V).
Motor not turning: Verify the connections to the DC motor and ensure your motor driver (if used) is connected properly.
Relay not toggling: Check the relay connections and verify the relay module’s power requirements.
