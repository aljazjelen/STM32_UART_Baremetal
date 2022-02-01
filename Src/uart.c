/*
 * uart.c
 *
 *  Created on: Feb 1, 2022
 *      Author: AljazJelen
 */

#include "uart.h"
#include "rcc.h"
#include "gpio.h"





/**
 * Retargeting part of implementation of printf.
 * \n From now on, USART3 will be used
 * @param[in] ch character to be sent
 */
int __io_putchar(int ch){
	UARTx_Write(USART3,ch);
	return ch;
}

/**
 * USART3 initialization for transmission purposes.
 * \n For STM32H723 nucleo board, following pins are used:
 * - PD8 for Tx
 * - PD9 for Rx
 */
void USART3_Tx_Init(void){
	// Enable clock access to peripheral GPIOD
	RCC_SetAHB4_PeriphClock(RCC_AHB4ENR_GPIODEN);

	// SET PD8 and PD9 to alternate function types
	GPIO_SetPinMode(GPIOD, UART3_TX, GPIO_ALT_MODE);
	GPIO_SetPinAltFun(GPIOD,UART3_TX,GPIO_ALT_FUN_07);

	// Enable clock access to USART3 module
	RCC_SetAPB1_PeriphClock(USART3_EN);

	// Configure USART parameters (baudrate, parity, nmbr of bits)
	UARTx_Config(USART3,USART3_WIDTH_8b,USART3_STOPBITS_1,USART3_STOPBITS_1);
	UARTx_SetBaudrate(USART3, 64000000, 115200);
	UARTx_SetTransferDirection(USART3,USART3_DUPLEX_FULL);

	// Enable USART3
	SET_BIT(USART3->CR1,USART_CR1_UE);

}

/**
 * USART generic write method.
 * \n Applicable for both cases, when FIFO is disabled or enabled.
 * @param[in] USARTx USART Handler
 * @param[in] val Value to be sent over USART (refer to USARTx_ISR and _TDR)
 */
void UARTx_Write(USART_TypeDef *USARTx, uint8_t val){
	// Make sure transmit buffer is empty
	//while (!(READ_BIT(USARTx->ISR,USART_ISR_TXE_TXFNF)));
	while (!((USARTx->ISR & USART_ISR_TXE_TXFNF)==USART_ISR_TXE_TXFNF));
	// Write value in transmit data register
	WRITE_REG(USARTx->TDR,val);
}

/**
 * USART generic configuration method.
 * @param[in] USARTx USART Handler
 * @param[in] DataWidth Width of data (refer to USARTx_CR1)
 * @param[in] Parity Enable of disable parity check (refer to USARTx_CR1)
 * @param[in] StopBits Number of stop bits (refer to USARTx_CR2)
 */
void UARTx_Config(USART_TypeDef *USARTx, uint32_t DataWidth, uint32_t Parity, uint32_t StopBits){
	MODIFY_REG(USARTx->CR1, USART_CR1_PS | USART_CR1_M | USART_CR1_PCE, Parity | StopBits );
	MODIFY_REG(USARTx->CR2, USART_CR2_STOP, StopBits);
}

/**
 * USART generic baudrate selection method.
 * @param[in] USARTx USART Handler
 * @param[in] PeriphClock Peripheral Clock frequency [Hz]
 * @param[in] Baudrate Selectected baudrate for USART
 */
void UARTx_SetBaudrate(USART_TypeDef *USARTx, uint32_t PeriphClock, uint32_t Baudrate){
	USARTx->BRR = UARTx_ComputeDivider(PeriphClock,Baudrate);
}

/**
 * USART generic baudrate divider calculation method.
 * @param[in] PeriphClock Peripheral Clock frequency [Hz]
 * @param[in] Baudrate Selectected baudrate for USART
 * @param[out]	BaudDiv Calculated baudrate divider based on clock and desired baudrate
 */
uint16_t UARTx_ComputeDivider(uint32_t PerpihClock, uint32_t Baudrate){
	return (PerpihClock + (Baudrate/2U))/Baudrate;
}

/**
 * USART generic tranmission selection method.
 * @param[in] USARTx USART Handler
 * @param[in] Direction Transmission direction [Half Duplex, Full Duplex] (refer to USARTx_CR1)
 */
void UARTx_SetTransferDirection(USART_TypeDef *USARTx, uint32_t Direction){
	MODIFY_REG(USARTx->CR1, USART_CR1_TE | USART_CR1_RE, Direction);
}
