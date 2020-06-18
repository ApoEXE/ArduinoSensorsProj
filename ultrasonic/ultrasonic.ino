#include "motor.h"
//#include "servoMove.h"
#include <Servo.h>
int calculateDistance();

void avoidLogic2();
void servo(uint8_t angle);
motor mo;
//servoMove ser;
Servo myservo;
const int trigPin = 7;
const int echoPin = 4;
const int servoPwm = 5;
uint8_t last_angle = 90;
int dis = 0;
long duration;
int distance;
void setup()
{
  // put your setup code here, to run once:
  myservo.attach(servoPwm);  // attaches the servo on pin 9 to the servo object
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
  mo = motor();


}
int avoid = 40;
int avoid_ar[2] = {0};
void loop()
{
  //sweep();

  analogWrite(enA, 100);
  analogWrite(enB, 100);
  dis = calculateDistance();
  //Serial.println(dis);
  if (dis > avoid) {
    mo.moveForward();
  }

  if (dis < avoid) {
    mo.moveBackward();
    delay(200);
    mo.stopMotor();
    servo(0);
    delay(100);
    avoid_ar[0] = calculateDistance();
    servo(180);
    delay(100);
    avoid_ar[1] = calculateDistance();
    avoidLogic2();
  }

}
void avoidLogic2() {
  Serial.println(avoid_ar[0]);
  Serial.println(avoid_ar[1]);
  if (avoid_ar[0] >= avoid) { //look right is empty
    analogWrite(enA, 100);
    analogWrite(enB, 100);
    mo.toRight();
    servo(90);

  } else if (avoid_ar[1] >= avoid) { //look right is empty
    analogWrite(enA, 60);
    analogWrite(enB, 60);
    mo.toLeft();
    servo(90);
  }
  if (avoid_ar[1] < avoid && avoid_ar[0] < avoid) {
    while (dis < avoid) {
      dis = calculateDistance();
      mo.rotateLeft();
    }
    servo(90);

  }
  //delay(10);
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;
  return distance;
}

void servo(uint8_t angle) {

  if (angle > last_angle)
    for (int i = last_angle; i <= angle; i++) {
      myservo.write(i);//lookFront
      delay(10);
    }
  else
    for (int i = last_angle; i >= angle; i--) {
      myservo.write(i);//lookFront
      delay(10);
    }
  last_angle =  angle;
}
void sweep() {
  for (int i = 15; i <= 165; i++) {
    myservo.write(i);
    delay(10);
    distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

    Serial.print(i); // Sends the current degree into the Serial Port
    Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance); // Sends the distance value into the Serial Port
    Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for (int i = 165; i > 15; i--) {
    myservo.write(i);
    delay(10);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}
