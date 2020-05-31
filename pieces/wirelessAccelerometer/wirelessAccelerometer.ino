#include "VirtualWire.h"
const int dataPin = 9;
const int ledPin = 12;
float X_out, Y_out, Z_out;  // Outputs
float roll, pitch, rollF, pitchF = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  vw_setup(2000);
  vw_set_rx_pin(dataPin);
  vw_rx_start();


}
uint8_t data;
uint8_t dataLength = 1;
uint8_t accData[6];
void loop() {
  // put your main code here, to run repeatedly:

  if (vw_get_message(&data, &dataLength))
  {
    Serial.print("0x");
    
    Serial.print(data, HEX); //MSB of X
    Serial.println("");

    if (data == 0x98)
      if (vw_get_message(&data, &dataLength))
        if (data == 0x00)
          if (vw_get_message(&data, &dataLength))
            if (data == 0x98) {
              vw_get_message(&data, &dataLength);
              accData[0] = data;
              //Serial.print(data);//MSB of X
              vw_get_message(&data, &dataLength);
              accData[1] = data;
              vw_get_message(&data, &dataLength);
              accData[2] = data;
              vw_get_message(&data, &dataLength);
              accData[3] = data;
              vw_get_message(&data, &dataLength);
              accData[4] = data;
              vw_get_message(&data, &dataLength);
              accData[5] = data;
            }
    /*
        X_out = (accData[1] | accData[0] << 8); // X-axis value
        X_out = X_out / 256; //For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
        Y_out = ( accData[3]  | accData[2]  << 8); // Y-axis value
        Y_out = Y_out / 256;
        Z_out = ( accData[5]  | accData[4]  << 8); // Z-axis value
        Z_out = Z_out / 256;
        //Serial.print(X_out);
        //Serial.print(" g");
        //Serial.print(Y_out);
        //Serial.print(" g");
        //Serial.print(Z_out);
        //Serial.println(" g");
        // Calculate Roll and Pitch (rotation around X-axis, rotation around Y-axis)
        roll = atan(Y_out / sqrt(pow(X_out, 2) + pow(Z_out, 2))) * 180 / PI;
        pitch = atan(-1 * X_out / sqrt(pow(Y_out, 2) + pow(Z_out, 2))) * 180 / PI;

        // Low-pass filter
        rollF = 0.94 * rollF + 0.06 * roll;
        pitchF = 0.94 * pitchF + 0.06 * pitch;

        Serial.print(rollF);
        Serial.print("/");
        Serial.println(pitchF);
    */
  }


}
