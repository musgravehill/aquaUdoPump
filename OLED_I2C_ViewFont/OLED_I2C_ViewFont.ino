// OLED_I2C_ViewFont
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// A quick demo of how to use my OLED_I2C library.
//
// To use the hardware I2C (TWI) interface of the Arduino you must connect
// the pins as follows:
//
// Arduino Uno/2009:
// ----------------------
// Display:  SDA pin   -> Arduino Analog 4 or the dedicated SDA pin
//           SCL pin   -> Arduino Analog 5 or the dedicated SCL pin
//
// Arduino Leonardo:
// ----------------------
// Display:  SDA pin   -> Arduino Digital 2 or the dedicated SDA pin
//           SCL pin   -> Arduino Digital 3 or the dedicated SCL pin
//
// Arduino Mega:
// ----------------------
// Display:  SDA pin   -> Arduino Digital 20 (SDA) or the dedicated SDA pin
//           SCL pin   -> Arduino Digital 21 (SCL) or the dedicated SCL pin
//
// Arduino Due:
// ----------------------
// Display:  SDA pin   -> Arduino Digital 20 (SDA) or the dedicated SDA1 (Digital 70) pin
//           SCL pin   -> Arduino Digital 21 (SCL) or the dedicated SCL1 (Digital 71) pin
//
// The internal pull-up resistors will be activated when using the 
// hardware I2C interfaces.
//
// You can connect the OLED display to any available pin but if you use 
// any other than what is described above the library will fall back to
// a software-based, TWI-like protocol which will require exclusive access 
// to the pins used, and you will also have to use appropriate, external
// pull-up resistors on the data and clock signals.
//

#include <OLED_I2C.h>

OLED  myOLED(SDA, SCL);

extern uint8_t SmallFont[]; //6*8
extern uint8_t MediumNumbers[]; //12*16
extern uint8_t BigNumbers[]; //14*24

void setup()
{
  myOLED.begin();
  myOLED.setFont(SmallFont);
  myOLED.setBrightness(4);
}

void loop()
{
  myOLED.clrScr();
  
  //time
  myOLED.setFont(SmallFont);
  myOLED.print(":", 28, 10);
  myOLED.setFont(BigNumbers);
  myOLED.printNumI(12, 0, 0);  
  myOLED.printNumI(55, 34, 0);  

  //tC
  myOLED.setFont(MediumNumbers);
  myOLED.printNumF(25.7888, 1, 74, 4);
  myOLED.setFont(SmallFont);
  myOLED.print("o", 122, 0);

  //error 
  myOLED.setFont(SmallFont); 
  myOLED.print("!!! ALARM tC DT UDO", 0, 28);   

  //uptime
  myOLED.setFont(SmallFont); 
  myOLED.print("UPTIME DAYS", 0, 40);  
  myOLED.printNumI(millis()/86400000, 62, 40);
 
  myOLED.update();
  delay (5000);   
 
}


