#include"Lcd_Project_variable.h"
#include"Lcd_Project.h"
#include "Lcd.h"
#include "Keypad.h"
#include "util.h"
#include "REGISTERS.h"
#include "std_type1.h"
#include"avr/delay.h"
#include"Dio.h"
#include"Timer.h"
#include"TimerCfg.h"

void Lcd_project(void)
{
	i=0;
	u8 pressed ;
	Lcd_Init();
	KeyPad_Init();
	Lcd_SendCommand(DISPLAY_CLEAR);
	Lcd_SendString(lcd_user);
	Lcd_SendCommand(0xC0);
	Dio_SetPinDirection(PHY_PORTB,PIN_7,OUTPUT_DIRECTION);
	while(i<4)
	{
		pressed=KeyPad_GetPressedKey();
		if(pressed!=0)
		{
			user_id[i]=pressed;
			Lcd_SendChar(user_id[i]);
			i++ ;
		}
	}
	_delay_ms(1);
	Lcd_SendCommand(DISPLAY_CLEAR);
	_delay_ms(1);
	Lcd_SendString(lcd_pass);
	_delay_ms(1);
	i=0 ;
	Lcd_SendCommand(0xC0);
	while(i<4)
	{
		pressed=KeyPad_GetPressedKey();
		if(pressed!=0)
		{
			pass_id[i]=pressed;
			Lcd_SendChar(pass_id[i]);
			i++ ;
		}
	}
	_delay_ms(1);
	Lcd_SendCommand(DISPLAY_CLEAR);
	_delay_ms(1);
	Lcd_SendString(finish);
	_delay_ms(1);
	while(KeyPad_GetPressedKey()!='=')
	{

	}

	identify_user() ;

}
void identify_user(void)
{
	for(i=0 ; i<4 ; i++)
	{
		errors=0 ;
		if(pass_id[i]!=user_id[3-i])
		{
			errors=1;
			break ;
		}
		error_counter=0;
	}
	if(errors==1)
	{
		error_counter++ ;
	}
	if(error_counter==0)
	{
		Lcd_SendCommand(DISPLAY_CLEAR);
		Lcd_SendString(hello);
		Dio_WritePin(PHY_PORTB,PIN_7,LOW_LEVEL);
		_delay_ms(300);

		Get_Temp();
	}
	else if(error_counter==1)
	{
		Lcd_SendCommand(DISPLAY_CLEAR);
		Lcd_SendString(reenter1);
		_delay_ms(100);
		Lcd_SendCommand(DISPLAY_CLEAR);
		Lcd_project();
	}
	else if(error_counter==2)
	{
		Lcd_SendCommand(DISPLAY_CLEAR);
		Lcd_SendString(reenter2);
		_delay_ms(100);
		Lcd_SendCommand(DISPLAY_CLEAR);
		Lcd_project();
	}
	else if(error_counter==3)
	{
		Lcd_SendCommand(DISPLAY_CLEAR);
		Lcd_SendString(terminate);
		Dio_WritePin(PHY_PORTB,PIN_7,HIGH_LEVEL);
		_delay_ms(100);
		Lcd_SendCommand(DISPLAY_CLEAR);


	}
}
void Get_Temp(void)
{
	// 1 cold
	// 2 normal
	// 3 warm
	u8 pressed=0 ;
	Lcd_SendCommand(DISPLAY_CLEAR);
	Lcd_SendString(temp);
	Lcd_SendCommand(0xC0);
	Dio_SetPinDirection(PHY_PORTB,PIN_3,OUTPUT_DIRECTION);
	Dio_WritePin(PHY_PORTB,PIN_3,LOW_LEVEL);
	Timer0_Init(&strTimerCfg);
	pressed = KeyPad_GetPressedKey();
	while(pressed==0)
	{
		pressed = KeyPad_GetPressedKey();
	}
	switch(pressed)
	{
	case '1':
		WRITE_REGISTER(REG_OCR0,250);
		Lcd_SendString(temp1);
		Dio_SetPinDirection(PHY_PORTB,PIN_6,OUTPUT_DIRECTION);
		Dio_WritePin(PHY_PORTB,PIN_6,LOW_LEVEL);
		break ;
	case '2' :
		WRITE_REGISTER(REG_OCR0,150);
		Lcd_SendString(temp2);
		break ;
	case '3':
		WRITE_REGISTER(REG_OCR0,50);
		Lcd_SendString(temp3);
		break ;
	}

}


