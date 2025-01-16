/**
 ********************************************************
 * @file    Inc/uart.h
 * @author  Jacob Zarnstorff
 * @date    09-January-2025
 * @brief   This file contains function prototypes for
 *          to enable TX pin on USART2 for the STM32F4xx
 *          microcontroller.
 ********************************************************
 */

#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>

void init_usart2_tx(uint32_t baud_rate);

#endif // __UART_H__
