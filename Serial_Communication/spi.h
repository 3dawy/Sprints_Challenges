#ifndef SPI_H_
#define SPI_H_

#include "registers.h"
#include "gpio.h"

#define SPIF BIT7

//Initialize SPI Master
void SPI_MasterInit();
//SPI Send char
void SPI_SendChar(unsigned char data);
//SPI Send String
void SPI_SendString(unsigned char *str);

/**************
				//SPI Slave Initialization
									*************/

//Initialize SPI Slave
void SPI_SlaveInit();
//SPI Get char
unsigned char SPI_GetChar(void);
//SPI Get String
void SPI_GetString(unsigned char *str);





#endif