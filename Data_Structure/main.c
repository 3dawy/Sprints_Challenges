
#include "Queue.h"
#include <stdio.h>
#include "Stack.h"
#include "Linked_List.h"


#define RETURN_INITIAL_VALUE 2

ST_Queue Queue_1;
ST_Queue * Queue_Ptr = &(Queue_1);
ST_Stack Stack_Open;
ST_Stack * strp_Stack_Open = &(Stack_Open);
ST_List List1;
ST_List * PTR = &List1;



unsigned char check_For_Balanced_Parantheses(char* expression);
long long evaluate(char* expression);
void  Linked_List_Test (void);

int main (void)
{
	setvbuf(stdout,NULL,_IONBF,0);
	uint8_t au8_String[100];
	uint8_t au8_S;
	uint64_t au64_Result = ZERO;

		printf("please enter the expression \n");

		scanf("%s", (au8_String));
	au8_S= check_For_Balanced_Parantheses((char*)&(au8_String));

	if(1 == au8_S)
	{
		printf("Parantheses's ok \n");
	}
	else if (0 == au8_S)
	{
		printf("Parantheses's not ok");
		return 0;
	}

	au64_Result = evaluate((char*)&(au8_String));


	printf("The result of the operation is %ld", (long int)au64_Result);


	return 0;
}


