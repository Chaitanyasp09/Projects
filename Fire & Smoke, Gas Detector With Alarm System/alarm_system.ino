// Input ports
#include <SoftwareSerial.h>
int redLed = 12;        // Red LED pin
int greenLed = 11;      // Green LED pin
int buzzer = 10;        // Buzzer pin
int smokeA0 = A0;       // Smoke sensor analog pin
int sensorPin = A1;     // Flame sensor analog pin
int sensorThres = 500;  // Threshold value for smoke sensor

// Setup function for initializing pins and serial communication
void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  pinMode(sensorPin, INPUT);
  
  Serial.begin(9600);
}

// Main loop for monitoring smoke and flame sensors
void loop() {
  // Smoke sensor logic
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThres) {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);

  // Flame sensor logic
  Serial.println("Flame Sensor");
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if (sensorValue < 100) {
    Serial.println("Fire Detected");
    Serial.println("LED on");
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
}
