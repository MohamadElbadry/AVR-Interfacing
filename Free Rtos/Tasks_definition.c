/*
 * Tasks_definition.c
 *
 *  Created on: Jul 12, 2019
 *      Author: medos
 */
#include "Dio.h"
#include "util.h"
#include "REGISTERS.h"
#include "std_type1.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Tasks_definition.h"

void led1 (void *pv)
{
	Dio_SetPinDirection(PHY_PORTA,PIN_0,OUTPUT_DIRECTION) ;
	while(1)
	{
		TOGGLE_BIT(REG_PORTA,0);
		vTaskDelay(1);

	}

}


void led2 (void *pv)
{
	Dio_SetPinDirection(PHY_PORTA,PIN_1,OUTPUT_DIRECTION) ;
	while(1)
	{
		TOGGLE_BIT(REG_PORTA,1);
		vTaskDelay(2);
	}

}

void led3 (void *pv)
{
	Dio_SetPinDirection(PHY_PORTA,PIN_2,OUTPUT_DIRECTION) ;
	while(1)
	{
		TOGGLE_BIT(REG_PORTA,2);
		vTaskDelay(3);
	}

}
