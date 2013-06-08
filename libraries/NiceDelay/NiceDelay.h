/*** class: NiceDelay ***************************************************/

#ifndef LIBDUINO_NICE_DELAY_H_
#define LIBDUINO_NICE_DELAY_H_

#ifndef MAX_DELAYED_WRITES
#define MAX_DELAYED_WRITES  20
#endif

#ifndef NICE_DELAY_GRANULARITY_MSEC
#define NICE_DELAY_GRANULARITY_MSEC 3
#endif

#include <DelayedWrite.h>

class NiceDelay 
{
  public:
    void add(unsigned long current_time,
             byte          pin_number, 
             byte          value_to_write, 
             unsigned long initial_delay, 
             unsigned long each_millisec = 0,
             unsigned int  times_to_write = 0);
    void remove(byte pin_number)
    void delay(unsigned long millisec);
  private:
    DelayedWrite delayed_writes[MAX_DELAYED_WRITES];
    int get_free(void);
};

#endif