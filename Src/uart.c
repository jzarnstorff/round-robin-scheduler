/**
 ********************************************************
 * @file    Src/uart.c
 * @author  Jacob Zarnstorff
 * @date    09-January-2025
 * @brief   This file contains the function definition
 *          to enable TX pin on USART2 for the STM32F4xx
 *          microcontroller.
 ********************************************************
 */

#include "stm32f4xx_conf.h"
#include <stdint.h>

/**
 * @brief Initialize and enable the transmit pin of USART2.
 * @param baud_rate The desired baud rate USART2 should transmit data.
 * @retval None
 */
void init_usart2_tx(uint32_t baud_rate) {
    GPIO_InitTypeDef GPIO_InitStruct = {
        .GPIO_Pin = GPIO_Pin_2,
        .GPIO_Mode = GPIO_Mode_AF,
        .GPIO_Speed = GPIO_Speed_2MHz,
        .GPIO_OType = GPIO_OType_PP,
        .GPIO_PuPd = GPIO_PuPd_NOPULL
    };

    USART_InitTypeDef USART_InitStruct = {
        .USART_BaudRate = baud_rate,
        .USART_WordLength = USART_WordLength_8b,
        .USART_StopBits = USART_StopBits_1,
        .USART_Parity = USART_Parity_No,
        .USART_Mode = USART_Mode_Tx,
        .USART_HardwareFlowControl = USART_HardwareFlowControl_None
    };

    // enable clock to AHB1
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    // initialize GPIO PA2 and set alternate function as USART2_TX
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);

    // enable clock for USART2 on APB1
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

    // intialize and enable USART2 for transmit only
    USART_Init(USART2, &USART_InitStruct);
    USART_Cmd(USART2, ENABLE);
}
