/*
* pushBotton.c
*
* Created: 1/18/2020 11:05:12 AM
*  Author: 3dawy
*/
#include "pushButton.h"
#include "pushButtonConfig.h"

#define ZERO_VALUE 0

void pushButtonInit(En_buttonId_t en_butotn_id)
{
	
	switch(en_butotn_id)
	{
		case BTN_0:
		gpioPinDirection(BTN_0_GPIO,BTN_0_BIT,INPUT);
		break;

		case BTN_1:
		gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,INPUT);
		break;

		case BTN_2:
		gpioPinDirection(BTN_2_GPIO,BTN_2_BIT,INPUT);
		break;

		case BTN_3:
		gpioPinDirection(BTN_3_GPIO,BTN_3_BIT,INPUT);
		break;
	}

}

En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id)
{
	En_buttonStatus_t ButtonStatus;
	uint8_t PinValue = ZERO_VALUE;
	switch(en_butotn_id)
	{
		case BTN_0:
		softwareDelayMs(BUTTONDELAYA);
		PinValue = gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
		break;
		
		case BTN_1:
		softwareDelayMs(BUTTONDELAYA);
		PinValue = gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
		break;
		
		case BTN_2:
		softwareDelayMs(BUTTONDELAYA);
		PinValue = gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
		break;
		
		case BTN_3:
		softwareDelayMs(BUTTONDELAYA);
		PinValue = gpioPinRead(BTN_3_GPIO,BTN_3_BIT);
		break;
	}
	if (PinValue)
	{
		ButtonStatus = Pressed;
	}
	else
	{
		ButtonStatus = Released;
	}
	return ButtonStatus;
}