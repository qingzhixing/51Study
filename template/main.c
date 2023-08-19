#include "main.h"

void main()
{
    Timer0Init();
    while (TRUE)
    {
        // your codes here
    }
}

void Timer0_ISR() interrupt 1
{
    InitTimer0Counter();
}