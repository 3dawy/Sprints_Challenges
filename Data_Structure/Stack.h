/*
 * Stack.h
 *
 *  Created on: Feb 4, 2020
 *      Author: Khaled
 */

#ifndef STACK_H_
#define STACK_H_

#include "std_types.h"
#include <stdlib.h>


#define ZERO 0
#define TOP_STACK_INITIAL_VALUE -1



//Stack contrtol structure
typedef struct ST_Stack
{
	uint8_t stru8_Size;
	sint16_t strs16_Counter;
	uint8_t * gpstr_Stack;
}ST_Stack;



//Stack functions prototypes:

uint8_t IS_Full (ST_Stack * ptr);
//Description: use this function to check the stack if it full or not
//@parameter:Pointer to stack structure

uint8_t Is_Empty (ST_Stack * Ptr);
//Description: use this function to check the stack if it empty or not
//@parameter:Pointer to stack structure


void Creat_Stack (ST_Stack * ptr, uint8_t Capacity);
//Description: use this function to creat a stack.
//@parameter:Pointer to stack structure and stack's size


void Push (ST_Stack * Ptr, uint8_t Data);
//Description: use this function to store data in top of stack and increase the top of stack by 1.
//@parameter:Pointer to stack structure and the data to store.


uint8_t Pop (ST_Stack * Ptr);
//Description: use this function to load data from top of stack and decrease the top of stack by 1.
//@parameter:Pointer to stack structure and pointer to desired data.

void Peek (ST_Stack * Ptr, uint8_t * Data);
//Description: use this function to load data from top of stack.
//@parameter:Pointer to stack structure and pointer to desired data.
#endif /* STACK_H_ */
