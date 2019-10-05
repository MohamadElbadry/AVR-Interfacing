#include"util.h"
#include"I2C.h"
#include"REGISTERS.h"
#include"std_type1.h"
#include "Dio.h"
static u8 Get_status(void);

static u8 Get_status(void)
{
	u8 status ;
	status=GET_REGISTER(REG_TWSR);
	status= status & 0xF8 ;
	return status ;
}
void Init_Master(void)
{
	// Enable I2C
	SET_BIT(REG_TWCR,2);

	//Frequency  F= (Fosc)/(16+2*(TWBR)*4^TWPS)= 200K
	//Prescaler 0

	CLEAR_BIT(REG_TWSR,1);
	CLEAR_BIT(REG_TWSR,0);
	//TWBS=12
	WRITE_REGISTER(REG_TWBR,12);
}

void Init_Slave(void)
{
	u8 slave = 0b00000010 ;
	// Enable I2C
	SET_BIT(REG_TWCR,2);

	//set address address    0000001
	REG_TWAR= (REG_TWAR & 0x01) | slave ;


}

//master wants to transmitt
void Start_Condition (void)
{
/*	u8 status ;*/

	REG_TWCR=(1<<7)|(1<<5)|(1<<2);

	while((GET_BIT(REG_TWCR,7)) == 0) ;


	/*status=Get_status();
	if(0x08==status)
	{
		// error
	}*/
}

// master wants to end communication
void Stop_Condition (void)
{
	REG_TWCR=(1<<7)|(1<<2)|(1<<4);
}

void Send_Slave_Adress_Read(u8 address)
{
	// address to enable general call recognition 00000001 <<1 = 00000001(0) write
	REG_TWDR= (address<<1) | (0x01) ;
	// data must be written will flag=1 to avoid collision
	REG_TWCR= (1<<7) | (1<<2) ;
	while((GET_BIT(REG_TWCR,7)) == 0);

	if(0x20==(Get_status()))
	{
		// error
	}
}


void Send_Slave_Adress_Write(u8 address)
{

	// address to enable general call recognition 00000001 <<1 = 00000001(0) write
	REG_TWDR= address<<1 ;
	// address must be written will flag=1 to avoid collision
	//data transmit with in flag cleared
	REG_TWCR= (1<<7) | (1<<2) ;
	while((GET_BIT(REG_TWCR,7)) == 0);

	if(0x18==(Get_status()))
	{
		// error
	}
}


void Send_Data(u8 data)
{
	REG_TWDR=data ;
	// data must be written will flag=1 to avoid collision
	//data transmit with in flag cleared
	REG_TWCR= (1<<7) | (1<<2) ;
	while((GET_BIT(REG_TWCR,7)) == 0);
	if(0x28==(Get_status()))
	{
		// error
	}
}

u8 Received_Data(u8 ack)
{
	if(1==ack)
	{
		// flag has been 1 you need to clear to know when data received
		REG_TWCR=(1<<7)|(1<<2)|(1<<6);
		while((GET_BIT(REG_TWCR,7)) == 0);
		if(0x50==(Get_status()))
		{
			// error
		}
		return REG_TWDR;
	}
	else if(0==ack)
	{
		REG_TWCR=(1<<7)|(1<<2);
		while((GET_BIT(REG_TWCR,7)) == 0);
		if(0x48==(Get_status()))
		{
			// error
		}
		return REG_TWDR;
	}
	else
	{
		//error
	}

}

void Slave_Listen(void)
{
	// only need to enable acknowledge comparing is made by hardware
	REG_TWCR=(1<<7)|(1<<6)|(1<<2);
}


void I2C_Reapeted_Start(void)
{
	u8 status ;
	REG_TWCR=(1<<7)|(1<<5)|(1<<2);
	while((GET_BIT(REG_TWCR,7)) == 0);
	status=Get_status();
	if(0x10==status)
	{
		// error
	}

}
