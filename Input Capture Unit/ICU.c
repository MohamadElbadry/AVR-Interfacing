
#include"ICU.h"
#include"util.h"
#include"REGISTERS.h"
#include"std_type1.h"
#include<avr/interrupt.h>

u32 overflowcounter=0 ;
volatile u8 counter=0 ;
u32 Ton , Ttot ;
u32 T1 , T2 , T3 ;

void Icu_Init(void)
{
	// Prescaler Timer 1  // precsaler = 64
	SET_BIT(REG_TCCR1B,0);
	SET_BIT(REG_TCCR1B,1);
	CLEAR_BIT(REG_TCCR1B,2);

	// ICP INPUT
	CLEAR_BIT(REG_DDRD,6);

	//TIMER 1 NORMAL mode
	CLEAR_BIT(REG_TCCR1A,0);
	CLEAR_BIT(REG_TCCR1A,1);
	CLEAR_BIT(REG_TCCR1B,3);
	CLEAR_BIT(REG_TCCR1B,4);

	// RISING EDGE
	SET_BIT(REG_TCCR1B,6);

	// Enable Global interrupt mask
	SET_BIT(REG_SREG, 7);

	// ENable input Capture flag interrupt
	SET_BIT(REG_TIMSK,5);

	// Enable Over flow interrupt
	SET_BIT(REG_TIMSK,2);

}

void Icu_GetDutyCycle(u8 *ptrDutyCycle)
{

	if(3==counter)
	{
		*ptrDutyCycle=(Ton*100)/(Ttot);

		// counter to 0
		counter=0 ;
		// Clear flag
		SET_BIT(REG_TIFR,5);

		// ENable input Capture interrupt
		SET_BIT(REG_TIMSK,5);



	}
	else
	{
		*ptrDutyCycle=255;
	}




}


ISR(TIMER1_OVF_vect)
{
	overflowcounter++ ;

}

ISR(TIMER1_CAPT_vect)
{


	if(0==counter)
	{
		//T1
		T1=GET_REGISTER(REG_ICR1L)|((u16)GET_REGISTER(REG_ICR1H<<8));
		CLEAR_BIT(REG_TCCR1B,6);
		counter=1;
		overflowcounter=0;

	}
	else if(1==counter)
	{

		// T2
		T2=GET_REGISTER(REG_ICR1L)|((u16)GET_REGISTER(REG_ICR1H<<8));
		SET_BIT(REG_TCCR1B,6);
		counter=2;

		Ton=(T2+(overflowcounter*65536))-T1 ;
	}
	else if(2==counter)
	{
		T3=GET_REGISTER(REG_ICR1L)|((u16)GET_REGISTER(REG_ICR1H<<8));
		// ENable input Capture interrupt
		CLEAR_BIT(REG_TIMSK,5);


		Ttot=(T3+(overflowcounter*65536))-T1 ;
		counter=3;
	}

}
