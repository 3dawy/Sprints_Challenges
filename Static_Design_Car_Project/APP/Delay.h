/*
 * Delay.h
 *
 * Created: 2/18/2020 8:42:42 AM
 *  Author: Khaled
 */ 


#ifndef DELAY_H_
#define DELAY_H_

#include "timers.h"


#define  Timer_0      0
#define  Timer_1      1
#define  Timer_2      2

/**************************************************************************
 * Function 	: Delay_ms                                                *
 * Input 		: Timer_Chan        *
 * Return 		: value of type ERROR_STATUS							  *
 * 				  which is one of the following values:					  *
 * 				  - E_OK  : initialized successfully					  *
 *				     - E_NOK : not initialized successfully				  *
 * Description  : doing nothing for giving time        			  *
 **************************************************************************/
ERROR_STATUS Delay_ms (uint8_t Timer_Chan,uint16_t Time);



#endif /* DELAY_H_ */