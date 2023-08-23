#include "lib/LCD1602.h"
#include "lib/defines.h"
#include "lib/matrix_key.h"
#include "lib/utilities.h"

// 这里定义功能按键
#define BACKSPACE 11
#define CONFIRM 12

uint8_t scanValue = 0;
uint8_t inputPassword[6] = {0};
uint8_t correctPassword[6] = {1, 1, 4, 5, 1, 4};
int8_t nextInputDigitId = 0;

void ShowInputPassword()
{
    int8_t index = 0;
    for (index = 0; index < 6; index++)
    {
        if (index < nextInputDigitId)
        {
            LCD_ShowNum(2, index + 1, inputPassword[index], 1);
        }
        else
        {
            LCD_ShowChar(2, index + 1, ' ');
        }
    }
}

bool CheckInputPassword()
{
    int8_t i = 0;
    // 没输入完成就直接判定错
    if (nextInputDigitId < 6)
        return false;
    for (i = 0; i < 6; i++)
    {
        if (inputPassword[i] != correctPassword[i])
            return false;
    }
    return true;
}

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
            if (scanValue <= 10 && nextInputDigitId < 6)
            {
                inputPassword[nextInputDigitId++] = scanValue % 10;
            }
            else if (scanValue == BACKSPACE && nextInputDigitId > 0)
            {
                inputPassword[nextInputDigitId--] = 0;
            }
            else if (scanValue == CONFIRM)
            {
                // 先清空显示位置
                LCD_ShowString(2, 8, "        ");
                Sleep(100);

                if (CheckInputPassword())
                {
                    LCD_ShowString(2, 8, "Correct!");
                }
                else
                {
                    LCD_ShowString(2, 8, "Error!");
                }
            }
        }

        ShowInputPassword();
    }
}