/*
 * Delay.c
 *
 * Created: 2/18/2020 8:42:23 AM
 *  Author: Khaled
 */ 


 #include "Delay.h"
 

#define  NUMBER_OF_TICKS_FOR_ONE_MS 250
#define  COUNTER_OF_MS_INITIAL_VALUE 0

 ERROR_STATUS Delay_ms (uint8_t Timer_Chan,uint16_t Time)
 {
    uint8_t Error = E_OK;
	 uint8_t au8_Data = ZERO;
    uint16_t au16_Counter_Of_ms = ZERO;
    
	 
	 
	 

    Timer_Cfg_ST Timer_Info;
    Timer_Info.Timer_Ch = Timer_Chan;
    Timer_Info.Timer_Interrupt_Mode = TIMER_MODE_POLLING;
    Timer_Info.Timer_PreScaler = PRESCALER_64;
    Timer_Info.Timer_Mode = ZERO;
	 
	 
	 
    
	 
	 Error |=  Timer_Init (&Timer_Info);

	 
    


	    for (au16_Counter_Of_ms = COUNTER_OF_MS_INITIAL_VALUE; au16_Counter_Of_ms < Time; au16_Counter_Of_ms++)
	    {

		    
			 Error |=  Timer_Start(Timer_Chan,NUMBER_OF_TICKS_FOR_ONE_MS);
			 
		    Error |=  Timer_Get_Status(Timer_Chan,&au8_Data);
			 
		    while (!au8_Data)
		    {
				 Error |=  Timer_Get_Status(Timer_Chan,&au8_Data);
		    }
			 
		    Error |=  Timer_Stop(Timer_Chan);
		  
		  
	    }
	    
    return Error;
 }