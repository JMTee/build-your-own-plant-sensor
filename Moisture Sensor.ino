#include "DHT.h"

int sensorPin = A0;    // select the input pin for the moisture Sensor
int sensorValue = 0;  // variable to store the value coming from the sensor
const int light = 4;
#define DHTPIN 5 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
	// declare the ledPin as an OUTPUT:
	Serial.begin(9600);
	dht.begin();
}

void loop() {
	sensorValue = analogRead(light);

	Serial.println(sensorValue);
	// Reading temperature or humidity takes about 250 milliseconds!
	// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
	float h = dht.readHumidity();
	float t = dht.readTemperature();

	// check if returns are valid, if they are NaN (not a number) then something went wrong!
	if (isnan(t) || isnan(h)) {
		Serial.println("Failed to read from DHT");
	}
	else {
		Serial.print("Humidity: ");
		Serial.print(h);
		Serial.print(" %\t");
		Serial.print("Temperature: ");
		Serial.print(t);
		Serial.println(" *C");
	}

	// read the value from the sensor:
	sensorValue = analogRead(sensorPin);
	delay(1000);
	Serial.print("Moisture sensor = ");
	Serial.println(sensorValue);


	
}