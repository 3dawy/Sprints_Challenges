/*
 * Motor_Test.c
 *
 *  Created on: Feb 21, 2020
 *      Author: Khaled
 */


#include <stdio.h>
#include "Common_Macros.h"
#include "DIO.h"
#include "PWM.h"
#include "std_types.h"
#include "motor.h"
//#include "../../ECU/motor.h"
//#include "../../ECU/motor.c"
//#include "../../ECU/motorConfig.h"

#define RESULT_INITIAL_VALUE 5;


void Motor_Init_Test (void);
void Motor_Direction_Test (void);
void Motor_Start_Test(void);

uint8_t gu8_PWM_Init_Return = E_OK;
uint8_t gu8_DIO_Init_Return = E_OK;
uint8_t gu8_DIO_Write_Return = E_OK;
uint8_t gu8_PWM_Start_Return = E_OK;

int main (void)
{
	uint8_t au8_Test_Func_Number = ZERO;
	//line to correct error in IDE related to printf and scanf functions
	setvbuf(stdout,NULL,_IONBF,0);

	printf("choose 1 for Motor_Init \n");
	printf("choose 2 for Motor_Direction \n");
	printf("choose 3 for Motor_Start \n");

	printf("The number of the desired function to test is ");
	scanf("%d",&au8_Test_Func_Number);

	switch (au8_Test_Func_Number)
	{
	case 1:
		Motor_Init_Test();
		break;

	case 2:
		Motor_Direction_Test();
		break;

	case 3:
		Motor_Start_Test();
		break;
	default:
		printf("Invalid function number");
		break;
	}



	return 0;
}

