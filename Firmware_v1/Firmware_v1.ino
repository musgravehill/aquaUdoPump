#include <stdlib.h>
//RTC
#include <Wire.h>
#include <DS3231.h>

//#define DEBUG true

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
// 1 ml ~ 5.6 mm cylinder ~ 7 оборотов винта M5*0.8
uint16_t STEPPER_UDO_1DOSE_steps = 7 * 2048L;
uint16_t STEPPER_UDO_1DOSE_steps_made = 0L;

#define STEPPER_UDO_DIR_push true
#define STEPPER_UDO_DIR_pull false

bool STEPPER_UDO_STATE_push = false; //push 1 doze of UDO to aqua
bool STEPPER_UDO_STATE_pull = false; //pull (suck) UDOs doses to cylinders

uint32_t STEPPER_UDO_push_prev_ms = 1L;
//================================== TIMEMACHINE ==================================================
uint32_t TIMEMACHINE_prev_211ms = 1L;
uint32_t TIMEMACHINE_prev_1103ms = 1L;
uint32_t TIMEMACHINE_prev_3571ms = 1L;

//================================== INTERFACE ====================================================
bool INTERFACE_BUZZER_isOn = false;

//==================================== RTC ========================================================
DS3231 RTC;
RTCDateTime RTC_DT;

void setup() {
  TIMER_STEPPER_UDO_config(); //timer ICR before all, first!
  RTC_init();
  STEPPER_UDO_init();
  INTERFACE_init();
  RELAY_init();
#ifdef DEBUG
  Serial.begin(9600);
#endif
  delay(10);
}

void loop() {
  TIMEMACHINE_loop();
}
