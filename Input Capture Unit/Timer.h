
#ifndef TIMER_H_
#define TIMER_H_

typedef enum
{
	NORMAL_MODE ,
	CTC_MODE,
	FAST_PWM_MODE,
	PHASE_CORRECT_MODE
}tenuTimer_Mode;
typedef enum
{
	NO_PRESCALER=0 ,
	PRESCALER_8=8 ,
	PRESCALER_16 =16,
	PRESCALER_64 = 64,
	PRESCALER_256 =256,
	PRESCALER_1024 =1024,
}tenuTimer_Prescaler;
typedef struct
{
	tenuTimer_Mode Mode ;
	tenuTimer_Prescaler prescaler ;
}tstrTimerCfg;


void Timer0_Init(tstrTimerCfg *pstrTimerCfg) ;
void Timer0_Clb();

#endif /* TIMER_H_*/

