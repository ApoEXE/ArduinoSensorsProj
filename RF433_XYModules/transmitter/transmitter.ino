#include "VirtualWire.h"
const int dataPin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  vw_setup(2000);
  vw_set_tx_pin(dataPin);

}
uint8_t data[6] = {0xAA, 0x00, 0xAA, 0, 0xAA, 0};
void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i < 7; i++) {
    if (Serial.available() > 0)
      break;
    //data[i] = Serial.read();
    uint8_t tmp = data[i];
    vw_send((uint8_t*)tmp, sizeof(tmp));
    vw_wait_tx();
    delay(200);
  }
  delay(5000);
}
