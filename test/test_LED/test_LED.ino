/*

test_LED - test for the LED library from the libduino project <github.com/jmrod4/libduino>

Copyright 2013 Juanma Rodriguez. 

You can redistribute and/or modify this software under the terms of 
GNU GPL v3 (or above) license.


Hardware Setup
--------------
* the internal LED of the arduino normally on pin 13
* a LED with 
     anode connected to pin 11 (that is PWM able)
     cathode connected to a resistor (ex. 470 ohm) and
     the resistor connected to ground


Tested behaviour
----------------
* the internal led blinks 10 times then 
* the other led progressively increases in brightness and
  then decreases also progressively, completing 5 cycles.
then repeats


Changelog
---------
2013-06-02 - initial version

*/


#include <Arduino.h>

#include <LED.h>


// hardware
LED myled(13);
LED pwmled(11);



// executes this every time the button reset is pushed
void setup(void) {
}



void loop(void) {
  int i, j;
  
  for (i = 0; i < 10; i++)
    myled.simpleBlink();
  myled.off();
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 256; j++) {
      pwmled.dim(j);
      delay(10);
    }
    for (j = 255; j >= 0; j--) {
      pwmled.dim(j);
      delay(10);
    }
  }
}
