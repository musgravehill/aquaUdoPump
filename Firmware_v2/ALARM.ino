void ALARM_process() {
  if (ALARM__RTC_DATE_incorrect || ALARM__SENSOR_tC_minmax) {
    BUZZER_isOn(true);
  } else {
    BUZZER_isOn(false);
  }
}
