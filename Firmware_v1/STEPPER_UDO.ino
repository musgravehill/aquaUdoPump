void STEPPER_UDO_tick() {
  PORTB |= _BV(PB2); //high
  delayMicroseconds(8); //DRV8825 needs 1.9 us
  PORTB &= ~_BV(PB2); //low
}

void STEPPER_UDO_dir(bool dir_forward) {
  if (dir_forward) {
    PORTB |= _BV(PB3); //high
  } else {
    PORTB &= ~_BV(PB3); //low
  }
}

void STEPPER_UDO_en(bool is_en) {
  if (is_en) {
    PORTB &= ~_BV(PB4); //low
  } else {
    PORTB |= _BV(PB4); //high
  }
  delay(1000); //in ms
}

void STEPPER_UDO_init() {
  pinMode(STEPPER_UDO_DRIVER_STEP, OUTPUT);
  digitalWrite(STEPPER_UDO_DRIVER_STEP, LOW); //no step

  pinMode(STEPPER_UDO_DRIVER_DIR, OUTPUT);
  STEPPER_UDO_dir(STEPPER_UDO_DIR_push);

  pinMode(STEPPER_UDO_DRIVER_notEN, OUTPUT);
  STEPPER_UDO_en(false);

  TIMER_STEPPER_UDO_config;
}

