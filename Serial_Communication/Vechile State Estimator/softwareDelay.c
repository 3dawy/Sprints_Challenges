/*
 * softwareDelay.c
 *
 * Created: 1/17/2020 6:36:39 PM
 *  Author: 3dawy
 */ 
#include "softwareDelay.h"
#include "std_types.h"

#define NOMBEROFITERATIONSFORONEMILISECOND 98
#define COUNTERINITIALVALUE 0

void softwareDelayMs(uint32_t u32_delay_in_ms)
{
	uint64_t au64_Counter, au64_NomberOfIterrations;
	au64_NomberOfIterrations = u32_delay_in_ms * NOMBEROFITERATIONSFORONEMILISECOND;
	
	for (au64_Counter = COUNTERINITIALVALUE; au64_Counter < au64_NomberOfIterrations; au64_Counter++)
	{
		;
	}
}