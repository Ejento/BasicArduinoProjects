int leds[] = { 5, 6, 7, 8, 9, 10 };
int timer = 1000;
int lastLed = 0;
int randomLed = 0;
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < (sizeof(leds) / sizeof(int)); i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
    delay(timer);
    digitalWrite(leds[i], LOW);
    delay(timer);
  }
  delay(timer);
  for (int i = 0; i < (sizeof(leds) / sizeof(int)); i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(timer);
  for (int i = 0; i < (sizeof(leds) / sizeof(int)); i++) {
    digitalWrite(leds[i], LOW);
  }
}

void loop() {
  randomLed = random(6);
  Serial.print("The random number is ");
  Serial.println(randomLed);
  if (randomLed != lastLed) {
    if (randomLed >= 3) {
      digitalWrite(leds[randomLed], HIGH);
      delay(timer);
      digitalWrite(leds[randomLed], LOW);
      delay(timer);
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
  lastLed = randomLed;
}
