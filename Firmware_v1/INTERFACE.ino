void INTERFACE_init() {
  pinMode(BUTTON_udo_push, INPUT);
  pinMode(BUTTON_udo_pull, INPUT);
  pinMode(BUZZER_pin, OUTPUT);
  delay(10);
  digitalWrite(BUZZER_pin, HIGH);
  delay(20);
  digitalWrite(BUZZER_pin, LOW);
}

void BUTTON_check() {
  int8_t btnState1, btnState2;

  btnState1 = digitalRead(BUTTON_udo_push);
  btnState2 = digitalRead(BUTTON_udo_pull);

  //feed
  if (btnState1 == LOW && btnState2 == LOW) { //press it
    FEEDER_1DOSE_init();
  }

  //udo push
  if (btnState1 == LOW) { //press it
    STEPPER_UDO_PUSH_handmade();
  }
  //udo pull
  if (btnState2 == LOW) { //press it
    STEPPER_UDO_PULL_init();
  }
}

void BUZZER_isOn(bool isOn) {
  if (isOn) {
    digitalWrite(BUZZER_pin, HIGH);
  } else {
    digitalWrite(BUZZER_pin, LOW);
  }
}
