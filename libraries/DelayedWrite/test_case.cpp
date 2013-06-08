
#include <Arduino.h>

#include <DelayedWrite.h>

//Usage Example 1:

DelayedWrite blink_on, blink_off;

setup() 
{
  unsigned long current_time = millis();
  // blinking infinite times
  blink_on.set (current_time, 13, HIGH, 1000, 0);
  blink_off.set(current_time, 13, LOW,  1000, 200);
  // for blinking only 3 times substitute previous for the following
  //blink_on.set (current_time, 13, HIGH, 1000, 0,   3);
  //blink_off.set(current_time, 13, LOW,  1000, 200, 3);
}

loop()
{
  unsigned long current_time = millis();
  blink_on.written (current_time);
  blink_off.written(current_time);
  delay(1);
}


