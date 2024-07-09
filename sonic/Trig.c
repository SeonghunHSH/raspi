#include <stdio.h>
#include <wiringPi.h>

#define TRIG	8
#define ECHO	9

void Trigger()
{
	digitalWrite(TRIG, 0);
	delayMicroseconds(10);
	// Trigger signal
	digitalWrite(TRIG, 1);
	delayMicroseconds(10);
	digitalWrite(TRIG, 0);
	delayMicroseconds(200);
	
}

