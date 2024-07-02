#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
	int fd = wiringPiI2CSetup(0x48);      // Device 초기화
	
	
	while(1)
	{	
			wiringPiI2CWrite(fd, 0); wiringPiI2CRead(fd); //ch01 set & clear
			int x = (wiringPiI2CRead(fd) * 80) / 255;   // 0~255
			delay(100);
			
			wiringPiI2CWrite(fd, 1); // ch01 (temp)  // read를 위한 체널 셀렉트
			wiringPiI2CRead(fd);
			int y = (wiringPiI2CRead(fd) * 24) / 255;
			delay(100);
			
			//wiringPiI2CWrite(fd, 3); // ch03 (VR)  // read를 위한 체널 셀렉트
			//v3 = wiringPiI2CRead(fd);
			//f3 = (float)((v3/255.0)*5.0);
			
			printf("\033[%d;%dH(%d,%d)\n", y, x, x, y);
			delay(200);
			
	}
}
