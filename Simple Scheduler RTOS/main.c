/*
 * main.c
 *
 *  Created on: Jul 6, 2019
 *      Author: medos
 */
#include"REGISTERS.h"
#include"std_type1.h"
#include"Dio.h"
#include"Timer.h"
#include"7segment.h"
#include<avr/delay.h>
#define num_of_tasks 5

void Tasks_Creation(u8 priority , u8 periodicity ,void (*Fptr)(void) ) ;
void func1(void);
void func2(void);
void func3(void);
void func4(void);
void func5(void);

u32 extern  counter ;

u8 i ;
u8  j ;

typedef struct
{
	u8 periodicity;
	void (*Fptr)(void);
}Tasks;

Tasks arr[num_of_tasks] ;

////////////////////////////////////////

int main()
{
	Dio_SetPortDirection(PHY_PORTA,OUTPUT_DIRECTION);
	Dio_SetPortDirection(PHY_PORTD,OUTPUT_DIRECTION);
	Dio_SetPortDirection(PHY_PORTC,OUTPUT_DIRECTION);

	Timer1_Init();
	Tasks_Creation(0,3,&func1);
	Tasks_Creation(1,5,&func2);
	Tasks_Creation(2,7,&func3);
	Tasks_Creation(3,9,&func4);
	Tasks_Creation(4,11,&func5);
	WRITE_REGISTER(REG_OCR1AH,0x7A);
	WRITE_REGISTER(REG_OCR1AL,0x12);

	while(1)
	{
		for( ; j<=10 ;)
		{
			if(j==10)
			{
				j=1 ;
			}
			WRITE_REGISTER(REG_PORTD,Arr_DecToSeg[j]);

		}

	}

	return 0 ;
}
//////////////////////////////////////////////////////////

void Tasks_Creation(u8 priority , u8 periodicity ,void (*Fptr)(void) )
{
	arr[priority].periodicity=periodicity ;
	arr[priority].Fptr = Fptr ;
}

void Scheduler (void)
{
	j++;
	u8 i ;
	for(i=0 ; i < num_of_tasks ; i++)
	{
		if((counter % arr[i].periodicity) == 0)
		{
			arr[i].Fptr() ;
		}

	}


}
void func1(void)
{
	TOGGLE_BIT(REG_PORTA,0);

}
void func2(void)
{
	TOGGLE_BIT(REG_PORTA,1);
}
void func3(void)
{
	TOGGLE_BIT(REG_PORTA,2);
}
void func4(void)
{
	TOGGLE_BIT(REG_PORTA,3);
}
void func5(void)
{
	TOGGLE_BIT(REG_PORTA,4);
}

