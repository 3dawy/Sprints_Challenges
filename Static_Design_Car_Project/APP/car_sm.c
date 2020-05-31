/*
 * car_sm.c
 *
 * Created: 2/18/2020 7:37:43 PM
 *  Author: Khaled
 */ 


 #include "car_sm.h"
 #include "delay.h"

 #define TURN_RIGHT 1
 #define GO_FORWARD 2
 #define GO_BACK 3

 #define MIN_DISTANCE      25
 #define MAX_DISTANCE      30
 #define CAR_TURN_SPEED    30  
 #define CAR_SPEED         10 
 #define TURN_DELAY_TIME   500

 ERROR_STATUS Car_SM_Init(void)
 {
    /*variable to store errors*/
	 uint8_t Error = E_OK;

	 Error |= Us_Init();

	 Error |= Steering_Init();

	 Error |= Steering_SteerCar(CAR_FORWARD,CAR_SPEED);

	 return Error;
 }


 ERROR_STATUS Car_SM_Update(void)
 {
    uint16_t au16_Distance = ZERO;
	 /*variable to store errors*/
	 uint8_t Error = E_OK;
    uint8_t State = ZERO;
	 Us_Trigger();

	 Us_GetDistance(&au16_Distance);

	 /*check the distance if it between 30 and 25 cm turn*/
	 if ((au16_Distance >= MIN_DISTANCE) && (au16_Distance <= MAX_DISTANCE))
	 {
	    State = TURN_RIGHT;
	 }
	 /*check the distance if it more than 30 cm forward*/
	 else if (au16_Distance > MAX_DISTANCE)
	 {
	    State = GO_FORWARD;
	 }
	 /*check the distance if it less than 25 cm reverse*/
	 else if (au16_Distance < MIN_DISTANCE)
	 {
	    State = GO_BACK;
	 }

	 switch (State)
	 {
	    case TURN_RIGHT:


		 Error |= Steering_SteerCar(CAR_STOP,CAR_TURN_SPEED);

		 Error |= Steering_SteerCar(CAR_RIGHT,CAR_TURN_SPEED);
		 Delay_ms(Timer_2,TURN_DELAY_TIME);
		 break;

		 case GO_FORWARD:
		 Error |= Steering_SteerCar(CAR_FORWARD,CAR_SPEED);
		 break;

		 case GO_BACK:
		 Error |= Steering_SteerCar(CAR_BACKWARD,CAR_SPEED);
		 break;
		 

		 default:
		 Error |= E_NOK;
		 break;
	 }

	 return Error;
 }