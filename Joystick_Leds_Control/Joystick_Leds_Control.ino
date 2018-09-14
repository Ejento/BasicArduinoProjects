int leds[] = {3, 4, 5, 6};
int yPin = 0;
int xPin = 1;
int buttonJ = 2;

void setup() {
  for (int i = 0; i < (sizeof(leds) / sizeof(int)); i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(buttonJ, INPUT);
  digitalWrite(buttonJ, HIGH);
  Serial.begin(9600);
}

void loop() {
  int stateOfButton = digitalRead(buttonJ);
  if (stateOfButton == LOW) {
    if (analogRead(xPin) >= 550) {
      digitalWrite(leds[3], HIGH);
    } else if (analogRead(yPin) <= 450) {
      digitalWrite(leds[1], HIGH);
    } else if (analogRead(yPin) >= 550) {
      digitalWrite(leds[2], HIGH);
    } else if (analogRead(xPin) <= 450) {
      digitalWrite(leds[0], HIGH);
    } else {
      for (int i = 0; i < (sizeof(leds) / sizeof(int)); i++) {
        digitalWrite(leds[i], LOW);
      }
    }
  } else {
    int x = random(4);
    digitalWrite(leds[x], HIGH);
    delay(50);
    digitalWrite(leds[x], LOW);
    delay(50);
  }
  delay(50);
}
