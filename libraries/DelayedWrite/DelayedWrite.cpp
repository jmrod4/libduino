/*

DelayedWrite - lets you set parameters for a cyclic write operation and 
               perform it when it's due
 
Copyright 2013 Juanma Rodriguez. 

This file is part of the [libduino project](github.com/jmrod4/libduino) 
You can redistribute and/or modify this software under the terms of 
GNU GPL v3 license.

Changelog
---------
2013-06: started coding :)

*/

#include <Arduino.h>

#include <DelayedWrite.h>


DelayedWrite::DelayedWrite(void)  
  { clear(); }


// leaves the pin in LOW state and then deactivates itself
void DelayedWrite::clear(void)    
{ 
  digitalWrite(pin, LOW);
  pin = 0; 
}


byte DelayedWrite::pin_number(void)
  { return pin; }


void DelayedWrite::write(void)
// this function just writes the value inmediately
{
  if ( pin == 0 ) 
    return;

  // FIXME: if you are using a continuous PWM and try to write 1 you will 
  // get an unexpected result as the output will be like 255 was written
  if ( value == HIGH || value == LOW )
    digitalWrite(pin, value); // digital
  else
    analogWrite(pin, value);  // PWM
}


boolean DelayedWrite::written(unsigned long current_time)
// WARNING: no delayed write is done unless written is called!!
// it returns if the value was actually written
{
  if ( pin == 0 ) 
    return false;

  // if time to write
  if ( current_time > last_execution + each )
  {
    write();
    last_execution += each;
    // if no more repetitions needed or this was the last repetition then clear it
    if ( each == 0 || times == 1)
    {
      clear();
    }
    // if some repetitions left then update the times left counter
    else if ( times > 0 ) 
    {
      times -= 1; 
    }
    return true; // the value was written
  } 
  return false; // the vaule wasn't written
}


void DelayedWrite::set(unsigned long current_time,
                       byte          pin_number, 
                       byte          value_to_write, 
                       unsigned long initial_delay, 
                       unsigned long each_millisec,
                       unsigned      times_to_write)
{
  pin   = pin_number;
  value = value_to_write;
  each  = each_millisec;
  times = times_to_write;

  pinMode(pin, OUTPUT); // set correct mode !!
  last_execution = current_time + initial_delay - each;
}



