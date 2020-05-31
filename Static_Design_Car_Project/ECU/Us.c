/*
 * Us.c
 *
 * Created: 2/18/2020 12:39:51 AM
 *  Author: Khaled
 */ 

 #include "Us.h"
 
 #include "delay.h"

 #define TRIGGER_DELAY_TIME 1
 #define US_WAVE_SPEED  170
 #define FACTOR   10000

 ERROR_STATUS Us_Init(void)
 {
    /*variable to store errors*/
	 uint8_t Error= E_OK;
	 
	 Icu_cfg_s Icu_Info;
	 DIO_Cfg_s Dio_Info;

	 /*initialize the SWICU*/
	 Icu_Info.ICU_Ch_No = ICU_CH2;
	 Icu_Info.ICU_Ch_Timer = ICU_TIMER_CH0;
	 /*initialize the DIO trigger pin*/
	 Dio_Info.dir = OUTPUT;
	 Dio_Info.GPIO = GPIOA;
	 Dio_Info.pins = PIN0;

	 Error |= Icu_Init(&Icu_Info);

	 Error |= DIO_init(&Dio_Info);

	 return Error;
 }


 ERROR_STATUS Us_Trigger(void)
 {
    /*variable to store errors*/
	 uint8_t Error = E_OK;
	 
	 Error |= DIO_Write(GPIOA,PIN0,HIGH);
	 /*Delay_ms(Timer_2,1);*/
	 Delay_ms(Timer_2, TRIGGER_DELAY_TIME);
	 Error |= DIO_Write(GPIOA,PIN0,LOW);

	 return Error;
 }


 ERROR_STATUS Us_GetDistance(uint16_t *Distance)
 {
    uint32_t Icu_Time = ZERO;
	 /*variable to store errors*/
	 uint8_t Error = E_OK;

	 Error |= Icu_ReadTime(ICU_CH2,ICU_RISE_TO_FALL, &Icu_Time);

	 *Distance = (Icu_Time * US_WAVE_SPEED) / FACTOR;

	 return Error;
 }
