#include "colors.h"

void textcolor(int attr, int fg, int bg);
int main()
{	textcolor(BRIGHT, RED, BLACK);
    printf("In color\n");
    textcolor(RESET, WHITE, BLACK);
    return 0;
}

void textcolor(int attributes, int foreground, int background)
{
    char command[13];
    /* Command is the control command to the terminal */
    sprintf(command, "%c[%d;%d;%dm", 0x1B, attributes, foreground + 30, background + 40);
    printf("%s", command);
}