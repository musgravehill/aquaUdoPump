// now.pde
// Prints a snapshot of the current date and time along with the UNIX time
// Modified by Andy Wickert from the JeeLabs / Ladyada RTC library examples
// 5/15/11

#include <Wire.h>
#include "DS3231.h"

RTClib RTC;

const int btn1 = 6;
const int btn2 = 7;
const int buzz = 5;
int buttonState = 0; 

const int relay1 = 3;
const int relay2 = 4;

void setup () {
  Serial.begin(57600);
  Wire.begin();

  pinMode(buzz, OUTPUT);

  pinMode(btn1,INPUT);
  pinMode(btn2, INPUT);

   pinMode(relay1,OUTPUT);
    pinMode(relay2,OUTPUT);
}

void loop () {

  buttonState = digitalRead(btn1);   
  if (buttonState == LOW) {     
    digitalWrite(buzz, HIGH);
    digitalWrite(relay1, LOW);
  } else {     
    digitalWrite(buzz, LOW);
    digitalWrite(relay1, HIGH);
  }

  buttonState = digitalRead(btn2);   
  if (buttonState == LOW) {     
    digitalWrite(buzz, HIGH);
    digitalWrite(relay2, LOW);
  } else {     
    digitalWrite(buzz, LOW);
    digitalWrite(relay2, HIGH);
  }

  

  delay(1000);

  DateTime now = RTC.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();

  Serial.print(" since midnight 1/1/1970 = ");
  Serial.print(now.unixtime());
  Serial.print("s = ");
  Serial.print(now.unixtime() / 86400L);
  Serial.println("d");
}

