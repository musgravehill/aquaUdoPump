void INTERFACE_init() {
  pinMode(BUTTON_udo_add, INPUT);
  pinMode(BUTTON_udo_pull, INPUT);
  pinMode(BUZZER_pin, OUTPUT);
}

void BUTTON_check() {
}

void BUZZER_state() {
  if (INTERFACE_BUZZER_isOn) {
    digitalWrite(BUZZER_pin, HIGH);
  } else {
    digitalWrite(BUZZER_pin, LOW);
  }
}
