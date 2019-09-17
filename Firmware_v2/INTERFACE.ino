void INTERFACE_init() {
  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUZZER_pin, OUTPUT);
  delay(10);
}

void BUTTON_check() {
  int8_t btnState1, btnState2;
  btnState1 = digitalRead(BUTTON_1);
  btnState2 = digitalRead(BUTTON_2);

  //oled
  if (btnState1 == LOW || btnState2 == LOW) { //press it
    OLED_time_start_ms = millis();
    OLED_isOn = true;
  }
  if (btnState1 == LOW) { //press it
    FEEDER_1DOSE_init();
  }
  else if (btnState2 == LOW) { //press it
    UDO_1DOSE_init();
  }
}

void BUZZER_isOn(bool isOn) {
  if (isOn) {
    uint32_t  currMillis = millis();   
    if ((currMillis - INTERFACE_BUZZER_on_start) > 300000L) {
      digitalWrite(BUZZER_pin, HIGH);
      INTERFACE_BUZZER_on_start = currMillis;
    } else {
      digitalWrite(BUZZER_pin, LOW);
    }

  } else {
    digitalWrite(BUZZER_pin, LOW);
  }
}
