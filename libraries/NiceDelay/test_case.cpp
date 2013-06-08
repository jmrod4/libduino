#include <Arduino.h>

#include <NiceDelay.h>

/**** main **********************************************************/


NiceDelay nice;


void setup(void)
{
  unsigned long current_time = millis();
  nice.add(current_time, 13, HIGH, 1000, 0);
  nice.add(current_time, 13, LOW,  1000, 200);
}


void loop(void)
{
  // blinks 10 seconds
  nice.delay(10000U);
  // then stops blinking
  nice.remove(13);
}