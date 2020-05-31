/*
 * SPI.c
 
 * Created: 2/10/2020 3:16:50 PM
 * Author : Mohamed Ramadan
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"

int main(void)
{
    /* Replace with your application code */
	unsigned int Recieving_data = 0;
	PORTA_DIR  = 0xFF;
	//PORTA_DATA = 0x00;
	
	SPI_SlaveInit();
	
	while(1)
	{	
	
		Recieving_data = SPI_GetChar();
		_delay_ms(100);
		PORTA_DATA = Recieving_data;
		
	}
	
	return 0;
    }


