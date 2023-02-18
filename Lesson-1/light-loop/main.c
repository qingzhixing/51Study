#include <REGX52.H>
#include <INTRINS.H>

void Sleep(unsigned long int);
#define Delay() Sleep(200)

void main(void){
	while(1){
		P2=0xFE; //0b00000001
		Delay();
		P2=0xFD; //0b00000010
		Delay();
		P2=0xFB; //0b00000100
		Delay();
		P2=0xF7; //0b00001000
		Delay();
		P2=0xEF; //0b00010000
		Delay();
		P2=0xDF; //0b00100000
		Delay();
		P2=0xBF; //0b01000000
		Delay();
		P2=0x7F; //0b10000000
		Delay();
	}
}

void Sleep(unsigned long int sleepTime){
	while(sleepTime--){
		_nop_();
	}
}