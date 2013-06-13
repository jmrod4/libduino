/*

Usage example for the DelayedWrite library.

This file is part of the [libduino project](github.com/jmrod4/libduino) 
and it is subject to the same permissions and restrictions.

Hardware setup
--------------
* An LED connected at pin #13 (usually the Arduino board already have one)

Tested behaviour
----------------
* the internal LED blinks 200 ms each second.

Changelog
---------
2013-06: Initial version :)

*/

#include <Arduino.h>

#include <DelayedWrite.h>


DelayedWrite blink_on, blink_off;

void setup(void)
{
  unsigned long current_time = millis();
  // the following set two delayed writes to pin 13 with the same time reference
  // and the same cycling time,
  // one setting the line high and another low but the later with a 200 millisec delay
    blink_on.set(current_time, 13, HIGH, 0, 1000);
        // delayed write set: time reference = current_time
        //                    pin to write   = 13
        //                    value to write = HIGH
        //                    delay to apply = 0 millisec
        //                    cycle period   = 1000 millisec = 1 second
  blink_off.set(current_time, 13, LOW, 200, 1000);
        // delayed write set: time reference = current_time
        //                    pin to write   = 13
        //                    value to write = LOW
        //                    delay to apply = 200 millisec
        //                    cycle period   = 1000 millisec = 1 second
  
  // the net result is that 
  // code above set cycling (and therefore blinking) indefinitely 
  // but you can also limit the number of cycles 
  
  // for blinking only 3 times uncoment the following
  //blink_on.set (current_time, 13, HIGH, 0, 1000, 3);
  //blink_off.set(current_time, 13, LOW, 200, 1000, 3);
}

void loop(void)
{
  unsigned long current_time = millis();
  // WARNING: no delayed write is done unless written is called!!
  blink_on.written(current_time);
  blink_off.written(current_time);
  delay(1);
}



