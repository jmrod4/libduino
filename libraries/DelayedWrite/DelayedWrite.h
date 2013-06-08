/**** class: DelayedWrite *************************************************
*/

#ifndef LIBDUINO_DELAYEDWRITE_H_
#define LIBDUINO_DELAYEDWRITE_H_


class DelayedWrite
{
  public:
    DelayedWrite(void);
    void clear(void);
    byte pin_number(void);
    void write(void);
    boolean written(unsigned long current_time);
    // each = 0  -> write it only once
    // times = 1 -> write it only once
    // times = 0 -> write it forever (infinite times)
    void set(unsigned long current_time,
             byte          pin_number, 
             byte          value_to_write, 
             unsigned long initial_delay, 
             unsigned long each_millisec = 0,
             unsigned int  times_to_write = 0);
  private:
    byte pin;
    byte value;
    unsigned long each;
    unsigned int times;
    unsigned long last_execution;
};


#endif