/*
#include <avr/interrupt.h>
#include "util.h"
#include "REGISTERS.h"
#include "EXTI.h"
#include"ADC.h"
#include"Timer.h"
#include"TimerCfg.h"
#include"Dio.h"
#include <util/delay.h>

void main (void)
{
	Dio_SetPinDirection(PHY_PORTB,PIN_3,OUTPUT_DIRECTION);
	Timer_Init(&strTimerCfg);

	while(1)
	{

		WRITE_REGISTER(REG_OCR0,100);
		_delay_ms(1000);
		WRITE_REGISTER(REG_OCR0,200);
		_delay_ms(1000) ;
		WRITE_REGISTER(REG_OCR0,20);
		_delay_ms(1000);
		WRITE_REGISTER(REG_OCR0,250);
		_delay_ms(1000);
		WRITE_REGISTER(REG_OCR0,50);
		_delay_ms(1000);
		WRITE_REGISTER(REG_OCR0,150);
		_delay_ms(1000);


	}
}

*/
