/*
 * EEPROM.h
 *
 *  Created on: Jun 22, 2019
 *      Author: medos
 */

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_INIT(void);
void EEPROM_WriteData(u16 blocknumber, u8 data);
u8 EEPROM_ReceiveData(u16 blocknumber);


#endif /* EEPROM_H_ */
