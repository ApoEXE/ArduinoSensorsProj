#ifndef MOTOR_H
#define MOTOR_H
#include "Arduino.h"


#define in1 5 //rightside
#define in2 6 //right side
#define enRight 3 //left side
#define in3 9 //left side
#define in4 10 //left side
#define enLeft 11 //left side

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

};
#endif
