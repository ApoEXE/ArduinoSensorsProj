#include "motor.h"
motor::motor() {
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(enRight, OUTPUT);
	pinMode(enLeft, OUTPUT);
	digitalWrite(in1, HIGH);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, HIGH);
	digitalWrite(enLeft, HIGH);
	digitalWrite(enRight, HIGH);
	inc = 0;
}
motor::~motor() {}
void motor::leftForward() {
	// put your main code here, to run repeatedly:
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}
void motor::rightForward() {
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
}

void motor::leftBackward() {
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
}
void motor::rightBackward() {
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
}
void motor::stopMotor() {
	digitalWrite(in1, HIGH);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, HIGH);
}
void motor::stopLeft() {
	digitalWrite(in3, HIGH);
	digitalWrite(in4, HIGH);
}
void motor::stopRight() {
	digitalWrite(in1, HIGH);
	digitalWrite(in2, HIGH);
}
void motor::toLeft() {
	stopLeft();
	rightForward();
}
void motor::toRight() {
	stopRight();
	leftForward();
}
void motor::rotateLeft() {
	rightForward();
	leftBackward();
}
void motor::rotateRight() {
	rightBackward();
	leftForward();
}
void motor::cycleTest() {
	uint16_t testTime = 1000;
	if (inc < 255)
		inc += 51;
	else
		inc = 0;
	Serial.println((inc * 100) / 255);
	analogWrite(enLeft, inc);
	analogWrite(enRight, inc);
	rightForward();
	leftForward();
	delay(testTime);
	leftBackward();
	rightBackward();
	delay(testTime);
	stopRight();
	delay(testTime);
	stopLeft();
	delay(testTime);
	toLeft();
	delay(testTime);
	toRight();
	delay(testTime);
	rotateLeft();
	delay(testTime);
	rotateRight();
	delay(testTime);
	stopMotor();
	delay(testTime);
}