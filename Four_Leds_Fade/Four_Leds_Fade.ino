int pins[] = { 11, 10, 9 , 6, 5, 3 };
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < (sizeof(pins) / sizeof(int)); i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("1st loop!");
  for (int shade = 0; shade <= 255; shade += 1) {
    analogWrite(pins[2], shade);
    delay(15);
  }
  Serial.println("2nd loop!");
  for (int shade = 0; shade <= 255; shade += 1) {
    analogWrite(pins[1], shade);
    delay(15);
  }
  Serial.println("3rd loop!");
  for (int shade = 0; shade <= 255; shade += 1) {
    analogWrite(pins[0], shade);
    delay(15);
  }
  Serial.println("4th loop!");
  for (int shade = 255; shade >= 0; shade -= 1) {
    analogWrite(pins[1], shade);
    delay(15);
  }
  Serial.println("5th loop!");
  for (int shade = 255; shade >= 0; shade -= 1) {
    analogWrite(pins[0], shade);
    delay(15);
  }
  Serial.println("6th loop!");
  for (int shade = 255; shade >= 0; shade -= 1) {
    analogWrite(pins[2], shade);
    delay(15);
  }
  Serial.println("7th loop!");
  for (int shade = 0; shade <= 255; shade += 5) {
    analogWrite(pins[3], shade);
    delay(60);
  }
  Serial.println("8th loop!");
  for (int shade = 255; shade >= 0; shade -= 5) {
    analogWrite(pins[3], shade);
    delay(60);
  }
  Serial.println("9th loop!");
  for (int shade = 0; shade <= 255; shade += 5) {
    analogWrite(pins[4], shade);
    delay(60);
  }
  Serial.println("10th loop!");
  for (int shade = 255; shade >= 0; shade -= 5) {
    analogWrite(pins[4], shade);
    delay(60);
  }
  Serial.println("11th loop!");
  for (int shade = 0; shade <= 255; shade += 5) {
    analogWrite(pins[5], shade);
    delay(60);
  }
  Serial.println("12th loop!");
  for (int shade = 255; shade >= 0; shade -= 5) {
    analogWrite(pins[5], shade);
    delay(60);
  }
}
