#SPI commands used by the MCP2515.

# Introduction #

A list of the SPI commands used on the MCP2515.
I am going to try to keep these formatted so that they may be cut and pasted into any arduino sketch.


# Sample Code #

```
#define RESET 0xc0  
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

#define CAN_31.25_KHZ 0b00001111
#define CAN_62.5_KHZ 0b00000111
#define CAN_125_KHZ 0b00000011
#define CAN_250_KHZ 0b00000001
#define CAN_500_KHZ 0b00000000 //For CNF1 when, CNF2 = 0b10010000 and CNF3 = 0b00000010 16MHz
   
//Registers
#define CNF1 0x2A
#define CNF2 0x29
#define CNF3 0x28
#define TXB0CTRL 0x30 
#define TXB1CTRL 0x40
#define TXB2CTRL 0x50 //TRANSMIT BUFFER CONTROL REGISTER
```