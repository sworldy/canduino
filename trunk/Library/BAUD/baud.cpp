//Baud.cpp
#include<baud.h>
#include<SPI.h>
static void baud::regConfig(int bitRate)
{
byte config0, config1, config2;

switch (bitRate)
{
case:10
config0 = 0x31
config1 = 0xB8
config2 = 0x05
break;

case:20
config0 = 0x18
config1 = 0xB8
config2 = 0x05
break;

case:50
config0 = 0x09
config1 = 0xB8
config2 = 0x05
break;

case:100
config0 = 0x04
config1 = 0xB8
config2 = 0x05
break;

case:125
config0 = 0x03
config1 = 0xB8
config2 = 0x05
break;

case:250
config0 = 0x01
config1 = 0xB8
config2 = 0x05
break;

case:500
config0 = 0x00
config1 = 0xB8
config2 = 0x05
break;
}
  digitalWrite(ss, LOW);
  delay(10);
  SPI.transfer(WRITE);
  SPI.transfer(CNF0);
  SPI.transfer(config0);
  delay(10);
  digitalWrite(ss, HIGH);
  delay(10);

  digitalWrite(ss, LOW);
  delay(10);
  SPI.transfer(WRITE);
  SPI.transfer(CNF1);
  SPI.transfer(config1);
  delay(10);
  digitalWrite(ss, HIGH);
  delay(10);

  digitalWrite(ss, LOW);
  delay(10);
  SPI.transfer(WRITE);
  SPI.transfer(CNF2);
  SPI.transfer(config2);
  delay(10);
  digitalWrite(ss, HIGH);
  delay(10);
}