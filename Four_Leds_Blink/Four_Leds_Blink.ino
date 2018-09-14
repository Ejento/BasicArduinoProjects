// First we create a list of all the pins that we gonna use.
// Each digital pin from our Arduino is connected to an LED, so we can name this array as leds.
// I was using 3 different standalone leds and one RGB led for this project. My setup was something like this:
// Arduino pin 5 = Red LED
// Arduino pin 6 = Green LED
// Arduino pin 7 = Blue LED
// Arduino pin 8 = The blue color from a RGB LED
// Arduino pin 9 = The red color from a RGB LED
// Arduino pin 10 = The green color from a RGB LED
int leds[] = { 5, 6, 7, 8, 9, 10 };

// Because we want to have some delay between each action, we are initiating a timer here. The timer is in miliseconds, so 1000 ms = 1 sec.
int timer = 1000;

// We want to add some randomness in our project, so we are using the next to variables to add that.
int lastLed = 0; // Saves the last LED that has been turned on and off.
int randomLed = 0; // Saves the current random LED 

void setup() {
 
 // Here we are setting up our hardware. We want all the pins to act as outputs, so we are using the command pinMode to do that.
  // That could be enough, but I wanted to do a test drive to make sure that the LEDs are working as they should be.
  // In the first loop I turn on each LED on and off, and with the last two loops, I turn all the LEDs on and off at the same time.
  for (int i = 0; i < (sizeof(leds) / sizeof(int)); i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
    delay(timer);
    digitalWrite(leds[i], LOW);
    delay(timer);
  }
  delay(timer);
  
  // All the LEDs turned on
  for (int i = 0; i < (sizeof(leds) / sizeof(int)); i++) {
    digitalWrite(leds[i], HIGH);
  }
  // 1 secend delay
  delay(timer);
  
  // All the LEDs turned off
  for (int i = 0; i < (sizeof(leds) / sizeof(int)); i++) {
    digitalWrite(leds[i], LOW);
  }
}

// Here is my main function.
void loop() {
  // I choose a number between 0 and 5. I choose 6 because if you look at the array leds, you can see that I am using 6 LEDs for this project.
  randomLed = random(6);
  
  // If the random choosen LED is the same as the last LED, then we skip that and we start over.
  if (randomLed != lastLed) {
	  
	// If the random LED is one of the standalone LEDs, then we turned it on and off with a delay.
    if (randomLed <= 2) {
      digitalWrite(leds[randomLed], HIGH);
      delay(timer);
      digitalWrite(leds[randomLed], LOW);
      delay(timer);
	  
	// If the random LED is the RGB LED, then I am randomizing again the effect to get two colors to turn on at the same time. Still there is a chance to see only one color.
    } else {
      int randomRGB = random(3);
      digitalWrite(leds[randomLed], HIGH);
      digitalWrite(leds[randomRGB], HIGH);
      delay(timer);
      digitalWrite(leds[randomLed], LOW);
      digitalWrite(leds[randomRGB], LOW);
      delay(timer);
    }
  }
  
  // I save the last led that was been used.
  lastLed = randomLed;
}
