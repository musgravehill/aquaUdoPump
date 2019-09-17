void OLED_init() {
  myOLED.begin();
  myOLED.setBrightness(1);
}

void OLED_process() {
  if (OLED_isOn) {
    OLED_display();
    uint32_t  currMillis = millis();
    if ((currMillis - OLED_time_start_ms) > 31000) { //31s
      OLED_isOn = false;
      myOLED.clrScr();
      myOLED.update();
    }
  }
}

void OLED_display() {
  myOLED.clrScr();
  //time
  myOLED.setFont(SmallFont);
  myOLED.print(":", 28, 10);
  myOLED.setFont(BigNumbers);
  myOLED.printNumI(RTC_hour, 0, 0);
  myOLED.printNumI(RTC_minute, 34, 0);
  //tC
  myOLED.setFont(MediumNumbers);
  myOLED.printNumF(SENSOR_tC, 1, 74, 4);
  myOLED.setFont(SmallFont);
  myOLED.print("o", 122, 0);

  //error
  myOLED.setFont(SmallFont);
  myOLED.print("ALARM", 0, 28);
  if (ALARM__RTC_DATE_incorrect) {
    myOLED.print("DT", 54, 28);
  }
  if (ALARM__SENSOR_tC_minmax) {
    myOLED.print("tC", 36, 28);
  }

  //uptime
  myOLED.setFont(SmallFont);
  myOLED.print("UPTIME DAYS", 0, 40);
  myOLED.printNumI(millis() / 86400000, 72, 40);

  myOLED.update();
}
