//---------------------------------------------
// This circuit controls an LED based on the light intensity detected by an LDR.
// For more details, you can watch this Instagram reel: 
// URL: https://www.instagram.com/reel/DGv2zcjutrb/?utm_source=ig_web_copy_link&igsh=MzRlODBiNWFlZA==
// Don't forget to like and comment! Thanks :)
// --------------------------------------------

#define ldrPin A0   
#define ledPin 7   
int ldrValue = 0; 
int MAXValue = 300; // Threshold for light intensity to control the LED

void setup() {
  pinMode(ledPin, OUTPUT);  
  Serial.begin(9600);      
}

void loop() {
  ldrValue = analogRead(ldrPin);  // Read the light value from the LDR

  // If the light value is less than the MAXValue, turn the LED ON
  if (ldrValue < MAXValue) {
    digitalWrite(ledPin, HIGH);  
  } else {
    digitalWrite(ledPin, LOW);  
  }

  // Print LDR value to Serial Monitor (for debugging)
  Serial.println(ldrValue);      
  delay(100); 
}