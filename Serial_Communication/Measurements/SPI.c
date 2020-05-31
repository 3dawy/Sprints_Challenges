#include "spi.h"
#include "avr/interrupt.h"


volatile uint8_t SPIF_Flag =0;
//extern volatile uint8_t u8_speed;

//Initialize SPI Master
void SPI_MasterInit(){
	// Set The MISO Pin & SClock pin & Slave Select pin
	gpioPinDirection(SPI_M_SET_GPIO,SLAVE_SELECT_BIT|MO_SI_BIT|S_CLOCK_BIT,OUTPUT);
	//Drive Master Input Slave Output PIN as input
	gpioPinDirection(SPI_M_SET_GPIO,MI_SO_BIT,INPUT);
	
	// Set SPI as Master
	/*
	Enable SPI module,MSTR mode,CPOL is enable so idle state is high
	*/
					//SPCR = 0x58;
    //clear SPI Interrupt Enable PIN				
	CLR_BIT(SPI_CTRL_REGISTER,SPI_IN_ENABLE_BIT);		//SPCR &=~ (0x80);
	//clear SPI Data Order PIN
	CLR_BIT(SPI_CTRL_REGISTER,SPI_DATA_ORDER_BIT);		//SPCR &=~ (0x20);
	//SET SPI Master PIN
	SET_BIT(SPI_CTRL_REGISTER,SPI_MSTR_BIT);			//SPCR |= (0x10);
	//SET SPI clock polarity
	SET_BIT(SPI_CTRL_REGISTER,SPI_CPOL_BIT);			//SPCR |= (0x08);
	//Data is sampled on the leading edge of SCLK
	CLR_BIT(SPI_CTRL_REGISTER,SPI_CPHA_BIT);			//SPCR &=~ (0x04);
	//CLOCK Frequency is divided by 128
	SET_BIT(SPI_CTRL_REGISTER,SPI_SPR1_BIT);			//SPCR |= 0x02;
	SET_BIT(SPI_CTRL_REGISTER,SPI_SPR1_BIT);			//SPCR |= 0x01;
	//Enable SPI Module
	SET_BIT(SPI_CTRL_REGISTER,SPI_ENABLE_BIT);			//SPCR |= 0x40;	
	//DOUBLE SPEED is not supported
	CLR_BIT(SPI_STATUS_REGISTER,SPI_SPI2X_BIT);			//SPSR = 0x00;
					
}

//SPI Send char
void SPI_SendChar(unsigned char data){
	//Drive Slave Select to be LOW
	gpioPinWrite(SPI_M_SET_GPIO,SLAVE_SELECT_BIT,LOW);
	//loading DATA TO THE SDPR REGISTER
	SPDR = data;
	//polling until serial transfer is complete
	while(!(SPI_STATUS_REGISTER & (SPI_SPIF_BIT))); // SPIF 
	//DOUBLE SPEED is not supported
	CLR_BIT(SPI_STATUS_REGISTER,SPI_SPI2X_BIT);
	//Drive Slave Select to be HIGH
	gpioPinWrite(SPI_M_SET_GPIO,SLAVE_SELECT_BIT,HIGH);
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


/***********************Initialize SPI as Slave***************	
**************************************************************/
void SPI_SlaveInit(){
	// Set The MISO Pin 
	gpioPinDirection(SPI_M_SET_GPIO,MI_SO_BIT,OUTPUT);		//PORTB_DIR |= 0x40;
	//Initialize SPI in Slave mode 
	gpioPinDirection(SPI_M_SET_GPIO,SLAVE_SELECT_BIT|MO_SI_BIT|S_CLOCK_BIT,INPUT);
	//enable  SPI, CPOL
	//SET SPI Interrupt Enable PIN
	SET_BIT(SPI_CTRL_REGISTER,SPI_IN_ENABLE_BIT);	//SPCR |= (0x80);
	//clear SPI Data Order PIN
	CLR_BIT(SPI_CTRL_REGISTER,SPI_DATA_ORDER_BIT);	//SPCR &=~ (0x20);
	//Clear SPI Master PIN
	CLR_BIT(SPI_CTRL_REGISTER,SPI_MSTR_BIT);		//SPCR &=~ (0x10);
	//CLEAR SPI clock polarity 
	CLR_BIT(SPI_CTRL_REGISTER,SPI_CPOL_BIT);	    //SPCR &=~ (0x08);
	//Data is sampled on the leading edge of SCLK
	CLR_BIT(SPI_CTRL_REGISTER,SPI_CPHA_BIT);		//SPCR &=~ (0x04);
	//write 0x00 to SPSR register
	CLR_BIT(SPI_STATUS_REGISTER,SPI_SPI2X_BIT);		//SPSR &=~ (0x01);
	//Enable SPI Module
	SET_BIT(SPI_CTRL_REGISTER,SPI_ENABLE_BIT);		//SPCR |=  (0x40);
}

//SPI Get char
unsigned char SPI_GetChar(void){
	unsigned char value =0;
	//polling until the receiving data is complete
				//while(! (SPI_STATUS_REGISTER & SPI_SPIF_BIT));
	//return the data
	if (SPIF_Flag==1)
	{
		//value = SPDR;
		//SPIF_Flag=0;
	}
	return value;
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

