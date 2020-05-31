/*
*
*
Author:Mohamed Ramadan
*
*/
#ifndef SPI_H_
#define SPI_H_

#include "registers.h"
#include "gpio.h"

//#define SPIF BIT7
#define PUSH_BUTTON_GPIO	(GPIOC)
#define PUSH_BUTTON_BIT	    (BIT0)

#define Buzzer_GPIO			(GPIOB)
#define Buzzer_BIT			(BIT3)

#define SPI_M_SET_GPIO		(GPIOB)
#define SLAVE_SELECT_BIT	(BIT4)

#define SPI_M_SET_GPIO		(GPIOB)
#define MO_SI_BIT	        (BIT5)

#define SPI_M_SET_GPIO		(GPIOB)
#define MI_SO_BIT	        (BIT6)

#define SPI_M_SET_GPIO		(GPIOB)
#define S_CLOCK_BIT			(BIT7)

#define SPI_CTRL_REGISTER   (SPCR)
#define SPI_IN_ENABLE_BIT	(BIT7)

#define SPI_CTRL_REGISTER   (SPCR)
#define SPI_ENABLE_BIT		(BIT6)

#define SPI_CTRL_REGISTER   (SPCR)
#define SPI_DATA_ORDER_BIT  (BIT5)

#define SPI_CTRL_REGISTER   (SPCR)
#define SPI_MSTR_BIT		(BIT4)

#define SPI_CTRL_REGISTER   (SPCR)
#define SPI_CPOL_BIT		(BIT3)

#define SPI_CTRL_REGISTER   (SPCR)
#define SPI_CPHA_BIT		(BIT2)

#define SPI_CTRL_REGISTER   (SPCR)
#define SPI_SPR1_BIT		(BIT1)

#define SPI_CTRL_REGISTER   (SPCR)
#define SPI_SPR0_BIT		(BIT0)

#define SPI_STATUS_REGISTER (SPSR)
#define SPI_SPI2X_BIT		(BIT0)

#define SPI_STATUS_REGISTER (SPSR)
#define SPI_SPIF_BIT		(BIT7)

#define SET_BIT(PORT,PIN)   (PORT|=PIN)
#define CLR_BIT(PORT,PIN)   (PORT&=~PIN)
#define SET_PORT(PORT,DATA)	(PORT=DATA)

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