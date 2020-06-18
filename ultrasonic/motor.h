#ifndef MOTOR_H
#define MOTOR_H
#include "Arduino.h"

#define enA 3 //gray
#define in1 2 // purple
#define in2 8//blue
#define in3 9 //green
#define in4 12 //yellow
#define enB 6 //orange

class motor
{
  private:
    uint16_t inc;
  public:
    motor();
    ~motor();
    void leftForward();
    void leftBackward() ;
    void rightForward() ;
    void rightBackward();
    void stopMotor();
    void stopLeft();
    void stopRight();
    void toLeft();
    void toRight();
    void rotateLeft();
    void rotateRight();
    void cycleTest();
    void moveForward();
    void moveBackward();

};
#endif