void Motor_Init_Test (void)
{
	uint8_t au8_TestNumber = ZERO;
	uint8_t au8_Result = RESULT_INITIAL_VALUE;
	uint8_t au8_repeat = ZERO;

	while (TRUE)
	{

		printf("Please enter test number: ");

		scanf("%d",&au8_TestNumber);

		switch (au8_TestNumber)
		{
		case 1:

			gu8_PWM_Init_Return = E_OK;
			gu8_DIO_Init_Return = E_OK;
			au8_Result = Motor_Init(MOTOR_1);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;

		case 2:

			gu8_PWM_Init_Return = E_OK;
			gu8_DIO_Init_Return = E_OK;
			au8_Result = Motor_Init(MOTOR_2);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;

		case 3:

			gu8_PWM_Init_Return = E_OK;
			gu8_DIO_Init_Return = E_OK;
			au8_Result = Motor_Init(3);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 4:

			gu8_PWM_Init_Return = E_OK;
			gu8_DIO_Init_Return = E_OK;
			au8_Result = Motor_Init(0);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;


		case 5:

			gu8_PWM_Init_Return = E_OK;
			gu8_DIO_Init_Return = E_NOK;
			au8_Result = Motor_Init(MOTOR_1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 6:

			gu8_PWM_Init_Return = E_OK;
			gu8_DIO_Init_Return = E_NOK;
			au8_Result = Motor_Init(MOTOR_2);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 7:

			gu8_PWM_Init_Return = E_NOK;
			gu8_DIO_Init_Return = E_OK;
			au8_Result = Motor_Init(MOTOR_1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 8:

			gu8_PWM_Init_Return = E_NOK;
			gu8_DIO_Init_Return = E_OK;
			au8_Result = Motor_Init(MOTOR_2);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 9:

			gu8_PWM_Init_Return = E_OK;
			gu8_DIO_Init_Return = E_NOK;
			au8_Result = Motor_Init(5);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 10:

			gu8_PWM_Init_Return = E_OK;
			gu8_DIO_Init_Return = E_NOK;
			au8_Result = Motor_Init(3);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 11:

			gu8_PWM_Init_Return = E_NOK;
			gu8_DIO_Init_Return = E_OK;
			au8_Result = Motor_Init(8);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 12:

			gu8_PWM_Init_Return = E_NOK;
			gu8_DIO_Init_Return = E_OK;
			au8_Result = Motor_Init(0);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 13:

			gu8_PWM_Init_Return = E_NOK;
			gu8_DIO_Init_Return = E_NOK;
			au8_Result = Motor_Init(MOTOR_1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 14:

			gu8_PWM_Init_Return = E_NOK;
			gu8_DIO_Init_Return = E_NOK;
			au8_Result = Motor_Init(MOTOR_2);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 15:

			gu8_PWM_Init_Return = E_NOK;
			gu8_DIO_Init_Return = E_NOK;
			au8_Result = Motor_Init(0);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 16:

			gu8_PWM_Init_Return = E_NOK;
			gu8_DIO_Init_Return = E_NOK;
			au8_Result = Motor_Init(3);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		default:
			printf("invalid test number");
			break;
		}

		printf("\nTo exit motor_Init test press E or any char to continue ");
		scanf("%c", &au8_repeat);

		printf(" ");
		scanf("%c", &au8_repeat);

		if ('E'  == au8_repeat)
		{

			break;
		}

		printf(" ");
		scanf("%c", &au8_repeat);
	}

}

void Motor_Direction_Test (void)
{
	uint8_t au8_TestNumber = ZERO;
	uint8_t au8_Result = RESULT_INITIAL_VALUE;
	uint8_t au8_repeat = ZERO;

	while (TRUE)
	{

		printf("Please enter test number: ");

		scanf("%d",&au8_TestNumber);

		switch (au8_TestNumber)
		{
		case 1:
			gu8_DIO_Write_Return = E_OK;
			au8_Result = Motor_Direction(MOTOR_1,MOTOR_STOP);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;

		case 2:
			gu8_DIO_Write_Return = E_OK;
			au8_Result = Motor_Direction(MOTOR_2,MOTOR_STOP);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;


		case 3:
			gu8_DIO_Write_Return = E_OK;
			au8_Result = Motor_Direction(MOTOR_1,MOTOR_BACKWARD);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;

		case 4:
			gu8_DIO_Write_Return = E_OK;
			au8_Result = Motor_Direction(MOTOR_2,MOTOR_FORWARD);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;


		case 5:
			gu8_DIO_Write_Return = E_NOK;
			au8_Result = Motor_Direction(MOTOR_1,MOTOR_FORWARD);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 6:
			gu8_DIO_Write_Return = E_NOK;
			au8_Result = Motor_Direction(MOTOR_2,MOTOR_STOP);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 7:
			gu8_DIO_Write_Return = E_NOK;
			au8_Result = Motor_Direction(MOTOR_1,MOTOR_BACKWARD);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 8:
			gu8_DIO_Write_Return = E_OK;
			au8_Result = Motor_Direction(MOTOR_1,3);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 9:
			gu8_DIO_Write_Return = E_OK;
			au8_Result = Motor_Direction(MOTOR_2,-1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 10:
			gu8_DIO_Write_Return = E_NOK;
			au8_Result = Motor_Direction(MOTOR_1,3);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 11:
			gu8_DIO_Write_Return = E_NOK;
			au8_Result = Motor_Direction(MOTOR_2,-1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 12:
			gu8_DIO_Write_Return = E_NOK;
			au8_Result = Motor_Direction(MOTOR_1,-1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 13:
			gu8_DIO_Write_Return = E_OK;
			au8_Result = Motor_Direction(3,MOTOR_FORWARD);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 14:
			gu8_DIO_Write_Return = E_OK;
			au8_Result = Motor_Direction(0,MOTOR_BACKWARD);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 15:
			gu8_DIO_Write_Return = E_OK;
			au8_Result = Motor_Direction(-1,MOTOR_STOP);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 16:
			gu8_DIO_Write_Return = E_NOK;
			au8_Result = Motor_Direction(0,MOTOR_FORWARD);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 17:
			gu8_DIO_Write_Return = E_NOK;
			au8_Result = Motor_Direction(3,MOTOR_BACKWARD);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 18:
			gu8_DIO_Write_Return = E_OK;
			au8_Result = Motor_Direction(-1,3);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 19:
			gu8_DIO_Write_Return = E_OK;
			au8_Result = Motor_Direction(3,-1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 20:
			gu8_DIO_Write_Return = E_NOK;
			au8_Result = Motor_Direction(3,3);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;
		case 21:
			gu8_DIO_Write_Return = E_NOK;
			au8_Result = Motor_Direction(-1,-1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		default:
			printf("invalid test number");
			break;
		}

		printf("\nTo exit motor_Direction test press E or any char to continue ");
		scanf("%c", &au8_repeat);

		printf(" ");
		scanf("%c", &au8_repeat);

		if ('E'  == au8_repeat)
		{

			break;
		}

		printf(" ");
		scanf("%c", &au8_repeat);
	}

}

void Motor_Start_Test(void)
{
	uint8_t au8_TestNumber = ZERO;
	uint8_t au8_Result = RESULT_INITIAL_VALUE;
	uint8_t au8_repeat = ZERO;

	while (TRUE)
	{

		printf("Please enter test number: ");

		scanf("%d",&au8_TestNumber);

		switch (au8_TestNumber)
		{
		case 1:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_1,30);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;

		case 2:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_1,0);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;

		case 3:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_1,100);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;

		case 4:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_2,0);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;

		case 5:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_2,100);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;

		case 6:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_2,40);
			printf("The expected output is 0  and the actual output is %d", au8_Result);
			break;

		case 7:
			gu8_PWM_Start_Return = E_NOK;
			au8_Result = Motor_Start(MOTOR_1,0);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 8:
			gu8_PWM_Start_Return = E_NOK;
			au8_Result = Motor_Start(MOTOR_1,100);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 9:
			gu8_PWM_Start_Return = E_NOK;
			au8_Result = Motor_Start(MOTOR_2,0);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 10:
			gu8_PWM_Start_Return = E_NOK;
			au8_Result = Motor_Start(MOTOR_2,100);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 11:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_1,-1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 12:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_1,101);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 13:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_1,150);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 14:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_2,-1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 15:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_2,101);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 16:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(MOTOR_2,200);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 17:
			gu8_PWM_Start_Return = E_NOK;
			au8_Result = Motor_Start(MOTOR_1,-1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 18:
			gu8_PWM_Start_Return = E_NOK;
			au8_Result = Motor_Start(MOTOR_1,101);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 19:
			gu8_PWM_Start_Return = E_NOK;
			au8_Result = Motor_Start(MOTOR_2,-1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 20:
			gu8_PWM_Start_Return = E_NOK;
			au8_Result = Motor_Start(MOTOR_2,101);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 21:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(-1,0);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 22:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(3,101);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 23:
			gu8_PWM_Start_Return = E_NOK;
			au8_Result = Motor_Start(-1,0);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 24:
			gu8_PWM_Start_Return = E_NOK;
			au8_Result = Motor_Start(3,100);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 25:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(-1,-1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 26:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(3,101);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 27:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(-1,101);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 28:
			gu8_PWM_Start_Return = E_OK;
			au8_Result = Motor_Start(3,-1);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		case 29:
			gu8_PWM_Start_Return = E_NOK;
			au8_Result = Motor_Start(-1,101);
			printf("The expected output is 1  and the actual output is %d", au8_Result);
			break;

		default:
			printf("invalid test number");
			break;
		}

		printf("\nTo exit motor_Init test press E or any char to continue ");
		scanf("%c", &au8_repeat);

		printf(" ");
		scanf("%c", &au8_repeat);

		if ('E'  == au8_repeat)
		{

			break;
		}

		printf(" ");
		scanf("%c", &au8_repeat);
	}
}
