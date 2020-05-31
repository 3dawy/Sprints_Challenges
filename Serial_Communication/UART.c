/*
* UART.c
*
* Created: 2/9/2020 3:17:33 PM
*  Author: Khaled
*/

#include "UART.h"

#define	NINTH           0x0100
#define  GETRXB8         (UCSRB >> 1) & 0x01
#define  NINTHBITVALUE   (Ninth_Bit << 8)
void UART_INIT (En_UartParity_t en_parity, En_UartStopBit_t en_stop_bit, En_UartDataFrameSize_t en_data_frame_size, En_UartBaudRate_t en_baud_rate, 
					  En_UartSpeed_t en_speed,En_UartMultiProcessorCommunication_t en_multi_processor_communication)
{
	uint8_t UCSRC_Value = 134;
	
	/*Disable global interrupt*/
	CLEAR_BIT (SREG, BIT7);

	/*set Tx as output bit*/
	SET_BIT (PORTD_DIR, BIT1);

	/*set Rx as input bit*/
	CLEAR_BIT (PORTD_DIR, BIT0);
	
	CLEAR_BIT (UCSRA, UDRE);

	CLEAR_BIT (UCSRA, FE);
	
	CLEAR_BIT (UCSRA, DOR);

	CLEAR_BIT (UCSRA, PE);

	switch(en_speed)
	{
		case Uart_Async_Normal_Speed:
		CLEAR_BIT (UCSRA,U2X);
		break;

		case Uart_Async_Double_Speed:
		SET_BIT (UCSRA,U2X);
		break;
	}

	switch (en_multi_processor_communication)
	{
	   case Uart_Multi_Processor_Communication_Disable:
		CLEAR_BIT (UCSRA, MPCM);
		break;

		case Uart_Multi_Processor_Communication_Enable:
		SET_BIT (UCSRA, MPCM);
	}


	/*set ninth bit low as a initial value*/
	CLEAR_BIT (UCSRB, TXB8);
	/*set ninth bit low as a initial value*/
	CLEAR_BIT (UCSRB, RXB8);
	/*disable UDR interrupt*/
	CLEAR_BIT (UCSRB, UDRIE);
	/*disable TX interrupt*/
	CLEAR_BIT (UCSRB, TXCIE);
	/*disable RX interrupt*/
	CLEAR_BIT (UCSRB, RXCIE);
	 /*Enable UART Transmitter*/
	 SET_BIT (UCSRB, TXEN);
	 /*Enable UART Reception*/
	 SET_BIT (UCSRB, RXEN);
	 	/*set URSEL bit to select UCSRC reg during writing operation*/
	SET_BIT (UCSRC_Value, URSEL);
/*	UCSRC |= 0x80;*/
	/*select Asynchronous Operation*/
	CLEAR_BIT (UCSRC_Value, UMSEL);

	switch (en_parity)
	{
		case Uart_Parity_no:
		CLEAR_BIT (UCSRC_Value, UPM0);
		CLEAR_BIT (UCSRC_Value, UPM1);
		break;

		case Uart_Parity_Even:
		CLEAR_BIT (UCSRC_Value, UPM0);
		SET_BIT (UCSRC_Value, UPM1);
		break;

		case Uart_Parity_Odd:
		SET_BIT (UCSRC_Value, UPM0);
		SET_BIT (UCSRC_Value, UPM1);
		break;
	}

	switch (en_stop_bit)
	{
		case Uart_Stop_Bit_One:
		CLEAR_BIT (UCSRC_Value, USBS);
		break;

		case Uart_Stop_Bit_Two:
		SET_BIT (UCSRC_Value, USBS);
		break;
	}

	switch(en_data_frame_size)
	{
		case Uart_Data_5_Bit:
		CLEAR_BIT (UCSRB, UCSZ2);
		CLEAR_BIT (UCSRC_Value, UCSZ1);
		CLEAR_BIT (UCSRC_Value, UCSZ0);
		break;

		case Uart_Data_6_Bit:
		CLEAR_BIT (UCSRB, UCSZ2);
		CLEAR_BIT (UCSRC_Value, UCSZ1);
		SET_BIT (UCSRC_Value, UCSZ0);
		break;

		case Uart_Data_7_Bit:
		CLEAR_BIT (UCSRB, UCSZ2);
		SET_BIT (UCSRC_Value, UCSZ1);
		CLEAR_BIT (UCSRC_Value, UCSZ0);
		break;

		case Uart_Data_8_Bit:
		CLEAR_BIT (UCSRB, UCSZ2);
		SET_BIT (UCSRC_Value, UCSZ1);
		SET_BIT (UCSRC_Value, UCSZ0);
		break;

		case Uart_Data_9_Bit:
		SET_BIT (UCSRB, UCSZ2);
		SET_BIT (UCSRC_Value, UCSZ1);
		SET_BIT (UCSRC_Value, UCSZ0);
		break;
	}
	
	/*CLEAR Clock polarity during asynchronous mode*/
	CLEAR_BIT (UCSRC_Value,UCPOL);
	UCSRC = UCSRC_Value;
	switch(en_baud_rate)
	{
	   /*clear URSEL bit to select UBRRH register in writing operation*/
		//CLEAR_BIT (UBRRH, URSEL);

		case Uart_Baud_Rate_9600:
		if (Uart_Async_Normal_Speed == en_speed)
		{
		   UBRRL = 103;
			//UBRRH = 0x00;
		}
		else if (Uart_Async_Double_Speed == en_speed)
		{
		   UBRRL = 0xCF;
		//	UBRRH = 0x00;
		}
		break;

		case Uart_Baud_Rate_115200:
		if (Uart_Async_Normal_Speed == en_speed)
		{
			UBRRL = 0x08;
			//UBRRH = 0x00;
		}
		else if (Uart_Async_Double_Speed == en_speed)
		{
			UBRRL = 0x10;
		//	UBRRH = 0x00;
		}
		break;
	}
	
	
}


void UART_TRANSMIT (sint16_t Data)
{
  

	/*check if transmit buffer register is empty to write Data to UDR*/
	while (!(UCSRA & UDRE)) ;

	/* Copy 9th bit to TXB8 */
	UCSRB &= ~(TXB8);

	if ( Data & NINTH )
	
	UCSRB |= (TXB8);

	/* Put data into buffer, sends the data*/
	UDR = Data;

	/*CAN USE Txc flag to check if transmit occurs successfully or not and return status*/
}


sint16_t UART_RECEIVE (void)
{
   uint8_t Error_Check, Ninth_Bit;

	

	/* Wait for data to be received*/
	while (!(UCSRA & RXC));

	/* Get error*/ 
	Error_Check = (FE)|(DOR)|(PE);

	/* Get 9th bit*/ 
	Ninth_Bit = GETRXB8;
	       
	/* Check errors*/
	if (Error_Check & UCSRA);
	/* THIS MEAN THERE IS ERROR IN RECEVED FRAME*/

	/* Filter the 9th bit, then return*/
	return (NINTHBITVALUE | UDR);
}