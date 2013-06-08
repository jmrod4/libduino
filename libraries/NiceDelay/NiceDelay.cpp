#include <Arduino.h>

#include <NiceDelay.h>


int NiceDelay::get_free(void)
{
  for (int i = 0; i < MAX_DELAYED_WRITES; i++)
    if (delayed_writes[i].pin_number() == 0)
      return i;
  return -1;
}


void NiceDelay::remove(pin)
{
  for (int i = 0; i < MAX_DELAYED_WRITES; i++)
    if (delayed_writes[i].pin_number() == pin)
      delayed_writes[i].clear();
}


void NiceDelay::delay(unsigned long millisec)
{
  while (millisec > NICE_DELAY_GRANULARITY_MSEC)
  {
    this.delay(NICE_DELAY_GRANULARITY_MSEC);
    millisec -= NICE_DELAY_GRANULARITY_MSEC;
  }  

  unsigned long current_time = millis();

  for (int i = 0; i < MAX_DELAYED_WRITES; i++)
    delayed_writes[i].written(current_time);
  millisec -= millis() - current_time;
  if (millisec > 0)
    std::delay(millisec);
}


void NiceDelay::add(unsigned long current_time,
                    byte          pin_number, 
                    byte          value_to_write, 
                    unsigned long initial_delay, 
                    unsigned long each_millisec = 0,
                    unsigned int  times_to_write = 0)
{
  int i = get_free()
  // FIXME: if i==-1 no free spaces, and does nothing
  if ( i < 0 ) 
    return;

  delayed_writes[i].set(current_time, pin_number, value_to_write,
                        initial_delay, each_millisec, times_to_write);
}

