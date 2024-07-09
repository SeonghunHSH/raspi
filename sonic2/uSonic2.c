#include <stdio.h>
#include <wiringPi.h>

#define TRIG 8
#define ECHO 9

extern double Dist();
extern void playMelody(double distance);

int main(void) {
    wiringPiSetup(); // 
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    
    for(;;) {
        double distance = Dist();
        printf("Distance : %.2f(cm)\n", distance);
        playMelody(distance);
        delay(500);
    }
    return 0;
}
