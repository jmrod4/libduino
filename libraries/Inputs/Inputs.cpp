/*

Inputs - class for dealing with inputs from the world to the Arduino pins

Copyright 2013 Juanma Rodriguez. 

This file is part of the [libduino project](github.com/jmrod4/libduino) 
You can redistribute and/or modify this software under the terms of 
GNU GPL v3 license.

Changelog
---------
2013-06: started coding :)

*/

/*
WARNING: Due to a pitfall in the Arduino IDE, a library cannot include another one
so you must add the following lines to your sketch:

#include <Arduino.h>
#include <DelayedWrite.h>
#include <NiceDelay.h>
#include <Inputs.h>
*/

#include <Arduino.h>
#include <NiceDelay.h>
#include <Inputs.h>

extern NiceDelay nice;



DigitalInput::DigitalInput(byte pin_number)
{
  _pin = pin_number;
  _debounce_msec = 0;    // no debounce by default
  _changed = false;
  _last_read_value = read_raw();
  pinMode(_pin, INPUT);
}


int DigitalInput::read_raw(void)
{
  return digitalRead(_pin);
}


int DigitalInput::read(void)
{
  int result = digitalRead(_pin);
  if ( result != _last_read_value )
  {
    _last_read_value = result;
    _changed = true;
    if ( _debounce_msec > 0)
      nice.delay(_debounce_msec);
  }
  return result;
}


void DigitalInput::set_debounce(unsigned millisec)
{
  _debounce_msec = millisec;
}


boolean DigitalInput::is_on(void)
{
  return read();
}


boolean DigitalInput::is_off(void)
{
  return !read();
}


boolean DigitalInput::has_changed(void)
{
  return _changed;
}


boolean DigitalInput::reset_change(void)
{
  boolean old_state = _changed;
  _changed = false;
  return old_state;
}


AnalogInput::AnalogInput(byte pin_number) : DigitalInput(pin_number)
{
  set_average_samples(4, 200); // defaults: 4 samples, each 200 microsec
                               // = 4*100 + 3*200 = 1000 microsec = 1 millisec
  //set_range(0, 1023);        // defaults: value from 0 to 1023 
}


int AnalogInput::read_raw(void)
{
  return analogRead(_pin);
}


int AnalogInput::read(void)
{
  int average = analogRead(_pin);
  for (int i = 1; i < _average_samples_number; i++)
  {
    delayMicroseconds(_average_samples_microsec);
    average = (average + analogRead(_pin)) / 2;
  }
  return average;
}


// void AnalogInput::set_range(int min_value, int max_value)
// {
  // _range_min_value = min_value;
  // _range_max_value = max_value;
// }


void AnalogInput::set_average_samples(
    unsigned samples_number, 
    unsigned microsec_between_samples) // additional to the 100 microsec reading
{
    _average_samples_number = samples_number;
    _average_samples_microsec = microsec_between_samples;
}


boolean AnalogInput::peak_detected(void)
{
  // FIXME
}
