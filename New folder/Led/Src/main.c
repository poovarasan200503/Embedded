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

#include<stdint.h>

int main(void){

uint32_t *clockreg = (uint32_t) 0x40023830;  //RCC->AHB1ENR
uint32_t *moderreg = (uint32_t) 0x40020800;  //GPIOD->MODER
uint32_t *odrreg = (uint32_t) 	0x40020814;    //GPIOD->ODR

*clockreg |=(1<<2);

*moderreg |=(1<<30);
*moderreg &= ~(1<<31);



while(1){

	*odrreg &= ~(1<<15);
	for(uint32_t i=0;i<200000;i++);
	*odrreg |= (1<<15);
	for(uint32_t i=0;i<200000;i++);
}

return 0;
}
