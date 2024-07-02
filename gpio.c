#include <stdio.h>
#include <wiringPi.h>

#define RED      8
#define GREEN    9
#define YELLOW   7
#define SW       2
#define STOP_SW  0

    int mode = 0;
	int intv = 0;    //0 ~ 8
	int tim;         // delay time interval(ms)
    int ps[40];   //pin number : 40, pin status : default 0
    int stop = 0;   // LED깜빡임을 멈추는 변수
    
    void Toggle(int pin)
{
	ps[pin] = !ps[pin];
	digitalWrite(pin,ps[pin]);
}

void gpioisr()
{
	if(++intv > 8) intv = 0;
	printf("GPIO interrupt occured...\n");
 }
 
void stopisr()
{
	//stop = !stop;     //스탑변수를 토글하여 led깜빡임을 멈추거나 시작
	stop = 1;
	printf("stop please!!!!!!!!!fuck!!\n");
	}
	
int main()
{
	wiringPiSetup();    //pin number use case (wPi)
	pinMode(RED, OUTPUT);// 8,9,7 : out	2 : in
	pinMode(GREEN, OUTPUT);
	pinMode(YELLOW, OUTPUT);
	pinMode(SW, INPUT);
	pinMode(STOP_SW, INPUT); //핀 0을 입력모드로 설정
	
	wiringPiISR(SW, INT_EDGE_FALLING, gpioisr); //register GPIO ISR
	wiringPiISR(STOP_SW, INT_EDGE_FALLING, stopisr);
	//stop_sw에 대한 인터럽트 핸들러 등
	
	
		
		
		
	
		
	for(;;) //while(1)
	{
		tim = (9-intv)*100;
		if(mode)
		{
		Toggle(RED);		delay(tim);
		Toggle(GREEN);		delay(tim);
		Toggle(YELLOW);		delay(tim);
	    }
	    else
	    {
		Toggle(RED);		delay(tim);
		Toggle(GREEN);		delay(tim);
		Toggle(YELLOW);		delay(tim);
		}
		if(stop == 1)  //스탑변수가 0일때만 엘이디를 깜빡
		{
		digitalWrite(RED, 0);		
		digitalWrite(GREEN, 0);		
		digitalWrite(YELLOW, 0);	
		break;	
	    }
	    
		
	}
		return 0;
}
	
