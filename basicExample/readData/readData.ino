#include <Wire.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String temp = "";
String temp2 = "";
int playerScore1 = 0;
int playerScore2 = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  Wire.begin();        // join i2c bus (address optional for master);
  Serial.begin(9600);  // start serial for output
}


void loop() {

  Wire.requestFrom(7, 4);    // request 6 bytes from slave device #8
  // lcd.setCursor(0, 0);

  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    //lcd.print(c);
    temp += c;
    Serial.print(c);
    // print the character
  }
  lcd.print(temp);
  // lcd.setCursor(0, 16);

  Wire.requestFrom(8, 4);
  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    //lcd.print(c);
    temp2 += c;
    Serial.print(c);         // print the character
  }
  lcd.print(" ");
  lcd.print(temp2);
  lcd.print(" ");
  temp = "";
  temp2 = "";
  delay(500);
  

}
