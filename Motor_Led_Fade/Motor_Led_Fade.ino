int enabler = 2;
int motorPin1 = 3;
int motorPin2 = 5;
int greenLed = 7;
int redLed = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(enabler, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(greenLed, HIGH);
  for (int motorSpeed = 0; motorSpeed <= 255; motorSpeed += 5) {
    analogWrite(enabler, motorSpeed);
    delay(30);
  }
  delay(2000);
  for (int motorSpeed = 255; motorSpeed >= 0; motorSpeed -= 5) {
    analogWrite(enabler, motorSpeed);
    delay(30);
  }
  digitalWrite(enabler, LOW);
  digitalWrite(greenLed, LOW);
  delay(2000);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(redLed, HIGH);
  for (int motorSpeed = 0; motorSpeed <= 255; motorSpeed += 5) {
    analogWrite(enabler, motorSpeed);
    delay(30);
  }
  delay(2000);
  for (int motorSpeed = 255; motorSpeed >= 0; motorSpeed -= 5) {
    analogWrite(enabler, motorSpeed);
    delay(30);
  }
  digitalWrite(enabler, LOW);
  digitalWrite(redLed, LOW);
  delay(2000);
}
