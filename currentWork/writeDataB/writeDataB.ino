#include <Wire.h>

double measureSoundLevel() {
   /*
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level
 
   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;
   unsigned sampleWindow = 50;
   unsigned int sample;
 
   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   */
   /*long sum = 0;
   int i;
   for (i = 0; i < 100; i++)
       sum += analogRead(0);
   return sum / 100;
   /*
   Serial.print("peakToPeak");
   Serial.println(x * 5.0 / 1024);
   return x * 5.0 / 1024;
   */
   double x = analogRead(0);
   return x/100;
   
}

void setup() {
  Serial.begin(9600);
  Wire.begin(8);                
  Wire.onRequest(requestEvent); 
}

void loop() {
  delay(100);
}

void requestEvent() {
   char arr[10];

   // Serial.print("Hello");
   double x = measureSoundLevel();
   // Serial.print("World!");
   Serial.print(x);
   dtostrf(x, 4, 2, arr);
   //arr[4] = '/0';
   Wire.write(arr);
}
