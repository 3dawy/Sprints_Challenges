/*
 * Steering.c
 *
 * Created: 2/18/2020 6:49:57 PM
 *  Author: Khaled
 */ 

 #include "Steering.h"


 ERROR_STATUS Steering_Init(void)
 {
    /*variable to store errors*/
	 uint8_t Error = E_OK;
	 
	 Error |= Motor_Init(MOTOR_1);

	 Error |= Motor_Init(MOTOR_2);

	 return Error;
 }

 

 ERROR_STATUS Steering_SteerCar(uint8_t Steering_CarCmd, uint8_t speed)
 {
    /*variable to store errors*/
	 uint8_t Error = E_OK;
	 switch (Steering_CarCmd)
	 {
	    case CAR_STOP:
		 Error |= Motor_Direction(MOTOR_1,MOTOR_STOP);
		 Error |= Motor_Direction(MOTOR_2,MOTOR_STOP);
		 break;

		 case CAR_FORWARD:
		 Error |= Motor_Direction(MOTOR_1,MOTOR_FORWARD);
		 Error |= Motor_Direction(MOTOR_2,MOTOR_FORWARD);
		 Error |= Motor_Start(MOTOR_1,30);
		 Error |= Motor_Start(MOTOR_2,30);
		 break;

		 case CAR_BACKWARD:
		 Error |= Motor_Direction(MOTOR_1,MOTOR_BACKWARD);
		 Error |= Motor_Direction(MOTOR_2,MOTOR_BACKWARD);
		 Error |= Motor_Start(MOTOR_1,30);
		 Error |= Motor_Start(MOTOR_2,30);
		 break;

		 case CAR_RIGHT:
		 Error |= Motor_Direction(MOTOR_1,MOTOR_FORWARD);
		 Error |= Motor_Direction(MOTOR_2,MOTOR_BACKWARD);
		 Error |= Motor_Start(MOTOR_1,30);
		 Error |= Motor_Start(MOTOR_2,30);
		 break;

		 case CAR_LEFT:
		 Error |= Motor_Direction(MOTOR_1,MOTOR_BACKWARD);
		 Error |= Motor_Direction(MOTOR_2,MOTOR_FORWARD);
		 Error |= Motor_Start(MOTOR_1,30);
		 Error |= Motor_Start(MOTOR_2,30);
		 break;

		 default:
		 Error |= E_NOK;
		 break;
	 }

	 return Error;
 }