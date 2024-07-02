#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <unistd.h>

#define AIN0 0  // VRX connected to AIN0
#define AIN1 1  // VRY connected to AIN1
#define SCREEN_WIDTH 80  // Assuming terminal width
#define SCREEN_HEIGHT 24  // Assuming terminal height

int main()
{
    int fd = wiringPiI2CSetup(0x48);  // Device setup
    int vrx, vry;
    int cursor_x = SCREEN_WIDTH / 2;
    int cursor_y = SCREEN_HEIGHT / 2;

    if (fd == -1) {
        printf("Failed to initialize I2C device.\n");
        return -1;
    }

    while (1) {
        wiringPiI2CWrite(fd, AIN0); 
        vrx = wiringPiI2CRead(fd);

        wiringPiI2CWrite(fd, AIN1); 
        vry = wiringPiI2CRead(fd);

        // Map the joystick values to screen coordinates
        cursor_x = (vrx * SCREEN_WIDTH) / 255;
        cursor_y = (vry * SCREEN_HEIGHT) / 255;

        // Ensure cursor stays within screen boundaries
        if (cursor_x < 1) cursor_x = 1;
        if (cursor_x > SCREEN_WIDTH) cursor_x = SCREEN_WIDTH;
        if (cursor_y < 1) cursor_y = 1;
        if (cursor_y > SCREEN_HEIGHT) cursor_y = SCREEN_HEIGHT;

        // Clear the screen and move the cursor
        printf("\033[2J");  // Clear screen
        printf("\033[%d;%dH", cursor_y, cursor_x);  // Move cursor to (x, y)

        fflush(stdout);  // Ensure the output is displayed immediately

        usleep(100000);  // Sleep for 100 milliseconds
    }

    return 0;
}
