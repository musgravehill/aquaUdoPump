
/*
  ======TODO

*/

//=============================== CONFIG =============================================
#define UDO_1DOSE_ml  2.0 // 1.0 ml
#define FEEDER_1DOSE_ms  3000 //3000ms = 3s 
#define SENSOR_tC_min_alarm  20 //celcius degree
#define SENSOR_tC_max_alarm  28 //celcius degree

//#define DEBUG true

//=============================== include libs =======================================

//may be Timer1 ?
#include <stdlib.h>

//RTC
#include <Wire.h>
#include <DS3231.h>

//DS18B20  temperature
#include <OneWire.h>
OneWire SENSOR_TEMPERATURE(2);

//OLED SDA A4, SCL A5
#include <OLED_I2C.h>
OLED  myOLED(SDA, SCL);
extern uint8_t SmallFont[];

//=======================INIT IN-OUT======================================================
#define STEPPER_UDO_DRIVER_notEN 12 //PB4
#define STEPPER_UDO_DRIVER_STEP 10 //PB2
#define STEPPER_UDO_DRIVER_DIR 11 //PB3
#define STEPPER_UDO_SENSOR_END_min 8 //PB0
#define STEPPER_UDO_SENSOR_END_max 9 //PB1

#define BUZZER_pin 5 //PD5
#define BUTTON_udo_push 6 //PD6
#define BUTTON_udo_pull 7 //PD7

#define RELAY_1 3 //PD3
#define RELAY_2 4 //PD4
//================================= STEPPER_UDO =================================================
// 1 ml => 5.6 mm cylinder => 7 оборотов винта M5*0.8 => 7 * (2048 steps on 1 turn)
uint16_t STEPPER_UDO_1DOSE_steps = 7.0 * 2048.0 * UDO_1DOSE_ml;
uint16_t STEPPER_UDO_1DOSE_steps_made = 0L;

#define STEPPER_UDO_DIR_push true
#define STEPPER_UDO_DIR_pull false

bool STEPPER_UDO_STATE_push = false; //push 1 doze of UDO to aqua
bool STEPPER_UDO_STATE_pull = false; //pull (suck) UDOs doses to cylinders

uint32_t STEPPER_UDO_push_prev_ms = 0L;
//================================== TIMEMACHINE ==================================================
uint32_t TIMEMACHINE_prev_211ms = 0L;
uint32_t TIMEMACHINE_prev_1103ms = 0L;
uint32_t TIMEMACHINE_prev_3571ms = 0L;

//================================== INTERFACE ====================================================
bool INTERFACE_BUZZER_isOn = false;

//==================================== RTC ========================================================
DS3231 RTC;
RTCDateTime RTC_DT;
uint8_t RTC_hour = 1;
uint8_t RTC_minute = 1;

//===================================== SENSOR_TEMPERATURE ========================================
int SENSOR_tC = 10;
bool SENSOR_TEMPERATURE_state = false;

//===================================== ALARM =====================================================
bool ALARM__STEPPER_UDO_SENSOR_END_minmax = false;
bool ALARM__RTC_DATE_incorrect = false;
bool ALARM__SENSOR_tC_minmax = false;

//===================================== FEEDER ====================================================
uint32_t FEEDER_time_start_ms = 0L;
bool FEEDER_isFeed = false;

void setup() {
  TIMER_STEPPER_UDO_config(); //timer ICR before all, first!
  RTC_init();
  STEPPER_UDO_init();
  INTERFACE_init();
  RELAY_init();
  OLED_init();
#ifdef DEBUG
  Serial.begin(9600);
#endif
  delay(10);
}

void loop() {
  TIMEMACHINE_loop();
}
