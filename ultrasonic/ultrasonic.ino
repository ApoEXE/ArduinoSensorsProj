#include "motor.h"
//#include "servoMove.h"
#include <Servo.h>
#define in1 5 //rightside
#define in2 6 //right side
#define enRight 3 //left side
#define in3 9 //left side
#define in4 10 //left side
#define enLeft 11 //left side
motor mo;
//servoMove ser;
Servo myservo;
const int trigPin = 7;
const int echoPin = 4;
const int servoPwm = 5;
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
  myservo.write(115);//lookFront

}

void loop()
{
  analogWrite(enLeft, 50);
  analogWrite(enRight, 50);
  mo.leftForward();
  //mo.cycleTest();
  //ser.servoTest();
  //Serial.println(so.readDistance());
  //ser.lookRight();
  //delay(200);
  //ser.lookLeft();
  //delay(200);
  //Serial.println(ser.servoRead());
  //sweep();
  /*
    analogWrite(enLeft, 50);
    analogWrite(enRight, 50);
    int dis = calculateDistance();
    Serial.println(dis);
    if (dis > 20)
    mo.moveForward();

    if (dis < 20) {
    mo.stopMotor();}

    myservo.write(20);//lookRight
    dis = calculateDistance();
    if (dis < 20) {
      myservo.write(140);//lookLeft
      dis = calculateDistance();
      if (dis < 20) {
        while (dis < 20) {
          dis = calculateDistance();
          mo.rotateLeft();
        }
        mo.stopMotor();
        myservo.write(115);//lookFront
      }
    }
    }
  */


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
