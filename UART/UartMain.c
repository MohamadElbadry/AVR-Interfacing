#include"UART.h"
#include"Dio.h"
#include"std_type1.h"

int main(void)
{
	Dio_SetPinDirection(PHY_PORTA,PIN_0,OUTPUT_DIRECTION);
	UART_INIT();
	while(1)
	{
		u8 data ;
		data=UART_RX();
		if(data=='5')
		{
			Dio_WritePin(PHY_PORTA,PIN_0,HIGH_LEVEL);
		}
		else if(data=='6')
		{
			Dio_WritePin(PHY_PORTA,PIN_0,LOW_LEVEL);

		}
	}
	return 0 ;
}


