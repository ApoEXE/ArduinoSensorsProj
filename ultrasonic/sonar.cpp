#include "sonar.h"

sonar::sonar(/* args */)
{
  sonarSensor.setupSensor(7, 4, 200);
}

sonar::~sonar()
{
}
uint16_t sonar::readDistance()
{
  delay(70);
  int cm = sonarSensor.ping_cm();
  if (cm == 0)
  {
    cm = 250;
  }
  return cm;
}
