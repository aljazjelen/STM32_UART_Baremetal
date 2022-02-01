/*
 * uart.h
 *
 *  Created on: Feb 1, 2022
 *      Author: AljazJelen
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "stm32h7xx.h"

uint16_t UARTx_ComputeDivider(uint32_t PerpihClock, uint32_t Baudrate);
void UARTx_Config(USART_TypeDef *USARTx, uint32_t DataWidth, uint32_t Parity, uint32_t StopBits);
void UARTx_SetBaudrate(USART_TypeDef *USARTx, uint32_t PeriphClock, uint32_t Baudrate);
void UARTx_Write(USART_TypeDef *USARTx, uint8_t val);
void UARTx_SetTransferDirection(USART_TypeDef *USARTx, uint32_t Direction);
void USART3_Tx_Init(void);


/****************** Definition for USART3  ********************/

#define UART3_TX			(1U << 8)	// Pin mask for GPIOD
#define USART3_EN			(1U << 18)	// Enable mask for USART3 clock
#define USART3_WIDTH_8b		(0U << 0)	// Word Length
#define USART3_PARITY_NONE	(0U << 0)	// No Parity
#define USART3_STOPBITS_1	(0U << 0)	// 1 Stopbit
#define USART3_DUPLEX_FULL	(0x3 << 3)	// Full Duplex


#endif /* UART_H_ */
