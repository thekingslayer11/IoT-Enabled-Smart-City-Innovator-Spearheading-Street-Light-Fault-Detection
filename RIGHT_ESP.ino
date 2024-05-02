#include "arduino_secrets.h"
#include "thingProperties.h"

void setup() {
  Serial.begin(9600);
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  
  location=Location(12.929411767804996, 77.62252839431241);
  Serial.print(led1);
  Serial.print(led2);
  Serial.print(led3);
  delay(500);
  
  if(Serial.available() >= 3){
   
   ldr1=Serial.read()-'0';
   ldr2=Serial.read()-'0';
   ldr3=Serial.read()-'0';
   
   ldr1 = (ldr1 == 1) ? 0 : 1;
   ldr2 = (ldr2 == 1) ? 0 : 1;
   ldr3 = (ldr3 == 1) ? 0 : 1;
   delay(1000);
  }

}

void onLdr1Change()  {
  // Add your code here to act upon Ldr1 change
}

void onLdr2Change()  {
  // Add your code here to act upon Ldr2 change
}

void onLdr3Change()  {
  // Add your code here to act upon Ldr3 change
}

void onLed1Change()  {
  // Add your code here to act upon Led1 change
}

void onLed2Change()  {
  // Add your code here to act upon Led2 change
}

void onLed3Change()  {
  // Add your code here to act upon Led3 change
}

void onLocationChange(){

}
/*
  Since Location is READ_WRITE variable, onLocationChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLocationChange()  {
  // Add your code here to act upon Location change
}