unsigned char check_For_Balanced_Parantheses(char* expression)
{


	uint8_t Expression_Counter = ZERO;
	uint8_t au8_Result = RETURN_INITIAL_VALUE;
	uint8_t aU8_Comapre_Result = ZERO;



	//   Creat stack for open Parantheses
	Creat_Stack(strp_Stack_Open,50);


	//Separate the close Parentheses and the open Parentheses
	while ('\0' != (expression[Expression_Counter]))

	{
		switch ((expression[Expression_Counter]))
		{
		case '{':
			Push(strp_Stack_Open,'{');
			break;

		case '(':
			Push(strp_Stack_Open,'(');
			break;

		case '[':
			Push(strp_Stack_Open,'[');
			break;

		case '}':
			if (!(Is_Empty(strp_Stack_Open)))
			{
				aU8_Comapre_Result = Pop(strp_Stack_Open);
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
			if (!(Is_Empty(strp_Stack_Open)))
			{
				aU8_Comapre_Result = Pop(strp_Stack_Open);
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
			if (!(Is_Empty(strp_Stack_Open)))
			{
				aU8_Comapre_Result = Pop(strp_Stack_Open);
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

	if (!(Is_Empty(strp_Stack_Open)))
	{au8_Result = 0;}
	return au8_Result;

}


long long evaluate(char* expression)
{
	uint8_t Expression_Counter = ZERO;
	uint16_t au16_Num = ZERO;
	uint8_t au8_Dequeue = ZERO;
	uint64_t au64_Sum = ZERO;


	createQueue(Queue_Ptr,50);

	//enqueue the numbers and operations to the queue
	while ('\0' != (expression[Expression_Counter]))
	{
		switch ((expression[Expression_Counter]))
		{
		case '*':
			enqueue(Queue_Ptr,'*');
			break;

		case '/':
			enqueue(Queue_Ptr,'/');
			break;

		case '+':
			enqueue(Queue_Ptr,'+');
			break;

		case '-':
			enqueue(Queue_Ptr,'-');
			break;
		}

		if ((((expression[Expression_Counter]) > 47) && (expression[Expression_Counter]) < 58))
		{
			enqueue(Queue_Ptr,expression[Expression_Counter]);
		}

		Expression_Counter ++;
	}


	au8_Dequeue = dequeue(Queue_Ptr);


	while ((au8_Dequeue > 47) && (au8_Dequeue < 58) && (!(Is_Queue_Empty(Queue_Ptr))))
	{
		au16_Num = (au16_Num * 10) + (au8_Dequeue - 48);

		au8_Dequeue = dequeue(Queue_Ptr);
	}
	if (Is_Queue_Empty(Queue_Ptr))
	{
		au16_Num = (au16_Num * 10) + (au8_Dequeue - 48);
	}

	au64_Sum = au16_Num;

	while (!(Is_Queue_Empty(Queue_Ptr)))
	{

		au16_Num = ZERO;





		switch (au8_Dequeue)
		{
		case '*':
			au8_Dequeue = dequeue(Queue_Ptr);
			while ((au8_Dequeue > 47) && (au8_Dequeue < 58) && (!(Is_Queue_Empty(Queue_Ptr))))
			{
				au16_Num = (au16_Num * 10) + (au8_Dequeue - 48);

				au8_Dequeue = dequeue(Queue_Ptr);
			}

			if (Is_Queue_Empty(Queue_Ptr))
			{
				au16_Num = (au16_Num * 10) + (au8_Dequeue - 48);
			}
			au64_Sum = au64_Sum * au16_Num;
			break;

		case '/':
			au8_Dequeue = dequeue(Queue_Ptr);
			while ((au8_Dequeue > 47) && (au8_Dequeue < 58) && (!(Is_Queue_Empty(Queue_Ptr))))
			{
				au16_Num = (au16_Num * 10) + (au8_Dequeue - 48);

				au8_Dequeue = dequeue(Queue_Ptr);
			}

			if (Is_Queue_Empty(Queue_Ptr))
			{
				au16_Num = (au16_Num * 10) + (au8_Dequeue - 48);
			}
			au64_Sum = au64_Sum / au16_Num;
			break;

		case '+':
			au8_Dequeue = dequeue(Queue_Ptr);
			while ((au8_Dequeue > 47) && (au8_Dequeue < 58) && (!(Is_Queue_Empty(Queue_Ptr))))
			{
				au16_Num = (au16_Num * 10) + (au8_Dequeue - 48);

				au8_Dequeue = dequeue(Queue_Ptr);
			}

			if (Is_Queue_Empty(Queue_Ptr))
			{
				au16_Num = (au16_Num * 10) + (au8_Dequeue - 48);
			}
			au64_Sum = au64_Sum + au16_Num;
			break;

		case '-':
			au8_Dequeue = dequeue(Queue_Ptr);
			while ((au8_Dequeue > 47) && (au8_Dequeue < 58) && (!(Is_Queue_Empty(Queue_Ptr))))
			{
				au16_Num = (au16_Num * 10) + (au8_Dequeue - 48);

				au8_Dequeue = dequeue(Queue_Ptr);
			}

			if (Is_Queue_Empty(Queue_Ptr))
			{
				au16_Num = (au16_Num * 10) + (au8_Dequeue - 48);
			}
			au64_Sum = au64_Sum - au16_Num;
			break;
		}



	}

	return au64_Sum;
}



void  Linked_List_Test (void)
{

	int x=55;
	ST_Node * y = NULL;
	setvbuf(stdout,NULL,_IONBF,0);

	createList(PTR);
	insertToList(PTR,1,1);
    printf("%d \n",PTR->strp_List_Head->Data);
	insertToList(PTR,2,2);
	printf("%d ",PTR->strp_List_Head->Data);
	printf("%d \n",PTR->strp_List_Head->strp_Next_Node->Data);
	insertToList(PTR,3,3);
	printf("%d ",PTR->strp_List_Head->Data);
	printf("%d ",PTR->strp_List_Head->strp_Next_Node->Data);
	printf("%d \n",PTR->strp_List_Head->strp_Next_Node->strp_Next_Node->Data);
	insertToList(PTR,4,4);

	deleteFromList(PTR,2,&x);

	printf("%d \n \n",x);
	printf("%d ",PTR->strp_List_Head->Data);
	printf("%d ",PTR->strp_List_Head->strp_Next_Node->Data);
	printf("%d \n",PTR->strp_List_Head->strp_Next_Node->strp_Next_Node->Data);
	y = searchIntoList(PTR,4);

	printf("%d", y->Data);

	//printf("%d \n",PTR->strp_List_Head->strp_Next_Node->strp_Next_Node->strp_Next_Node->Data);
}


