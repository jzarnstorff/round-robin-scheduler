/**
 ********************************************************
 * @file    Src/tasks.c
 * @author  Jacob Zarnstorff
 * @date    09-January-2025
 * @brief   This file contains function
 *          definitions for task handlers
 ********************************************************
 */

#include "scheduler.h"
#include <stdio.h>

/**
 * @brief The idle task which is always marked as
 *        `READY` and is never in a blocking state.
 * @param None
 * @retval None
 */
void idle_task(void) {
    while (1)
        ;
}

/**
 * @brief A task to be scheduled that prints a message to the UART
 * @param None
 * @retval None
 */
void task_0_handler(void) {
    while (1) {
        printf("This is task 0\r\n");
        task_delay(125);
    }
}

/**
 * @brief A task to be scheduled that prints a message to the UART
 * @param None
 * @retval None
 */
void task_1_handler(void) {
    while (1) {
        printf("This is task 1\r\n");
        task_delay(250);
    }
}

/**
 * @brief A task to be scheduled that prints a message to the UART
 * @param None
 * @retval None
 */
void task_2_handler(void) {
    while (1) {
        printf("This is task 2\r\n");
        task_delay(500);
    }
}

/**
 * @brief A task to be scheduled that prints a message to the UART
 * @param None
 * @retval None
 */
void task_3_handler(void) {
    while (1) {
        printf("This is task 3\r\n");
        task_delay(1000);
    }
}
