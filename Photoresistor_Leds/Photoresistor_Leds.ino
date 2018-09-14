const int input = A0;
const int leds[] = {8, 6, 12};
int sensorV = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i <= (sizeof(leds) / sizeof(int)); i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorV = analogRead(input);
  while (sensorV >= 2700 and sensorV < 3700) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], LOW);
    digitalWrite(leds[2], LOW);
    sensorV = analogRead(input);
    Serial.println(sensorV);
  }
  while (sensorV >= 1700 and sensorV < 2700) {
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[0], LOW);
    digitalWrite(leds[2], LOW);
    sensorV = analogRead(input);
    Serial.println(sensorV);
  }
  while (sensorV >= 700 and sensorV < 1700) {
    digitalWrite(leds[2], HIGH);
    sensorV = analogRead(input);
    digitalWrite(leds[0], LOW);
    digitalWrite(leds[1], LOW);
    Serial.println(sensorV);
  }
}
