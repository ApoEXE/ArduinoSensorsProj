#include "VirtualWire.h"
const int dataPin = 9;
const int ledPin = 12;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  vw_setup(2000);
  vw_set_rx_pin(dataPin);
  vw_rx_start();


}
char data;
uint8_t dataLength = 1;
void loop() {
  // put your main code here, to run repeatedly:
  if (vw_get_message(&data,&dataLength))
  {
    Serial.write(data);
  }
}
