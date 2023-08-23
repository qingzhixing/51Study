#include "main.h"

static void Initialize()
{
    Timer0Init();
    LCD_Init();
    UART_Init();
}

void main()
{
    Initialize();
    UART_SendByte(0x55);
    UART_SendByte(0xaa);
    while (TRUE)
    {
        // your codes here
    }
}

void Timer0_ISR() interrupt 1
{
    InitTimer0Counter();
    // Timer0_ISR codes here
}