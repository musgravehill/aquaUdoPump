
void RTC_events() {
  RTC_DT = RTC.getDateTime();
  uint8_t hour = RTC_DT.hour;
  uint8_t minute = RTC_DT.minute;

  //STEPPER_UDO
  if (hour == 18 && minute == 30 ) {
    STEPPER_UDO_PUSH_init();
  }

  //relay
  if (minute % 2 == 1) {
    //RELAY_1_set(true);
    //RELAY_2_set(false);
  } else {
    //RELAY_1_set(false);
    //RELAY_2_set(true);
  }

#ifdef DEBUG
  Serial.print(hour);
  Serial.print(":");
  Serial.println(minute);
#endif

}

void RTC_init() {
  RTC.begin();
  //RTC.setDateTime(__DATE__, __TIME__); //ONCE!! COMMENT IT! set sketch compiling time
  delay(10);
}

void RTC_alarm() {
  /*if (ttime==2000) {
    INTERFACE_BUZZER_isOn = true;
    }*/
}
