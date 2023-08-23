#ifndef MAIN_H
#define MAIN_H
#include "lib/defines.h"
#include "lib/individual_key.h"
#include "lib/stdint.h"
#include "lib/timer.h"
#include "lib/utilities.h"

#define BUTTON_RIGHT 0
#define BUTTON_LEFT 1
#define LED_MOVE_INTERVAL_MS 100

#define LED_REGISTER P2
#define LED_NUM 8

#define LED_OFF(id) SET_DIGIT_1(LED_REGISTER, id)
#define LED_ON(id) SET_DIGIT_0(LED_REGISTER, id)

enum LEDMode
{
    FORWARD,
    BACKWARD,
    LEDMode_MAX
};

#endif /* MAIN_H */
