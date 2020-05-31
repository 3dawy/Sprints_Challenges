/*
 * DIO_Mock.c
 *
 *  Created on: Feb 21, 2020
 *      Author: Khaled
 */

#include "DIO.h"


extern gu8_DIO_Init_Return;
extern gu8_DIO_Write_Return;

ERROR_STATUS DIO_init (DIO_Cfg_s * DIO_info)
{
	return gu8_DIO_Init_Return;
}

ERROR_STATUS DIO_Write (uint8_t GPIO, uint8_t pins, uint8_t value)
{
	return gu8_DIO_Write_Return;
}
