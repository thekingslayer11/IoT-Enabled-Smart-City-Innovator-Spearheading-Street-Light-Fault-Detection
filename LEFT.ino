#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <SoftwareSerial.h>

const char *monthName[12] = {
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

tmElements_t tm;

const int ldr4 = 5;
const int ldr5 = 6;
const int ldr6 = 7;

const int led4 = 9;
const int led5 = 10;
const int led6 = 11;

bool ledValue4 = false;
bool ledValue5 = false;
bool ledValue6 = false;

bool ldrValue4;
bool ldrValue5;
bool ldrValue6;

const int pir2 = 8;

int brightness = 10;  // Initial brightness (50% of maximum)

void setup() {

  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  pinMode(pir2, INPUT);

  analogWrite(led4, brightness);
  analogWrite(led5, brightness);
  analogWrite(led6, brightness);

  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for Native USB only
  }

  pinMode(ldr4, INPUT);
  pinMode(ldr5, INPUT);
  pinMode(ldr6, INPUT);
}

void loop() {

  ldrValue4 = digitalRead(ldr4);
  ldrValue5 = digitalRead(ldr5);
  ldrValue6 = digitalRead(ldr6);

  Serial.print(ldrValue4);
  Serial.print(ldrValue5);
  Serial.print(ldrValue6);

  if (Serial.available() >= 3) {
    ledValue4 = Serial.read() - '0';
    ledValue5 = Serial.read() - '0';
    ledValue6 = Serial.read() - '0';

    digitalWrite(led4, ledValue4);
    digitalWrite(led5, ledValue5);
    digitalWrite(led6, ledValue6);

    delay(500);
  }

  if (ledValue4 == 1 && ledValue5 == 1 && ledValue6 == 1) {
    if (digitalRead(pir2) == HIGH) {
      brightness = 255;
      analogWrite(led4, brightness);
      analogWrite(led5, brightness);
      analogWrite(led6, brightness);
      delay(1000);
    }
  }
  delay(1000);
}