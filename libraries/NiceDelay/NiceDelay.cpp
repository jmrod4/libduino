/*

NiceDelay - lets you program delayed and repetitive tasks on the Arduino
            currently implementing: write

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
*/

#include <Arduino.h>
#include <DelayedWrite.h>
#include <NiceDelay.h>


int NiceDelay::_get_free(void)
// returns -1 if unable to find a free slot
{
  for (int i = 0; i < MAX_DELAYED_WRITES; i++)
    if (_delayed_writes[i].pin_number() == 0)
      return i;
  return -1;
}


void NiceDelay::remove(byte pin)
{
  for (int i = 0; i < MAX_DELAYED_WRITES; i++)
    if (_delayed_writes[i].pin_number() == pin)
      _delayed_writes[i].clear();
}


void NiceDelay::delay(unsigned long millisec)
{
  while (millisec > NICE_DELAY_GRANULARITY_MILLISEC)
  {
    this->delay(NICE_DELAY_GRANULARITY_MILLISEC);
    millisec -= NICE_DELAY_GRANULARITY_MILLISEC;
  }  

  unsigned long current_time = millis();

  for (int i = 0; i < MAX_DELAYED_WRITES; i++)
    _delayed_writes[i].written(current_time);
  millisec -= millis() - current_time;
  if (millisec > 0)
    delayMicroseconds(millisec*1000U);
  else
    delayMicroseconds(1000U);
}


void NiceDelay::addWrite
(
  unsigned long current_time,
  byte          pin_number, 
  byte          value_to_write, 
  unsigned long initial_delay, 
  unsigned long each_millisec,
  unsigned int  times_to_write
)
{
  int i = _get_free();
  // WARNING: if i==-1 no free spaces, and does nothing
  if ( i < 0 ) 
    return;

  _delayed_writes[i].set(current_time, pin_number, value_to_write,
                        initial_delay, each_millisec, times_to_write);
}

