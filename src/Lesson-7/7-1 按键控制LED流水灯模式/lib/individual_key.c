#include "individual_key.h"
#include "REGX52.H"
#include "stdint.h"
#include "utilities.h"

// 返回按下的独立按键编号,没按下返回-1
int IndividualKey_Scan(void)
{
    uint8_t keyDown = -1;
#define CheckButtonDown(buttonRegisterId, keyId) \
    if (buttonRegisterId == 0)                   \
    {                                            \
        Sleep(20);                               \
        while (buttonRegisterId == 0)            \
            ;                                    \
        Sleep(20);                               \
        keyDown = keyId;                         \
    }

    CheckButtonDown(P2_0, 0);
    CheckButtonDown(P2_1, 1);
    CheckButtonDown(P2_2, 2);
    CheckButtonDown(P2_3, 3);

    return keyDown;
}