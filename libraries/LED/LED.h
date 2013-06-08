/*

LED - simple class for dealing with LEDs in the Arduino

Copyright 2013 Juanma Rodriguez. 

You can redistribute and/or modify this software under the terms of 
GNU GPL v3 (or above) license.

Changelog
---------
2013-06 - initial usable version

*/

#ifndef LIBDUINO_LED_H
#define LIBDUINO_LED_H_

#define DEFAULT_BLINK_MSEC_ON   100
#define DEFAULT_BLINK_MSEC_OFF  900

// a simple class on LED dealing :)
class LED {
  public:
    LED(byte pin_number);
    void off(void);
    void on(void);
    void dim(byte pwm_intensity);  // 0 (completly off) to 255 (completly on)
    void simpleBlink(void);  // do a single blink cycle
    byte pinNumber(void);
    unsigned long blink_msec_on;
    unsigned long blink_msec_off;
    //boolean  blinking;  // future implementation
  private:
    byte _pin_number;
    byte _pwm_intensity;
};

#endif
