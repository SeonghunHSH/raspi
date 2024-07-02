#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

main()
{
	int fd = wiringPiI2CSetup(0x48);      // Device 초기화
	
	int v1, v2, v3;
	float f1, f2, f3;
	
	while(1)
	{	
			wiringPiI2CWrite(fd, 0); v1 = wiringPiI2CRead(fd); //ch01 set & clear
			f1 = (float)((v1/255.0)*5.0);
			delay(100);
			
			wiringPiI2CWrite(fd, 1); // ch01 (temp)  // read를 위한 체널 셀렉트
			v2 = wiringPiI2CRead(fd);
			f2 = (float)((v2/255.0)*5.0);
			delay(100);
			
			wiringPiI2CWrite(fd, 3); // ch03 (VR)  // read를 위한 체널 셀렉트
			v3 = wiringPiI2CRead(fd);
			f3 = (float)((v3/255.0)*5.0);
			
			printf("ADC input level =%d %d %d(%4.1fv %4.1f %4.1f)\n", v1, v2, v3, f1, f2, f3);
			
	}
}
