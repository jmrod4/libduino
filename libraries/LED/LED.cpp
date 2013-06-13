/*

LED - simple class for dealing with LEDs in the Arduino

Copyright 2013 Juanma Rodriguez. 

This file is part of the [libduino project](github.com/jmrod4/libduino) 
You can redistribute and/or modify this software under the terms of 
GNU GPL v3 license.

Changelog
---------
2013-06: initial usable version

*/

/*
WARNING: Due to a pitfall in the Arduino IDE, a library cannot include another one
so you must add the following lines to your sketch:

#include <Arduino.h>
#include <DelayedWrite.h>
#include <NiceDelay.h>
#include <LED.h>
*/


#include <Arduino.h>
#include <NiceDelay.h>  
#include <LED.h>




/***** class: LED *****************************************************
*/


LED::LED(byte pin_number) {
  _pin_number = pin_number;
  _pwm_intensity = 255;
  //blinking = false;  // future implentation
  blink_msec_on = DEFAULT_BLINK_MSEC_ON;
  blink_msec_off = DEFAULT_BLINK_MSEC_OFF;
  pinMode(_pin_number, OUTPUT);
}

// accessors
byte LED::pin_number(void)  
{ 
  return _pin_number; 
}


void LED::off(void) 
{ 
  digitalWrite(_pin_number, LOW); 
}


void LED::on(void) {
  if ( _pwm_intensity == 255 )
    digitalWrite(_pin_number, HIGH);
  else
    analogWrite(_pin_number, _pwm_intensity);
}


void LED::dim(byte pwm_intensity) {
  _pwm_intensity = pwm_intensity; // change the previous intensity and
  on(); // lits the LED at the desired intensity immediatly !
}


void LED::simple_blink(void) {
  on();
  delay(blink_msec_on);
  off();
  delay(blink_msec_off);
}

