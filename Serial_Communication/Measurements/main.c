/*
 * V_State_Estimator.c
 *
 * Created: 2/12/2020 11:41:11 PM
 * Author : Mohamed Ramadan
 */ 

#include "spi.h"
#include "timers.h"
#include "PushButton.h"
#include "led.h"
#include "gpio.h"
#include "avr/interrupt.h"
#include "UART.h"
#include <stdio.h>

volatile uint8_t ovf_counter =InitialValue ;
static volatile uint8_t u8_speed = 0x00;

int main(void)
{
	uint8_t arr[arrayelement];
	uint8_t OverAllDistance =InitialValue;
	uint8_t u8_startFlag = InitialValue;
	uint8_t u8_stopFlag = InitialValue;
	uint8_t u8_prevspeed = InitialValue;
	uint8_t u8_InitialFlag = 1;
	uint8_t u8_PUSH_BUTTON0_ST = InitialValue;
	uint8_t u8_PUSH_BUTTON1_ST = InitialValue;
	uint8_t speed_arr[speedarrayelement]={0};
	uint8_t	OVF_arr[OVFarrelement]={0};
		
	uint8_t counter=InitialValue;	
	uint8_t counter_distance=InitialValue;
	volatile uint8_t Distance[distancearray];	
	uint8_t i =InitialValue;
		
	//Enable Global Interrupt
	SREG|=(1<<7);
	//Initialize UART	
	UART_INIT(Uart_Parity_no,Uart_Stop_Bit_One,Uart_Data_8_Bit,Uart_Baud_Rate_9600,
	Uart_Async_Normal_Speed,Uart_Multi_Processor_Communication_Disable);
	
	//Initialize SPI
	SPI_SlaveInit();
	//Initialize Timer
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_1024,TimerInitialValue,0,T0_INTERRUPT_NORMAL);
	//Initialize Start and Stop PushButton
	pushButtonInit(BTN_0);
	pushButtonInit(BTN_1);
	 
	//PORTB_DIR|=(1<<5);
    while (1) 
    {	
		
	u8_PUSH_BUTTON0_ST=pushButtonGetStatus(BTN_0);   //u8_PUSH_BUTTON0_ST  initiate start flag
			if(u8_PUSH_BUTTON0_ST==High){
				u8_startFlag = High;
			}
			
	while (u8_startFlag==High)
	{
		timer0Start();
		u8_PUSH_BUTTON1_ST=pushButtonGetStatus(BTN_1);
		if(u8_PUSH_BUTTON1_ST == High){						//u8_PUSH_BUTTON1_ST  initiate stop flag
			u8_stopFlag = High;
			u8_startFlag =Low;
					}
		if (u8_InitialFlag==High)							//first iteration after start pushbutton pressed 
			{	
				
				speed_arr[i] = u8_speed;
				u8_prevspeed = u8_speed;
				u8_InitialFlag = Low;
			}
		
		if(u8_prevspeed!=u8_speed){
				timer0Stop();	
				OVF_arr[i]  = ovf_counter;
				u8_prevspeed = u8_speed;
				timer0Set(TimerInitialValue);	
				ovf_counter = Low;
				i++;
				speed_arr[i] = u8_speed;
				}			
    }
	
	if (u8_stopFlag==High)
	{
			timer0Stop();
			OVF_arr[i]  = ovf_counter;   
			for(counter=InitialValue;counter<=i;counter++){
			Distance[counter] = (((speed_arr[counter]-InitialAsciValue) * OVF_arr[counter]));
			sprintf(arr,"the speed is %d and the time is %d and the distance is %d \n",(speed_arr[counter]-48),OVF_arr[counter],Distance[counter]);
			UART_TRANSMIT_String(arr);
			}
			
			for (counter_distance=InitialValue;counter_distance<=i;counter_distance++)
			{
				OverAllDistance += Distance[counter_distance]; 	
			}
 			sprintf(arr,"the overall Distance is %d",OverAllDistance);
			UART_TRANSMIT_String(arr);
			ovf_counter = InitialValue;
			i=InitialValue;
			u8_InitialFlag=High;
			u8_stopFlag =InitialValue;
	}
		
}

	}
	
	ISR(SPI_STC_vect)
	{
		u8_speed = SPDR;
		
	}