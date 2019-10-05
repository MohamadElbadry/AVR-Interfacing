/*
 * UART.h
 *
 *  Created on: Jun 14, 2019
 *      Author: medos
 */

#ifndef UART_H_
#define UART_H_
#include"std_type1.h"
void UART_TX(u8 data);
u8 UART_RX(void);
void UART_INIT(void);

#endif /* UART_H_ */
