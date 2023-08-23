#include "lib/LCD1602/LCD1602.h"
#include "lib/defines.h"
#include "lib/utilities.h"
void main()
{
    LCD_Init();
    LCD_ShowString(2, 4, "sb SEGA");
    while (TRUE)
    {
        // your codes are here
    }
}