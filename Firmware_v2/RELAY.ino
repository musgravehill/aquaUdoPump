void RELAY_1_set(bool pos) {
  if (!pos) {
    PORTD |= _BV(PD3); //high
  } else {
    PORTD &= ~_BV(PD3); //low
  }
}

void RELAY_2_set(bool pos) {
  if (!pos) {
    PORTD |= _BV(PD4); //high
  } else {
    PORTD &= ~_BV(PD4); //low
  }
}

void RELAY_init() {
  pinMode(RELAY_1, OUTPUT);
  RELAY_1_set(false);

  pinMode(RELAY_2, OUTPUT);
  RELAY_2_set(false);
}
