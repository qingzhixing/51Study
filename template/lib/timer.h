#ifndef __LIB_TIMER_H
#define __LIB_TIMER_H

// 外部晶振频率
#define FOSC 11059200L

// 定时1ms时需要设置的计数器初始值(12T模式下)
#define T1MS (65536 - FOSC / 12 / 1000)

#define LOW_8_BIT(value) (value & 0xFF)
#define HIGH_8_BIT(value) (value >> 8)

void Time0Init(void);
void InitTimer0Counter(void);

#endif /* __LIB_TIMER_H */
