#include "init.h"
#include "LCD1602.h"
#include "timer.h"
#include "utilities.h"

void InitAll(void)
{
    LCD_Init(); // 初始化LCD1602
    LCD_ShowString(1, 1, "LCD_Init Done.");
    Timer0Init(); // 初始化定时器0
    LCD_ShowString(1, 1, "Time0InitDone.");
    LCD_ShowString(1, 1, "InitAll Done.");
}