/*

This test file uses the following hardware setup:
* the internal LED of the arduino normally on pin 13
* a LED with 
     anode connected to pin 11 (that is PWM able)
     cathode connected to a resistor (ex. 470 ohm) and
     the resistor connected to ground

Tested behaviour:
* the internal led blinks 10 times then
* the other led progressively increases in brightness and
  the decrease also progressively, completing 5 cycles.
* then start all again

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
