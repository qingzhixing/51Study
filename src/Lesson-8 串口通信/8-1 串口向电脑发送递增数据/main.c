#include "main.h"

static void Initialize()
{
    Timer0Init();
    LCD_Init();
    UART_Init();
}

uint16_t msCounter = 0;
uint8_t second = 0;

void main()
{
    Initialize();
    UART_SendByte(0x55);
    UART_SendByte(0xaa);
    LCD_ShowString(1, 1, "Seconds:");
    ON_INTERRUPT();
    while (TRUE)
    {
        // your codes here
        LCD_ShowHexNum(2, 1, second, 2);
    }
}

void Timer0_ISR() interrupt 1
{
    InitTimer0Counter();
    // Timer0_ISR codes here

    msCounter++;
    if (msCounter >= 1000)
    {
        msCounter = 0;
        second++;
        UART_SendByte(second);
    }
}