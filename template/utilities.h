#ifndef __UTILITIES_H
#define __UTILITIES_H
#include "stdint.h"
#include <REGX52.h>

void Delay1ms();
void Sleep(uint32_t);
void NixieTubeNumberDisplay(uint8_t, uint8_t);
void NixieTubeAlphaDisplay(uint8_t, uint8_t);

#endif /* __UTILITIES_H */
