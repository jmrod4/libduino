/*

LED - simple class for dealing with LEDs in the Arduino

Copyright 2013 Juanma Rodriguez.

You can redistribute and/or modify this software under the terms of
GNU GPL v3 (or above) license.

Changelog
---------
2013-06-02 - initial usable version

*/


#include "Arduino.h"

#include "LED.h"


/***** class: LED *****************************************************
*/


LED::LED(uint8_t pin_number) {
  _pin_number = pin_number;
  _pwm_intensity = 255;
  //blinking = false;  // future implentation
  blink_msec_on = DEFAULT_BLINK_MSEC_ON;
  blink_msec_off = DEFAULT_BLINK_MSEC_OFF;
  pinMode(_pin_number, OUTPUT);
}

// accessors
void LED::pin_number(void)  { return _pin_number; }


void LED::off(void) {
  digitalWrite(_pin_number, LOW);
}


void LED::on(void) {
  if ( _pwm_intensity == 255 )
    digitalWrite(_pin_number, HIGH);
  else
    analogWrite(_pin_number, _pwm_intensity);
}


void LED::dim(uint8_t pwm_intensity) {
  _pwm_intensity = pwm_intensity;
  on();
}


void LED::simpleBlink(void) {
  on();
  delay(blink_msec_on);
  off();
  delay(blink_msec_off);
}

