#include <SPI.h>
#include "WProgram.h"
#include "CAN.h"



CANClass::CANClass()//constructor for initializing can module.
{
	// set the slaveSelectPin as an output 
	pinMode (SCK,OUTPUT);
	pinMode (MISO,INPUT);
	pinMode (MOSI, OUTPUT);
	pinMode (SS, OUTPUT);
	pinMode(RESET,OUTPUT);

	// initialize SPI:
	SPI.begin(); 
	SPI.setDataMode(SPI_MODE0);
	SPI.setClockDivider(SPI_CLOCK_DIV4);
	SPI.setBitOrder(MSBFIRST);

	digitalWrite(RESET,LOW); /* RESET CAN CONTROLLER*/
	delay(10);
	digitalWrite(RESET,HIGH);
	delay(100);
}

void CANClass::baudConfig(int bitRate)//sets bitrate for CAN node
{
	byte config0, config1, config2;

	switch (bitRate)
	{
case 10:
		config0 = 0x31;
		config1 = 0xB8;
		config2 = 0x05;
		break;

case 20:
		config0 = 0x18;
		config1 = 0xB8;
		config2 = 0x05;
		break;

case 50:
		config0 = 0x09;
		config1 = 0xB8;
		config2 = 0x05;
		break;

case 100:
		config0 = 0x04;
		config1 = 0xB8;
		config2 = 0x05;
		break;

case 125:
		config0 = 0x03;
		config1 = 0xB8;
		config2 = 0x05;
		break;

case 250:
		config0 = 0x01;
		config1 = 0xB8;
		config2 = 0x05;
		break;

case 500:
		config0 = 0x00;
		config1 = 0xB8;
		config2 = 0x05;
		break;
	}
	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(WRITE);
	SPI.transfer(CNF0);
	SPI.transfer(config0);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);

	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(WRITE);
	SPI.transfer(CNF1);
	SPI.transfer(config1);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);

	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(WRITE);
	SPI.transfer(CNF2);
	SPI.transfer(config2);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);
}

void CANClass::send_0()//transmits buffer 0
{
	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(SEND_TX_BUF_0);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);
}

void CANClass::send_1()//transmits buffer 1
{
	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(SEND_TX_BUF_1);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);
}

void CANClass::send_2()//transmits buffer 2
{
	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(SEND_TX_BUF_2);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);
}

byte CANClass::readID_0()//reads ID in recieve buffer 0
{
	byte retVal;
	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(READ_RX_BUF_0_ID);
	retVal = SPI.transfer(0xFF);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);
	return retVal;
}

byte CANClass::readID_1()//reads ID in reciever buffer 1
{
	byte retVal;
	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(READ_RX_BUF_1_ID);
	retVal = SPI.transfer(0xFF);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);
	return retVal;
}

byte CANClass::readDATA_0()//reads DATA in recieve buffer 0
{
	byte retVal;
	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer( READ_RX_BUF_0_DATA);
	retVal = SPI.transfer(0xFF);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);
	return retVal;
}

byte CANClass::readDATA_1()//reads data in recieve buffer 1
{
	byte retVal;
	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer( READ_RX_BUF_1_DATA);
	retVal = SPI.transfer(0xFF);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);
	return retVal;
}

void CANClass::load_0(byte identifier, byte data)//loads ID and DATA into transmit buffer 0
{
	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(LOAD_TX_BUF_0_ID);
	SPI.transfer(identifier);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);

	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(LOAD_TX_BUF_0_DATA);
	SPI.transfer(data);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);
}

void CANClass::load_1(byte identifier, byte data)//loads ID and DATA into transmit buffer 1
{
	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(LOAD_TX_BUF_1_ID);
	SPI.transfer(identifier);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);

	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(LOAD_TX_BUF_1_DATA);
	SPI.transfer(data);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);
}

void CANClass::load_2(byte identifier, byte data)//loads ID and DATA into transmit buffer 2
{
	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(LOAD_TX_BUF_2_ID);
	SPI.transfer(identifier);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);

	digitalWrite(SS, LOW);
	delay(10);
	SPI.transfer(LOAD_TX_BUF_2_DATA);
	SPI.transfer(data);
	delay(10);
	digitalWrite(SS, HIGH);
	delay(10);
}
