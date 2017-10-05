void INTERFACE_init() {
  pinMode(BUTTON_udo_push, INPUT);
  pinMode(BUTTON_udo_pull, INPUT);
  pinMode(BUZZER_pin, OUTPUT);
  delay(10);
  INTERFACE_BUZZER_isOn = true;
  delay(10);
  INTERFACE_BUZZER_isOn = false;
}

void BUTTON_check() {
  int8_t btnState;
  //udo push
  btnState = digitalRead(BUTTON_udo_push);
  if (btnState == LOW) { //press it
    STEPPER_UDO_PUSH_handmade();
  }
  //udo pull
  btnState = digitalRead(BUTTON_udo_pull);
  if (btnState == LOW) { //press it
    STEPPER_UDO_PULL_init();
  } 
}

void BUZZER_state() {
  if (INTERFACE_BUZZER_isOn) {
    digitalWrite(BUZZER_pin, HIGH);
  } else {
    digitalWrite(BUZZER_pin, LOW);
  }
}
