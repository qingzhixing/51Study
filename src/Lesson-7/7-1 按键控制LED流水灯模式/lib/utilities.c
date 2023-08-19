#include "utilities.h"
#include "defines.h"

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
    数码管显示数字
    location:从左到右8个LED编号0~7
    number:0x0~0xF
*/
static uint8_t numberToNixieSign[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x00};
void NixieTubeNumberDisplay(uint8_t location, uint8_t number)
{
    // LED消影
    Delay1ms();
    P0 = 0x00;

    // 反转LED位置，使左边第一个LED从原来的LED8变成LED7
    location = 7 - location;

    P2_2 = location & 1;
    P2_3 = location & 1 << 1;
    P2_4 = location & 1 << 2;

    P0 = numberToNixieSign[number];
}
/*
    数码管显示字母
    location:从左到右8个LED编号0~7
    alpha:'a'~'z'共26个字母
*/

static uint8_t alphaToNixieSign[] = {0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x3d, 0x76, 0x0f, 0x0e,
                                     0x75, 0x38, 0x37, 0x54, 0x5c, 0x73, 0x67, 0x31, 0x49, 0x78,
                                     0x3e, 0x1c, 0x7e, 0x64, 0x6e, 0x59};
void NixieTubeAlphaDisplay(uint8_t location, uint8_t alpha)
{
    // LED消影
    Delay1ms();
    P0 = 0x00;

    // 反转LED位置，使左边第一个LED从原来的LED8变成LED7
    location = 7 - location;

    P2_2 = location & 1;
    P2_3 = location & 1 << 1;
    P2_4 = location & 1 << 2;

    // alpha to id
    alpha = alpha - 'a' + 0;

    P0 = alphaToNixieSign[alpha];
}

void Panic()
{
    while (TRUE)
    {
    }
}