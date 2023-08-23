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

/*
    初始化Timer0: 16位定时器/计数器
*/
void Timer0Init()
{
    /*
        启用Timer0(设置TMOD低4bit)
        从低到高:
        Mode位(第0-1位):    01 - 16位定时器/计数器，TL0、TH0全用
        C/T位(第2位):       0 - 定时器模式，计数器溢出时产生中断
        Gate位(第3位):      0 - 仅用TR0激活计时器，不用考虑外部输入INT0
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
/*
    初始化Timer1: 8位定时器自动重装，用作波特率发生器
    Timer1被分为两个8位存储器，一个用于保存用于自动重装的数据
*/
void Timer1Init()
{
    /*
        启用Timer0作为波特率发生器(设置TMOD高4bit)
        从高到低:
        Gate: 0 - 仅用TR1激活计时器，不用考虑外部输入INT1
        C/T: 0 - 定时器模式，溢出就产生信号
        Mode位: 10 - 工作模式2: 8位定时器自动重装，用作波特率发生器
    */
    // 高4位置 0b0010
    TMOD &= 0x0f;
    TMOD |= 0x20;

    /*
        定时器初始值计算公式:(中间除以2是因为波特率不加倍)
            256-晶振值/12/2/16/波特率
        这里我们使用: 9600bps@11.0592MHz
    */
    TL1 = 0xFD; // 设置定时初始值
    TH1 = 0xFD; // 设置定时重载值

    TF1 = 0; // 溢出标志位
    ET1 = 0; // 不开启Timer1中断
    TR1 = 1; // Gate = 0, TR1 = 1时, 开始计数
}