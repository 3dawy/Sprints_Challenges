/*
 * Req2.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Khaled
 */


/*
 * main.c
 *
 *  Created on: Feb 4, 2020
 *      Author: Khaled
 */

#include "Stack.h"
#include <stdio.h>

#include "Req2.h"


#define RETURN_INITIAL_VALUE 2




ST_Stack Stack_Open_Req_2;

ST_Stack * strp_Stack_Open_Req_2 = &(Stack_Open_Req_2);



void Req2 (void)
{
	setvbuf(stdout,NULL,_IONBF,0);
	uint8_t au8_String[100];
	uint8_t au8_S;

		printf("please enter the expression \n");

		scanf("%s", (au8_String));
	au8_S= checkForBalancedParantheses((char*)&(au8_String));

	if(1 == au8_S)
	{
		printf("It's ok");
	}
	else if (0 == au8_S)
	{
		printf("It's not ok");
	}


}


unsigned char checkForBalancedParantheses(char* expression)
{


	uint8_t Expression_Counter = ZERO;
	uint8_t au8_Result = RETURN_INITIAL_VALUE;
	uint8_t aU8_Comapre_Result = ZERO;



	//   Creat stack for open Parantheses
	Creat_Stack(strp_Stack_Open_Req_2,50);


	//Separate the close Parentheses and the open Parentheses
	while ('\0' != (expression[Expression_Counter]))

	{
		switch ((expression[Expression_Counter]))
		{
		case '{':
			Push(strp_Stack_Open_Req_2,'{');
			break;

		case '(':
			Push(strp_Stack_Open_Req_2,'(');
			break;

		case '[':
			Push(strp_Stack_Open_Req_2,'[');
			break;

		case '}':
			if (!(Is_Empty(strp_Stack_Open_Req_2)))
			{
				aU8_Comapre_Result = Pop(strp_Stack_Open_Req_2);
				if ('{' == aU8_Comapre_Result)
				{
					au8_Result = 1;
				}

				else
				{
					au8_Result = 0;
				}
			}
			else
			{
				au8_Result = 0;
			}
			break;

		case ')':
			if (!(Is_Empty(strp_Stack_Open_Req_2)))
						{
							aU8_Comapre_Result = Pop(strp_Stack_Open_Req_2);
							if ('(' == aU8_Comapre_Result)
							{
								au8_Result = 1;
							}

							else
							{
								au8_Result = 0;
							}
						}
						else
						{
							au8_Result = 0;
						}
			break;

		case ']':
			if (!(Is_Empty(strp_Stack_Open_Req_2)))
						{
							aU8_Comapre_Result = Pop(strp_Stack_Open_Req_2);
							if ('[' == aU8_Comapre_Result)
							{
								au8_Result = 1;
							}

							else
							{
								au8_Result = 0;
							}
						}
						else
						{
							au8_Result = 0;
						}
			break;

		default :
			//do nothing
			break;
		}

		Expression_Counter++;

		if (1 == au8_Result)
		{
			;
		}
		else if (0 == au8_Result)
		{
			break;
		}



	}

	if (!(Is_Empty(strp_Stack_Open_Req_2)))
				{au8_Result = 0;}
	return au8_Result;

}
