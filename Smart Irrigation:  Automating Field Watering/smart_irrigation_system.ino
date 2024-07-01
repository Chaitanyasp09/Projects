// Include necessary libraries
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

// Pin definitions
#define DHT11PIN 16 // Digital pin for DHT11 sensor
#define sensor 33   // Analog pin for soil moisture sensor
#define relay 13    // Digital pin for relay control
#define SunLightPin 34 // Analog pin for sunlight sensor

// Initialize DHT sensor and LCD display
DHT dht(DHT11PIN, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Blynk authentication and Wi-Fi credentials
char auth[] = "authentication id";
char ssid[] = "admin";
char pass[] = "password";

// BlynkTimer object
BlynkTimer timer;

// Setup function, runs once on startup
void setup() {
  Serial.begin(115200); // Start serial communication
  dht.begin(); // Start DHT sensor
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); // Connect to Blynk server
  lcd.init(); // Initialize LCD
  lcd.backlight(); // Turn on LCD backlight
  pinMode(relay, OUTPUT); // Set relay pin as output
  digitalWrite(relay, LOW); // Ensure relay is initially off

  // Display system loading message on LCD
  lcd.setCursor(1, 0);
  lcd.print("System Loading");
  for (int a = 0; a <= 15; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(200);
  }
  lcd.clear(); // Clear LCD screen
}

// Function to read soil moisture and send data to Blynk
void soilMoisture() {
  moistureValue = analogRead(sensor); // Read soil moisture sensor
  moistureValue = map(moistureValue, 0, 4095, 0, 100); // Map sensor value to percentage
  moistureValue = (moistureValue - 100) * -1; // Adjust moisture value
  Blynk.virtualWrite(V0, moistureValue); // Send moisture value to Blynk app
  Serial.print("Moisture value = ");
  Serial.println(moistureValue);
  lcd.setCursor(0, 0);
  lcd.print("Moisture :");
  lcd.print(moistureValue);
  lcd.print(" ");
}

// Blynk callback for relay control
BLYNK_WRITE(V1) {
  bool relayState = param.asInt();
  if (relayState == 1) {
    digitalWrite(relay, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor is ON ");
  } else {
    digitalWrite(relay, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Motor is OFF");
  }
}

// Function to check sunlight level and send status to Blynk
void checkSun() {
  int lightValue = analogRead(SunLightPin); // Read sunlight sensor
  String sunStatus;

  // Determine sunlight status based on sensor value
  if (lightValue >= 200 && lightValue <= 1000) {
    sunStatus = "Cloudy";
  } else if (lightValue > 1000 && lightValue <= 4095) {
    sunStatus = "Dusk";
  } else if (lightValue >= 0 && lightValue <= 200) {
    sunStatus = "Daylight";
  } 
  Blynk.virtualWrite(V3, sunStatus); // Send sunlight status to Blynk app
  Serial.println(sunStatus);
}

// Function to read temperature and humidity and send data to Blynk
void tempHumidity() {
  humidityValue = dht.readHumidity(); // Read humidity from DHT sensor
  temperatureValue = dht.readTemperature(); // Read temperature from DHT sensor
  Serial.print("Temperature: ");
  Serial.print(temperatureValue);
  Serial.print("ºC ");
  Serial.print("Humidity: ");
  Serial.println(humidityValue);
  Blynk.virtualWrite(V4, humidityValue); // Send humidity to Blynk app
  Blynk.virtualWrite(V5, temperatureValue); // Send temperature to Blynk app
  delay(1000); // Delay to prevent flooding Blynk server
}

// Function to output messages based on sensor readings
void output() {
  String message;

  // Determine appropriate message based on sensor readings
  if (moistureValue < 30 ) {
     message = "Need water!!";
     Blynk.logEvent("alert","Need water!!");
  }
  else if (temperatureValue >= 30 || humidityValue <= 30){
        message = "Temperature and humidity alert: Start watering!!";
        Blynk.logEvent("alert","Temperature and humidity alert: Start watering!!");
    }
  else if (moistureValue < 30 && temperatureValue >= 27 && humidityValue >= 25) {
     message = "Take care of me!!";
     Blynk.logEvent("alert","Take care of me!!");
  }
  else 
   message = "Temperature and humidity: Normal";
  
  Serial.println(message);
  Blynk.virtualWrite(V6, message); // Send message to Blynk app
}

// Main loop function
void loop() {
  soilMoisture(); // Read soil moisture
  checkSun(); // Check sunlight level
  tempHumidity(); // Read temperature and humidity
  output(); // Output messages based on sensor readings
  Blynk.run(); // Run Blynk
  delay(200); // Delay for stability
}
