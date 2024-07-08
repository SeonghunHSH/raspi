#include <stdio.h>
#include <wiringPi.h>


#define wPi_PWM1 23

int PSC = 19;      
int RANGE = 100;   

enum { DO=0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, SI };

int pitch[] = { 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494 };

int range[12];

int song[] = { SL, SL, LA, LA, SL, SL, MI, SL, SL, MI, MI, RE,
               SL, SL, LA, LA, SL, SL, MI, SL, MI, RE, MI, DO, -1};

int rythm[] = {4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 8, 4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 8 };

void calcRange() {
    for (int i = 0; i < 12; i++) {
        range[i] = 19200000 / (PSC * pitch[i]); // 
    }
}

void playSound(int um, int rythm) {
    pwmSetClock(PSC);              
    pwmSetRange(range[um]);        
    pwmWrite(wPi_PWM1, range[um] / 2); 
    delay(2000 / rythm);                  
}

int main() {
    wiringPiSetup();                
    pinMode(wPi_PWM1, PWM_OUTPUT);  
    pwmSetMode(PWM_MODE_MS);        
    calcRange();  
    for (int i = 0; song[i] != -1; i++) {
        playSound(song[i], rythm[i]);  
    }

    return 0;
}
