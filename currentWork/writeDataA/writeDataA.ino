
#include <Wire.h>
#include "measureCommunicate.h"

#define MY_ADDRESS 8

void setup() {
  Serial.begin(9600);
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
   //dtostrf(volts, 5, 3, str);
   // Serial.print("From slave A");
   // Serial.print(str);
   // int i = 0;
   // Wire.write("Glycine");
   I2C_writeAnything(valueToSend);
   // Serial.println("Glycine");
   
   // valueToBeSent = (int) (100.0 * volts);
}
