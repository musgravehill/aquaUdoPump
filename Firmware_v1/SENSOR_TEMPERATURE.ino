void SENSOR_TEMPERATURE_get() {
  if (SENSOR_TEMPERATURE_state) {
    SENSOR_TEMPERATURE.reset();
    SENSOR_TEMPERATURE.write(0xCC);
    SENSOR_TEMPERATURE.write(0x44);
    SENSOR_TEMPERATURE_state = false;
  } else {     ///delay(750+);
    byte data[2];
    SENSOR_TEMPERATURE.reset();
    SENSOR_TEMPERATURE.write(0xCC);
    SENSOR_TEMPERATURE.write(0xBE);
    data[0] = SENSOR_TEMPERATURE.read();
    data[1] = SENSOR_TEMPERATURE.read();
    SENSOR_tC = (data[1] << 8) + data[0];
    SENSOR_tC = SENSOR_tC >> 4;
    SENSOR_TEMPERATURE_state = true;
  }

  SENSOR_TEMPERATURE_alarm();

#ifdef DEBUG
  Serial.println(SENSOR_tC);
#endif
}

void SENSOR_TEMPERATURE_alarm() {
  if (SENSOR_tC < 20 || SENSOR_tC > 29) {
    ALARM__SENSOR_tC_minmax = true;
  }
}
