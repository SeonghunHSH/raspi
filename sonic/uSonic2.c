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
	
	printf("Distance : %.2f(cm)\n", Dist());
	delay(500);
	}
	return 0;
}
