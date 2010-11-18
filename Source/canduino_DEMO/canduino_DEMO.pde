#include <SPI.h>
#include <SoftwareSerial.h>
#include <CAN.h>


CANClass can;//create can object


void setup()
{
  can.baudConfig(125);
  Serial.begin(9600);
}



void loop()
{
  byte man;
  can.load_0(0x64,0x34);
  can.send_0();
  delay(1000);
  man = can.readID_0;//what? invalid?
  Serial.print("Recieve ID ONE: ");
  Serial.write(can.readID_0);
  Serial.print("Recieve ID TWO: ");
  Serial.write(can.readID_1);
  
  Serial.print("Recieve data ONE: ");
  Serial.write(can.readDATA_0);
  Serial.print("Recieve data TWO: ");
  Serial.write(can.readDATA_1);
}
