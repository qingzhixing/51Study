#ifndef __LIB_LED_H
#define __LIB_LED_H
#define LED_REGISTER P2
#define LED_NUM 8

#define LED_OFF(id) SET_DIGIT_1(LED_REGISTER, id)
#define LED_ON(id) SET_DIGIT_0(LED_REGISTER, id)

#endif /* __LIB_LED_H */
