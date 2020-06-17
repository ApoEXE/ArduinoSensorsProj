#ifndef SERVOMOVE_H
#define SERVOMOVE_H
#include "Arduino.h"
#include <Servo.h>
//SERVO
#define servo_pin 5
class servoMove
{
private:
    Servo myservo;
    uint8_t pos=0;
public:
    servoMove(/* args */);
    ~servoMove();
    void moveServo(uint16_t degree);
    void servoReset();
    void servoTest();
    uint8_t servoRead();
    void lookRight();
    void lookLeft();
};



#endif
