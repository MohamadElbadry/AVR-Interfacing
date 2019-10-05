
#include "util.h"
#include "REGISTERS.h"
#include"Timer.h"
#include"TimerCfg.h"
#include"Dio.h"
#include <util/delay.h>

// we need to illuminate a led with different density
// we are using fast PWM mode

int main (void)
{
	// pin num 3 in portB as output
	Dio_SetPinDirection(PHY_PORTB,PIN_3,OUTPUT_DIRECTION);
	Timer0_Init(&strTimerCfg);

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
	return 0;
}

