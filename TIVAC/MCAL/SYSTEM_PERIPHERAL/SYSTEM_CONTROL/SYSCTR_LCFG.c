/*
 * SYSCTR_LCFG.c
 *
 * Created: 4/6/2020 8:18:23 PM
 *  Author: Khaled
 */ 


#include "SYSCTR_LCFG.h"



#define RCGC_GPIO                            0x608   //GPIO Peripheral
#define GPIO_PORTA                          0       //GPIO Channel A
#define GPIO_PORTB                          1       //GPIO Channel B
#define GPIO_PORTC                          2       //GPIO Channel C       
#define GPIO_PORTD                          3       //GPIO Channel D
#define GPIO_PORTE                          4       //GPIO Channel E
#define GPIO_PORTF                          5       //GPIO Channel F

#define RCGC_ADC                             0x638   //ADC Peripheral
#define ADC_Module_0                        0       //ADC Channel 0
#define ADC_Module_1                        1       //ADC Channel 1


SYSCL_Type garrstr_SYSCTR_Cfg[NUMBER_OF_PERIPHERALS]={
                                                      {RCGC_GPIO, GPIO_PORTF}

                                                      };
