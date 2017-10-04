void STEPPER_UDO_PUSH_handmade() {
  STEPPER_UDO_en(true);
  STEPPER_UDO_dir(STEPPER_UDO_DIR_push);  
  for (int i=0; i <= 255; i++){
      STEPPER_UDO_tick();
      delay(1);
   } 
}


void STEPPER_UDO_PUSH_init() {
  if ( (millis() - STEPPER_UDO_push_prev_ms) > 333000 ) { //333s прошло от предыдущей подачи удо
    if (!STEPPER_UDO_STATE_push) {
      STEPPER_UDO_PULL_END();
      STEPPER_UDO_1DOSE_steps_made = 0L;
      STEPPER_UDO_en(true);
      STEPPER_UDO_dir(STEPPER_UDO_DIR_push);
      STEPPER_UDO_push_prev_ms = millis();
    }
    STEPPER_UDO_STATE_push = true;
  }
}
void STEPPER_UDO_PUSHING_1DOSE() {
  if ( (STEPPER_UDO_1DOSE_steps_made < STEPPER_UDO_1DOSE_steps) && STEPPER_UDO_SENSOR_END_min_isAllow()) {
    STEPPER_UDO_tick();
    STEPPER_UDO_1DOSE_steps_made++;
  } else {
    STEPPER_UDO_PUSH_END();
  }
}
void STEPPER_UDO_PUSH_END() {
  if (STEPPER_UDO_STATE_push) {
    STEPPER_UDO_en(false);
  }
  STEPPER_UDO_STATE_push = false;
}

void STEPPER_UDO_PULL_init() {
  if (!STEPPER_UDO_STATE_pull) {
    STEPPER_UDO_PUSH_END();
    STEPPER_UDO_en(true);
    STEPPER_UDO_dir(STEPPER_UDO_DIR_pull);
  }
  STEPPER_UDO_STATE_pull = true;
}
void STEPPER_UDO_PULLING() {
  if (STEPPER_UDO_SENSOR_END_max_isAllow()) {
    STEPPER_UDO_tick();
  }
}
void STEPPER_UDO_PULL_END() {
  if (STEPPER_UDO_STATE_pull) {
    STEPPER_UDO_en(false);
  }
  STEPPER_UDO_STATE_pull = false;
}

bool STEPPER_UDO_SENSOR_END_min_isAllow() {
  uint8_t st;
  st = digitalRead(STEPPER_UDO_SENSOR_END_min);
  if (st == HIGH) {
    return true;
  } else {
    return false;
  }
}

bool STEPPER_UDO_SENSOR_END_max_isAllow() {
  uint8_t st;
  st =  digitalRead(STEPPER_UDO_SENSOR_END_max);
  if (st == HIGH) {
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
    //digitalWrite(BUZZER_pin, HIGH);
  } else {
    PORTB |= _BV(PB4); //high
    //digitalWrite(BUZZER_pin, LOW);
  }
  delay(500); //in ms
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

  delay(10);
}

