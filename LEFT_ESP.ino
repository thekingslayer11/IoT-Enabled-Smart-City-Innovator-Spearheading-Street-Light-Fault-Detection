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
  
  Serial.print(led4);
  Serial.print(led5);
  Serial.print(led6);
  delay(500);
  
  if(Serial.available() >= 3){
   
  ldr4=Serial.read()-'0';
  ldr5=Serial.read()-'0';
  ldr6=Serial.read()-'0';
   
  ldr4 = (ldr4 == 1) ? 0 : 1;
  ldr5 = (ldr5 == 1) ? 0 : 1;
  ldr6 = (ldr6 == 1) ? 0 : 1;
  delay(1000);
  }
}

/*
  Since Ldr1 is READ_WRITE variable, onLdr1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLdr4Change()  {
  // Add your code here to act upon Ldr1 change
}

/*
  Since Ldr2 is READ_WRITE variable, onLdr2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLdr5Change()  {
  // Add your code here to act upon Ldr2 change
}

/*
  Since Ldr3 is READ_WRITE variable, onLdr3Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLdr6Change()  {
  // Add your code here to act upon Ldr3 change
}

/*
  Since Led1 is READ_WRITE variable, onLed1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLed4Change()  {
  // Add your code here to act upon Led1 change
}

/*
  Since Led2 is READ_WRITE variable, onLed2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLed5Change()  {
  // Add your code here to act upon Led2 change
}

/*
  Since Led3 is READ_WRITE variable, onLed3Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLed6Change()  {
  // Add your code here to act upon Led3 change
}