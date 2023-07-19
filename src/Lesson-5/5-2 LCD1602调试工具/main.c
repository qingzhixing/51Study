#include "lib/LCD1602/LCD1602.h"
#include "lib/defines.h"
#include "lib/utilities.h"
void main()
{
    LCD_Init();
    LCD_ShowString(2, 3, "114514");
    while (TRUE)
    {
        // your codes are here
    }
}