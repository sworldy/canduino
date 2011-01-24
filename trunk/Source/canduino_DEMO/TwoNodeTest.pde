#include <CAN.h>

#include <SPI.h>

#define BUS_SPEED 1000
#define RX 1
#define TX 0

//global variable used to determine whether loop should
//be in Tx or Rx mode.
int state;
//global variable used to toggle pin
int pin;
//increment global
int inc;

void setup() {                
  
  Serial.begin(115200);
  
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
  // initialize CAN bus class
  // this class initializes SPI communications with MCP2515
  CAN.begin();
  CAN.baudConfig(BUS_SPEED);
  CAN.setMode(NORMAL);  
  
  //Wait 5 seconds so that I can still upload even
  //if the previous iteration spams the serial port
  delay(5000);
  
  //Set to determine whether uploading transmitter or receiver code
  state = RX; //Rx = 1, Tx = 0
  inc = 0;

  pin = LOW;  
}

void loop() {
  
  byte length,rx_status,i;
  unsigned short frame_id;
  byte frame_data[8];
  
  //signal iterations on pin 8
  digitalWrite(8,pin);  
  
  switch(state) {
    case TX: //Tx
    
      //signal state on pin 7;
      digitalWrite(7,LOW);
      
      frame_data[0] = 0x55+inc;
      frame_data[1] = 0xAA+inc;
      frame_data[2] = 0x00+inc;
      frame_data[3] = 0xFF+inc;
      frame_data[4] = 0x1A+inc;
      frame_data[5] = 0xCF+inc;
      frame_data[6] = 0xFC+inc;
      frame_data[7] = 0x1D+inc;
  
      frame_id = 0x05A5;
  
      length = 8;
  
      CAN.load_ff_0(length,frame_id,frame_data);
      CAN.send_0();
         
     // Serial.println("Tx ");
      delay(5);
      break;
    case RX: //Rx
    
      //signal state on pin 7
      digitalWrite(7,HIGH);    
      //clear receive buffers, just in case.
      frame_data[0] = 0x00;
      frame_data[1] = 0x00;
      frame_data[2] = 0x00;
      frame_data[3] = 0x00;
      frame_data[4] = 0x00;
      frame_data[5] = 0x00;
      frame_data[6] = 0x00;
      frame_data[7] = 0x00;
  
      frame_id = 0x0000;
  
      length = 0;
      
      rx_status = CAN.readStatus();
      
      if ((rx_status & 0x01) == 0x01) {
       
       CAN.readDATA_ff_0(&length,frame_data,&frame_id);
        
      } else if ((rx_status & 0x02) == 0x02) {
        
       CAN.readDATA_ff_1(&length,frame_data,&frame_id);
       
      }
      
      if (((rx_status & 0x01) == 0x01) ||
          ((rx_status & 0x02) == 0x02)) {
      
      Serial.print("Rx: ");
      Serial.print(rx_status,HEX);
      Serial.print(" / ");
      Serial.print(length,HEX);
      
      Serial.print(" / ");
      Serial.print(frame_id,HEX);
    
      for (i=0;i<8;i++) {
        Serial.print(" / ");
        Serial.print(frame_data[i],HEX);
      }

      Serial.println();
     }
    // delay(1);
     break;
  }
  
  if (pin == LOW) {
    pin = HIGH;
  } else {
    pin = LOW;
  }  

  inc++;
 

}
