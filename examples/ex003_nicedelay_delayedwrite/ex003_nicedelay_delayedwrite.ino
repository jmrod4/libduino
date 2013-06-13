/*

Usage example for the DelayedWrite and NiceDelay libraries.

This file is part of the [libduino project](github.com/jmrod4/libduino) 
and it is subject to the same permissions and restrictions.

Hardware setup
--------------
* An LED at pin #13 (usually the Arduino board already have one)

Tested behaviour
----------------
* the internal LED blinks only 10 times and then
* the LED switch off and stays off

Changelog
---------
2013-06: Initial version :)

*/

#include <Arduino.h>

#include <DelayedWrite.h>
#include <NiceDelay.h>

/**** main **********************************************************/


NiceDelay nice;


void setup(void)
{
  unsigned long current_time = millis();
  nice.addWrite(current_time, 13, HIGH, 0, 1000);
  nice.addWrite(current_time, 13, LOW,  200, 1000);
}


void loop(void)
{
  // blinks 10 seconds
  nice.delay(10000U);
  // then stops blinking
  nice.remove(13);
}
