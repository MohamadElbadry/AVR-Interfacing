/*
 * EEPROM.c
 *
 *  Created on: Jun 22, 2019
 *      Author: medos
 */
#include"I2C.h"
#include"std_type1.h"
#include"EEPROM.h"
#include "Dio.h"
void EEPROM_INIT(void)
{
	Init_Master();
}
void EEPROM_WriteData(u16 blocknumber, u8 data)
{

	u8 sectornumber , byteaddress ;

	Start_Condition();

	sectornumber= blocknumber/256 ;
	byteaddress=blocknumber%256;

	Send_Slave_Adress_Write(0b01010100| sectornumber);
	Send_Data(byteaddress);
	Send_Data(data);
	Stop_Condition();

}

u8 EEPROM_ReceiveData(u16 blocknumber)
{
	u8 data ;
	u8 sectornumber , byteaddress ;
	Start_Condition();
	sectornumber= blocknumber/256 ;
	byteaddress=blocknumber%256;

	Send_Slave_Adress_Write(0b01010100| sectornumber);
	Send_Data(byteaddress);

	I2C_Reapeted_Start();

	Send_Slave_Adress_Read(0b01010100| sectornumber);

	data=Received_Data(0);

	Stop_Condition();
return data ;
}
