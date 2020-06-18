#include "motor.h"
motor::motor() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  inc = 0;
}
motor::~motor() {}
void motor::leftForward() {
  // put your main code here, to run repeatedly:
  digitalWrite(in3, LOW);//nothing
  digitalWrite(in4, HIGH);//right
}
void motor::rightForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void motor::leftBackward() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
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
  uint16_t testTime = 2000;
  /*
    if (inc < 255)
  	inc += 51;
    else
  	inc = 0;
  */
  inc = 200;
  Serial.println((inc * 100) / 255);
  analogWrite(enA, inc);
  analogWrite(enB, inc);
  moveForward();
  delay(testTime);
  moveBackward();
  delay(testTime);
  stopRight();
  leftBackward();
  delay(testTime);
  stopLeft();
  rightBackward();
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

void motor::moveForward() {
  rightForward();
  leftForward();
}
void motor::moveBackward() {
  rightBackward();
  leftBackward();
}
