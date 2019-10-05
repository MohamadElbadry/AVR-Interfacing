#include "Dio.h"

#include "util.h"
#include "registers.h"

void Dio_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
	switch(Port)
	{
	case PHY_PORTA:
		if(Direction == INPUT_DIRECTION)
		{
			CLEAR_BIT(REG_DDRA, Pin);
			SET_BIT(REG_PORTA, Pin);
		}
		else if(Direction == OUTPUT_DIRECTION)
		{
			SET_BIT(REG_DDRA, Pin);
		}
		break;
	case PHY_PORTB:
		if(Direction == INPUT_DIRECTION)
		{
			CLEAR_BIT(REG_DDRB, Pin);
			SET_BIT(REG_PORTB, Pin);

		}
		else if(Direction == OUTPUT_DIRECTION)
		{
			SET_BIT(REG_DDRB, Pin);
		}

		break;
	case PHY_PORTC:
		if(Direction == INPUT_DIRECTION)
		{
			CLEAR_BIT(REG_DDRC, Pin);
			SET_BIT(REG_PORTC, Pin);

		}
		else if(Direction == OUTPUT_DIRECTION)
		{
			SET_BIT(REG_DDRC, Pin);
		}

		break;
	case PHY_PORTD:
		if(Direction == INPUT_DIRECTION)
		{
			CLEAR_BIT(REG_DDRD, Pin);
			SET_BIT(REG_PORTD, Pin);

		}
		else if(Direction == OUTPUT_DIRECTION)
		{
			SET_BIT(REG_DDRD, Pin);
		}

		break;
	default:
		break;
	}
}

void Dio_WritePin(u8 Port, u8 Pin, u8 Level)  // level is for high or low 0 or 1
{
	switch(Port)
	{
	case PHY_PORTA:
		if(Level == HIGH_LEVEL)
		{
			SET_BIT(REG_PORTA, Pin);
		}
		else if(Level == LOW_LEVEL)
		{
			CLEAR_BIT(REG_PORTA, Pin);
		}
		break;
	case PHY_PORTB:
		if(Level == HIGH_LEVEL)
		{
			SET_BIT(REG_PORTB, Pin);
		}
		else if(Level == LOW_LEVEL)
		{
			CLEAR_BIT(REG_PORTB, Pin);
		}
		break;
	case PHY_PORTC:
		if(Level == HIGH_LEVEL)
		{
			SET_BIT(REG_PORTC, Pin);
		}
		else if(Level == LOW_LEVEL)
		{
			CLEAR_BIT(REG_PORTC, Pin);
		}
		break;
	case PHY_PORTD:
		if(Level == HIGH_LEVEL)
		{
			SET_BIT(REG_PORTD, Pin);
		}
		else if(Level == LOW_LEVEL)
		{
			CLEAR_BIT(REG_PORTD, Pin);
		}
		break;
	default:
		break;
	}

}

u8 Dio_ReadPin(u8 Port, u8 Pin)
{
	u8 PinLevel;
	switch(Port)
	{
	case PHY_PORTA:
		PinLevel = GET_BIT(REG_PINA, Pin);

		break;
	case PHY_PORTB:
		PinLevel = GET_BIT(REG_PINB, Pin);
		break;
	case PHY_PORTC:
		PinLevel = GET_BIT(REG_PINC, Pin);
		break;
	case PHY_PORTD:
		PinLevel = GET_BIT(REG_PIND, Pin);
		break;
	}

	return PinLevel;
}

void Dio_SetPortDirection(u8 Port, u8 Direction)
{
	switch(Port)
	{
	case PHY_PORTA:
		if(Direction == INPUT_DIRECTION)
		{
			CLEAR_REGISTER_BITS(REG_DDRA);
			SET_REGISTER_BITS(REG_PORTA);
		}
		else if(Direction == OUTPUT_DIRECTION)
		{
			SET_REGISTER_BITS(REG_DDRA);
		}
		break;
	case PHY_PORTB:
		if(Direction == INPUT_DIRECTION)
		{
			CLEAR_REGISTER_BITS(REG_DDRB);
			SET_REGISTER_BITS(REG_PORTB);
		}
		else if(Direction == OUTPUT_DIRECTION)
		{
			SET_REGISTER_BITS(REG_DDRB);
		}

		break;
	case PHY_PORTC:
		if(Direction == INPUT_DIRECTION)
		{
			CLEAR_REGISTER_BITS(REG_DDRC);
			SET_REGISTER_BITS(REG_PORTC);
		}
		else if(Direction == OUTPUT_DIRECTION)
		{
			SET_REGISTER_BITS(REG_DDRC);
		}

		break;
	case PHY_PORTD:
		if(Direction == INPUT_DIRECTION)
		{
			CLEAR_REGISTER_BITS(REG_DDRD);
			SET_REGISTER_BITS(REG_PORTD);
		}
		else if(Direction == OUTPUT_DIRECTION)
		{
			SET_REGISTER_BITS(REG_DDRD);
		}

		break;
	default:
		break;
	}
}

void Dio_WritePort(u8 Port, u8 Value)
{
	switch(Port)
	{
	case PHY_PORTA:
		WRITE_REGISTER(REG_PORTA,Value);
		break;
	case PHY_PORTB:
		WRITE_REGISTER(REG_PORTB,Value);
		break;
	case PHY_PORTC:
		WRITE_REGISTER(REG_PORTC,Value);
		break;
	case PHY_PORTD:
		WRITE_REGISTER(REG_PORTD,Value);
		break;
	default:
		break;
	}
}

u8 Dio_ReadPort(u8 Port)
{
	u8 Portvalue;
	switch(Port)
	{
	case PHY_PORTA:
		Portvalue = GET_REGISTER(PHY_PORTA);
		break;
	case PHY_PORTB:
		Portvalue = GET_REGISTER(PHY_PORTB);
		break;
	case PHY_PORTC:
		Portvalue = GET_REGISTER(PHY_PORTC);
		break;
	case PHY_PORTD:
		Portvalue = GET_REGISTER(PHY_PORTD);
		break;
	}

	return Portvalue;
}

