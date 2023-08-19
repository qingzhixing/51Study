#ifndef __LIB_UTILITIES_H
#define __LIB_UTILITIES_H
#include "stdint.h"
#include <REGX52.h>

void Delay1ms();
void Sleep(uint32_t);
void NixieTubeNumberDisplay(uint8_t, uint8_t);
void NixieTubeAlphaDisplay(uint8_t, uint8_t);
void Panic();

#endif /* __LIB_UTILITIES_H */
