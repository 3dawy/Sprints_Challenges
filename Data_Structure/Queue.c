/*
 * Queue.c
 *
 *  Created on: Feb 5, 2020
 *      Author: Khaled
 */

#include "Queue.h"
#include <stdlib.h>

uint8_t Is_Queue_Empty (ST_Queue * Ptr)
{
	return !(Ptr->stru8_Queue_Counter );
}

uint8_t Is_Queue_Full (ST_Queue * Ptr)
{
	if ((Ptr->stru8_Queue_Counter) == (Ptr->stru8_Queue_Size))
	{
		return TRUE;
	}
	else
		return FALSE;
}

void createQueue(ST_Queue * Ptr, uint8_t maxSize)
{
	Ptr->stru8_Queue_Size = maxSize;

	Ptr->strpu8_Queue = (uint8_t *) calloc (Ptr->stru8_Queue_Size, sizeof(uint8_t));

	Ptr->stru8_Queue_Counter = ZERO;

	Ptr->stru8_Front_Counter = ZERO;

	Ptr->stru8_Rear_Counter = ZERO;
}
void enqueue(ST_Queue * Ptr, uint8_t data)
{
	if (Is_Queue_Full(Ptr))
		{

		}
		else
		{
			Ptr->strpu8_Queue[Ptr->stru8_Rear_Counter] = data;

			Ptr->stru8_Rear_Counter++;

			Ptr->stru8_Rear_Counter = (Ptr->stru8_Rear_Counter) % (Ptr->stru8_Queue_Size);

			Ptr->stru8_Queue_Counter ++;

		}
}
uint8_t dequeue(ST_Queue * Ptr)
{
	uint8_t data;
	if (Is_Queue_Empty(Ptr))
		{

		}
		else
		{
			data = Ptr->strpu8_Queue[Ptr->stru8_Front_Counter] ;

			Ptr->stru8_Front_Counter ++;

			Ptr->stru8_Front_Counter = (Ptr->stru8_Front_Counter ) % Ptr->stru8_Queue_Size;

			Ptr->stru8_Queue_Counter --;
		}
	return data;
}



