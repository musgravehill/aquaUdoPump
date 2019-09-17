void TIMEMACHINE_loop() {
  uint32_t  TIMEMACHINE_currMillis = millis();
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prev_211ms) > 211L) {
    TIMEMACHINE_211ms();
    TIMEMACHINE_prev_211ms = TIMEMACHINE_currMillis;
  }
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prev_1103ms) > 1103L) {
    TIMEMACHINE_1103ms();
    TIMEMACHINE_prev_1103ms = TIMEMACHINE_currMillis;
  }
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prev_3571ms) > 3571L) {
    TIMEMACHINE_3571ms();
    TIMEMACHINE_prev_3571ms = TIMEMACHINE_currMillis;
  }
}

void TIMEMACHINE_211ms() {
  BUTTON_check();
  FEEDER_1DOSE_process();
  UDO_1DOSE_process();
}

void TIMEMACHINE_1103ms() {
  ALARM_process();
}

void TIMEMACHINE_3571ms() {
  RTC_events();
  SENSOR_TEMPERATURE_get();
  OLED_process();
}

