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

#ifndef LIBDUINO_INPUTS_H_
#define LIBDUINO_INPUTS_H_

enum InputMode
{
  INPUT_DIGITAL,
  INPUT_ANALOG
};


class DigitalInput
{
  public:
    DigitalInput(byte pin_number);
    int read_raw(void); // inmediatly read and returns just the value, no processing
    int read(void); // process, debounces, scales, the value before returning it
    void set_debounce(unsigned millisec); // default is 0 (no debounce)
    
    boolean is_on(void);
    boolean is_off(void);
    // if applied to analog inputs "converts" to digital value 0 or 1
    
    boolean has_changed(void);
    boolean reset_change(void);
  protected:
    byte _pin;
  private:
    unsigned _debounce_msec;
    boolean _last_read_value;
    boolean _changed;
};


class AnalogInput : public DigitalInput
{
  public:
    AnalogInput(byte pin_number);
    int read_raw(void);
    int read(void);
    //void set_range(int min_value, int max_value);
    void set_average_samples(
        unsigned samples_number, 
        unsigned microsec_between_samples=200); // additional to the 100 microsec reading
    boolean peak_detected(void);
  private:
    int _range_min_value;
    int _range_max_value;
    unsigned _average_samples_number;
    unsigned _average_samples_microsec;
};

#endif


