#include "defines.h"
#include "utilities.h"
#include <REGX52.h>
void main()
{
    int8_t LEDOnLightId = 0;
    while (TRUE)
    {
        // right
        if (P3_3 == 0)
        {
            Sleep(20);
            while (P3_3 == 0)
            {
            }
            Sleep(20);

            LEDOnLightId++;
            if (LEDOnLightId > 7)
            {
                LEDOnLightId = 0;
            }
        }

        // left
        if (P3_1 == 0)
        {
            Sleep(20);
            while (P3_1 == 0)
            {
            }
            Sleep(20);

            LEDOnLightId--;
            if (LEDOnLightId < 0)
            {
                LEDOnLightId = 7;
            }
        }
        P2 = ~(0x01 << LEDOnLightId);
    }
}