#include <Stepper.h>

const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
const int leds[] = {5, 6, 7};

void setup() {
  myStepper.setSpeed(60);
  for (int i = 0; i < (sizeof(leds) / sizeof(int)); i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  digitalWrite(leds[0], HIGH);
  Serial.println("clockwise");
  for (int i = 0; i < 12; i++) {
    myStepper.step(stepsPerRevolution);
    delay(500);
  }
  digitalWrite(leds[0], LOW);
  delay(100);
  digitalWrite(leds[1], HIGH);
  for (int x = 0; x <= 360; x++) {
    myStepper.step(10);
    delay(15);
  }
  digitalWrite(leds[1], LOW);
  delay(100);
  
  digitalWrite(leds[2], HIGH);
  for (int i = 0; i < 12; i++) {
    myStepper.step(-stepsPerRevolution);
    delay(500);
  }
  digitalWrite(leds[2], LOW);
  delay(100);
}

