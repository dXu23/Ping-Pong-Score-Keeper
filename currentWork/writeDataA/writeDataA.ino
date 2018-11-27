#include <Wire.h>

void setup() {
  Wire.begin(7);                
  Wire.onRequest(requestEvent); 
}

void loop() {
  delay(100);
}

void requestEvent() {
   char arr[4];
   
   double x = 5.00;
   dtostrf(x, 4, 2, arr);
   //arr[4] = '/0';
   Wire.write(arr);
}
