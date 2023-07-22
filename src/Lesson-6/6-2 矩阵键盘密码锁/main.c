#include "lib/LCD1602.h"
#include "lib/defines.h"
#include "lib/matrix_key.h"
#include "lib/utilities.h"

// 这里定义功能按键

uint8_t scanValue = 0;
uint8_t password[4] = {0};
void main()
{
    LCD_Init();
    LCD_ShowString(1, 1, "Password:");
    while (TRUE)
    {
        scanValue = MatrixKey_Scan();
        if (scanValue != 0)
        {
            // 1 ~ 10 号按键我们定义为密码区，表示 1~9,0
            if (scanValue <= 10)
            {
            }
        }
    }
}