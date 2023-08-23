#include "matrix_key.h"
#include "utilities.h"
#include <REGX52.H>

// 暴力扫描得到按键编号(1~16)
// 返回0:按键未按下
uint8_t MatrixKey_Scan()
{
    uint8_t keyId = 0;

#define CheckButtonDown(ButtonRegisterId, Id) \
    if (ButtonRegisterId == 0)                \
    {                                         \
        Sleep(20);                            \
        while (ButtonRegisterId == 0)         \
            ;                                 \
        Sleep(20);                            \
        keyId = Id;                           \
    }

    P1 = 0xFF;
    P1_3 = 0;
    CheckButtonDown(P1_7, 1);
    CheckButtonDown(P1_6, 5);
    CheckButtonDown(P1_5, 9);
    CheckButtonDown(P1_4, 13);

    P1 = 0xFF;
    P1_2 = 0;
    CheckButtonDown(P1_7, 2);
    CheckButtonDown(P1_6, 6);
    CheckButtonDown(P1_5, 10);
    CheckButtonDown(P1_4, 14);

    P1 = 0xFF;
    P1_1 = 0;
    CheckButtonDown(P1_7, 3);
    CheckButtonDown(P1_6, 7);
    CheckButtonDown(P1_5, 11);
    CheckButtonDown(P1_4, 15);

    P1 = 0xFF;
    P1_0 = 0;
    CheckButtonDown(P1_7, 4);
    CheckButtonDown(P1_6, 8);
    CheckButtonDown(P1_5, 12);
    CheckButtonDown(P1_4, 16);

    return keyId;
#undef CheckButtonDown
}

#define KEY_MATRIX_PORT P1 // 使用宏定义矩阵按键控制口
uint8_t key_matrix_ranks_scan(void)
{
    uint8_t key_value = 0;

    KEY_MATRIX_PORT = 0xf7;      // 给第一列赋值0，其余全为1
    if (KEY_MATRIX_PORT != 0xf7) // 判断第一列按键是否按下
    {
        Sleep(20);
        ;                        // 消抖
        switch (KEY_MATRIX_PORT) // 保存第一列按键按下后的键值
        {
        case 0x77:
            key_value = 1;
            break;
        case 0xb7:
            key_value = 5;
            break;
        case 0xd7:
            key_value = 9;
            break;
        case 0xe7:
            key_value = 13;
            break;
        }
    }
    while (KEY_MATRIX_PORT != 0xf7)
        ; // 等待按键松开

    KEY_MATRIX_PORT = 0xfb;      // 给第二列赋值0，其余全为1
    if (KEY_MATRIX_PORT != 0xfb) // 判断第二列按键是否按下
    {
        Sleep(20);
        ;                        // 消抖
        switch (KEY_MATRIX_PORT) // 保存第二列按键按下后的键值
        {
        case 0x7b:
            key_value = 2;
            break;
        case 0xbb:
            key_value = 6;
            break;
        case 0xdb:
            key_value = 10;
            break;
        case 0xeb:
            key_value = 14;
            break;
        }
    }
    while (KEY_MATRIX_PORT != 0xfb)
        ; // 等待按键松开

    KEY_MATRIX_PORT = 0xfd;      // 给第三列赋值0，其余全为1
    if (KEY_MATRIX_PORT != 0xfd) // 判断第三列按键是否按下
    {
        Sleep(20);
        ;                        // 消抖
        switch (KEY_MATRIX_PORT) // 保存第三列按键按下后的键值
        {
        case 0x7d:
            key_value = 3;
            break;
        case 0xbd:
            key_value = 7;
            break;
        case 0xdd:
            key_value = 11;
            break;
        case 0xed:
            key_value = 15;
            break;
        }
    }
    while (KEY_MATRIX_PORT != 0xfd)
        ; // 等待按键松开

    KEY_MATRIX_PORT = 0xfe;      // 给第四列赋值0，其余全为1
    if (KEY_MATRIX_PORT != 0xfe) // 判断第四列按键是否按下
    {
        Sleep(20);
        ;                        // 消抖
        switch (KEY_MATRIX_PORT) // 保存第四列按键按下后的键值
        {
        case 0x7e:
            key_value = 4;
            break;
        case 0xbe:
            key_value = 8;
            break;
        case 0xde:
            key_value = 12;
            break;
        case 0xee:
            key_value = 16;
            break;
        }
    }
    while (KEY_MATRIX_PORT != 0xfe)
        ; // 等待按键松开

    return key_value;
}