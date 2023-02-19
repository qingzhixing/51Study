#ifndef _MAIN_H_
#define _MAIN_H_
#include <REGX52.H>
#include <INTRINS.H>

void Delay1ms();
void Sleep(unsigned long int);

void Sleep(unsigned long int sleepTime){
	while(sleepTime--){
		Delay1ms();
	}
}
void Delay1ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}


#endif /* _MAIN_H_ */
