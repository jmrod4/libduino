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
    void set(unsigned long current_time,
             byte          pin_number, 
             byte          value_to_write, 
             unsigned long initial_delay, 
             unsigned long each_millisec = 0,
    // each = 0  -> write it only once
             unsigned      times_to_write = 0);
    // times = n -> write it only n times
    // times = 0 -> write it forever (infinite times)
  private:
    byte pin;
    byte value;
    unsigned long each;
    unsigned int times;
    unsigned long last_execution;
};


#endif