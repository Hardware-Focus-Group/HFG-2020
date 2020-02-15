#include <DHT.h>

#define DHTPIN 6 // Define pin
 
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE); // Create object

void setup() {
  Serial.begin(9600); // Begin serial and dht
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  if (isnan(h) || isnan(t)) { // Check for valid readings
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  else {
    Serial.print("Temperature : "); // Print readings to serial monitor
    Serial.println(t);
    Serial.print("Humidity : ");
    Serial.println(h);
    return;
  }

  delay(1000*20); // 20 second delay
}
