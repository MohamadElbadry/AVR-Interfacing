

#ifndef REGISRES_H_
#define REGISRES_H_

#include"std_type1.h"

#define REG_PORTA *((volatile u8*)0x3B)
#define REG_DDRA  *((volatile u8*)0x3A)
#define REG_PINA  *((volatile u8*)0x39)

#define REG_PORTB *((volatile u8*)0x38)
#define REG_DDRB  *((volatile u8*)0x37)
#define REG_PINB  *((volatile u8*)0x36)

#define REG_PORTC *((volatile u8*)0x35)
#define REG_DDRC  *((volatile u8*)0x34)
#define REG_PINC  *((volatile u8*)0x33)

#define REG_PORTD *((volatile u8*)0x32)
#define REG_DDRD  *((volatile u8*)0x31)
#define REG_PIND  *((volatile u8*)0x30)

#define REG_SPDR *((volatile u8*)0x2F)
#define REG_SPSR *((volatile u8*)0x2E)
#define REG_SPCR *((volatile u8*)0x2D)
#define REG_ADMUX *((volatile u8*)0x27)
#define REG_ADCSRA *((volatile u8*)0x26)
#define REG_SFIOR *((volatile u8*)0x50)
#define REG_ADCL *((volatile u8*)0x24)
#define REG_ADCH *((volatile u8*)0x25)
#define REG_SREG *((volatile u8*)0x5F)
#define REG_GICR *((volatile u8*)0x5B)
#define REG_GIFR *((volatile u8*)0x5A)
#define REG_MCUCR *((volatile u8*)0x55)
#define REG_MCUCSR *((volatile u8*)0x54)
#define REG_TCCR0 *((volatile u8*)0x53)
#define REG_TCNT0 *((volatile u8*)0x52)
#define REG_OCR0 *((volatile u8*)0x5C)
#define REG_TIMSK *((volatile u8*)0x59)
#define REG_TIFR *((volatile u8*)0x58)
#define REG_TCCR1B *((volatile u8*)0x4E)
#define REG_TCCR1A *((volatile u8*)0x4F)
#define REG_OCR0 *((volatile u8*)0x5C)
#define REG_ICR1L *((volatile u8*)0x46)
#define REG_ICR1H *((volatile u8*)0x47)
#define REG_SPH *((volatile u8*)0x5E)
#define REG_SPMCR *((volatile u8*)0x57)
#define REG_TWCR *((volatile u8*)0x56)
#define REG_OSCCAL *((volatile u8*)0x51)
#define REG_OCDR *((volatile u8*)0x51)
#define REG_TCNT1H *((volatile u8*)0x4D)
#define REG_TCNT1L *((volatile u8*)0x4C)
#define REG_OCR1AH *((volatile u8*)0x4B)
#define REG_OCR1AL *((volatile u8*)0x4A)
#define REG_OCR1BH *((volatile u8*)0x49)
#define REG_OCR1BL *((volatile u8*)0x48)
#define REG_ASSR *((volatile u8*)0x42)
#define REG_OCR2 *((volatile u8*)0x23)
#define REG_TCCR2 *((volatile u8*)0x45)
#define REG_TCNT2 *((volatile u8*)0x4A)
#define REG_WDTCR *((volatile u8*)0x41)
#define REG_UBRRH *((volatile u8*)0x40)
#define REG_UCSRC *((volatile u8*)0x40)
#define REG_EEARH *((volatile u8*)0x3F)
#define REG_EEARL *((volatile u8*)0x3E)
#define REG_EEDR *((volatile u8*)0x3D)
#define REG_EECR *((volatile u8*)0x3C)
#define REG_EEDR *((volatile u8*)0x3D)
#define REG_UDR *((volatile u8*)0x2C)
#define REG_UCSRA *((volatile u8*)0x2B)
#define REG_UCSRB *((volatile u8*)0x2A)
#define REG_UBRRL *((volatile u8*)0x29)
#define REG_ACSR *((volatile u8*)0x28)
#define REG_TWDR *((volatile u8*)0x23)
#define REG_TWAR *((volatile u8*)0x22)
#define REG_TWSR *((volatile u8*)0x21)
#define REG_TWBR *((volatile u8*)0x20)
























#endif
