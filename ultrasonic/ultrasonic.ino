#include "motor.h"
//#include "servoMove.h"
#include "sonar.h"
#include <Servo.h>
motor mo;
//servoMove ser;
sonar so;
Servo myservo;


void setup()
{
  // put your setup code here, to run once:
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  Serial.println("Scanner v0.1");
  mo = motor();
}
int pos = 0;
void sweep() {
  for (pos = 0; pos <= 180; pos += 1)
  {
    Serial.println(pos);
    if (pos <= 180) {
      // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(15);          // waits 15ms for the servo to reach the position
    }
  }
  for (pos = 180; pos >= 0; pos -= 1)
  {
    if (pos <= 180) {
      Serial.println(pos);
      // goes from 180 degrees to 0 degrees
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(15);          // waits 15ms for the servo to reach the position
    }
  }
}


void loop()
{
  //mo.cycleTest();
  //ser.servoTest();
  //Serial.println(so.readDistance());
  //ser.lookRight();
  //delay(200);
  //ser.lookLeft();
  //delay(200);
  //Serial.println(ser.servoRead());
  myservo.write(180);

}
