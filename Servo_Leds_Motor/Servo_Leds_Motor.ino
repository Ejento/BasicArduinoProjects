#include <Servo.h>

Servo myservo;

const int leds[] = {2, 5, 6};
int pos = 0;

void setup() {
  myservo.attach(3);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT); 
}

void loop() {
  // Circle
  digitalWrite(leds[0], HIGH);
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);              
    delay(20);                      
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(20);
  }
  digitalWrite(leds[0], LOW);
  delay(30);

  // Standar thesis
  digitalWrite(leds[1], HIGH);
  for (pos =0; pos <= 180; pos += 90) {
    myservo.write(pos);
    delay(500);
  }
  for (pos = 180; pos >=0; pos -= 90) {
    myservo.write(pos);
    delay(500);
  }
  digitalWrite(leds[1], LOW);
  delay(30);
  
  // Random
  digitalWrite(leds[2], HIGH);
  for (int i = 0; i <= 10; i++) {
    int x = random(180);
    myservo.write(x);
    delay(500);
  }
  digitalWrite(leds[2], LOW);
  delay(30);
}

