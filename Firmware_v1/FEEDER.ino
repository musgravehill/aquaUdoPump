
void FEEDER_1DOSE_init() {
  if ( (millis() - FEEDER_time_start_ms) > 61000L ) { //можно запустить 1 раз в течение конкретной минуты
    FEEDER_isFeed = true;
    FEEDER_time_start_ms = millis();
  }
}

void FEEDER_1DOSE_process() {
  if (FEEDER_isFeed) {
    if ( (millis() - FEEDER_time_start_ms) <= FEEDER_1DOSE_ms) { //feed until time not ends
      RELAY_1_set(true);
    } else {
      RELAY_1_set(false);
      FEEDER_isFeed = false;
    }
  }
}
