/*
 * Linked_List.c
 *
 *  Created on: Feb 6, 2020
 *      Author: Khaled
 */


#include "Linked_List.h"

#define ONE 1
#define ZERO 0

void createList(ST_List * list)
{

	if (NULL == list)
	{

	}
	else
	{
		/*Initialize the list size by zero*/
		list->stru16_Size = 0;

		/*Initialize the list headed to null*/
		list->strp_List_Head = NULL;
	}
}
void insertToList(ST_List * list, uint8_t position, sint16_t data)
{
	if (NULL == list);

	else
	{

		ST_Node * Ptr = (list->strp_List_Head);
		ST_Node * Temp_Ptr = (list->strp_List_Head);
		uint8_t au8_Counter;

		/*Create the new node*/
		ST_Node * Link = (ST_Node *) calloc (ONE, sizeof(ST_Node));

		/* assign the data in the new node*/
		Link->Data = data;

		/* increase the list control structure size by one*/
		list->stru16_Size++;

		/*Special case to insert first node*/
		if (NULL == list->strp_List_Head)
		{
			list->strp_List_Head = Link;

			list->strp_List_Head->strp_Next_Node = NULL;

		}

		else
		{

			/*Loop until reach the post-desired position*/
			for(au8_Counter=0;au8_Counter<position-ONE;au8_Counter++)
			{
				Ptr = (Ptr)->strp_Next_Node;
			}

			/*make the new nod pointer point to the post-new node */
			Link->strp_Next_Node = Ptr;

			/*Loop until reach the pre-desired position*/
			for(au8_Counter=1;au8_Counter<position-ONE;au8_Counter++)
			{
				(Temp_Ptr) = (Temp_Ptr)->strp_Next_Node;
			}


			/*make the pre-new node pointer point to the new node*/
			Temp_Ptr->strp_Next_Node = (Link);

		}
	}
}



void deleteFromList(ST_List * list, uint8_t position, sint16_t * data)
{
	if (NULL == list);

	else
	{
		ST_Node * Ptr = (list->strp_List_Head);
		ST_Node * Temp_Ptr = (list->strp_List_Head);
		uint8_t au8_Counter;

		/* decrease the list control structure size by one*/
		list->stru16_Size--;

		/*Loop until reach the post-desired position*/
		for(au8_Counter=ONE;au8_Counter<position-ONE;au8_Counter++)
		{
			Ptr = (Ptr)->strp_Next_Node;
		}

		/*Loop until reach the pre-desired position*/
		for(au8_Counter=ONE;au8_Counter<position;au8_Counter++)
		{
			(Temp_Ptr) = (Temp_Ptr)->strp_Next_Node;
		}


		*data = Temp_Ptr->Data;
		Ptr->strp_Next_Node = Temp_Ptr->strp_Next_Node;
	}
}
ST_Node* searchIntoList(ST_List * list, sint16_t data)
{
	uint16_t au16_Counter;
	if (NULL == list);

	else
	{
		ST_Node * Ptr = (list->strp_List_Head);

		for (au16_Counter=ZERO; au16_Counter < list->stru16_Size; au16_Counter++)
		{
			if (data == Ptr->Data )
			{
				break;
			}
			else
			{
				Ptr = (Ptr)->strp_Next_Node;
			}
		}
		return Ptr;
	}

}










