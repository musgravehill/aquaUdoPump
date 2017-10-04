void INTERFACE_init() {
  pinMode(BUTTON_udo_add, INPUT);
  pinMode(BUTTON_udo_pull, INPUT);
  pinMode(BUZZER_pin, OUTPUT);
}

void BUTTON_check() {
  uint8_t btnState;
  //udo pull
  btnState = digitalRead(BUTTON_udo_pull);
  if (btnState == LOW && STEPPER_UDO_SENSOR_END_max_isAllow()) {
    STEPPER_UDO_dir(STEPPER_UDO_DIR_pull);
    STEPPER_UDO_STATE_pull = true;
  } else {
    STEPPER_UDO_STATE_pull = false;
  }
}

void BUZZER_state() {
  if (INTERFACE_BUZZER_isOn) {
    digitalWrite(BUZZER_pin, HIGH);
  } else {
    digitalWrite(BUZZER_pin, LOW);
  }
}
