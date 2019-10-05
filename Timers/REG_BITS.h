/*
 * REG_BITS.h
 *
 *  Created on: Oct 5, 2019
 *      Author: medos
 */

#ifndef REG_BITS_H_
#define REG_BITS_H_

// Register TCCR0
#define CS00   0
#define CS01   1
#define CS02   2
#define WGM01  3
#define COM00  4
#define COM01  5
#define WGM00  6
#define FOC0   7

//Register TIMSK ( TIMER COUNTER INTERRUPT MASK )
#define TOIE0  0
#define OCIE0  1
#define TOIE1  2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2  6
#define OCIE2  7

//Register TIFR (Timer Counter Interrupt flag)
#define TOV0  0
#define OCF0  1
#define TOV1  2
#define OCF1B 3
#define OCF1A 4
#define ICF1  5
#define TOV2  6
#define OCF2  7

//Register SFIOR (Special Function I/O Register)
#define PSR10 0
#define PSR2  1
#define PUD   2
#define ACME  3
#define ADTS0 5
#define ADTS1 6
#define ADTS2 7


#endif /* REG_BITS_H_ */
