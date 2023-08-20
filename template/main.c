#include "main.h"

static void Initialize()
{
    Timer0Init();
}

void main()
{
    Initialize();
    while (TRUE)
    {
        // your codes here
    }
}

void Timer0_ISR() interrupt 1
{
    InitTimer0Counter();
}