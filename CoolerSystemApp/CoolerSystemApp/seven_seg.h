
/*
 * seven_seg.h
 *
 * Created: 12/10/2021 1:26:22 PM
 *  Author: Abd-Alrahman Saba
 */ 

#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_
#include "header.h"

#define SEVEN_SEG_PORT_INIT() DDRD |= 0x5f;
#define SEVEN_SEG_PORT(x) PORTD = PORTD & 0xf0;  PORTD |= ((x) & 0x0f);

#define EN0(x) if(x == 1) SETBIT(PORTD,4); else CLRBIT(PORTD,4);
#define EN1(x) if(x == 1) SETBIT(PORTD,6); else CLRBIT(PORTD,6);

void SEVEN_SEG_init(void);
void SEVEN_SEG_write(uint8_t);




#endif