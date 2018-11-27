#include "measureCommunicate.h"
#include <Wire.h> // Probably not necessary, but just for good measure. 
#include <LiquidCrystal.h>

// Slave Addresses
#define SLAVE_ADDRESS_A 8
#define SLAVE_ADDRESS_B 7

// Variables for liquid crystal display
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned int bytesRead;

// Variables for volume
char volumeA[5];
char volumeB[5];
char c;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  // Wire.onReceive(receiveEvent)
  // lcd.print("Hello world!");
}

void loop() {
  // lcd.print("Hello0");
  Wire.requestFrom(SLAVE_ADDRESS_A, 6);
  // lcd.print("world");
  // lcd.setCursor(0, 0);
  // while (Wire.available) {
  // c = Wire.read();
  // Serial.print(c);
  // lcd.print(c);
  lcd.setCursor(0, 0);
  //Serial.println("Beginning of slave A output");
  while (Wire.available()) {
      c = Wire.read();
      lcd.print(c);
      Serial.print(c);
  }
  
  // lcd.print(volumeA);
  // lcd.print("Working?");
  // Serial.print(bytesRead);
  // Serial.print(volumeA);
  // }
  // lcd.print("World");

  delay(200);

  Wire.requestFrom(SLAVE_ADDRESS_B, 6);
  // while (Wire.available()) {
  // c = Wire.read();
  // Serial.print(c);
  // lcd.print(c);
  
  // lcd.setCursor(0, 1);
  while (Wire.available()) {
      c = Wire.read();
      lcd.print(c);
      Serial.print(c);
  }
  // bytesRead = I2C_readAnything(volumeB);
  
  // lcd.print(volumeB);
  // Serial.print(bytesRead);
  // Serial.print(volumeB);
    
  //}

  delay(200);
 
}
