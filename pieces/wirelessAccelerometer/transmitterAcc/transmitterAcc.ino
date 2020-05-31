/*
    Arduino and ADXL345 Accelerometer - 3D Visualization Example
     by Dejan, https://howtomechatronics.com
*/
#include <Wire.h>  // Wire library - used for I2C communication
#include "VirtualWire.h"
const int dataPin = 9;

int ADXL345 = 0x53; // The ADXL345 sensor I2C address

int X_out, Y_out, Z_out;  // Outputs


void setup() {
  Serial.begin(9600); // Initiate serial communication for printing the results on the Serial monitor

  Wire.begin(); // Initiate the Wire library
  // Set ADXL345 in measuring mode
  Wire.beginTransmission(ADXL345); // Start communicating with the device
  Wire.write(0x2D); // Access/ talk to POWER_CTL Register - 0x2D
  // Enable measurement
  Wire.write(8); // Bit D3 High for measuring enable (8dec -> 0000 1000 binary)
  Wire.endTransmission();
  delay(10);

  //Off-set Calibration
  //X-axis
  Wire.beginTransmission(ADXL345);
  Wire.write(0x1E);
  Wire.write(1);
  Wire.endTransmission();
  delay(10);
  //Y-axis
  Wire.beginTransmission(ADXL345);
  Wire.write(0x1F);
  Wire.write(-2);
  Wire.endTransmission();
  delay(10);

  //Z-axis
  Wire.beginTransmission(ADXL345);
  Wire.write(0x20);
  Wire.write(-9);
  Wire.endTransmission();
  delay(10);

  vw_setup(2000);
  vw_set_tx_pin(dataPin);
}

uint8_t data[9] = {0xff, 0x06, 0xff, 0, 0, 0, 0, 0, 0}; //first 3 MSB begging Transmission with ff 00 ff follow byt 6 bytes X2X1 Y2Y1 Z2Z1
void loop() {
  // === Read acceleromter data === //
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers

  int data_int = 0;
  X_out = ( Wire.read() | Wire.read() << 8); // X-axis value
  //Serial.print(X_out, HEX);
  //Serial.println("");
  /*
    data[3] = X_out >> 8;
    data[4] = 0xff & X_out;
    Y_out = ( Wire.read() | Wire.read() << 8);
    data[5] = Y_out >> 8;
    data[6] = 0xff & Y_out;
    Z_out = ( Wire.read() | Wire.read() << 8);;
    data[7] = Z_out >> 8;
    data[8] = 0xff & Z_out;


    for (int i = 0; i < 9; i++) {
    vw_send((uint8_t*)data[i], sizeof(data[i]));
    vw_wait_tx();
  */
  vw_send((uint8_t*)data[1], sizeof(data[1]));
  vw_wait_tx();
  Serial.print(data[1], HEX);
  Serial.println("");
  delay(200);

}
