#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <SoftwareSerial.h>

const char *monthName[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

tmElements_t tm;

const int ldr1 = 5;
const int ldr2 = 6;
const int ldr3 = 7;

const int led1 = 9;
const int led2 = 10;
const int led3 = 11;

bool ledValue1 = false;
bool ledValue2 = false;
bool ledValue3 = false;

bool ldrValue1;
bool ldrValue2;
bool ldrValue3;

const int pir1 = 8;

int brightness = 10;     // Initial brightness (50% of maximum)

void setup() {
  bool parse=false;
  bool config=false;

  if (getDate(__DATE__) && getTime(__TIME__)) {
    parse = true;
    if (RTC.write(tm)) {
      config = true;
    }
  }
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(pir1, INPUT);

  analogWrite(led1, brightness);
  analogWrite(led2, brightness);
  analogWrite(led3, brightness);

  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  if (parse && config) {
    Serial.print("DS1307 configured Time=");
    Serial.print(__TIME__);
    Serial.print(", Date=");
    Serial.println(__DATE__);
  } else if (parse) {
    Serial.println("DS1307 Communication Error :-{");
    Serial.println("Please check your circuitry");
  } else {
    Serial.print("Could not parse info from the compiler, Time=\"");
    Serial.print(__TIME__);
    Serial.print("\", Date=\"");
    Serial.print(__DATE__);
    Serial.println("\"");
  }
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  pinMode(ldr3, INPUT);
}

void loop() {
  if(Serial.available() >= 3){ 
    ledValue1 = Serial.read() - '0';
    ledValue2 = Serial.read() - '0';
    ledValue3 = Serial.read() - '0';

    digitalWrite(led1, ledValue1);
    digitalWrite(led2, ledValue2);
    digitalWrite(led3, ledValue3);

    delay(500);
  }

  if (RTC.read(tm)) {
    int currentHour = tm.Hour;
    
    // Turn off LEDs from 6 am to 6 pm
    if (currentHour >= 6 && currentHour < 18) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
    else {
      ldrValue1 = digitalRead(ldr1);
      ldrValue2 = digitalRead(ldr2);
      ldrValue3 = digitalRead(ldr3);

      Serial.print(ldrValue1);
      Serial.print(ldrValue2);
      Serial.print(ldrValue3);

      if (digitalRead(pir1) == HIGH) {
          brightness = 255;  // Set brightness to maximum (100%)
          Serial.println("Motion Detected!");
          analogWrite(led1, brightness);
          analogWrite(led2, brightness);
          analogWrite(led3, brightness);
      } 
      else {
          Serial.println("No Motion Detected!");
        }
      
  delay(5000);
  }
 }
}
  /*if (RTC.read(tm)) {
    int currentHour = tm.Hour;
    int currentMinute = tm.Minute;

    if ((currentHour == 12 && currentMinute >= 55) || (currentHour == 13 && currentMinute <= 0)) {
  */
bool getTime(const char *str)
{
  int Hour, Min, Sec;

  if (sscanf(str, "%d:%d:%d", &Hour, &Min, &Sec) != 3) return false;
  tm.Hour = Hour;
  tm.Minute = Min;
  tm.Second = Sec;
  return true;
}

bool getDate(const char *str)
{
  char Month[12];
  int Day, Year;
  uint8_t monthIndex;

  if (sscanf(str, "%s %d %d", Month, &Day, &Year) != 3) return false;
  for (monthIndex = 0; monthIndex < 12; monthIndex++) {
    if (strcmp(Month, monthName[monthIndex]) == 0) break;
  }
  if (monthIndex >= 12) return false;
  tm.Day = Day;
  tm.Month = monthIndex + 1;
  tm.Year = CalendarYrToTm(Year);
  return true;
}
