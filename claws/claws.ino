/**********************************************************************
  Filename    : Control_Motor_by_L293D
  Description : Use PWM to control the direction and speed of the motor.
  Auther      : www.freenove.com
  Modification: 2020/07/11
**********************************************************************/
int in1Pin = 12;      // Define L293D channel 1 pin
int in2Pin = 14;      // Define L293D channel 2 pin
int enable1Pin = 13;  // Define L293D enable 1 pin
int channel = 0;

boolean rotationDir;  // Define a variable to save the motor's rotation direction
int rotationSpeed;    // Define a variable to save the motor rotation speed

void setup() {
  // Initialize the pin into an output mode:
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  
  ledcSetup(channel,1000,11);         //Set PWM to 11 bits, range is 0-2047
  ledcAttachPin(enable1Pin,channel);
}

void loop() {
 driveMotor(true, 1000);
}

void driveMotor(boolean dir, int spd) {
  // Control motor rotation direction
  if (rotationDir) {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  }
  else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }
  // Control motor rotation speed
  ledcWrite(channel, spd);
}
