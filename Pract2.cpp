#include "DHT.h"   // Adafruit DHT library

#define DHTPIN A0   // DHT11 connected to A0
#define DHTTYPE DHT11  // Define the sensor type (DHT11)
#define LED 13     // LED connected to pin 13

DHT dht(DHTPIN, DHTTYPE);  // Create sensor object

void setup() {
  pinMode(LED, OUTPUT);     // Set LED pin as output
  Serial.begin(9600);       // Start Serial communication
  dht.begin();              // Initialize DHT sensor
  delay(1000);

  // Assignment No: 02
  // Roll No: COA-55
  // Batch: A3
  // DHT11 connected to A0
  // LED connected to pin 13
}

void loop() {
  float humidity = dht.readHumidity();     // Read humidity
  float temperature = dht.readTemperature(); // Read temperature in °C

  Serial.print("Current Humidity = ");
  Serial.print(humidity);
  Serial.print("%  ");
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println("°C");

  if (temperature > 30) {      // If temperature > 30°C
    digitalWrite(LED, HIGH);   // Turn ON LED
  } else {
    digitalWrite(LED, LOW);    // Turn OFF LED
  }

  delay(1000); // Wait 1 second
}
