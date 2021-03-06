#include <Wire.h>
#include "measureCommunicate.h"
#include "Arduino.h"

#define MY_ADDRESS 7

unsigned int bytesSent;

void setup() {
  Wire.begin(MY_ADDRESS);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
   double valueToSend = measureSoundLevel();
   // bytesSent = I2C_writeAnything(valueToSend);
   char str[5];
   dtostrf(valueToSend, 5, 3, str);
   Wire.write("world");
   
   // Wire.write((String)valueToSend);
   // Serial.print(bytesSent);
   // Serial.print(": ");
   // Serial.print(valueToSend);
}
