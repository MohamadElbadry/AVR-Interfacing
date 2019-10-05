/*
 * main.c
 *
 *  Created on: Jul 12, 2019
 *      Author: medos
 */

#include "Dio.h"
#include "util.h"
#include "REGISTERS.h"
#include "std_type1.h"
#include "Tasks_definition.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

int  main(void)
{
	xTaskCreate(led1 , NULL , configMINIMAL_STACK_SIZE,NULL,3,NULL);
	xTaskCreate(led2 , NULL , configMINIMAL_STACK_SIZE,NULL,2,NULL);
	xTaskCreate(led3 , NULL , configMINIMAL_STACK_SIZE,NULL,1,NULL);
	vTaskStartScheduler();
while(1)
{

}
return 0 ;

}

