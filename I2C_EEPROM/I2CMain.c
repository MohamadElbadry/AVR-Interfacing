/*
 * I2CMain.c
 *
 *  Created on: Jun 21, 2019
 *      Author: medos
 */

#include"std_type1.h"
#include"util.h"
#include"REGISTERS.h"
#include"EEPROM.h"
#include"I2C.h"
#include"avr/delay.h"
#include"Dio.h"
void main()
{
	EEPROM_INIT();
	Dio_SetPinDirection(PHY_PORTA,PIN_0,OUTPUT_DIRECTION);
	Dio_SetPinDirection(PHY_PORTA,PIN_1,OUTPUT_DIRECTION);

	u8 data ;
	while(1)
	{

		EEPROM_WriteData(100 , 50 );

		_delay_ms(1000);
		data=EEPROM_ReceiveData(100);

		if(data==50)
		{
			Dio_WritePin(PHY_PORTA,PIN_0,HIGH_LEVEL);
			_delay_ms(5000);
			Dio_WritePin(PHY_PORTA,PIN_0,LOW_LEVEL);
			_delay_ms(5000);
		}
		else
		{
			Dio_WritePin(PHY_PORTA,PIN_0,LOW_LEVEL);
/*			Dio_WritePin(PHY_PORTA,PIN_1,HIGH_LEVEL);*/

		}
		_delay_ms(1000);
	}
}
