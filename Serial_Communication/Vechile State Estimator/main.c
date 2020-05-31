/*
 * Serial_Communication.c
 *
 * Created: 2/9/2020 3:06:41 PM
 * Author : Khaled Aladawy 
 */ 


#include "UART.h"
#define F_CPU 16000000UL 
#include "Util/delay.h"
#include "pushButton.h"
#include "led.h"
#include <stdio.h>

#define GET_BIT(reg,bitposition) (reg & bitposition)
#define SPEED_INITAIL_VALUE 0

int main (void)
{
	uint8_t au8_Speed = SPEED_INITAIL_VALUE;

	uint8_t au8_Prev_Speed = SPEED_INITAIL_VALUE;

	uint8_t arr[100] = "welcome user please enter the speed : ";

	uint8_t i =0;
	//initialize increment PB
	pushButtonInit(BTN_0);
	//initialize decrement PB
	pushButtonInit(BTN_1);

// 	Led_Init(LED_0);
// 	Led_Init(LED_1);
// 	Led_Init(LED_2);

	UART_INIT(Uart_Parity_no,Uart_Stop_Bit_One,Uart_Data_8_Bit,Uart_Baud_Rate_9600,
	          Uart_Async_Normal_Speed,Uart_Multi_Processor_Communication_Disable);

				SPI_MasterInit();
			

	/*wait until data injection send the speed initial value*/
	UART_TRANSMIT_String(arr);

	au8_Speed = UART_RECEIVE();

	SPI_SendChar(au8_Speed);
	SPI_SendChar(au8_Speed);
	SPI_SendChar('A');
	
	UART_TRANSMIT_Char(SPDR);
	while (TRUE)
	{
	   if (pushButtonGetStatus(BTN_1))
		{
		   //speed increase
			//Led_On(LED_0);
			au8_Speed++;
		}

		if (pushButtonGetStatus(BTN_0))
		{
			//speed decrease
			//Led_On(LED_1);
			au8_Speed--;
		}

		if (au8_Prev_Speed != au8_Speed)
		{
		   //send speed using spi
			au8_Prev_Speed = au8_Speed;
			//UART_TRANSMIT_char(au8_Speed);
			SPI_SendChar(au8_Speed);
			//Led_On(LED_2);
			_delay_ms(1000);
			//this line and the for loop after use to print string using uart with adjustable variable
			sprintf(arr,"the speed is equal %d \r \n",au8_Prev_Speed-48);
			UART_TRANSMIT_String(arr);
			//SPI_SendChar(au8_Speed);
		}

		Led_Off(LED_0);
		Led_Off(LED_1);
		Led_Off(LED_2);
	}


	return 0;
}


/*


/ *variable to carry received data* /
uint8_t Data;
/ *initialize led Pins output* /
SET_BIT (PORTB_DIR, BIT4);
SET_BIT (PORTB_DIR, BIT5);
SET_BIT (PORTB_DIR, BIT6);
SET_BIT (PORTB_DIR, BIT7);
/ *initialize led to low* /
CLEAR_BIT(PORTB_DATA, BIT4);
CLEAR_BIT(PORTB_DATA, BIT5);
CLEAR_BIT(PORTB_DATA, BIT6);
CLEAR_BIT(PORTB_DATA, BIT7);

UART_INIT(Uart_Parity_no,Uart_Stop_Bit_One,Uart_Data_8_Bit,Uart_Baud_Rate_9600,Uart_Async_Normal_Speed,Uart_Multi_Processor_Communication_Disable);


UART_TRANSMIT('p');
_delay_ms(100);
UART_TRANSMIT('l');
_delay_ms(100);
UART_TRANSMIT('e');
_delay_ms(100);
UART_TRANSMIT('a');
_delay_ms(100);
UART_TRANSMIT('s');
_delay_ms(100);
UART_TRANSMIT('e');
_delay_ms(100);
UART_TRANSMIT(' ');
_delay_ms(100);
UART_TRANSMIT('E');
_delay_ms(100);
UART_TRANSMIT('n');
_delay_ms(100);
UART_TRANSMIT('t');
_delay_ms(100);
UART_TRANSMIT('e');
_delay_ms(100);
UART_TRANSMIT('r');
_delay_ms(100);
UART_TRANSMIT(' ');
_delay_ms(100);
UART_TRANSMIT('L');
_delay_ms(100);
UART_TRANSMIT('e');
_delay_ms(100);
UART_TRANSMIT('d');
_delay_ms(100);
UART_TRANSMIT(' ');
_delay_ms(100);
UART_TRANSMIT('N');
_delay_ms(100);
UART_TRANSMIT('u');
_delay_ms(100);
UART_TRANSMIT('m');
_delay_ms(100);
UART_TRANSMIT('b');
_delay_ms(100);
UART_TRANSMIT('e');
_delay_ms(100);
UART_TRANSMIT('r');
_delay_ms(100);
UART_TRANSMIT(' ');
_delay_ms(100);
UART_TRANSMIT(':');
_delay_ms(1000);

Data = UART_RECEIVE();
if ('1' == Data)
{
	SET_BIT(PORTB_DATA, BIT4);
	_delay_ms(1000);
}
else if ('2' == Data)
{
	SET_BIT(PORTB_DATA, BIT5);
	_delay_ms(1000);
}
else if ('3' == Data)
{
	SET_BIT(PORTB_DATA, BIT6);
	_delay_ms(1000);
}
else if ('4' == Data)
{
	SET_BIT(PORTB_DATA, BIT7);
	_delay_ms(1000);
}

CLEAR_BIT(PORTB_DATA, BIT4);
CLEAR_BIT(PORTB_DATA, BIT5);
CLEAR_BIT(PORTB_DATA, BIT6);
CLEAR_BIT(PORTB_DATA, BIT7);
*/
