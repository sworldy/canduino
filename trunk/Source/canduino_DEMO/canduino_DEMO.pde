#include <SoftwareSerial.h>

#include "CAN.h"





void setup()
{
  can.baudConfig(125);
  Serial.begin(9600);
}



loop()
{
  can.load_0(0x64,0x34);
  can.send_0();
  delay(1000);
  Serial.print("Recieve ID ONE: ");
  Serial.print(can.readID_0);
  Serial.print("Recieve ID TWO: ");
  Serial.print(can.readID_1);
  
  Serial.print("Recieve data ONE: ");
  Serial.print(can.readDATA_0);
  Serial.print("Recieve data TWO: ");
  Serial.print(can.readDATA_1);
}
