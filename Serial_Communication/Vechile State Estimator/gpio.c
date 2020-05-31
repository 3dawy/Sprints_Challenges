/*
* gpio.c
*
* Created: 1/17/2020 2:23:25 PM
*  Author: 3dawy
*/

#include "gpio.h"
#include "std_types.h"

#define ZERO_VALE 0

void gpioPortDirection(uint8_t u8_port, uint8_t u8_direction)
{
	switch (u8_port)
	{
		case GPIOA:
		PORTA_DIR = u8_direction;
		break;
		
		case GPIOB:
		PORTB_DIR = u8_direction;
		break;
		
		case GPIOC:
		PORTC_DIR = u8_direction;
		break;
		
		case GPIOD:
		PORTD_DIR = u8_direction;
		break;
	}
}

void gpioPortWrite(uint8_t u8_port, uint8_t u8_value)
{
	switch (u8_port)
	{
		case GPIOA:
		PORTA_DATA = u8_value;
		break;
		
		case GPIOB:
		PORTB_DATA = u8_value;
		break;
		
		case GPIOC:
		PORTC_DATA = u8_value;
		break;
		
		case GPIOD:
		PORTD_DATA = u8_value;
		break;
	}
}

void gpioPortToggle(uint8_t u8_port)
{
	switch (u8_port)
	{
		case GPIOA:
		PORTA_DATA = PORTA_DATA ^ (HIGH);
		break;
		
		case GPIOB:
		PORTB_DATA = PORTB_DATA ^ (HIGH);
		break;
		
		case GPIOC:
		PORTC_DATA = PORTC_DATA ^ (HIGH);
		break;
		
		case GPIOD:
		PORTD_DATA = PORTD_DATA ^ (HIGH);
		break;
	}
}

uint8_t gpioPortRead(uint8_t u8_port)
{
	uint8_t au8_PortValue = ZERO_VALE;
		switch (u8_port)
		{
			case GPIOA:
			au8_PortValue = PORTA_PIN;
			break;
			
			case GPIOB:
			au8_PortValue = PORTB_PIN;
			break;
			
			case GPIOC:
			au8_PortValue = PORTC_PIN;
			break;
			
			case GPIOD:
			au8_PortValue = PORTD_PIN;
			break;
		}
		return au8_PortValue;
}

void gpioPinDirection(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_direction)
{
	
	switch (u8_port)
	{
		case GPIOA:
		if (u8_direction == OUTPUT)
		/** 
		OR the Port direction value with pins to SET this pins without affect on other pins
		*/
		PORTA_DIR = PORTA_DIR | (u8_pins);
		
		else if (u8_direction == INPUT)
		/** 
		AND the Port direction value with NOT pins to CLEAR this pins without affect on other pins
		*/
		PORTA_DIR = PORTA_DIR & (~(u8_pins));
		break;
		
		case GPIOB:
		if (u8_direction == OUTPUT)
		/** 
		OR the Port direction value with pins to SET this pins without affect on other pins
		*/
		PORTB_DIR = PORTB_DIR | (u8_pins);
		
		else if (u8_direction == INPUT)
		/** 
		AND the Port direction value with NOT pins to CLEAR this pins without affect on other pins
		*/
		PORTB_DIR = PORTB_DIR & (~(u8_pins));
		break;
		
		case GPIOC:
		if (u8_direction == OUTPUT)
		/** 
		OR the Port direction value with pins to SET this pins without affect on other pins
		*/
		PORTC_DIR = PORTC_DIR | (u8_pins);
		
		else if (u8_direction == INPUT)
		/** 
		AND the Port direction value with NOT pins to CLEAR this pins without affect on other pins
		*/
		PORTC_DIR = PORTC_DIR & (~(u8_pins));
		break;
		
		case GPIOD:
		if (u8_direction == OUTPUT)
		/** 
		OR the Port direction value with pins to SET this pins without affect on other pins
		*/
		PORTD_DIR = PORTD_DIR | (u8_pins);
		
		else if (u8_direction == INPUT)
		/** 
		AND the Port direction value with NOT pins to CLEAR this pins without affect on other pins
		*/
		PORTD_DIR = PORTD_DIR & (~(u8_pins));
		break;
	}
}

void gpioPinWrite(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_value)
{
	switch (u8_port)
	{
		case GPIOA:
		if (u8_value == HIGH)
		/** 
		OR the Port DATA value with pins to SET this pins without affect on other pins
		*/
		PORTA_DATA = PORTA_DATA | (u8_pins);
		
		else if (u8_value == LOW)
		/** 
		AND the Port DATA value with NOT pins to CLEAR this pins without affect on other pins
		*/
		PORTA_DATA = PORTA_DATA & (~(u8_pins));
		break;
		
		case GPIOB:
		if (u8_value == HIGH)
		/** 
		OR the Port DATA value with pins to SET this pins without affect on other pins
		*/
		PORTB_DATA = PORTB_DATA | (u8_pins);
		
		else if (u8_value == LOW)
		/** 
		AND the Port DATA value with NOT pins to CLEAR this pins without affect on other pins
		*/
		PORTB_DATA = PORTB_DATA & (~(u8_pins));
		break;
		
		case GPIOC:
		if (u8_value == HIGH)
		/** 
		OR the Port DATA value with pins to SET this pins without affect on other pins
		*/
		PORTC_DATA = PORTC_DATA | (u8_pins);
		
		else if (u8_value == LOW)
		/** 
		AND the Port DATA value with NOT pins to CLEAR this pins without affect on other pins
		*/
		PORTC_DATA = PORTC_DATA & (~(u8_pins));
		break;
		
		case GPIOD:
		if (u8_value == HIGH)
		/** 
		OR the Port DATA value with pins to SET this pins without affect on other pins
		*/
		PORTD_DATA = PORTD_DATA | (u8_pins);
		
		else if (u8_value == LOW)
		/** 
		AND the Port DATA value with NOT pins to CLEAR this pins without affect on other pins
		*/
		PORTD_DATA = PORTD_DATA & (~(u8_pins));
		break;
	}
}

void gpioPinToggle(uint8_t u8_port, uint8_t u8_pins)
{
	switch (u8_port)
	{
		case GPIOA:
		PORTA_DATA = PORTA_DATA ^ (u8_pins);
		break;
		
		case GPIOB:
		PORTB_DATA = PORTB_DATA ^ (u8_pins);
		break;
		
		case GPIOC:
		PORTC_DATA = PORTC_DATA ^ (u8_pins);
		break;
		
		case GPIOD:
		PORTD_DATA = PORTD_DATA ^ (u8_pins);
		break;
	}
}


uint8_t gpioPinRead(uint8_t u8_port, uint8_t u8_pin)
{
	uint8_t PinValue = ZERO_VALE;
		switch (u8_port)
		{
			case GPIOA:
			PinValue = (PORTA_PIN & u8_pin);
			break;
			
			case GPIOB:
			PinValue = (PORTB_PIN & u8_pin);
			break;
			
			case GPIOC:
			PinValue = (PORTC_PIN & u8_pin);
			break;
			
			case GPIOD:
			PinValue = (PORTD_PIN & u8_pin);
			break;
		}
	
		return PinValue;
}