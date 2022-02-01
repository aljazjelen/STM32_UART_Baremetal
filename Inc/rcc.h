/*
 * rcc.h
 *
 *  Created on: Feb 1, 2022
 *      Author: AljazJelen
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>
#include "stm32h7xx.h"

void RCC_SetAHB1_PeriphClock(uint32_t periph);
void RCC_SetAHB2_PeriphClock(uint32_t periph);
void RCC_SetAHB4_PeriphClock(uint32_t periph);
void RCC_SetAPB1_PeriphClock(uint32_t periph);
void RCC_SetAPB2_PeriphClock(uint32_t periph);


#endif /* RCC_H_ */
