/*
 * CoolerSystemApp.c
 *
 * Created: 12/10/2021 10:31:23 AM
 * Author : Abd-Alrahman Saba
 */ 

#include "header.h"
#include "LCD.h"
#include "PWM.h"
#include "ADC.h"
#include "seven_seg.h"


int main(void)
{	
	SETBIT(DDRA,2); //for buzzer
	SETBIT(DDRC,0); // for led
    LCD_init();
	ADC_init();
	PWM_OC1A_init();
	SEVEN_SEG_init();
    while (1) 
    {
		uint8_t temperature = getTemp();				// Get current temperature
		uint8_t speed = checkTempGetSpeed(temperature);			// Get speed corresponding to the current temperature
		applySpeedOnMotor(speed);					// Increase/decrease motor speed according to measured temperature
		displayTempAndSpeed(temperature, speed);			// Display both on screen
    }

}

