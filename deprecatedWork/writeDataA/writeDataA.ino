
#include <Wire.h>
#include "Arduino.h"
#include "measureCommunicate.h"

#define MY_ADDRESS 8

void setup() {
  // Serial.begin(9600);
  Wire.begin(MY_ADDRESS);                
  Wire.onRequest(requestEvent); 
}

void loop() {
  delay(100);
}

void requestEvent() {
   double valueToSend = measureSoundLevel();
   // Serial.println(volts);
   // bytesSent = I2C_writeAnything(volts);
   // Serial.print("From slave A");
   // Serial.print(str);
   // int i = 0;
   // char str[6];
   // dtostrf(valueToSend, 5, 3, str);
   // str[6] = '\0';
   Wire.write("hello ");
   // I2C_writeAnything(valueToSend);
   // Serial.println("Glycine");
   
   // valueToBeSent = (int) (100.0 * volts);
}
