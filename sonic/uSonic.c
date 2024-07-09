#include <stdio.h>
#include <wiringPi.h>
#include <pthread.h>

#define TRIG	8
#define ECHO	9

extern double Dist();
extern void Play(double r);

int main(int argc, char **argv)
{
	wiringPiSetup(); //pin numbering method : wPi
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	
	for(;;)
	{
	double d = Dist();
	printf("Distance : %.2f(cm)\n", d);
	double r;
	if(d > 100) r = 1.0;
	else if(d < 50) r = 2.0;
	else r = 1.5;
	Play(r);
	delay(500);
	}
	return 0;
}
//100보다 크면 그린 100보다 작은데 50보단 크다 엘로우 50보다 작으면 레드

