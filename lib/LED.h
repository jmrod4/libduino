/*

LED - simple class for dealing with LEDs in the Arduino

Copyright 2013 Juanma Rodriguez. 

You can redistribute and/or modify this software under the terms of 
GNU GPL v3 (or above) license.

Changelog
---------
0.0 - still in development

*/

#ifndef LIBDUINO_LED_H
#define LIBDUINO_LED_H_

#define DEFAULT_BLINK_MSEC_ON   100
#define DEFAULT_BLINK_MSEC_OFF  900

// a simple class on LED dealing :)
class LED {
  public:
    LED(uint8_t pin);
    void off(void);
    void on(void);
    void dim(uint8_t pwm); // 0 (completly off) to 255 (completly on)
    void blink(void);
    uint8_t pin(void);
    boolean  blinking;
    unsigned long blink_msec_on;
    unsigned long blink_msec_off;
  private:
    uint8_t _pin;
    uint8_t _pwm;
};

#endif
