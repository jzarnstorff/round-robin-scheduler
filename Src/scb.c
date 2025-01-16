/**
 ******************************************************************************
 * @file    Src/scb.c
 * @author  Jacob Zarnstorff
 * @date    09-January-2025
 * @brief   This file contains the function definition for
 *          enabling processor faults in the system control
 *          block of the Cortex M4 microcontroller and function
 *          handlers for Bus Fault, Hard Fault, Memory Fault,
 *          and Usage Fault exceptions.
 ******************************************************************************
 */

#include "stm32f4xx.h"

/**
 * @brief Enable the Usage Fault, Bus Fault, and Memory Fault
 *        exceptions on the Cortex M4 microcontroller.
 * @param None
 * @retval None
 */
void enable_processor_faults(void) {
    SCB->SHCSR |= (SCB_SHCSR_USGFAULTENA_Msk | SCB_SHCSR_BUSFAULTENA_Msk | SCB_SHCSR_MEMFAULTENA_Msk);
}

/**
 * @brief Function handler to be called when a Bus Fault
 *        Exception handler occurs.
 * @param None
 * @retval None
 */
void BusFault_Handler(void) {
    printf("Exception: BusFault\r\n");
    while (1)
        ;
}

/**
 * @brief Function handler to be called when a Hard Fault
 *        Exception handler occurs.
 * @param None
 * @retval None
 */
void HardFault_Handler(void) {
    printf("Exception: Hardfault\r\n");
    while (1)
        ;
}

/**
 * @brief Function handler to be called when a Memory Fault
 *        Exception handler occurs.
 * @param None
 * @retval None
 */
void MemManage_Handler(void) {
    printf("Exception: MemManage\r\n");
    while (1)
        ;
}

/**
 * @brief Function handler to be called when a Usage Fault
 *        Exception handler occurs.
 * @param None
 * @retval None
 */
void UsageFault_Handler(void) {
    printf("Exception: UsageFault\r\n");
    while (1)
        ;
}
