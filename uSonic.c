#include <stdio.h>
#include <wiringPi.h>

#define TRIG	8
#define ECHO	9

extern double Dist();

int main(void)
{
	wiringPiSetup(); //pin numbering method : wPi
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	
	for(;;)
	{
	
	printf("Distance : %f(cm)\n", Dist());
	delay(500);
	}
	return 0;
}
//100보다 크면 그린 100보다 작은데 50보단 크다 엘로우 50보다 작으면 레드

