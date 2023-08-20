#include "main.h"

static uint16_t T0Counter = 0;
static uint8_t hour = 0, minute = 0, second = 0;

static void Initialize()
{
    LCD_Init();
    Timer0Init();
}

void main()
{
    Initialize();

    LCD_ShowString(1, 1, "Clock:");

    while (TRUE)
    {

        LCD_ShowNum(2, 1, hour, 2);
        LCD_ShowChar(2, 3, ':');
        LCD_ShowNum(2, 4, minute, 2);
        LCD_ShowChar(2, 6, ':');
        LCD_ShowNum(2, 7, second, 2);
    }
}
void Timer0_ISR() interrupt 1
{
    InitTimer0Counter();
    T0Counter++;
    if (T0Counter >= 1000)
    {
        T0Counter = 0;
        second++;
        if (second >= 60)
        {
            second = 0;
            minute++;
        }
        if (minute >= 60)
        {
            minute = 0;
            hour++;
        }
        if (hour >= 100)
        {
            hour = 0;
        }
    }
}