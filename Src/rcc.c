/*
 * rcc.c
 *
 *  Created on: Feb 1, 2022
 *      Author: AljazJelen
 */

#include "rcc.h"


/**
 * Set the AHB1 clock access to peripheral. See RCC_AHB1ENR.
 * @param[in] periph [e.g. peripheral 8 is 0b 0000 0000 0000 0000 0000 0001 0000 0000]
 */
void RCC_SetAHB1_PeriphClock(uint32_t periph){
	SET_BIT(RCC->AHB1ENR,periph);
}

/**
 * Set the AHB2 clock access to peripheral. See RCC_AHB2ENR.
 * @param[in] periph [e.g. peripheral 8 is 0b 0000 0000 0000 0000 0000 0001 0000 0000]
 */
void RCC_SetAHB2_PeriphClock(uint32_t periph){
	SET_BIT(RCC->AHB2ENR,periph);
}

/**
 * Set the AHB4 clock access to peripheral. See RCC_AHB4ENR.
 * @param[in] periph [e.g. peripheral 8 is 0b 0000 0000 0000 0000 0000 0001 0000 0000]
 */
void RCC_SetAHB4_PeriphClock(uint32_t periph){
	SET_BIT(RCC->AHB4ENR,periph);
}

/**
 * Set the APB1 clock access to peripheral. See RCC_APB1ENR.
 * @param[in] periph [e.g. peripheral 8 is 0b 0000 0000 0000 0000 0000 0001 0000 0000]
 */
void RCC_SetAPB1_PeriphClock(uint32_t periph){
	SET_BIT(RCC->APB1LENR,periph);
}

/**
 * Set the APB2 clock access to peripheral. See RCC_APB2ENR.
 * @param[in] periph [e.g. peripheral 8 is 0b 0000 0000 0000 0000 0000 0001 0000 0000]
 */
void RCC_SetAPB2_PeriphClock(uint32_t periph){
	SET_BIT(RCC->APB2ENR,periph);
}
