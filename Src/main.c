/**
 ******************************************************************************
 * @file           main.c
 * @author         AljazJelen
 * @brief          Bare Metal UART Driver
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32h7xx.h"
#include "rcc.h"
#include "uart.h"
#include "gpio.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


int main(void)
{
	USART3_Tx_Init();
    /* Loop forever */
	while(1){
		printf("Hello world!");
		for (int i = 0; i<500000; i++){}
		printf("from Bare metal UART \n\r");
		for (int i = 0; i<500000; i++){}
	}
}





