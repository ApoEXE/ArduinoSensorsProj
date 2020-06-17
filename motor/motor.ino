#define in1 5 //rightside
#define in2 6 //right side
#define enRight 3 //left side
#define in3 9 //left side
#define in4 10 //left side
#define enLeft 11 //left side
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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


}
void leftForward() {
  // put your main code here, to run repeatedly:
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void rightForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void leftBackward() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void rightBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
void stopMotor() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
}
void stopLeft() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
}
void stopRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
}
void toLeft() {
  stopLeft();
  rightForward();
}
void toRight() {
  stopRight();
  leftForward();
}
void rotateLeft() {
  rightForward();
  leftBackward();
}
void rotateRight() {
  rightBackward();
  leftForward();
}
int inc = 0;
void loop() {

  if (inc < 255)
    inc += 51;
  else
    inc = 0;
  Serial.println((inc * 100) / 255);
  analogWrite(enLeft, inc);
  analogWrite(enRight, inc);
  rightForward();
  leftForward();
  delay(1000);
  leftBackward();
  rightBackward();
  delay(1000);
  stopRight();
  delay(1000);
  stopLeft();
  delay(1000);
  toLeft();
  delay(1000);
  toRight();
  delay(1000);
  rotateLeft();
  delay(1000);
  rotateRight();
  delay(1000);
  stopMotor();
  delay(1000);

}
