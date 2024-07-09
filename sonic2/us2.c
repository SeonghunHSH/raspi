#include <stdio.h>
#include <wiringPi.h>

#define TRIG 8
#define ECHO 9

extern void Trigger();

double Dist(){
    Trigger();
    
    while(digitalRead(ECHO) != 1); // 
    int t1 = micros(); // 
    while(digitalRead(ECHO) != 0); // 
    int t2 = micros(); // 
    
    return (t2 - t1) * 0.017;
}
