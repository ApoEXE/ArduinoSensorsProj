#include "Arduino.h"
#ifndef SONAR_H
#define SONAR_H
#include "NewPing.h"

class sonar
{
  private:
    //UTRALSONIC SENSOR
    NewPing sonarSensor;
  public:
    sonar(/* args */);
    ~sonar();
    uint16_t readDistance();
};

#endif
