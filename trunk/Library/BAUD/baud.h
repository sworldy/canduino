/*
For canduino with 16MHz oscillator.
CNFx register values.
use preprocessor command "_XXkbps" 
"XX" is the baud rate.

10 kbps
CNF1/BRGCON1  	b'00110001'  	0x31
CNF2/BRGCON2 	b'10111000' 	0xB8
CNF3/BRGCON3 	b'00000101' 	0x05

20 kbps
CNF1/BRGCON1  	b'00011000'  	0x18
CNF2/BRGCON2 	b'10111000' 	0xB8
CNF3/BRGCON3 	b'00000101' 	0x05

50 kbps
CNF1/BRGCON1  	b'00001001'  	0x09
CNF2/BRGCON2 	b'10111000' 	0xB8
CNF3/BRGCON3 	b'00000101' 	0x05

100 kbps
CNF1/BRGCON1  	b'00000100'  	0x04
CNF2/BRGCON2 	b'10111000' 	0xB8
CNF3/BRGCON3 	b'00000101' 	0x05

125 kbps
CNF1/BRGCON1  	b'00000011'  	0x03
CNF2/BRGCON2 	b'10111000' 	0xB8
CNF3/BRGCON3 	b'00000101' 	0x05

250 kbps
CNF1/BRGCON1  	b'00000001'  	0x01
CNF2/BRGCON2 	b'10111000' 	0xB8
CNF3/BRGCON3 	b'00000101' 	0x05

500 kbps
CNF1/BRGCON1  	b'00000000'  	0x00
CNF2/BRGCON2 	b'10111000' 	0xB8
CNF3/BRGCON3 	b'00000101' 	0x05

800 kbps
Not yet supported

1000 kbps
Not yet supported

*/

#ifdef _10kbps
#define baud0
#define baud1
#define baud2
#endif

#ifdef _20kbps

#endif

#ifdef _50kbps

#endif

#ifdef _100kbps

#endif

#ifdef _125kbps

#endif

#ifdef _250kbps

#endif

#ifdef _500kbps

#endif

