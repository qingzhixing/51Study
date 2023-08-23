#include "main.h"

int8_t keyDown;
enum LEDMode LEDMoveMode = FORWARD;

void main()
{
    Timer0Init();

    while (TRUE)
    {
        keyDown = IndividualKey_Scan();
        if (keyDown == -1)
            continue;
        switch (keyDown)
        {
        case BUTTON_RIGHT:
            LEDMoveMode = FORWARD;
            break;
        case BUTTON_LEFT:
            LEDMoveMode = BACKWARD;
            break;
        default:
            break;
        }
    }
}

void Timer0_ISR() interrupt 1
{
    static uint16_t T0Counter = 0;
    static int8_t LEDLightId = 0;

    InitTimer0Counter();

    T0Counter++;
    if (T0Counter >= LED_MOVE_INTERVAL_MS)
    {
        T0Counter = 0;
        switch (LEDMoveMode)
        {
        case FORWARD:
            LED_OFF(LEDLightId);
            LEDLightId++;
            if (LEDLightId >= LED_NUM)
            {
                LEDLightId = 0;
            }
            LED_ON(LEDLightId);
            break;

        case BACKWARD:
            LED_OFF(LEDLightId);
            LEDLightId--;
            if (LEDLightId < 0)
            {
                LEDLightId = LED_NUM - 1;
            }
            LED_ON(LEDLightId);
            break;
        }
    }
}