/*

Usage example for the libduino libraries.

This file is part of the [libduino project](github.com/jmrod4/libduino) 
and it is subject to the same permissions and restrictions.

Hardware setup
--------------
* An LED at pin #13 (usually the Arduino board already have one)
* A pushbutton at pin #3
* A potentiometer at pin A0

Tested behaviour
----------------
When the push button changes state (after debouncing):
* The LED is switched on or off to reflect the pushbutton state
* Converts the analog input (pot) to digital and
* Prints serial port ON or OFF according to the converted value

Changelog
---------
2013-06: Initial version :)

*/

#include <Arduino.h>

// WARNING: it is necessary to explicitly include this here for the libraries 
// to be able to find the file! 
#include <DelayedWrite.h> 
#include <NiceDelay.h>  


#include <LED.h>
#include <Inputs.h>


NiceDelay nice;


LED          led       (13);
DigitalInput pushbutton(3);
AnalogInput  pot       (A0);

void prints(int value)
{
   Serial.println((value) ? "ON" : "OFF");
}


void setup(void)
{
   Serial.begin(115200);
   pushbutton.set_debounce(10); // millisec
}

void loop(void)
{
   Serial.println(pot.read());
   Serial.println(pot.is_on()); // "converts" the analog input to digital value 0 or 1
  
   if ( pushbutton.is_on() )
   {
      led.on();
   }
   else
   {
      led.off();
   }

   do 
   {
      nice.delay(2);
      pushbutton.read(); // read already debounces
   } while ( ! pushbutton.has_changed() );

   pushbutton.reset_change();
}

