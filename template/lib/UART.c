#include "UART.h"
#include "REGX52.h"
#include "timer.h"
/*
    UART初始化 - 工作模式1: 8位UART,波特率可变
*/
void UART_Init(void)
{
    Timer1Init(); // 利用定时器1作为波特率发生器

    /*
        串行控制寄存器SCON = 0b_0100_0000 = 0x40
        高位到低位:
        SM0~1: 01 - 工作模式1: 8位UART,波特率可变(为T1溢出率)
        SM2: 控制工作模式2,3多机通信,这里不用管
        REN: 1 - 打开串行接收
        TB8,RB8: 管理方式2,3 第九位数据，这里不管
        TI,RI: 标志位，清空
    */
    SCON = 0x50;

    /*
        波特率选择特殊功能寄存器PCON,设置高2位为0b00.
        剩余位与电源控制位共用一个寄存器
        高2位从高到底:
        SMOD波特率选择位: 0 - 除以二, 1 - 不除以二,即给1加倍, 加倍可以降低误差,这里不加倍
        SMOD0帧错误检测位:    0 - SCON的SM0 和 SM1一起指定工作模式
                            1 - SCON的SM0用于帧错误检测功能
    */
    // 设置高2位为0b00
    PCON &= 0x3F;
    PCON |= 0x00; // 0b0000_0000
}

void UART_SendByte(uint8_t byte)
{
    SBUF = byte;
    // 检测是否完成(TI = 1)
    while (TI != 1)
    {
    }
    TI = 0;
}