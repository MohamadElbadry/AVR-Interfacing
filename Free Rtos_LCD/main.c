/*
 * main.c
 *
 *  Created on: Jul 12, 2019
 *      Author: medos
 */
#include "std_type1.h"
#include "util.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "semphr.h"
#include "queue.h"
#include "Dio.h"
#include "Lcd.h"
#include "keypad.h"
#define x 200

/*
xSemaphoreHandle lcd_semaphor ;

void task1 (void *pv)
{
	u8 flag ;
	u8 arr[]={'I',' ','a','m',' ','f','u','n','c','t','i','o','n',' ','1',0};
	while(1)
	{
		flag = xSemaphoreTake(lcd_semaphor,20) ;
		if(flag== pdPASS)
		{
			Lcd_SendCommand(DISPLAY_CLEAR);
			Lcd_SendString(arr) ;
			xSemaphoreGive(lcd_semaphor);
		}

		vTaskDelay(3000) ;


	}
}


void task2 (void *pv)
{
	u8 arr[]={'I',' ','a','m',' ','f','u','n','c','t','i','o','n',' ','2',0};
	u8 flag ;
	while(1)
	{
		flag = xSemaphoreTake(lcd_semaphor,20);
		if(flag== pdPASS)
		{
			Lcd_SendCommand(DISPLAY_CLEAR);
			Lcd_SendString(arr) ;
			xSemaphoreGive(lcd_semaphor);
		}

		vTaskDelay(3000) ;

	}
}

int  main(void)
{
	Lcd_Init();
	xTaskCreate(task1,NULL,300,NULL,1,NULL) ;
	xTaskCreate(task2,NULL,300,NULL,1,NULL) ;
	vSemaphoreCreateBinary(lcd_semaphor) ;
	vTaskStartScheduler() ;


	while(1)
	{

	}
	return 0 ;
}
 */

xQueueHandle mail_box ;

void Task_1(void *pv)
{
	u8 flag1 ;
	u8 button ;
	KeyPad_Init();
	Dio_SetPinDirection(PHY_PORTD,PIN0,OUTPUT_DIRECTION);
	Dio_SetPinDirection(PHY_PORTD,PIN2,OUTPUT_DIRECTION);

	while(1)
	{
		/*
		flag1 = xQueueReceive(mail_box,&button,3) ;
		if(flag1==pdPASS)
		{
			if(button==50)
			{
				Dio_WritePin(PHY_PORTA,PIN0,HIGH_LEVEL);
			}
			else if (button==20)
			{
				Dio_WritePin(PHY_PORTA,PIN0,LOW_LEVEL);
			}
		}*/
		button =  KeyPad_GetPressedKey();
		if(button==0)
		{
			TOGGLE_BIT(REG_PORTD,PIN2);
		}
		else
		{
			flag1 = xQueueSend(mail_box,&button,100);
		}
		if(flag1==pdPASS)
		{
			Dio_WritePin(PHY_PORTD,PIN0,HIGH_LEVEL);
		}
		else if (flag1==pdFAIL)
		{
			TOGGLE_BIT(REG_PORTD,PIN0);
		}


		vTaskDelay(100) ;
	}

}


void Task_2(void *pv)
{
	u8 flag1 ;
	u8 button ;
	Lcd_Init();
	Dio_SetPinDirection(PHY_PORTD,PIN1,OUTPUT_DIRECTION);
	while(1)
	{
		/*if(flag==0)
		{
		if(Dio_ReadPin(PHY_PORTB,PIN7)==1)
		{
			flag =1 ;
		}
		}
		else if (Dio_ReadPin(PHY_PORTB,PIN7)==0)
		{
			flag=0 ;
		}
		else
		{
			flag=2 ;
		}

		if(flag==1)
		{
			button = 20 ;
			flag1 = xQueueSend(mail_box , &button , 50) ;
			if(flag1==pdPASS)
			{
				Dio_WritePin(PHY_PORTA,PIN1,HIGH_LEVEL);
				_delay_ms(x);
			}
			else if (flag1==pdFAIL)
			{
				Dio_WritePin(PHY_PORTA,PIN1,HIGH_LEVEL);
				_delay_ms(x);
			}
		}
		else if (flag==0)
		{
			button = 50 ;
			flag1 = xQueueSend(mail_box , &button , 50) ;
			if(flag1==pdPASS)
			{
				Dio_WritePin(PHY_PORTA,PIN1,HIGH_LEVEL);
			}
			else if (flag1==pdFAIL)
			{
				Dio_WritePin(PHY_PORTA,PIN1,HIGH_LEVEL);
			}
		}
		 */
		/*
		while(Dio_ReadPin(PHY_PORTB,PIN7)==1)

		{
			button =50 ;
			xQueueSend(mail_box , &button , 3) ;
			while(Dio_ReadPin(PHY_PORTB,PIN7)==1)
			{

			}
		}
		while(Dio_ReadPin(PHY_PORTB,PIN7)==0)
		{
			button =20 ;
			xQueueSend(mail_box , &button , 3) ;
			while(Dio_ReadPin(PHY_PORTB,PIN7)==0)
			{

			}

		}*/

		flag1 = xQueueReceive(mail_box,&button,100);
		if(flag1==pdPASS)
		{
			Lcd_SendChar(button);
			Dio_WritePin(PHY_PORTD,PIN1,HIGH_LEVEL);
		}
		else if(flag1==pdFAIL)
		{
			TOGGLE_BIT(REG_PORTD,PIN1);
		}

		vTaskDelay(1000);
	}
}




void main (void)
{
	xTaskCreate(Task_1,NULL,500,NULL,1,NULL) ;
	xTaskCreate(Task_2,NULL,500,NULL,1,NULL) ;
	mail_box = xQueueCreate(5,sizeof(u8));
	vTaskStartScheduler() ;
	while(1)
	{

	}
}
