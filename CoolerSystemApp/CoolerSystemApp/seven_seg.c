
/*
 * seven_seg.c
 *
 * Created: 12/10/2021 1:26:34 PM
 *  Author: Abd-Alrahman Saba
 */ 

#include "seven_seg.h"

void SEVEN_SEG_init(void){
	SEVEN_SEG_PORT_INIT();
}

void SEVEN_SEG_write(uint8_t data){ // 0 to 99
	
	EN0(1);
	EN1(0);
	SEVEN_SEG_PORT(data/10);
	_delay_ms(100);
	
	EN0(0);
	EN1(1);
	SEVEN_SEG_PORT(data%10);
	_delay_ms(100);
	
}