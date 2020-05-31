#include "spi.h"

//Initialize SPI Master
void SPI_MasterInit(){
	// Set The MOSI Pin & SClock pin & Slave Select pin
	gpioPinDirection(SPI_M_SET_GPIO,SLAVE_SELECT_BIT|MO_SI_BIT|S_CLOCK_BIT,OUTPUT);
	 gpioPinDirection(SPI_M_SET_GPIO,BIT6,INPUT);
	// Set SPI as Master
	
	/**************
	Enable SPI module,MSTR mode,CPOL is enable so idle state is high
	******************/
		//Enable SPI module
		
// 		SPCR |= 0x1B;
// 		SPSR = 0x00;
// 		SPCR |= 0x40;

SPCR = 0b01110010;


	}

//SPI Send char
void SPI_SendChar(unsigned char data){
	PORTB_DATA&=~(1<<4);
	
	//loading DATA TO THE SDPR REGISTER
	SPDR = data;
	//polling until serial transfer is complete
	while(!(SPSR & 0x80)); // SPIF 
	SPSR &=~ 0x80;
	PORTB_DATA|=(1<<4);
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
	PORTB_DIR=0x40;
	//enable  SPI, CPOL
	SPCR = 0x48;   
	SPSR = 0x00;
	
}

//SPI Get char
unsigned char SPI_GetChar(void){
	//polling until the receiving data is complete
	while(!(SPSR & 0x80 ));
	//return the data
	return SPDR;
	
}

//SPI Get string
void SPI_GetString(unsigned char *str){
unsigned char data = 0;
	do
	{	//load the data with recieved 
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
