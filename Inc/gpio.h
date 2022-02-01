/*
 * gpio.h
 *
 *  Created on: Feb 1, 2022
 *      Author: AljazJelen
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include "stm32h7xx.h"

#define GPIO_IN_MODE		(0x0)		// Input Mode
#define GPIO_OUT_MODE		(0x1)		// Output Mode
#define GPIO_ALT_MODE		(0x2)		// Alternative Function Mode
#define GPIO_ANALOG_MODE	(0x3)		// Analog Mode

#define GPIO_ALT_FUN_00		(0x0)		// Alternate Function 0
#define GPIO_ALT_FUN_01		(0x1)		// Alternate Function 1
#define GPIO_ALT_FUN_02		(0x2)		// Alternate Function 2
#define GPIO_ALT_FUN_03		(0x3)		// Alternate Function 3
#define GPIO_ALT_FUN_04		(0x4)		// Alternate Function 4
#define GPIO_ALT_FUN_05		(0x5)		// Alternate Function 5
#define GPIO_ALT_FUN_06		(0x6)		// Alternate Function 6
#define GPIO_ALT_FUN_07		(0x7)		// Alternate Function 7
#define GPIO_ALT_FUN_08		(0x8)		// Alternate Function 8
#define GPIO_ALT_FUN_09		(0x9)		// Alternate Function 9
#define GPIO_ALT_FUN_10		(0xA)		// Alternate Function 10
#define GPIO_ALT_FUN_11		(0xB)		// Alternate Function 11
#define GPIO_ALT_FUN_12		(0xC)		// Alternate Function 12
#define GPIO_ALT_FUN_13		(0xD)		// Alternate Function 13
#define GPIO_ALT_FUN_14		(0xE)		// Alternate Function 14
#define GPIO_ALT_FUN_15		(0xF)		// Alternate Function 15

void GPIO_SetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode);
void GPIO_SetPinAltFun(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t AltFun);

#endif /* GPIO_H_ */
