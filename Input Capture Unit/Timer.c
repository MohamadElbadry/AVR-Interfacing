#include <avr/interrupt.h>
#include "util.h"
#include "REGISTERS.h"
#include"TIMER.h"
#include"Dio.h"

void Timer0_Init(tstrTimerCfg *pstrTimerCfg)
{
	switch(pstrTimerCfg->Mode)
	{
	case NORMAL_MODE :
		CLEAR_BIT(REG_TCCR0,3);
		CLEAR_BIT(REG_TCCR0,6);
		break ;
	case CTC_MODE :
		SET_BIT(REG_TCCR0,3);
		CLEAR_BIT(REG_TCCR0,6);
		break ;
	case FAST_PWM_MODE :
		SET_BIT(REG_TCCR0,3);
		SET_BIT(REG_TCCR0,6);

		// Clear On Compare
		CLEAR_BIT(REG_TCCR0,4);
		SET_BIT(REG_TCCR0,5);
		break ;
	case PHASE_CORRECT_MODE :


		break ;


	default :

		break ;
	}
	switch(pstrTimerCfg->prescaler)
	{
	case NO_PRESCALER :
		SET_BIT(REG_TCCR0,0);
		CLEAR_BIT(REG_TCCR0,1);
		CLEAR_BIT(REG_TCCR0,2);

		break ;
	case PRESCALER_1024 :
		SET_BIT(REG_TCCR0,0);
		CLEAR_BIT(REG_TCCR0,1);
		SET_BIT(REG_TCCR0,2);
		break ;
	case PRESCALER_64 :
		SET_BIT(REG_TCCR0,0);
		SET_BIT(REG_TCCR0,1);
		CLEAR_BIT(REG_TCCR0,2);
		break ;

	default :
		break ;
	}
	// enable glaobal interput
	SET_BIT(REG_SREG,7);

	//enable timer0 interept
	SET_BIT(REG_TIMSK,0);
	WRITE_REGISTER(REG_TCNT0,112);
}
ISR (TIMER0_OVF_vect)
{


	volatile u8 static  counter =0 ;
	counter ++ ;
	if(counter==31)
	{
		TOGGLE_BIT(*((volatile u8*)0x3B),0);
		counter=0 ;
		WRITE_REGISTER(REG_TCNT0,112);

	}
}


