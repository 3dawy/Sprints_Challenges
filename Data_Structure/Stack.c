/*
 * Stack.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Khaled
 */

#include "Stack.h"


uint8_t IS_Full (ST_Stack * ptr)
{
	return (ptr->stru8_Size == (ptr->strs16_Counter + 1));
}


uint8_t Is_Empty (ST_Stack * Ptr)
{
	return (TOP_STACK_INITIAL_VALUE == Ptr->strs16_Counter);
}


void Creat_Stack (ST_Stack * ptr, uint8_t Capacity)
{
	ptr->stru8_Size = Capacity;

	ptr->gpstr_Stack = (uint8_t *) calloc (Capacity, sizeof(uint8_t));

	ptr->strs16_Counter = TOP_STACK_INITIAL_VALUE;

}


void Push (ST_Stack * Ptr, uint8_t Data)
{
	if (NULL != Ptr)
	{
		if (TRUE == IS_Full(Ptr))
			;
		else
		{
			Ptr->strs16_Counter ++;
			Ptr->gpstr_Stack[Ptr->strs16_Counter] = Data;
		}
	}

	else
		; //error value

}


uint8_t Pop (ST_Stack * Ptr)
{
	uint8_t Data;
	if (NULL != Ptr)
	{
		if( Is_Empty(Ptr))
		{
			;//error value
		}

		else
		{
			Data = Ptr->gpstr_Stack[Ptr->strs16_Counter];
			Ptr->strs16_Counter --;
		}
	}

	else
		;//erro value

	return Data;
}


//void Peek (ST_Stack * Ptr, uint8_t * Data)
//{
//	if (NULL != Ptr)
//	   {
//	      if(TRUE == Is_Empty(Ptr))
//	      {
//	         ;//error value
//	      }
//
//	      else
//	      {
//	         Data = Ptr->gpstr_Stack[(Ptr->strs16_Counter)];
//	      }
//	   }
//
//	   else
//		   ;//erro value
//}
