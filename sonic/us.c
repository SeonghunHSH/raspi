#include <stdio.h>
#include <wiringPi.h>

#define TRIG	8
#define ECHO	9

extern void Trigger();

double Dist(){
	//Trigger signal
	Trigger();
	
	//while(digitalRead(ECHO) != 0);  //Wait for burst End
	//버스트가 끝나면 echo단자는 high상태가 된다.
	
	//Wait for Echo signal
	while(digitalRead(ECHO) != 1); //wait for Echo HIGH
	int t1 = micros();	// Get start time (in micro-second)
	while(digitalRead(ECHO) != 0);  //wait for Echo Low
	int t2 = micros();  // Get end time
	//double dist = (t2 - t1) * (340 / 1000000 / 2 * 100);
	return (t2 - t1) * 0.017;
	}
