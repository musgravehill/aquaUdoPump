void TIMEMACHINE_loop() {
  uint32_t  TIMEMACHINE_currMillis = millis();

  if ((TIMEMACHINE_currMillis - TIMEMACHINE_prev_503ms) > 503L) {
    TIMEMACHINE_503ms();
    TIMEMACHINE_prev_503ms = TIMEMACHINE_currMillis;
  }
}

void TIMEMACHINE_503ms() {
  BUTTON_check(); 
  BUZZER_state();
}
