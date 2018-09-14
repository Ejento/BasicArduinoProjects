// First we create a list of all the pins that we gonna use.
// Each digital pin from our Arduino is connected to an LED, so we can name this array as leds.
// I was using 3 different standalone leds and one RGB led for this project. My setup was something like this:
// Arduino pin 3 = Red LED
// Arduino pin 5 = Green LED
// Arduino pin 6 = Blue LED
// Arduino pin 9 = The blue color from the RGB LED
// Arduino pin 10 = The red color from the RGB LED
// Arduino pin 11 = The green color from the RGB LED
int leds[] = { 11, 10, 9 , 6, 5, 3 };

void setup() {
  // I am setting up the hardware for this project, as we want each pin to act as output.
  for (int i = 0; i < (sizeof(leds) / sizeof(int)); i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // This loop turns on the LED little by little with a very small, unnoticed delay.
  for (int shade = 0; shade <= 255; shade += 1) {
    analogWrite(leds[2], shade);
    delay(15);
  }
  // This loop turns on the LED little by little with a very small, unnoticed delay.
  for (int shade = 0; shade <= 255; shade += 1) {
    analogWrite(leds[1], shade);
    delay(15);
  }

  // This loop turns on the LED little by little with a very small, unnoticed delay.
  for (int shade = 0; shade <= 255; shade += 1) {
    analogWrite(leds[0], shade);
    delay(15);
  }
  
  // This loop turns off the LED little by little with a very small, unnoticed delay. 
  for (int shade = 255; shade >= 0; shade -= 1) {
    analogWrite(leds[1], shade);
    delay(15);
  }

  // This loop turns off the LED little by little with a very small, unnoticed delay.
  for (int shade = 255; shade >= 0; shade -= 1) {
    analogWrite(leds[0], shade);
    delay(15);
  }

  // This loop turns off the LED little by little with a very small, unnoticed delay.
  for (int shade = 255; shade >= 0; shade -= 1) {
    analogWrite(leds[2], shade);
    delay(15);
  }

  // This loop turns on the LED little by little with a very small, unnoticed delay.
  for (int shade = 0; shade <= 255; shade += 5) {
    analogWrite(leds[3], shade);
    delay(60);
  }

  // This loop turns off the LED little by little with a very small, unnoticed delay.
  for (int shade = 255; shade >= 0; shade -= 5) {
    analogWrite(leds[3], shade);
    delay(60);
  }

  // This loop turns on the LED little by little with a very small, unnoticed delay.
  for (int shade = 0; shade <= 255; shade += 5) {
    analogWrite(leds[4], shade);
    delay(60);
  }

  // This loop turns off the LED little by little with a very small, unnoticed delay.
  for (int shade = 255; shade >= 0; shade -= 5) {
    analogWrite(leds[4], shade);
    delay(60);
  }

  // This loop turns on the LED little by little with a very small, unnoticed delay.
  for (int shade = 0; shade <= 255; shade += 5) {
    analogWrite(leds[5], shade);
    delay(60);
  }

  // This loop turns off the LED little by little with a very small, unnoticed delay.
  for (int shade = 255; shade >= 0; shade -= 5) {
    analogWrite(leds[5], shade);
    delay(60);
  }
}
