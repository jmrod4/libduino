/*

Outputs - class for dealing with outputs from the Arduino pins to the world

Copyright 2013 Juanma Rodriguez. 

This file is part of the [libduino project](github.com/jmrod4/libduino) 
You can redistribute and/or modify this software under the terms of 
GNU GPL v3 license.

Changelog
---------
2013-06: started coding :)

*/

/*
WARNING: Due to a pitfall in the Arduino IDE, a library cannot include another one
so you must add the following lines to your sketch:

#include <Arduino.h>
#include <DelayedWrite.h>
#include <NiceDelay.h>
#include <Outputs.h>
*/

#include <Arduino.h>
#include <NiceDelay.h>
#include <Outputs.h>

extern NiceDelay nice;
