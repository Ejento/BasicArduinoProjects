#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

const int pins[] = {6, 7, 8, 9, 10, 11};
const int rec = 5;
int blinkSpeed = 500;
IRrecv irrecv(rec);
decode_results results;

bool nightMode = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < (sizeof(pins) / sizeof(int)); i++) {
    pinMode(pins[i], OUTPUT);
  }
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    switch (results.value) {
      case 16724175:
        Serial.println("1 was pressed!");
        digitalWrite(9, HIGH);
        delay(blinkSpeed);
        digitalWrite(9, LOW);
        Serial.println("Done!");
        break;
      case 16718055:
        Serial.println("2 was pressed!");
        digitalWrite(11, HIGH);
        digitalWrite(6, HIGH);
        delay(blinkSpeed);
        digitalWrite(11, LOW);
        digitalWrite(6, LOW);
        Serial.println("Done!");
        break;
      case 16743045:
        Serial.println("3 was pressed!");
        digitalWrite(10, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        delay(blinkSpeed);
        digitalWrite(10, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        Serial.println("Done!");
        break;
      case 16716015:
        Serial.println("4 was pressed!");
        inLine();
        Serial.println("Done!");
        break;
      case 16726215:
        Serial.println("5 was pressed!");
        randomish();
        Serial.println("Done!");
        break;
      case 16734885:
        Serial.println("6 was pressed!");
        allTogether();
        Serial.println("Done!");
        break;
      case 16728765:
        Serial.println("7 was pressed!");
        dancingLeds();
        Serial.println("Done!");
        break;
      case 16730805:
        Serial.println("8 was pressed!");
        randomLeds();
        Serial.println("Done!");
        break;
      case 16732845:
        Serial.println("9 was pressed!");
        semiFading();
        Serial.println("Done!");
        break;
      case 16754775:
        Serial.println("Speed up!");
        if (blinkSpeed < 2000) {
          blinkSpeed += 500;
        }
        Serial.print("Actual speed now is ");
        Serial.println(blinkSpeed);
        break;
      case 16769055:
        Serial.println("Speed down!");
        if (blinkSpeed > 500) {
          blinkSpeed -= 500;
        }
        Serial.print("Actual speed now is ");
        Serial.println(blinkSpeed);
        break;
      case 16750695:
        Serial.println("Speed up!");
        if (blinkSpeed < 2000) {
          blinkSpeed += 100;
        }
        Serial.print("Actual speed now is ");
        Serial.println(blinkSpeed);
        break;
      case 16756815:
        Serial.println("Speed up!");
        if (blinkSpeed < 2000) {
          blinkSpeed += 200;
        }
        Serial.print("Actual speed now is ");
        Serial.println(blinkSpeed);
        break;
      case 16738455:
        blinkSpeed = 500;
        Serial.println("Speed back at default!");
        Serial.print("Speed is now :");
        Serial.println(blinkSpeed);
        break;
      case 16748655: {
          irrecv.resume();
          if (nightMode == false) {
            nightMode = true;
          }
          Serial.println("Nightmode is ON!");
          while (nightMode) {
            int x = random(6);
            int y = random(6);
            if (x != y) {
              digitalWrite(pins[x], HIGH);
              digitalWrite(pins[y], HIGH);
              delay(blinkSpeed);
              digitalWrite(pins[x], LOW);
              digitalWrite(pins[y], LOW);
              if (irrecv.decode(&results)) {
                if (results.value == 16748655) {
                  nightMode == false;
                  Serial.println(results.value);
                  Serial.println("Nightmode is OFF!");
                  break;
                }
              }
            }
          }
          break;
        }
      default:
        Serial.println("Default action!");
        for (int i = 0; i < (sizeof(pins) / sizeof(int)); i++) {
          digitalWrite(pins[i], LOW);
        }
        //blinkSpeed = 500;
        break;
    }
    irrecv.resume();
  }
  delay(100);
}

void randomish() {
  for (int i = 0; i < (sizeof(pins) / sizeof(int)); i++) {
    digitalWrite(pins[i], HIGH);
    delay(blinkSpeed);
    digitalWrite(pins[i], LOW);
  }
}

void inLine() {
  digitalWrite(9, HIGH);
  delay(blinkSpeed);
  digitalWrite(6, HIGH);
  delay(blinkSpeed);
  digitalWrite(11, HIGH);
  delay(blinkSpeed);
  digitalWrite(10, HIGH);
  delay(blinkSpeed);
  digitalWrite(7, HIGH);
  delay(blinkSpeed);
  digitalWrite(8, HIGH);
  delay(blinkSpeed);
  digitalWrite(8, LOW);
  delay(blinkSpeed);
  digitalWrite(7, LOW);
  delay(blinkSpeed);
  digitalWrite(10, LOW);
  delay(blinkSpeed);
  digitalWrite(11, LOW);
  delay(blinkSpeed);
  digitalWrite(6, LOW);
  delay(blinkSpeed);
  digitalWrite(9, LOW);
}

void allTogether() {
  for (int i = 0; i < (sizeof(pins) / sizeof(int)); i++) {
    digitalWrite(pins[i], HIGH);
  }
  delay(blinkSpeed);
  for (int i = 0; i < (sizeof(pins) / sizeof(int)); i++) {
    digitalWrite(pins[i], LOW);
  }
}

void dancingLeds() {
  digitalWrite(10, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(blinkSpeed);
  digitalWrite(10, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  delay(blinkSpeed);
  digitalWrite(6, HIGH);
  digitalWrite(11, HIGH);
  delay(blinkSpeed);
  digitalWrite(6, LOW);
  digitalWrite(11, LOW);
  delay(blinkSpeed);
  digitalWrite(9, HIGH);
  delay(blinkSpeed);
  digitalWrite(9, LOW);
}

void randomLeds() {
  for (int i = 0; i < (sizeof(pins) / sizeof(int)); i++) {
    int x = random(6);
    int y = random(6);
    if ( x != y) {
      digitalWrite(pins[x], HIGH);
      digitalWrite(pins[y], HIGH);
      delay(blinkSpeed);
      digitalWrite(pins[x], LOW);
      digitalWrite(pins[y], LOW);
    }
  }
}

void semiFading() {
  for (int shade = 0; shade <= 255; shade += 5) {
    analogWrite(6, shade);
    analogWrite(10, shade);
    analogWrite(9, shade);
    delay(50);
  }
  digitalWrite(11, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
  for (int shade = 255; shade >= 0; shade -= 5) {
    analogWrite(9, shade);
    analogWrite(10, shade);
    analogWrite(6, shade);
    delay(50);
  }
  digitalWrite(11, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}
