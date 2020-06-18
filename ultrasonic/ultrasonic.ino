#include "motor.h"
//#include "servoMove.h"
#include <Servo.h>


int calculateDistance();
void avoidLogic2();
void servo(uint8_t angle);
bool scanFront();



motor mo;
//servoMove ser;
Servo myservo;
const int trigPin = 7;
const int echoPin = 4;
const int servoPwm = 5;
uint8_t last_angle = 90;
bool scan = false;
int avoid = 30;
int avoid_ar[2] = {0};
int dis = 100;
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
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  scan = false;
  Serial.println("START");
}

void loop()
{
  //sweep();



  if (!scanFront()) {
    Serial.println("forward");
    mo.moveForward();
  } else {
    Serial.println("STOP");
    mo.moveBackward();
    delay(300);
    mo.stopMotor();
    servo(15);
    delay(10);
    avoid_ar[0] = calculateDistance();
    Serial.print("avoid_ar[0] right ");
    Serial.println(avoid_ar[0]);
    servo(165);
    delay(10);
    avoid_ar[1] = calculateDistance();
    Serial.print("avoid_ar[1] left ");
    Serial.println(avoid_ar[1]);
    avoidLogic2();
  }

}
void avoidLogic2() {
  //Serial.println(avoid_ar[0]);
  //Serial.println(avoid_ar[1]);
  if (avoid_ar[0] >= avoid && avoid_ar[0] >= avoid_ar[1]) { //look right is empty
    Serial.println("movin to right");
    mo.toRight();
    delay(500);
    mo.stopMotor();
    scan = false;
  } else if (avoid_ar[1] >= avoid && avoid_ar[1] >= avoid_ar[0]) { //look right is empty
    Serial.println("movin to left");
    mo.toLeft();
    delay(500);
    mo.stopMotor();
    scan = false;
  }
  if (avoid_ar[1] < avoid && avoid_ar[0] < avoid) {
    Serial.println("rotate");
    while (dis < avoid) {
      dis = calculateDistance();
      mo.rotateLeft();
    }
    scan = false;


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


bool scanFront() {

  uint16_t di = 0;
  uint8_t base = 25;
  uint8_t bottom = base * 3;
  uint8_t top = 180 - bottom;
  Serial.println("scan");
  for (int i = myservo.read(); i <= top; i++) {

    myservo.write(i);//lookFront
    delay(1);
    di = calculateDistance();
    if (di < avoid && di > 5) {
      Serial.println(di);
      Serial.println("in 1");
      scan = true;
      break;
    }
  }
  if (!scan) {
    for (int i = myservo.read(); i > bottom; i--) {
      myservo.write(i);//lookFront
      delay(1);
      di = calculateDistance();
      if (di < avoid && di > 5) {
        Serial.println(di);
        Serial.println("in 2");
        scan = true;
        break;
      }
    }

  }
  Serial.println(scan);
  return scan;
}
