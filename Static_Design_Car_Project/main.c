/*
 * Static_Design.c
 *
 * Created: 2/15/2020 5:44:46 PM
 * Author : Khaled
 */ 

 

#include "car_sm.h"


int main(void)
{
    uint8_t Error = E_OK;
	 Error |=  Car_SM_Init();
    while (1) 
    {
	    Error |=  Car_SM_Update();
			
    }

	 return Error;
}
