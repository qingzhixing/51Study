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

void Panic()
{
    while (TRUE)
    {
    }
}