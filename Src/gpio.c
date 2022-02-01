/*
 * gpio.c
 *
 *  Created on: Feb 1, 2022
 *      Author: AljazJelen
 */

#include "gpio.h"

/**
 * Set the mode of the pin. See GPIOx_MODER.
 * @param[in] GPIOx GPIO Handler
 * @param[in] Pin [e.g. pin 8 is 0b 0000 0000 0000 0000 0000 0001 0000 0000]
 * @param[in] Mode [0 - Input, 1 - Output, 2 - Alternate, 3 - Analog]
 */
void GPIO_SetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode){
	// Clear existing config for particular Pin
	CLEAR_BIT(GPIOx->MODER,(0x3<<(2*Pin)));
	MODIFY_REG(GPIOx->MODER, (0x3 << 2U * POSITION_VAL(Pin)), (Mode <<  2U * POSITION_VAL(Pin)));
}

/**
 * Set the alternate function of the pin.
 * There are 2 registers to be addressed. It depends on the pin location and it is valid for each GPIO port.
 * - Pins 00-07 are in ARFL
 * - Pins 08-16 are in ARFH
 * @param[in] GPIOx GPIO Handler
 * @param[in] Pin [e.g. pin 8 is 0b 0000 0000 0000 0000 0000 0001 0000 0000]
 * @param[in] AltFun [e.g. Alternate Function 9 is 0b 0000 0000 0000 0000 0000 0010 0000 0000]
 */
void GPIO_SetPinAltFun(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t AltFun){
	MODIFY_REG(GPIOx->AFR[POSITION_VAL(Pin)>7],
			0xF 	<< 4U * (1 - POSITION_VAL(Pin)>7) * (POSITION_VAL(Pin)),
			AltFun 	<< 4U * (1 - POSITION_VAL(Pin)>7) * (POSITION_VAL(Pin)));
}
