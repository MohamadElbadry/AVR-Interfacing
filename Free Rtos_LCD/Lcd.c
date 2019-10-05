#include "Dio.h"
#include "std_type1.h"
#include <avr/delay.h>
#include "REGISTERS.h"
#include "Lcd.h"

void Lcd_Init(void)
{
	// RS , RW , E output
	Dio_SetPinDirection(PHY_PORTB, PIN_0, OUTPUT_DIRECTION);  //RS
	Dio_SetPinDirection(PHY_PORTB, PIN_1, OUTPUT_DIRECTION);  //RW
	Dio_SetPinDirection(PHY_PORTB, PIN_5, OUTPUT_DIRECTION);  //E


	// Data , output
	Dio_SetPortDirection(PHY_PORTC, OUTPUT_DIRECTION); // Data pins (D0 ~ D7)


	Lcd_SendCommand(DISPLAY_CLEAR);

	Lcd_SendCommand(0x06); // entry mode : AC & Cursor increments by one

	Lcd_SendCommand(0x0F);  //Display ON/OFF: Display ON , Cursor ON,Blinking ON

	Lcd_SendCommand(0x38);   // Function Set : 8 bit mode , 2 lines , 5x7 character size
}

void Lcd_SendChar(u8 Char)
{
	Dio_SetPortDirection(PHY_PORTC, OUTPUT_DIRECTION); // Data pins (D0 ~ D7)

	// RS = 1 // data
	Dio_WritePin(PHY_PORTB, PIN_0, HIGH_LEVEL); // RS

	// RW = 0 // write
	Dio_WritePin(PHY_PORTB, PIN_1 , LOW_LEVEL);  // RW

	// Data
	Dio_WritePort(PHY_PORTC, Char);

	// E
	Dio_WritePin(PHY_PORTB, PIN_5, HIGH_LEVEL);
	_delay_ms(2);
	Dio_WritePin(PHY_PORTB, PIN_5, LOW_LEVEL);


}

void Lcd_SendCommand(u8 Command)
{
	Dio_SetPortDirection(PHY_PORTC, OUTPUT_DIRECTION); // Data pins (D0 ~ D7)

	// RS = 0   // instruction
	Dio_WritePin(PHY_PORTB, PIN_0, LOW_LEVEL); // RS

	// RW = 0   // write
	Dio_WritePin(PHY_PORTB, PIN_1 , LOW_LEVEL);  // RW

	// Data
	Dio_WritePort(PHY_PORTC, Command);

	// E
	Dio_WritePin(PHY_PORTB, PIN_5, HIGH_LEVEL);
	_delay_ms(2);
	Dio_WritePin(PHY_PORTB, PIN_5, LOW_LEVEL);



}
void Lcd_WritePattern(u8 address , u8 *pattern)
{
	u8 i=0 ;
	Lcd_SendCommand(address); // adress=0x40 1st place in CGRAM
	for(i=0;i<8;i++)
	{
		Lcd_SendChar(pattern[i]);
	}

}
void Lcd_SendString(u8 *ptr)
{
	u8 count=0  ;
	while(*(ptr+count)!=0)
	{
		Lcd_SendChar(*(ptr+count));
		count++ ;
	}
}
/*
void Lcd_CheckAC(void)
{
	u8 static AC=0 ;

	// RS = 0 // instruction
	Dio_WritePin(PHY_PORTB, PIN_0,LOW_LEVEL ); // RS

	// RW = 1 // Read
	Dio_WritePin(PHY_PORTB, PIN_1 , HIGH_LEVEL);  // RW

	Dio_SetPortDirection(PHY_PORTC, INPUT_DIRECTION); // Data pins (D0 ~ D7)
	// E
	Dio_WritePin(PHY_PORTB, PIN_5, HIGH_LEVEL);

	_delay_us(40);

	AC=Dio_ReadPort(PHY_PORTC)&0b01111111 ;

	Dio_WritePin(PHY_PORTB, PIN_5, LOW_LEVEL);

	Lcd_SendChar(AC);

	if(AC==0b00010101)
	{
		Lcd_SendCommand(0xC0);
		Lcd_SendChar('a');


	}


	AC++ ;
	if(AC==8)
	{
		Lcd_SendCommand(0xC0);
	}

}
 */

