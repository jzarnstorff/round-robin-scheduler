/**
 ********************************************************
 * @file    Inc/scheduler.h
 * @author  Jacob Zarnstorff
 * @date    09-January-2025
 * @brief   This file provides macros for calculating
 *          stack boundaries for the tasks, function
 *          prototypes to initialize tasks and launch
 *          the round robin scheduler, and the definitions
 *          needed for the thread control block which
 *          describes a task to be executed.
 ********************************************************
 */

#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "misc.h"
#include <stdint.h>

#define MAX_TASKS 5 // 1 idle task (always ready; never blocked) + 4 user tasks

#define TICK_HZ_MS (HSI_VALUE / 1000U)

#define SIZE_TASK_STACK (1 * KiB)
#define SIZE_SCHEDULER_STACK (1 * KiB)

#define T0_STACK_START SRAM_END
#define T1_STACK_START ((SRAM_END) - (1 * (SIZE_TASK_STACK)))
#define T2_STACK_START ((SRAM_END) - (2 * (SIZE_TASK_STACK)))
#define T3_STACK_START ((SRAM_END) - (3 * (SIZE_TASK_STACK)))
#define IDLE_STACK_START ((SRAM_END) - (4 * (SIZE_TASK_STACK)))
#define SCHED_STACK_START ((SRAM_END) - (5 * (SIZE_SCHEDULER_STACK)))

/**
 *
 * @brief An enumeration to define all
 *        of the states a task can take
 *
 */
enum task_state {
    READY,  /**< A task's state is marked as READY when it is ready to be scheduled */
    BLOCKED /**< A task's state is marked as BLOCKED when it is doesn't need to be scheduled */
};

/**
 * @brief The Thread Control Block contains thread-specific
 *        information needed to manage the thread.
 */
typedef struct TCB {
    uint32_t psp_value;         /**< The current address of the task's stack pointer */
    uint32_t block_count;       /**< The total count a task should delay in reference to systick */
    uint8_t current_state;      /**< The current state the task is in */
    void (*task_handler)(void); /**< The task's handler function */
} TCB_Type;

#endif // __SCHEDULER_H__
