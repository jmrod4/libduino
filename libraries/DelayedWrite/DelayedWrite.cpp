
#include <Arduino.h>

#include <DelayedWrite.h>


DelayedWrite::DelayedWrite(void)  
  { clear(); }


void DelayedWrite::clear(void)    
  { pin = 0; }


byte DelayedWrite::pin_number(void)
  { return pin; }


void DelayedWrite::write(void)
{
  if ( pin == 0 ) 
    return;

  if ( value == 0 || value == 255 )
    digitalWrite(pin, value); // digital
  else
    analogWrite(pin, value);  // PWM
}


boolean DelayedWrite::written(unsigned long current_time)
{
  if ( pin == 0 ) 
    return;

  // if time to write
  if ( current_time > last_execution + each )
  {
    write();
    // clear it if no more repetitions needed
    if ( each == 0 || times == 1)
    {
      clear();
    }
    else
      last_execution += each;
    return true;
  }
  return false;
}


void DelayedWrite::set(unsigned long current_time,
                       byte          pin_number, 
                       byte          value_to_write, 
                       unsigned long initial_delay, 
                       unsigned long each_millisec = 0,
                       unsigned int  times_to_write = 0);
{
  pin   = pin_number;
  value = value_to_write;
  each  = each_millisec;
  times = times_to_write;

  last_execution = current_time + initial_delay - each;
}



