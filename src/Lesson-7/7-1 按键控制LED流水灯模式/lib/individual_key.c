#include "individual_key.h"
#include "REGX52.H"
#include "utilities.h"

// 返回按下的独立按键编号,没按下返回-1
int8_t IndividualKey_Scan(void)
{
    int8_t keyDown = -1;
#define CheckButtonDown(buttonRegisterId, keyId) \
    if (buttonRegisterId == 0)                   \
    {                                            \
        Sleep(20);                               \
        while (buttonRegisterId == 0)            \
            ;                                    \
        Sleep(20);                               \
        keyDown = keyId;                         \
    }

    CheckButtonDown(P3_0, 0);
    CheckButtonDown(P3_1, 1);
    CheckButtonDown(P3_2, 2);
    CheckButtonDown(P3_3, 3);

    return keyDown;
}