#include <AFMotor.h>


AF_Stepper motor(48, 2);


void setup() {
  motor.setSpeed(250);  // ** rpm    
}

void loop() {
  motor.step(100, FORWARD, DOUBLE); 
}
