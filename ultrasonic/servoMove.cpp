#include "servoMove.h"
servoMove::servoMove(/* args */)
{
  myservo.attach(servo_pin);

}

servoMove::~servoMove()
{
}

void servoMove::moveServo(uint16_t degree)
{
  myservo.write(degree);
  delay(15);
}

uint8_t servoMove::servoRead() {
  uint8_t angle = myservo.read();
  return angle;
}

void servoMove::servoReset()
{
  myservo.write(90);
  delay(15);
}

void servoMove::servoTest()
{
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

void servoMove::lookRight() {
  myservo.write(50);
  delay(15);
  myservo.write(115);
  delay(15);
}
void servoMove::lookLeft() {
  myservo.write(170);
  delay(15);
  myservo.write(115);
  delay(15);
}
