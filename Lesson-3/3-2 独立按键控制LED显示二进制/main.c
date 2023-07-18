#include "main.h"

int main()
{
	unsigned short int LEDDisplay = 128;
	while (1)
	{
		if (CheckButton(0) == BUTTON_DOWN)
		{
			LEDDisplay--;
			if (LEDDisplay >= 128)
				LEDDisplay = 128;
		}
		else if (CheckButton(1) == BUTTON_DOWN)
		{
			LEDDisplay++;
			if (LEDDisplay >= 128)
				LEDDisplay = 0;
		}
		P2 = ~LEDDisplay;
		Sleep(20);
	}
	return 0;
}