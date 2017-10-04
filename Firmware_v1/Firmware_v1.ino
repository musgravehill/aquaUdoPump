#include <stdlib.h>

//=======================INIT IN-OUT======================================================
#define STEPPER_UDO_DRIVER_notEN 12 //PB4
#define STEPPER_UDO_DRIVER_STEP 10 //PB2
#define STEPPER_UDO_DRIVER_DIR 11 //PB3
#define BUZZER_pin 5 //PD5
#define BUTTON_udo_push 6 //PD6
#define BUTTON_udo_pull 7 //PD7
#define STEPPER_UDO_SENSOR_END_min 8 //PB0
#define STEPPER_UDO_SENSOR_END_max 9 //PB1

//================================= STEPPER_UDO =================================================
// 1 ml ~ 5.6 mm cylinder ~ 7 оборотов винта M5*0.8
uint16_t STEPPER_UDO_1DOSE_steps = 1000L;
uint16_t STEPPER_UDO_1DOSE_steps_made = 0L;

#define STEPPER_UDO_DIR_push true
#define STEPPER_UDO_DIR_pull false

bool STEPPER_UDO_STATE_push = false; //push 1 doze of UDO to aqua
bool STEPPER_UDO_STATE_pull = false; //pull (suck) UDOs doses to cylinders

//================================== TIMEMACHINE ==================================================
uint32_t TIMEMACHINE_prev_211ms = 1L;

//================================== INTERFACE ====================================================
bool INTERFACE_BUZZER_isOn = false;


void setup() {
  TIMER_STEPPER_UDO_config();
  STEPPER_UDO_init();
  INTERFACE_init();
  delay(10);
  Serial.begin(9600);
  delay(10);
}

void loop() {
  TIMEMACHINE_loop();
}
