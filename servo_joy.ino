#include <Servo.h>

const int servo1 = 3;       // first servo
const int servo2 = 10;       // second servo
const int joyH = 3;        // L/R Parallax Thumbstick
const int joyV = 4;        // U/D Parallax Thumbstick

int servoVal;           // variable to read the value from the analog pin

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
int servoVal1 = 90;
int servoVal2 = 90;


void setup() {

  // Servo  
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo

  // Inizialize Serial
  Serial.begin(115200);
  myservo1.write(servoVal1);
  myservo2.write(servoVal2);
}


void loop(){

    // Display Joystick values using the serial monitor
    outputJoystick();

    // Read the horizontal joystick value  (value between 0 and 1023)
    servoVal = analogRead(joyH);          
    if (servoVal > 1000)
      servoVal2++;
    else if (servoVal < 200)
      servoVal2--;
    
    if (servoVal2 > 180)
      servoVal2 = 180;
    if (servoVal2 < 0)
      servoVal2 = 0;
    myservo2.write(servoVal2);                         // sets the servo position according to the scaled value    

    // Read the vertical joystick value  (value between 0 and 1023)
    servoVal = analogRead(joyV);          
    if (servoVal > 1000)
      servoVal1++;
    else if (servoVal < 200)
      servoVal1--;
    
    if (servoVal1 > 180)
      servoVal1 = 180;
    if (servoVal1 < 0)
      servoVal1 = 0;
    myservo1.write(servoVal1);                         // sets the servo position according to the scaled value    

    delay(15);                                       // waits for the servo to get there

}


/**
* Display joystick values
*/
void outputJoystick(){

    Serial.print(analogRead(joyH));
    Serial.print ("---"); 
    Serial.print(analogRead(joyV));
    Serial.println ("----------------");
}
