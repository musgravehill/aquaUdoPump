#define STEPPER_UDO_DRIVER_notEN 12 //PB4
#define STEPPER_UDO_DRIVER_STEP 10 //PB2
#define STEPPER_UDO_DRIVER_DIR 11 //PB3

void setup() {
 pinMode(STEPPER_UDO_DRIVER_STEP, OUTPUT);
  digitalWrite(STEPPER_UDO_DRIVER_STEP, LOW); //no step

  pinMode(STEPPER_UDO_DRIVER_DIR, OUTPUT);
   

  pinMode(STEPPER_UDO_DRIVER_notEN, OUTPUT);
  digitalWrite(STEPPER_UDO_DRIVER_notEN, LOW);  

}

void loop() {
  digitalWrite(STEPPER_UDO_DRIVER_STEP, HIGH); //no step
  delay(1);
  digitalWrite(STEPPER_UDO_DRIVER_STEP, LOW); //no step
  delay(1);

}
