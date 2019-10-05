#include"std_type1.h"
#include"util.h"
#include<avr/delay.h>
#include"keypad.h"
#include"Lcd.h"
#include"Lcd_Project.h"
#include"ExtIEnum.h"
#include"ExtICfg.h"
int main(void)

{
	ExtI_Init();
	ExtI0_Init(&strInterrupt0);
	ExtI1_Init(&strInterrupt1);
	Lcd_SendChar('x');
	Lcd_SendCommand(0x01);
	while(1)
	{


	}

	return 0;
}


