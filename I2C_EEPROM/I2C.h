/*
 * I2C.h
 *
 *  Created on: Jun 21, 2019
 *      Author: medos
 */

#ifndef I2C_H_
#define I2C_H_
#include"std_type1.h"

#define MASTER 1
#define SLAVE 0

#define I2C MASTER

void Init_Master(void);
void Init_Slave(void);
void Start_Condition (void);
void Stop_Condition (void);
void Send_Slave_Adress_Read(u8 address);
void Send_Slave_Adress_Write(u8 address);
void Send_Data(u8 data);
void Slave_Listen(void);
void I2C_Reapeted_Start(void);
u8 Received_Data(u8 ack);
#endif /* I2C_H_ */
