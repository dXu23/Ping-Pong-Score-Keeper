// #include <Wire.h>

/*
#define ANALOG_PIN A0
#define DIGITAL_PIN 7
double measureSoundLevel() {
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
   peakToPeak = signalMax - signalMin;
   return 5.0 * peakToPeak / 1024;
   
}

long sndMeasureSound() {
  int i;
  long sum = 0;
  for (i = 0; i < 128; i++) 
    sum += analogRead(0);
  return sum / 128;
}

void setup() {
  Serial.begin(9600);
  pinMode(DIGITAL_PIN, OUTPUT);
  // Wire.begin(7);                
  // Wire.onRequest(requestEvent); 
}

void loop() {
  double x = analogRead(ANALOG_PIN);
  
  delay(100);
  Serial.println(x);
  // delay(100);
}
/*
void requestEvent() {
   // char arr[4];
   // Serial.print("YO");
   
   
   // Serial.println("Whatup");
   // dtostrf(x, 4, 2, arr);
   //arr[4] = '/0';
   // Wire.write(arr);
}
*/

int sensorPin = A0;
void setup() {
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  // int digitalReading = digitalRead(7);
  // if (digitalReading == HIGH) 
  //  Serial.println("Reading was high!");
  // else
  //   Serial.println("Reading was low!");
  // delay(500);
  
  unsigned int sensorValue = analogRead(sensorPin);
  // double result = sensorValue / 1024.0 * 50.0;
  Serial.println(sensorValue);
  delay(500);
}
