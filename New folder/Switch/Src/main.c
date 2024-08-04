/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
int main(void)
{
    uint32_t *abh1enr = 0x40023830;  //ABH1 -enr
    uint32_t *moderB = 0x40020400;  //port B
    uint32_t *moderD = 0x40020C00;  //port D

    uint32_t *idrB = 0x40020410; //input
    uint32_t *odrD = 0x40020C14; //output

    uint32_t *pullB = 0x4002040c; //pull (up or down)

    *abh1enr |=(1<<1);  //clock to port -->B
    *abh1enr |=(1<<3);  //clock to port -->D

    *moderB &=~(1<<0); //set as input
    *moderB &=~(1<<1);

    *moderD |=(1<<30);  //set as output
    *moderD &=~(1<<31);

//    *pullB &=~(1<<0);  //pulldown
//    *pullB |=(1<<1);   //+5v should be externaly connect  and groung is internally connected

    *pullB |=(1<<0); //pullup
    *pullB &=~(1<<1); //ground should be externaly connect  and +5v is internally connected

    while(1)
    {
    	if(*idrB &(1<<0)==1)
    	{
    		*odrD |=(1<<15);
    	}
    	else
    	{
			*odrD &=~(1<<15);
    	}
    }


}
