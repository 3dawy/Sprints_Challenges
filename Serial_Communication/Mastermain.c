/*
 * SPI.c
 *
 * Author : Mohamed Ramadan
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"

#define F_CPU 16000000UL


/******************************************************************************
main application is to test the signal is sent from master M.C "1" 
to slave By detecting if the Push Button is pressed then Led is ON on the M.C"2"
********************************************************************************/

int main(void)
{
    //Initialize PORTC as INPUT
	gpioPortDirection(GPIOC,INPUT);
	//Initialize SPI Master
	SPI_MasterInit();
	
	//main Super loop
    while (1) 
    {	
		uint8_t PUTTON_IS_PRESSED=0;
		//check if Push Button on PORTC PIN0 is Pressed in Master
		PUTTON_IS_PRESSED = gpioPinRead(PUSH_BUTTON_GPIO,PUSH_BUTTON_BIT);
		if(PUTTON_IS_PRESSED)
		 {
			//Send 1 through M.C
			SPI_SendChar(0x01);
			//delay 100 ms
			_delay_ms(100); 
		 }else{
			SPI_SendChar(0x00);
		 }
	 }
	 return 0;
    }


