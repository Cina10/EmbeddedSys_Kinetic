//Includes the Arduino Stepper Library
#include <Stepper.h>
#include <WiFi.h>
#include <HTTPClient.h>
// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

const char *ssid_Router     = "";
const char *password_Router = "";
String address= "http://165.227.76.232:3000/mlw2173/running";

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 14, 26, 27, 25);

void setup() {
  // Nothing to do (Stepper Library sets pins as outputs)
  Serial.begin(9600);
  WiFi.begin(ssid_Router, password_Router);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to wifi");
}

void loop() {
  HTTPClient http;
  Serial.print("[HTTP] begin...\n");
  http.begin(address); //HTTP
  Serial.print("[HTTP] GET...\n"); // start connection and send HTTP header
  int httpCode = http.GET();
  if(httpCode > 0 && http.getString().equals("true")) {
    // Rotate CW slowly
    myStepper.setSpeed(10);
    myStepper.step(stepsPerRevolution);
    delay(1000);
  }
  else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

}
