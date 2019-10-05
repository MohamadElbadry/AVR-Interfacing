#include "REGISTERS.h"
#include"std_type1.h"
#include"util.h"
#include<avr/delay.h>
#include"Dio.h"
#define x 10   // delay between every two steps
int main(void)
{
	Dio_SetPortDirection(PHY_PORTD,OUTPUT_DIRECTION);
	u8 j=0 ;
	// for complete cycle in full step mode 2048 steps are needed
	for(u16 i=0 ; i <2048; i++)
	{
		j= i%4 ;
		REG_PORTD=~(1<<j);
		_delay_ms(x);
	}
}

















/*
Dio_WritePin(PHY_PORTD,PIN_0,LOW_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_1,HIGH_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_2,HIGH_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_3,HIGH_LEVEL);
_delay_ms(x);
Dio_WritePin(PHY_PORTD,PIN_0,HIGH_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_1,LOW_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_2,HIGH_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_3,HIGH_LEVEL);
_delay_ms(x);
Dio_WritePin(PHY_PORTD,PIN_0,HIGH_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_1,HIGH_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_2,LOW_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_3,HIGH_LEVEL);
_delay_ms(x);
Dio_WritePin(PHY_PORTD,PIN_0,HIGH_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_1,HIGH_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_2,HIGH_LEVEL);
Dio_WritePin(PHY_PORTD,PIN_3,LOW_LEVEL);
/*

	while(1)
	{
		for(u8 i=0 ;i <64 ; i++)
		{
			Dio_WritePin(PHY_PORTD,PIN_0,LOW_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_1,HIGH_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_2,HIGH_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_3,HIGH_LEVEL);
			_delay_ms(x);
			Dio_WritePin(PHY_PORTD,PIN_0,HIGH_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_1,LOW_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_2,HIGH_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_3,HIGH_LEVEL);
			_delay_ms(x);
			Dio_WritePin(PHY_PORTD,PIN_0,HIGH_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_1,HIGH_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_2,LOW_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_3,HIGH_LEVEL);
			_delay_ms(x);
			Dio_WritePin(PHY_PORTD,PIN_0,HIGH_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_1,HIGH_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_2,HIGH_LEVEL);
			Dio_WritePin(PHY_PORTD,PIN_3,LOW_LEVEL);
			_delay_ms(x);
		}




	}
	 */


