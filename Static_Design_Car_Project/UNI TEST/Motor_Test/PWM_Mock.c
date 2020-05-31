/*
 * PWM_Mock.c
 *
 *  Created on: Feb 21, 2020
 *      Author: Khaled
 */


#include "PWM.h"


extern uint8_t gu8_PWM_Init_Return;
extern uint8_t gu8_PWM_Start_Return;


ERROR_STATUS Pwm_Init(Pwm_Cfg_s *Pwm_Cfg)
{
	return gu8_PWM_Init_Return;

}
ERROR_STATUS Pwm_Start(uint8_t Channel,uint8_t Duty,uint8_t Frequncy)
{
	return gu8_PWM_Start_Return;
}
