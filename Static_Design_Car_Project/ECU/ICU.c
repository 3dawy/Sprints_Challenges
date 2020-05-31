/*
 * ICU.c
 *
 * Created: 2/17/2020 6:21:56 PM
 *  Author: Khaled
 */ 


 #include "ICU.h"



 #define Rising_Enter 0
 #define Falling_Enter 1
 #define NUMBER_OF_COUNTS_FOR_100_US 200
 #define TIME_OF_EACH_COUNT 100


 ERROR_STATUS Icu_Init(Icu_cfg_s * Icu_Cfg)
 {
    /*variable to store errors*/
	 uint8_t Error = E_OK;

	 DIO_Cfg_s Dio_Info;

	 Timer_Cfg_ST Timer_Info;

	 /*check if the given pointer is null  return error*/
	 if (NULL == Icu_Cfg)
	 {
	    Error |= E_NOK;
	 }

	 else
	 {
	    switch(Icu_Cfg->ICU_Ch_No)
		 {
		    case ICU_CH2:
			 /*set BIT2 Port B input*/
			 Dio_Info.dir = INPUT;
			 Dio_Info.GPIO = GPIOC;
			 Dio_Info.pins = BIT2;
			 DIO_init(&Dio_Info);
			 break;

			 default:
			 Error |= E_NOK;
			 break;
		 }

		 switch (Icu_Cfg->ICU_Ch_Timer)
		 {
			 case ICU_TIMER_CH0:
			 /*set timer 0 with pre-scaler 8 and polling mode*/
			 Timer_Info.Timer_Ch = Timer_0;
			 Timer_Info.Timer_Interrupt_Mode = TIMER_MODE_POLLING;
			 Timer_Info.Timer_Mode = TIMER_MODE;
			 Timer_Info.Timer_PreScaler = PRESCALER_8;
			 Timer_Init(&Timer_Info);
			 break;

			 default:
			 Error |= E_NOK;
			 break;
		 }

	 }
	 return Error;
 }


 ERROR_STATUS Icu_ReadTime(uint8_t Icu_Channel, uint8_t Icu_EdgeToEdge, uint32_t * Icu_Time)
 {
    /*variable to store errors*/
	 uint8_t Error = E_OK;
	 uint8_t  Pin_Data = ZERO;
	 uint8_t  Timer_Data = ZERO;
	 uint8_t  Number_Timer_Count = ZERO;
	 
	 switch (Icu_Channel)
	 {
	    case ICU_CH2:
		 switch (Icu_EdgeToEdge)
		 {
		    case ICU_RISE_TO_FALL:
			 DIO_Read(GPIOC,PIN2,&Pin_Data);
			 /*if the pin is HIGH wait for the next pulse to ensure that you read the pulse form the beginning*/
			 while (Pin_Data)DIO_Read(GPIOC,PIN2,&Pin_Data);
			 /*wait for the next pulse to start the timer and stop it at the end of the pulse*/
			 while (!Pin_Data)DIO_Read(GPIOC,PIN2,&Pin_Data);
			 while (Pin_Data)
			 {
			    Timer_Start(Timer_0,NUMBER_OF_COUNTS_FOR_100_US); //200 count equal 100us
			    Timer_Get_Status(Timer_0,&Timer_Data);
			    while (!Timer_Data)
			    {
				    Timer_Get_Status(Timer_0,&Timer_Data);
			    }
				 Number_Timer_Count ++;
				 DIO_Read(GPIOC,PIN2,&Pin_Data);
			 }
			 Timer_Stop(Timer_0);
			 
			 /*calculate the real time for HIGH part of the pulse using number of timer count and time of each count*/
			 *Icu_Time =  Number_Timer_Count * TIME_OF_EACH_COUNT;
			 break;

			 default:
			 Error |= E_NOK;
			 break;
		 }
		 break;

		 default:
		 Error |= E_NOK;
		 break;
	 }

	 return Error;
 }

 