#ifndef _MAIN_H_
#define _MAIN_H_
#include <REGX52.H>
#include <INTRINS.H>

#define BOOLEAN int
#define TRUE 1
#define FALSE 0

void Delay1ms();
void Sleep(unsigned long int);
BOOLEAN CheckButtonWithoutDebouncing(unsigned short int);
BOOLEAN CheckButton(unsigned short int);

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

BOOLEAN CheckButtonWithoutDebouncing(unsigned short int bottonID){
	bottonID %= 4;
	if(bottonID==0)
		return P3_1;
	if(bottonID==1)
		return P3_0;
	if(bottonID==2)
		return P3_2;
	if(bottonID==3)
		return P3_3;
	return FALSE;
}

BOOLEAN CheckButton(unsigned short int bottonID){
	if(!CheckButtonWithoutDebouncing(bottonID))
		return FALSE;
	Sleep(20);
	return CheckButtonWithoutDebouncing(bottonID);
}

#endif /* _MAIN_H_ */ 
