
void STEPPER_UDO_PUSHING_1_DOSE() {
  if (STEPPER_UDO_SENSOR_END_min_isAllow()) {
    STEPPER_UDO_tick();
  }
}

void STEPPER_UDO_PULLING() {
  STEPPER_UDO_tick();
}


bool STEPPER_UDO_SENSOR_END_min_isAllow() {
  uint8_t st;
  st = digitalRead(STEPPER_UDO_SENSOR_END_min);
  if (st == LOW) {
    return true;
  } else {
    return false;
  }
}

bool STEPPER_UDO_SENSOR_END_max_isAllow() {
  uint8_t st;
  st =  digitalRead(STEPPER_UDO_SENSOR_END_max);
  if (st == LOW) {
    return true;
  } else {
    return false;
  }
}

void STEPPER_UDO_SENSOR_alarm() {
  if (!STEPPER_UDO_SENSOR_END_min_isAllow()) {
    INTERFACE_BUZZER_isOn = true;
  }
}

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

  pinMode(STEPPER_UDO_SENSOR_END_min, INPUT);

  pinMode(STEPPER_UDO_SENSOR_END_max, INPUT);

  TIMER_STEPPER_UDO_config;
}

