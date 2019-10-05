
#include <avr/interrupt.h>
#include "util.h"
#include "Registers.h"
#include"Timer.h"
#include"TimerCfg.h"
#include"Dio.h"
#include<avr/delay.h>
#include"ICU.h"
#include "Lcd.h"
#include <stdlib.h>
void main(void)
{
	Dio_SetPinDirection(PHY_PORTB,PIN_3,OUTPUT_DIRECTION);
	Timer0_Init(&strTimerCfg);
	u8 Text[4];
	u8 duty ;
	Icu_Init();
	Lcd_Init();
	WRITE_REGISTER(REG_OCR0,127);
	while(1)
	{

		_delay_ms(1000);
		Icu_GetDutyCycle(&duty);
		itoa(duty,Text,10);
		Lcd_SendString(Text);
		_delay_ms(1000);
		Lcd_SendCommand(0x01);
		_delay_ms(500);

	}
}


