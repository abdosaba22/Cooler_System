
/*
 * ADC.c
 *
 * Created: 12/10/2021 10:34:13 AM
 *  Author: Abd-Alrahman Saba
 */ 
#include "ADC.h"

/*****************************************************************************
* Function Name: ADC_Init
* Purpose      : Initialize ADC with AVCC, single conversion mode and ADC_freq = 128 Khz
* Parameters   : void
* Return value : void
*****************************************************************************/
void ADC_init(void){
	DDRA = 0x00;
	SETBIT(ADMUX,REFS0); //  AVCC 
	ADCSRA |= 0x87; // enable ADC , decide ADC sampling freq 128
}

/*****************************************************************************
* Function Name: ADC_Read
* Purpose      : Trigger the ADC to start conversion (sync func)
* Parameters   : void
* Return value : uint8_t ADC value
*****************************************************************************/
uint16_t ADC_read(void){
	SETBIT(ADMUX,MUX0); // channel ADC1
	SETBIT(ADCSRA,ADSC); //start ADC conversion 
	while(READBIT(ADCSRA,ADSC) == 1){}
	return ADC;	
}