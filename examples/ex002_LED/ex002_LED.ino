/*

Usage example for the LED library.

This file is part of the [libduino project](github.com/jmrod4/libduino) 
and it is subject to the same permissions and restrictions.

Hardware Setup
--------------
* An LED connected at pin #13 (usually the Arduino board already have one)
* An LED connected at pin #11 (that is PWM able)

Tested behaviour
----------------
* the internal LED blinks 10 times then 
* the other LED progressively increases in brightness and then 
* decreases also progressively, completing 5 cycles.
* repeat from the beginning

Changelog
---------
2013-06: Initial version :)

*/


#include <Arduino.h>

#include <LED.h>


// hardware
LED myled(13);
LED pwmled(11);



// executes this every time the button reset is pushed
void setup(void) 
{
}

void loop(void) 
{
  int i, j;
  
  for (i = 0; i < 10; i++)
    myled.simpleBlink();
    
  myled.off();
  
  for (i = 0; i < 5; i++) 
  {
    for (j = 0; j < 256; j++) 
    {
      pwmled.dim(j);
      delay(10);
    }
    for (j = 255; j >= 0; j--) 
    {
      pwmled.dim(j);
      delay(10);
    }
  }
}

