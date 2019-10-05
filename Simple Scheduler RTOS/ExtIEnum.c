
#include<avr/interrupt.h>
#include"ExtIEnum.h"
#include"REGISTERS.h"
#include"util.h"
#include<avr/delay.h>
/*#include"Lcd_Project.h"*/
void ExtI_Init(void)
{

	// Enable globla interrupt mask
	SET_BIT(REG_SREG, 7);

	// Activate pull up resistor -> SFIOR.PUD = 0
	CLEAR_BIT(REG_SFIOR, 2);

}
#if INT_0==ENABLE
void ExtI0_Init(tstrInterruptCfg *pstrInterruptCfg)
{
	// Set PD2 to input direction
	CLEAR_BIT(REG_DDRD , 2);

	// Activate pull up resistor of INT0 (PD2)
	SET_BIT(REG_PORTD, 2);

	//Enable INT0 interrupt mask
	SET_BIT(REG_GICR, 6);

	switch(pstrInterruptCfg -> level)
	{
	case LOW_LEVEL_0 :
		CLEAR_BIT(REG_MCUCR, 0);
		CLEAR_BIT(REG_MCUCR, 1);
		break ;
	case FALLING_EDGE :
		CLEAR_BIT(REG_MCUCR, 0);
		SET_BIT(REG_MCUCR, 1);
		break ;
	case RAISING_EDGE :
		SET_BIT(REG_MCUCR, 0);
		SET_BIT(REG_MCUCR, 1);
		break ;
	case CHANGE :
		CLEAR_BIT(REG_MCUCR, 1);
		SET_BIT(REG_MCUCR, 0);
		break ;
	}

}
#endif
#if INT_1==ENABLE
void ExtI1_Init(tstrInterruptCfg *pstrInterruptCfg)
{

	// Set PORTD3 to input direction
	CLEAR_BIT(REG_DDRD ,3);

	// Activate pull up resistor of INT1 (PORTD3)
	SET_BIT(REG_PORTD, 3);

	//Enable INT1 interrupt mask
	SET_BIT(REG_GICR, 7);

	switch(pstrInterruptCfg -> level)
	{
	case FALLING_EDGE :
		CLEAR_BIT(REG_MCUCR, 2);
		SET_BIT(REG_MCUCR, 3);
		break ;
	case RAISING_EDGE :
		SET_BIT(REG_MCUCR, 2);
		SET_BIT(REG_MCUCR, 3);
		break ;
	case CHANGE :
		CLEAR_BIT(REG_MCUCR, 3);
		SET_BIT(REG_MCUCR, 2);
		break ;
	case LOW_LEVEL_0 :
		CLEAR_BIT(REG_MCUCR, 2);
		CLEAR_BIT(REG_MCUCR, 3);
		break ;

	}
}
#endif
#if INT_2==ENABLE
void ExtI2_Init(tstrInterruptCfg *pstrInterruptCfg)
{
	// Set PORTB3 to input direction
	CLEAR_BIT(REG_DDRB ,3);

	// Activate pull up resistor of INT0 (PORTB3)
	SET_BIT(REG_PORTB, 3);

	//Enable INT2 interrupt mask
	SET_BIT(REG_GICR, 5);

	switch(pstrInterruptCfg -> level)
	{
	case FALLING_EDGE :
		CLEAR_BIT(REG_MCUCSR, 6);
		break ;
	case RAISING_EDGE :
		SET_BIT(REG_MCUCSR, 6);
		break ;
	}
}
#endif

ISR(INT0_vect)
{
/*	Lcd_project();*/


}

ISR(INT1_vect)
{
/*	Get_Temp();*/

}

ISR(INT2_vect)
{
	SET_BIT(REG_DDRC,0);
	TOGGLE_BIT(REG_PORTC,0);
}

