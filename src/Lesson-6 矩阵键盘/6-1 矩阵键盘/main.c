#include "lib/LCD1602.h"
#include "lib/defines.h"
#include "lib/matrix_key.h"
#include "lib/utilities.h"
void main()
{
    int scanValue = 0;
    int lastButtonDown = 0;

    LCD_Init();
    while (TRUE)
    {
        LCD_ShowString(2, 6, "Entered");
        scanValue = MatrixKey_Scan();
        lastButtonDown = scanValue == 0 ? lastButtonDown : scanValue;
        LCD_ShowNum(1, 1, lastButtonDown, 2);
    }
}