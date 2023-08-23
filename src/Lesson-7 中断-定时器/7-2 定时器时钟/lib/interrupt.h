#ifndef __LIB_INTERRUPT_H
#define __LIB_INTERRUPT_H
#include "REGX52.h"
#define ON_INTERRUPT() EA = 1
#define OFF_INTERRUPT() EA = 0
#endif /* __LIB_INTERRUPT_H */
