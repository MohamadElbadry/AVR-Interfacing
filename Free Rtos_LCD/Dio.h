/*
 * DIO.h
 *
 *  Created on: Apr 12, 2019
 *      Author: medos
 */

#ifndef DIO_H_
#define DIO_H_
#include"std_type1.h"
#include"util.h"
#include"REGISTERS.h"
void Dio_SetPinDirection(u8 port , u8 pin , u8 direction ) ;
void Dio_WritePin(u8 port , u8 pin , u8 level );
u8 Dio_ReadPin(u8 port , u8 pin  );
void Dio_SetPortDirection(u8 port ,  u8 direction );
void Dio_WritePort(u8 port , u8 level );
u8 Dio_ReadPort(u8 port );
#define PHY_PORTA 1
#define PHY_PORTB 2
#define PHY_PORTC 3
#define PHY_PORTD 4
#define INPUT_DIRECTION 0
#define OUTPUT_DIRECTION 1
#define HIGH_LEVEL  1
#define LOW_LEVEL   0
#define PIN_0  0
#define PIN_1  1
#define PIN_2  2
#define PIN_3  3
#define PIN_4  4
#define PIN_5  5
#define PIN_6  6
#define PIN_7  7

#endif /* DIO_H_ */
