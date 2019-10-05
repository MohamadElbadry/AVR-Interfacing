#include <avr/interrupt.h>
#include "util.h"
#include "REGISTERS.h"
#include"TIMER.h"
#include"Dio.h"
#include "REG_BITS.h"
// Timer0_Init is a function taking a pointer to structure to decide mode
void Timer0_Init(tstrTimerCfg *pstrTimerCfg)
{
	switch(pstrTimerCfg->Mode)
	{
	// count till it reaches the top
	case NORMAL_MODE :
		CLEAR_BIT(REG_TCCR0,WGM01);
		CLEAR_BIT(REG_TCCR0,WGM00);
		break ;
		//count till it equals OCR0 then cleared
	case CTC_MODE :
		SET_BIT(REG_TCCR0,WGM01);
		CLEAR_BIT(REG_TCCR0,WGM00);
		break ;
		//count till it equals OCR0 and set OC0 to ground and to HIGH when reach top
	case FAST_PWM_MODE :
		SET_BIT(REG_TCCR0,WGM01);
		SET_BIT(REG_TCCR0,WGM00);
		// Clear On Compare
		CLEAR_BIT(REG_TCCR0,COM00);
		SET_BIT(REG_TCCR0,COM01);
		break ;

	case PHASE_CORRECT_MODE :
		SET_BIT(REG_TCCR0,WGM00);
		SET_BIT(REG_TCCR0,WGM01);
		// Clear On Compare
		CLEAR_BIT(REG_TCCR0,COM00);
		SET_BIT(REG_TCCR0,COM01);
		break ;


	default :

		break ;
	}
	switch(pstrTimerCfg->prescaler)
	{
	case NO_PRESCALER :
		SET_BIT(REG_TCCR0,CS00);
		CLEAR_BIT(REG_TCCR0,CS01);
		CLEAR_BIT(REG_TCCR0,CS02);

		break ;
	case PRESCALER_8 :
		CLEAR_BIT(REG_TCCR0,CS00);
		SET_BIT(REG_TCCR0,CS01);
		CLEAR_BIT(REG_TCCR0,CS02);
		break ;
	case PRESCALER_64 :
			SET_BIT(REG_TCCR0,CS00);
			SET_BIT(REG_TCCR0,CS01);
			CLEAR_BIT(REG_TCCR0,CS02);
			break ;
	case PRESCALER_256 :
			SET_BIT(REG_TCCR0,CS00);
			CLEAR_BIT(REG_TCCR0,CS01);
			CLEAR_BIT(REG_TCCR0,CS02);
			break ;

	case PRESCALER_1024 :
		SET_BIT(REG_TCCR0,CS00);
		CLEAR_BIT(REG_TCCR0,CS01);
		SET_BIT(REG_TCCR0,CS02);
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


