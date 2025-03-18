
#define DECODE_NEC        
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp> 
#define IR_pin 2
// led pin 
#define  led_red  8
#define  led_yellow 9 
#define  led_green 10  


enum control {
 RED = 7,
 YELLOW = 21,
 GREEN  = 9,
 DANCE = 64,
 DANCE_REVERS = 25,
 ALL_ON = 28,   
};


void setup() {
    pinMode(led_red,OUTPUT);
    pinMode(led_yellow,OUTPUT);
    pinMode(led_green,OUTPUT);

    Serial.begin(115200);
    IrReceiver.begin(IR_pin, ENABLE_LED_FEEDBACK);
    printActiveIRProtocols(&Serial);
}

void loop() {
    if (IrReceiver.decode()) {
        IrReceiver.resume(); 
       int Read_IR  =  IrReceiver.decodedIRData.command ; 
       Serial.println(Read_IR); 
       switch(Read_IR){
        case (RED):
          digitalWrite(led_red,1);
        break; 
       
        case (YELLOW):
        digitalWrite(led_yellow,1);
        break; 

        case (GREEN):
        digitalWrite(led_green,1);
        break; 

        
        case (DANCE):
        dance();
        break; 

        case (DANCE_REVERS):
        dance_rev();
        break; 
        
        case (ALL_ON):
         digitalWrite(led_red,1);
         digitalWrite(led_yellow,1);
         digitalWrite(led_green,1);
        break; 

    

      }
        
  }else{
    digitalWrite(led_red,0); 
    digitalWrite(led_yellow,0);
    digitalWrite(led_green,0);
  }
  delay(110);
}
void dance(){
   digitalWrite(led_red,1);
   delay(100);
   digitalWrite(led_red,0);
   digitalWrite(led_yellow,1);
   delay(100);
   digitalWrite(led_yellow,0);
   digitalWrite(led_green,1);
   delay(100);
   digitalWrite(led_green,0);
  
}
void dance_rev(){
   digitalWrite(led_green,1);
   delay(100);
   digitalWrite(led_green,0);
   digitalWrite(led_yellow,1);
   delay(100);
   digitalWrite(led_yellow,0);
   digitalWrite(led_red,1);
   delay(100);
   digitalWrite(led_red,0);
}
