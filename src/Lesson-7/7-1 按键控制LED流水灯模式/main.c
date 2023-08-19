#include "lib/LCD1602.h"
#include "lib/defines.h"
#include "lib/init.h"
#include "lib/timer.h"
#include "lib/utilities.h"

void Time0RoutineHandler(void);
uint16_t counter = 0;
uint8_t seconds = 0;

void main()
{
    InitAll();
    while (TRUE)
    {
        // your codes are here
    }
}

// 定时器0产生中断的中断处理函数
void Time0RoutineHandler() interrupt 1
{
    InitTimer0Counter();
    counter++;
    if (counter >= 1000)
    {
        counter = 0;
        seconds++;
        LCD_ShowNum(2, 1, seconds, 4);
    }
}