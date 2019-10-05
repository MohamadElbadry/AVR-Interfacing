#include"std_type1.h"
#include"util.h"
#include<avr/delay.h>
#include"Dio.h"
#include"Lcd.h"
#include"ADC.h"
#include<stdlib.h>

int main(void)
{
	char Temp[5]={'x','x','x',0};
	u16 volt ,temp;
	u32 Digital_Value ;
	Adc_Init();
	Lcd_Init();
	Lcd_SendString(Temp);
	Dio_SetPinDirection(PHY_PORTD,PIN_0,OUTPUT_DIRECTION);
	while(1)
	{
		_delay_ms(1000);
		Digital_Value=Adc_Read();
		if((Digital_Value*50)>5000)
		{
			Dio_WritePin(PHY_PORTD,PIN_0,HIGH_LEVEL);
		}
		else
		{
			Dio_WritePin(PHY_PORTD,PIN_0,LOW_LEVEL);

		}
		_delay_ms(50);
		volt=(Digital_Value*5000)/1023 ;
		temp=volt/10 ;
		itoa(volt,Temp,10);
		Lcd_SendString(Temp);
		_delay_ms(1000);
		Lcd_SendCommand(0x01);
		_delay_ms(1000);
	}
	return 0 ;
}
