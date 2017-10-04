void INTERFACE_init() {
  pinMode(BUTTON_udo_push, INPUT);
  pinMode(BUTTON_udo_pull, INPUT);
  pinMode(BUZZER_pin, OUTPUT);
}

void BUTTON_check() {
  uint8_t btnState;
  //udo push
  btnState = digitalRead(BUTTON_udo_push);
  if (btnState == LOW) {
    STEPPER_UDO_PUSH_init();
  }
  //udo pull
  btnState = digitalRead(BUTTON_udo_pull);
  if (btnState == LOW) {
    STEPPER_UDO_PULL_init();
  } else {
    STEPPER_UDO_PULL_END();
  }
}

void BUZZER_state() {
  if (INTERFACE_BUZZER_isOn) {
    digitalWrite(BUZZER_pin, HIGH);
  } else {
    digitalWrite(BUZZER_pin, LOW);
  }
}
