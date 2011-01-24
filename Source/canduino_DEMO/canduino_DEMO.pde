#include <SPI.h>
#include <SoftwareSerial.h>
#include <CAN.h>




void setup()
{
  CAN.begin();
  CAN.baudConfig(125);
  Serial.begin(9600);
}



void loop()
{
  CAN.load_0(0x64,0x34);//load message id 0x64 and data 0x34 into tx buffer 0
  CAN.send_0();
  delay(1000);
  Serial.print("Recieve ID ONE: ");
  Serial.print(CAN.readID_0(),HEX);
  Serial.print("Recieve ID TWO: ");
  Serial.print(CAN.readID_1(),HEX);
  
  Serial.print("Recieve data ONE: ");
  Serial.print(CAN.readDATA_0(),HEX);
  Serial.print("Recieve data TWO: ");
  Serial.print(CAN.readDATA_1(),HEX);
}
