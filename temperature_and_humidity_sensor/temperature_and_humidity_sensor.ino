// This code reads the temperature using a DHT11 sensor.
// For more details, you can watch this Instagram reel: 
// URL:https://www.instagram.com/reel/DG59fcvqDUz/?utm_source=ig_web_copy_link&igsh=MzRlODBiNWFlZA==
// Don't forget to like and comment! Thanks :)
// -- 
//-------------------------------------------------------------------------------------------------
//  #install library # 
//  https://github.com/adafruit/DHT-sensor-library.git
//-------------------------------------------------------------------------------------------------

#include <DHT11.h>
// Define the data pin where DHT11 is connected
#define DHT_data_pin 2

// Initialize the DHT11 sensor
DHT11 dht11(DHT_data_pin);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the temperature value
  int temperature = dht11.readTemperature();

  // Check if the reading was successful
  if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT) {
    // Print the temperature if the reading is valid
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
  } else {
    // Print error message if there was an issue reading the sensor
    Serial.println(dht11.getErrorString(temperature));
  }

  // Add a small delay before the next reading
  delay(2000); // Delay in milliseconds (2 seconds)
}
