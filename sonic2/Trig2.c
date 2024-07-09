#include <stdio.h>
#include <wiringPi.h>

#define wPi_PWM1 23

int PSC = 40;      
int RANGE = 100;   

enum { DO=0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, SI };

int pitch[] = { 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494 };

int range[12];  // Range Register values

int song[] = { SL, SL, LA, LA, SL, SL, MI, SL, SL, MI, MI, RE,
               SL, SL, LA, LA, SL, SL, MI, SL, MI, RE, MI, DO, -1 };

int rythm[] = {4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 8, 
                4, 4, 4, 4, 4, 4, 8, 4, 4, 4, 4, 8 };

void calcRange() {
    for (int i = 0; i < 12; i++) {
        range[i] = 19200000 / (PSC * pitch[i]); 
    }
}

void playSound(int um, int rythm) {
    pwmSetClock(PSC);              
    pwmSetRange(range[um]);        
    pwmWrite(wPi_PWM1, range[um] / 2); 
    delay(2000 / rythm);                  
}

void playMelody(double distance) {
    double speedFactor = 1.0;
    if (distance < 50) {
        speedFactor = 2.0;
    } else if (distance < 100) {
        speedFactor = 1.5;
    }
    
    wiringPiSetup();                
    pinMode(wPi_PWM1, PWM_OUTPUT);  
    pwmSetMode(PWM_MODE_MS);        
    calcRange();  
    
    for (int i = 0; song[i] != -1; i++) {
        playSound(song[i], rythm[i] / speedFactor);  
    }
    
    pwmWrite(wPi_PWM1, 0);
    pinMode(wPi_PWM1, OUTPUT);
    digitalWrite(wPi_PWM1, 0);
}
