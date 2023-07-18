#ifndef DCDBF978_AC4E_4EE2_81D7_D71BF583F236
#define DCDBF978_AC4E_4EE2_81D7_D71BF583F236
#ifndef D5D201D2_BE3C_4946_803E_DB0450651903
#define D5D201D2_BE3C_4946_803E_DB0450651903
#ifndef __UTILITIES_H
#define __UTILITIES_H
#include "stdint.h"

void Delay1ms();
void Sleep(uint32_t);

void Sleep(uint32_t sleepTime)
{
    while (sleepTime--)
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
#endif /* __UTILITIES_H */

#endif /* D5D201D2_BE3C_4946_803E_DB0450651903 */


#endif /* DCDBF978_AC4E_4EE2_81D7_D71BF583F236 */
