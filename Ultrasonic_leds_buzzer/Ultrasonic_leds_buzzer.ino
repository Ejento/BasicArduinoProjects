int const trigPin = 9;
int const echoPin = 10;
int const buzzPin = 5;
int const greenLed = 4;
int const redLed = 2;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance <= 6 && distance >= 0) {
    digitalWrite(buzzPin, HIGH);
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  } else {
    digitalWrite(greenLed, HIGH);
    digitalWrite(buzzPin, LOW);
    digitalWrite(redLed, LOW);
  }
  delay(60);
}
