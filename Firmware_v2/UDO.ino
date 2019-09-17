void UDO_1DOSE_init() {
  if ( (millis() - UDO_time_start_ms) > 61000L ) { //можно запустить 1 раз в течение конкретной минуты
    UDO_isFeed = true;
    UDO_time_start_ms = millis();
  }
}

void UDO_1DOSE_process() {
  if (UDO_isFeed) {
    if ( (millis() - UDO_time_start_ms) <= UDO_1DOSE_ms) { //feed until time not ends
      RELAY_2_set(true);
    } else {
      RELAY_2_set(false);
      UDO_isFeed = false;
    }
  }
}
