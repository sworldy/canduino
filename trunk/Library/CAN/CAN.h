#include <SPI.h>

/*
Created by: Kyle Crockett
For canduino with 16MHz oscillator.
CNFx register values.
use preprocessor command "_XXkbps" 
"XX" is the baud rate.

10 kbps
CNF1/BRGCON1    b'00110001'     0x31
CNF2/BRGCON2    b'10111000'     0xB8
CNF3/BRGCON3    b'00000101'     0x05

20 kbps
CNF1/BRGCON1    b'00011000'     0x18
CNF2/BRGCON2    b'10111000'     0xB8
CNF3/BRGCON3    b'00000101'     0x05

50 kbps
CNF1/BRGCON1    b'00001001'     0x09
CNF2/BRGCON2    b'10111000'     0xB8
CNF3/BRGCON3    b'00000101'     0x05

100 kbps
CNF1/BRGCON1    b'00000100'     0x04
CNF2/BRGCON2    b'10111000'     0xB8
CNF3/BRGCON3    b'00000101'     0x05

125 kbps
CNF1/BRGCON1    b'00000011'     0x03
CNF2/BRGCON2    b'10111000'     0xB8
CNF3/BRGCON3    b'00000101'     0x05

250 kbps
CNF1/BRGCON1    b'00000001'     0x01
CNF2/BRGCON2    b'10111000'     0xB8
CNF3/BRGCON3    b'00000101'     0x05

500 kbps
CNF1/BRGCON1    b'00000000'     0x00
CNF2/BRGCON2    b'10111000'     0xB8
CNF3/BRGCON3    b'00000101'     0x05

800 kbps
Not yet supported

1000 kbps
Not yet supported

*/
#ifndef can_h
#define can_h

#define SCK 13 //spi
#define MISO 12
#define MOSI 11
#define SS 10
#define RESET 2//reset pin

#define RESET_REG 0xc0  
#define READ 0x03 
#define WRITE 0x02 //read and write comands for SPI

#define READ_RX_BUF_0_ID 0x90
#define READ_RX_BUF_0_DATA 0x92
#define READ_RX_BUF_1_ID 0x94
#define READ_RX_BUF_1_DATA 0x96 //SPI commands for reading CAN RX buffers

#define LOAD_TX_BUF_0_ID 0x40
#define LOAD_TX_BUF_0_DATA 0x41
#define LOAD_TX_BUF_1_ID 0x42
#define LOAD_TX_BUF_1_DATA 0x43
#define LOAD_TX_BUF_2_ID 0x44
#define LOAD_TX_BUF_2_DATA 0x45 //SPI commands for loading CAN TX buffers

#define SEND_TX_BUF_0 0x81
#define SEND_TX_BUF_1 0x82
#define SEND_TX_BUF_2 0x83 //SPI commands for transmitting CAN TX buffers

#define READ_STATUS 0xA0
#define RX_STATUS 0xB0
#define BIT_MODIFY 0x05 //Other commands


//Registers
#define CNF0 0x2A
#define CNF1 0x29
#define CNF2 0x28
#define TXB0CTRL 0x30 
#define TXB1CTRL 0x40
#define TXB2CTRL 0x50 //TRANSMIT BUFFER CONTROL REGISTER

#include "WProgram.h"


class CANClass
{
private:

public:
	static void begin();//sets up MCP2515
	static void baudConfig(int bitRate);//sets up baud

	static void send_0();//request to transmit buffer X
	static void send_1();
	static void send_2();

	static char readID_0();//read ID/DATA of recieve buffer X
	static char readID_1();
	static char readDATA_0();
	static char readDATA_1();

	static void load_0(byte identifier, byte data);//load transmit buffer X
	static void load_1(byte identifier, byte data);
	static void load_2(byte identifier, byte data);

};
extern CANClass CAN;
#endif
