
/*
 * PWM.c
 *
 * Created: 12/10/2021 10:34:51 AM
 *  Author: Abd-Alrahman Saba
 */ 
#include "PWM.h"

/*****************************************************************************
* Function Name: PWM_OC1A_init
* Purpose      : Initialize OC1A as FAST-PWM in timer1 with no prescaler -
*                10 bit - non inverting mode
* Parameters   : void
* Return value : void
*****************************************************************************/

void PWM_OC1A_init(void){
	SETBIT(DDRD,5); // OC1A output
	TCCR1A |= 0x83; // set 1 to  WGM10 , WGM11 & COM1A1
	TCCR1B|=0x09; // set 1 to  WGM12 & CS10 --> no prescaler
	
}

/*****************************************************************************
* Function Name: PWM_set_duty_oc1a
* Purpose      : Set OCR1A register to generate PWM with a specific duty cycle
* Parameters   : duty: value range from 0 to 100
* Return value : void
*****************************************************************************/

void PWM_OC1A_set_duty(uint8_t duty){
	OCR1A = duty * 10.23 ;
}