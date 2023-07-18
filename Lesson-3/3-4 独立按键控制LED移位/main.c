#include "defines.h"
#include "utilities.h"
#include <REGX52.h>
void main()
{
    uint8_t LEDOnLightId = 0;
    while (TRUE)
    {
        if (P3_1 == 0)
        {
            Sleep(20);
            while (P3_1 == 0)
            {
            }
            Sleep(20);

            LEDOnLightId++;
            if (LEDOnLightId >= 8)
            {
                LEDOnLightId = 0;
            }
            P2 = ~(0x01 << LEDOnLightId);
        }
    }
}