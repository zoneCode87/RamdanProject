// This code implements a simple IR receiver to control LEDs using an IR remote.
// For more details, you can watch this Instagram reel: 
// URL: https://www.instagram.com/reel/DHG08eWqLVk/?utm_source=ig_web_copy_link&igsh=MzRlODBiNWFlZA==
// Don't forget to like and comment! Thanks :)

#define DECODE_NEC        
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp> 

// Define IR pin and LED pins
#define IR_pin 2
#define led_red 8
#define led_yellow 9 
#define led_green 10  

// Define IR command codes for controlling LEDs
enum control {
  RED = 7,
  YELLOW = 21,
  GREEN  = 9,
  DANCE = 64,
  DANCE_REVERS = 25,
  ALL_ON = 28,   
};

void setup() {
  
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);


  Serial.begin(115200);
  
  // Initialize IR receiver with feedback LED enabled
  IrReceiver.begin(IR_pin, ENABLE_LED_FEEDBACK);
  
  // Print active IR protocols for debugging
  printActiveIRProtocols(&Serial);
}

void loop() {
  // Check if the IR receiver has received a signal
  if (IrReceiver.decode()) {
    IrReceiver.resume();  // Prepare for the next IR signal
    int Read_IR = IrReceiver.decodedIRData.comma
    
    // Execute actions based on the received IR command
    switch(Read_IR) {
      case (RED):
        digitalWrite(led_red, HIGH); 
        break;
        
      case (YELLOW):
        digitalWrite(led_yellow, HIGH);  
        break;

      case (GREEN):
        digitalWrite(led_green, HIGH); 
        break;

      case (DANCE):
        dance();  // Trigger the dance sequence
        break;

      case (DANCE_REVERS):
        dance_rev();  // Trigger the reverse dance sequence
        break;

      case (ALL_ON):
        // Turn on all LEDs
        digitalWrite(led_red, HIGH);
        digitalWrite(led_yellow, HIGH);
        digitalWrite(led_green, HIGH);
        break;
    }
  } else {
    // Turn off all LEDs if no signal is received
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);
  }
  
  // Short delay to prevent excessive looping
  delay(110);
}

// Dance function: LEDs blink in sequence
void dance() {
  digitalWrite(led_red, HIGH);
  delay(100);
  digitalWrite(led_red, LOW);
  
  digitalWrite(led_yellow, HIGH);
  delay(100);
  digitalWrite(led_yellow, LOW);
  
  digitalWrite(led_green, HIGH);
  delay(100);
  digitalWrite(led_green, LOW);
}

// Reverse dance function: LEDs blink in reverse sequence
void dance_rev() {
  digitalWrite(led_green, HIGH);
  delay(100);
  digitalWrite(led_green, LOW);
  
  digitalWrite(led_yellow, HIGH);
  delay(100);
  digitalWrite(led_yellow, LOW);
  
  digitalWrite(led_red, HIGH);
  delay(100);
  digitalWrite(led_red, LOW);
}
