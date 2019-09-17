
void RTC_events() {
  RTC_DT = RTC.getDateTime();
  uint16_t RTC_year = RTC_DT.year;
  RTC_hour = RTC_DT.hour;
  RTC_minute = RTC_DT.minute;

  //UDO
  if (RTC_hour == 9 && RTC_minute == 10 ) {
    UDO_1DOSE_init();
  }

  //FEED
  if (RTC_hour == 10 && RTC_minute == 00 ) {
    FEEDER_1DOSE_init();
  }  
  if (RTC_hour == 18 && RTC_minute == 00 ) {
    FEEDER_1DOSE_init();
  }  
 

   
  

  //ALARM (if date is incorrect)
  RTC_alarm(RTC_year);

#ifdef DEBUG
  Serial.print(RTC_hour);
  Serial.print(":");
  Serial.println(RTC_minute);
#endif
}

void RTC_init() {
  RTC.begin();
  //RTC.setDateTime(__DATE__, __TIME__); //ONCE!! COMMENT IT! set sketch compiling time
  delay(10);
}

void RTC_alarm(uint16_t year) {
  if (year == 2000) {
    ALARM__RTC_DATE_incorrect = true;
  } else {
    ALARM__RTC_DATE_incorrect = false;
  }
}
