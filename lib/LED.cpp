/*

LED - simple class for dealing with LEDs in the Arduino

Copyright 2013 Juanma Rodriguez.

You can redistribute and/or modify this software under the terms of
GNU GPL v3 (or above) license.

Changelog
---------
0.0 - still in development

*/


#include "Arduino.h"

#include "LED.h"


/***** class: LED *****************************************************
*/


LED::LED(uint8_t pin_led) {
  _pin = pin_led;
  _pwm = 255;
  blinking = false;
  blink_msec_on = DEFAULT_BLINK_MSEC_ON;
  blink_msec_off = DEFAULT_BLINK_MSEC_ON;
  pinMode(_pin, OUTPUT);
}


void LED::off(void) {
  digitalWrite(_pin, LOW);
}


void LED::on(void) {
  if ( _pwm == 255 )
    digitalWrite(_pin, HIGH);
  else
    analogWrite(_pin, _pwm);
}


void LED::dim(uint8_t pwm) {
  _pwm = pwm;
  on();
}


void LED::blink(void) {
  on();
  delay(blink_msec_on);
  off();
  delay(blink_msec_off);
}

