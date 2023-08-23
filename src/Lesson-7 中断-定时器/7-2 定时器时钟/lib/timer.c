#include "timer.h"
#include "defines.h"
#include "utilities.h"

// 初始化计数器，每次中断时都要调用
void InitTimer0Counter()
{
    // 设置计数器初始值，只计数1000次，花费1000us=1ms 产生一次中断
    TL0 = LOW_8_BIT(T1MS);
    TH0 = HIGH_8_BIT(T1MS);
}

void Timer0Init()
{
    /*
        仅启用Timer0(低4bit)
        Mode位(第0-1位):    01 - 16位定时器/计数器，TL0、TH0全用
        C/T位(第2位):       0 - 定时器模式，计数器溢出时产生中断
        Gate位(第3位):      0 - 用内部信号激活定时器
    */
    // 后4位置 0b0001
    TMOD &= 0xf0;
    TMOD |= 0x01;
    TF0 = 0; // 初始化进位标志，当定时器溢出时该位为1,向CPU发出中断

    InitTimer0Counter();

    TR0 = 1; // Gate = 0, TR0 = 1时, 允许T0开始计数

    // 配置TF0信号路径
    ET0 = 1; // 允许Timer0产生中断
    PT0 = 0; // Timer0 产生 低级 中断
}