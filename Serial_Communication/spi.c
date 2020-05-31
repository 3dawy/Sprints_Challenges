#include "spi.h"

//Initialize SPI Master
void SPI_MasterInit(){
	// Set The MISO Pin & SClock pin & Slave Select pin
	PORTB_DIR |= 0xB0; 
	
	// Set SPI as Master
	/*
	Enable SPI module,MSTR mode,CPOL is enable so idle state is high
	*/
	SPCR = 0x58;
	//No interrupt needed 
	SPSR = 0x00;
}

//SPI Send char
void SPI_SendChar(unsigned char data){
	//loading DATA TO THE SDPR REGISTER
	SPDR = data;
	//polling until serial transfer is complete
	while(!(SPSR & (1<<SPIF))); // SPIF 
	
}
//SPI Send String
void SPI_SendString(unsigned char *str){
	//sending char by char
	while(*str != '\0')
	{
		SPI_SendChar(*str);
		str++;
	}
	
}


/*Initialize SPI as Slave	*/
void SPI_SlaveInit(){
	// Set The MISO Pin 
	PORTB_DIR |= 0x40;
	//enable  SPI, CPOL
	SPCR |= 0x40;
	SPCR |= 0x0B;
	SPSR = 0x00;

}

//SPI Get char
unsigned char SPI_GetChar(void){
	//polling until the receiving data is complete
	while(! (SPSR & 0x80));
	//return the data
	return SPDR;
}

//SPI Get string
void SPI_GetString(unsigned char *str){
unsigned char data = 0;
	do
	{	//load the data with received 
		data = SPI_GetChar();
		//load the buffer with data
		*str = data;
		//increment the index of data storing Buffer
		str++;
	}while(data != '#');
	str--;
	//fill the last element of the buffer string by null
	*str = '\0';
	
}
