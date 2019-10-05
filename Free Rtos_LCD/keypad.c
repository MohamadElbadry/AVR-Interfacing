
#include"Dio.h"
#include"std_type1.h"
#include<avr/io.h>
#include<avr/delay.h>
u8 key[4][4] = {
		{'1','2','3','+'},
		{'4','5','6','-'},
		{'7','8','9','*'},
		{'c','0','=','/'}
};
void KeyPad_Init(void)
{
	//set row direction
	Dio_SetPinDirection(PHY_PORTA,PIN_0,OUTPUT_DIRECTION);
	Dio_SetPinDirection(PHY_PORTA,PIN_1,OUTPUT_DIRECTION);
	Dio_SetPinDirection(PHY_PORTA,PIN_2,OUTPUT_DIRECTION);
	Dio_SetPinDirection(PHY_PORTA,PIN_3,OUTPUT_DIRECTION);

	// set colummn direction
	Dio_SetPinDirection(PHY_PORTA,PIN_4,INPUT_DIRECTION);
	Dio_SetPinDirection(PHY_PORTA,PIN_5,INPUT_DIRECTION);
	Dio_SetPinDirection(PHY_PORTA,PIN_6,INPUT_DIRECTION);
	Dio_SetPinDirection(PHY_PORTA,PIN_7,INPUT_DIRECTION);

	//write 5 volt on rows
	Dio_WritePin(PHY_PORTA,PIN_0,HIGH_LEVEL);
	Dio_WritePin(PHY_PORTA,PIN_1,HIGH_LEVEL);
	Dio_WritePin(PHY_PORTA,PIN_2,HIGH_LEVEL);
	Dio_WritePin(PHY_PORTA,PIN_3,HIGH_LEVEL);

	//activate pullup
	Dio_WritePin(PHY_PORTA,PIN_4,HIGH_LEVEL);
	Dio_WritePin(PHY_PORTA,PIN_5,HIGH_LEVEL);
	Dio_WritePin(PHY_PORTA,PIN_6,HIGH_LEVEL);
	Dio_WritePin(PHY_PORTA,PIN_7,HIGH_LEVEL);
}


u8 KeyPad_GetPressedKey(void)
{
	u8 pressedkey=0, pinlevel ;

	for(u8 row=0;row<4;row++)
	{
		Dio_WritePin(PHY_PORTA,row,LOW_LEVEL);
		for(u8 column=4;column<8;column++)
		{
			pinlevel=Dio_ReadPin(PHY_PORTA,column);
			if(pinlevel==0)
			{
				_delay_ms(0);
				if(Dio_ReadPin(PHY_PORTA,column)==0)
				{
					while(pinlevel==0)
					{
						pinlevel=Dio_ReadPin(PHY_PORTA,column);

					}

				}
				pressedkey = key[row][column-4];
				break;

			}
		}
		Dio_WritePin(PHY_PORTA,row,HIGH_LEVEL);
		if(pinlevel==0)
		{
			break;
		}
	}


	return pressedkey ;
}
