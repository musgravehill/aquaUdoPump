/*
  ATmega168, ATmega328:
  Using Timer 1 disables PWM (analogWrite) on pins 9 and 10

  ATmega2560:
  Using Timer 1 disables PWM (analogWrite) on pins 11 and 12
  Using Timer 3 disables PWM (analogWrite) on pins 2, 3 and 5
  Using Timer 4 disables PWM (analogWrite) on pins 6, 7 and 8
  Using Timer 5 disables PWM (analogWrite) on pins 44, 45 and 46
*/

void TIMER_STEPPER_UDO_config() {
  /////  starSpeed_us_for_microtick  18698.8043687066 us = 53.479355165272 Hz
  //OCR1A =  [ 16,000,000Hz/ (prescaler * desired interrupt frequency) ] - 1
  //OCR1A = 16000000/(256*53.479355165272)    -1 = 1167.675273044163
  //f = 16000000(256*(1168+1)) = 53.464499572284 Hz by Timer1

  cli(); //запретить все прерывания

  //------ Timer1 ----------
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0

  OCR1A = 1000;    //Верхняя граница счета. Диапазон от 0 до 65535.

  TCCR1B |= (1 << WGM12);  // Режим CTC (сброс по совпадению)

  TCCR1B |= (1 << CS12);         // CLK/256
  // Если нужен предделитель :
  // TCCR1B |= (1 << CS10);         // Тактирование от CLK/1
  // TCCR1B |= (1<<CS11);           // CLK/8
  // TCCR1B |= (1<<CS10)|(1<<CS11); // CLK/64
  // TCCR1B |= (1<<CS12);           // CLK/256
  // TCCR1B |= (1<<CS10)|(1<<CS12); // CLK/1024

  TIMSK1 |= (1 << OCIE1A); // Разрешить прерывание по совпадению

  sei (); // Разрешить прерывания
}

// Обработчик прерывания таймера 1
ISR (TIMER1_COMPA_vect) {
  if (STEPPER_UDO_STATE_push) {
    STEPPER_UDO_PUSHING_1DOSE();
  }
  if (STEPPER_UDO_STATE_pull) {
    STEPPER_UDO_PULLING();
  }  
}


