#include <ESP32Servo.h>
#include <WiFi.h>
#include <HTTPClient.h>
Servo myservo;  // create servo object to control a servo

const char *ssid_Router     = "";
const char *password_Router = "";

int posVal = 0;    // variable to store the servo position
int servoPin = 15; // Servo motor pin
int servoPin2 = 19;
String address= "http://165.227.76.232:3000/YOUR-UNI/running";

void setup() {
  myservo.setPeriodHertz(50);           // standard 50 hz servo
  myservo.attach(servoPin, 500, 2500);  // attaches the servo on servoPin to the servo object
  myservo.attach(servoPin2, 500, 1500);
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

  Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
  int httpCode = http.GET();

  if(httpCode > 0 && http.getString().equals("true")) {
    for (posVal = 0; posVal <= 180; posVal += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(posVal);       // tell servo to go to position in variable 'pos'
      delay(15);                   // waits 15ms for the servo to reach the position
    }
    for (posVal = 180; posVal >= 0; posVal -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(posVal);       // tell servo to go to position in variable 'pos'
      delay(15);                   // waits 15ms for the servo to reach the position
    }
  }
  else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
}
