#include <stdio.h>
#include <wiringPi.h>


#define wPi_PWM1 23
int PSC = 1000;      
int RANGE = 100;   

enum { DO=0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, SI };

int pitch[] = { 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494 };

int range[12];  //Range Register values

int song[] = { SL, SL, LA, LA, SL, SL, MI, -1, SL, SL, MI, MI, RE,
               SL, SL, LA, LA, SL, SL, MI, SL, MI, RE, MI, DO, -1};

int rythm[] = {4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 8, 
                4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 8 };

void calcRange() 
{
    for (int i = 0; i < 12; i++) 
    {
        range[i] = 19200000 / (PSC * pitch[i]); // 
    }
}
double rate = 1;
void playSound(int um, int rythm)
 {
    pwmSetClock(PSC);              //prescaler : ~1mhz
    pwmSetRange(range[um]);        
    pwmWrite(wPi_PWM1, range[um] / 2); 
    delay(2000 / (rythm * rate));  
    pwmWrite(wPi_PWM1, 0); delay(1);                
}
int iFlag = 0;
void initSound()
{
    wiringPiSetup();
    pinMode(wPi_PWM1, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    calcRange();
    iFlag = 1;
}

void Play(double r)
 {
    if(!iFlag) initSound();
    rate = r;
    for (int i = 0; song[i] != -1; i++) 
    {
        playSound(song[i], rythm[i]);  
    }
    
    pwmWrite(wPi_PWM1, 0);
    pinMode(wPi_PWM1, OUTPUT);
}
   
/*int main(int n, char *v[])
 {
     double d1 = rate;
     if(n>1)
     { 
         sscanf(v[1], "%lf", &d1);
     } 
     rate = d1;
     
    wiringPiSetup();                
    pinMode(wPi_PWM1, PWM_OUTPUT);  
    pwmSetMode(PWM_MODE_MS);        
    calcRange();  
    for (int i = 0; song[i] != -1; i++) {
        playSound(song[i], rythm[i]);  
    }
    
    pwmWrite(wPi_PWM1, 0);
    pinMode(wPi_PWM1, OUTPUT);
    digitalWrite(wPi_PWM1, 0);
    return 0;
}
*/
