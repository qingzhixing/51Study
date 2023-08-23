#ifndef __UTILITIES_H
#define __UTILITIES_H
#include "stdint.h"
#include <REGX52.h>

void Delay1ms();
void Sleep(uint32_t);
void NixieTubeDisplay(uint8_t, uint8_t);

void Sleep(uint32_t msTime)
{
    while (msTime--)
    {
        Delay1ms();
    }
}
void Delay1ms() //@12.000MHz
{
    unsigned char i, j;

    i = 2;
    j = 239;
    do
    {
        while (--j)
            ;
    } while (--i);
}

/*
    location:从左到右8个LED编号0~7
    number:0x0~0xF
*/
void NixieTubeDisplay(uint8_t location, uint8_t number)
{
    static uint8_t numberToNixieSign[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00};

    // 反转LED位置，使左边第一个LED从原来的LED8变成LED7
    location = 7 - location;

    P2_2 = location & 1;
    P2_3 = location & 1 << 1;
    P2_4 = location & 1 << 2;

    P0 = numberToNixieSign[number];
}
#endif /* __UTILITIES_H */
