void TIMEMACHINE_loop() {
  uint32_t  TIMEMACHINE_currMillis = millis();
  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prev_211ms) > 211L) {
    TIMEMACHINE_211ms();
    TIMEMACHINE_prev_211ms = TIMEMACHINE_currMillis;
  }
}

void TIMEMACHINE_211ms() {
  BUTTON_check();
  //BUZZER_state();
  //STEPPER_UDO_SENSOR_alarm();
  //RTC_alarm();
}
