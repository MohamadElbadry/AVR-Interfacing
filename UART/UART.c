#include"UART.h"
#include"util.h"
#include"REGISTERS.h"
#include"Dio.h"
#include"std_type1.h"

void UART_INIT(void)
{

	// CHARACTER SIZE
	SET_BIT(REG_UCSRC,1);
	SET_BIT(REG_UCSRC,2);
	CLEAR_BIT(REG_UCSRB,2);

	// no parity
	CLEAR_BIT(REG_UCSRC,4);
	CLEAR_BIT(REG_UCSRC,5);

	// stop bit
	CLEAR_BIT(REG_UCSRC,3);

	// asynch
	CLEAR_BIT(REG_UCSRC,6);

	// polling disable all
	CLEAR_BIT(REG_UCSRB,7);
	CLEAR_BIT(REG_UCSRB,6);
	CLEAR_BIT(REG_UCSRB,5);

	//enable TX RX
	SET_BIT(REG_UCSRB,4);
	SET_BIT(REG_UCSRB,3);

	Dio_SetPinDirection(PHY_PORTD,PIN_0,INPUT_DIRECTION);
	Dio_SetPinDirection(PHY_PORTD,PIN_1,OUTPUT_DIRECTION);

	// baud rRate
	CLEAR_BIT(REG_UCSRA,1);
	WRITE_REGISTER(REG_UBRRH,0);
	WRITE_REGISTER(REG_UBRRL,51);

}

void UART_TX(u8 data)
{

	while(GET_BIT(REG_UCSRA,5)==0)
	{

	}
	WRITE_REGISTER(REG_UDR,data);
}
u8 UART_RX(void)
{
	u8 data ;
	while((GET_BIT(REG_UCSRA,7))==0)
			{

			}
	data=GET_REGISTER(REG_UDR);


	return data ;
}


