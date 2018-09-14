#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const byte lcdAddr = 0x27;
const byte lcdCols = 16;
const byte lcdRows = 2;

LiquidCrystal_I2C lcd(lcdAddr, lcdCols, lcdRows);

// Demo parameters
const char myText1[]= "Hello World";
const char myText2[]= "I am using I2C!";
const unsigned int scrollDelay = 500;   
const unsigned int textDelay = 2000;  
byte textLen;                          

void setup() {
  textLen = sizeof(myText1) - 1;
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(myText1);
  lcd.setCursor(0, 1);
  lcd.print(myText2);
  delay(textDelay);
}

void loop() {
  for (byte positionCounter = 0; positionCounter < textLen; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(scrollDelay);
  }
  for (byte positionCounter = 0; positionCounter < textLen + lcdCols; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(scrollDelay);
  }
  for (byte positionCounter = 0; positionCounter < lcdCols; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(scrollDelay);
  }
  delay(textDelay);
}
