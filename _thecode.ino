#include <Servo.h>
#include <IRremote.h>

// Define pins
const int IR_RECEIVE_PIN = 3;
const int SERVO_PIN = 4;
const int DC_MOTOR_PIN = 5;
const int RELAY_PIN = 6;

// Create instances
IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;
Servo myservo;

void setup()
{
  Serial.begin(9600);
  Serial.println("IR Receiving...");
  
  irrecv.enableIRIn(); // Initialize the IR receiver
  myservo.attach(SERVO_PIN); // Attach the servo to the pin
  
  pinMode(DC_MOTOR_PIN, OUTPUT); // Set DC motor pin as output
  pinMode(RELAY_PIN, OUTPUT);    // Set relay pin as output
}

void loop()
{
  if (IrReceiver.decode())
 {
 Serial.println(IrReceiver.decodedIRData.command);
 IrReceiver.resume();
 }

  switch(IrReceiver.decodedIRData.command){
    
      case 16: // Example IR code for Relay ON
        digitalWrite(RELAY_PIN, HIGH);
        break;
        
      case 17: // Example IR code for Relay OFF
        digitalWrite(RELAY_PIN, LOW);
        break;
        
      case 18: // Example IR code for DC Motor ON
        digitalWrite(DC_MOTOR_PIN, HIGH);
        break;
        
      case 20: // Example IR code for DC Motor OFF
        digitalWrite(DC_MOTOR_PIN, LOW);
        break;
        
      // Add more cases for servo control or other devices
      case 21: // Example IR code for Servo to 0 degrees
        myservo.write(0);
        break;
        
      case 22: // Example IR code for Servo to 90 degrees
        myservo.write(90);
        break;
        
      case 24: // Example IR code for Servo to 180 degrees
        myservo.write(180);
        break;
    }
    
    irrecv.resume(); // Receive the next value
  }

