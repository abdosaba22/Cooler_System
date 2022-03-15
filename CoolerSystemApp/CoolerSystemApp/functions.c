
/*
 * functions.c
 *
 * Created: 12/10/2021 5:45:53 PM
 *  Author: Abd-Alrahman Saba
 */ 
#include "functions.h"

uint8_t getTemp()
{	
	/* 4.88 m.v for level --> 5 V / 1023 
	   ADC_read return number of the level multiply it by 4.88 = V_out m.v from sens 
	   T c = V_out m.v / 10.00 m.v --> 10 mv/c */
	uint8_t temp = ((ADC_read()*4.88)/10.00) ;	//temp in C
	return temp;
}
void applySpeedOnMotor(uint8_t speed)
{
	PWM_OC1A_set_duty(speed);
}

void displayTempAndSpeed(uint8_t temp, uint8_t speed)
{
	SEVEN_SEG_write(temp);				// Display temp on seven segment
	LCD_write_command(0x01);
	LCD_write_string("Temp:");
	LCD_write_command(0x87);
	LCD_write_num(temp);				// Display temp in first row of LCD
	LCD_write_command(0xC0);
	LCD_write_string("Motor_speed:");
	LCD_write_command(0xCD);
	LCD_write_num(speed);				// Display motor speed in percentage in second row of LCD
	_delay_ms(100);
}

uint8_t checkTempGetSpeed(uint8_t temp)
{
	uint8_t duty_cycle;
	if (temp <= 35)
	{
		CLRBIT(PORTC,0);		// Indicates temp is less than 35 degree
		CLRBIT(PORTA,2);
		duty_cycle = 0;			// Motor speed = zero
	}
	else
	{
		SETBIT(PORTC,0);		// Indicates temp is more than 35 degree
		SETBIT(PORTA,2);
		if	((temp >  35 ) && (temp < 38 ))		duty_cycle = 50;
		else if((temp >= 38 ) && (temp < 40 ))	duty_cycle = 60;
		else if((temp >= 40 ) && (temp < 42 ))	duty_cycle = 70;
		else if((temp >= 42 ) && (temp < 45 ))	duty_cycle = 80;
		else if((temp >= 45 ) && (temp < 48 ))	duty_cycle = 90;
		else	duty_cycle = 100;
	}
	return duty_cycle;
}
