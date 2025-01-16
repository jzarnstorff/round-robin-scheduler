/**
 ********************************************************
 * @file    Src/scheduler.c
 * @author  Jacob Zarnstorff
 * @date    09-January-2025
 * @brief   This file contains function definitions for
 *          initializing tasks, launching the round robin
 *          scheduler, and the interrupt service routines
 *          that is used switching context between tasks.
 ********************************************************
 */

#include "scheduler.h"
#include "stm32f4xx.h"
#include "tasks.h"
#include <stdint.h>
#include <stdlib.h>

uint8_t current_task = 1;
uint32_t g_tick_count = 0;

TCB_Type user_tasks[MAX_TASKS] = {
    {.psp_value = IDLE_STACK_START, .task_handler = idle_task},
    {.psp_value = T0_STACK_START, .task_handler = task_0_handler},
    {.psp_value = T1_STACK_START, .task_handler = task_1_handler},
    {.psp_value = T2_STACK_START, .task_handler = task_2_handler},
    {.psp_value = T3_STACK_START, .task_handler = task_3_handler}
};

/**
 * @brief Initialize the SysTick timer on the Cortex M4 microcontroller.
 * @param tick_hz Value in cycles per second the SysTick interrupt should trigger.
 * @retval None
 */
static void init_systick_timer(uint32_t tick_hz) {
    SysTick_Config(tick_hz);
}

/**
 * @brief Initialize a dummy stack frame for all tasks.
 * @param None
 * @retval None
 */
void init_tasks_stack(void) {
    uint32_t *p_PSP = NULL;

    for (size_t i = 0; i < MAX_TASKS; ++i) {
        user_tasks[i].current_state = READY;
        p_PSP = (uint32_t *)user_tasks[i].psp_value;
        --p_PSP;
        *p_PSP = xPSR_T_Msk;

        --p_PSP; // program counter
        *p_PSP = (uint32_t)user_tasks[i].task_handler;

        --p_PSP; // link register
        *p_PSP = 0xFFFFFFFD;

        // configure CPU registers R0-R12 with dummy
        // values of 0 in task's private stack
        for (unsigned char j = 0; j < 13; ++j) {
            --p_PSP;
            *p_PSP = 0;
        }

        user_tasks[i].psp_value = (uint32_t)p_PSP;
    }
}

/**
 * @brief A delay to simulate work for a task.
 * @param tick_count Value in number of ticks in reference to SysTick a task will delay.
 * @retval None
 */
void task_delay(uint32_t tick_count) {
    __disable_irq();

    if (current_task) {
        user_tasks[current_task].block_count = g_tick_count + tick_count;
        user_tasks[current_task].current_state = BLOCKED;
        SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
    }

    __enable_irq();
}

/**
 * @brief Set the address for the Main Stack Pointer (MSP) of the Cortex M4 microcontroller.
 * @param scheduler_stack_start The desired address in RAM the MSP should point to.
 * @retval None
 */
__attribute__((naked)) void init_scheduler_stack(uint32_t scheduler_stack_start) {
    __set_MSP(scheduler_stack_start);
    __asm volatile("BX LR");
}

/**
 * @brief Switch from using the Main Stack Pointer (MSP) to the Process Stack Pointer (PSP).
 * @param None
 * @retval None
 */
__attribute__((naked)) static void switch_sp_to_psp(void) {
    // initialize the PSP with TASK1 stack start

    // get the value of PSP of current_task
    __asm volatile("PUSH {LR}");        // preserve LR which returns back to main
    __asm volatile("BL get_psp_value"); // stack of current_task will be stored in R0
    __asm volatile("MSR PSP, R0");      // initialize PSP
    __asm volatile("POP {LR}");         // pops back LR value

    // change SP to PSP using CONTROL register
    __asm volatile("MOV R0, #0X02");
    __asm volatile("MSR CONTROL, R0");
    __asm volatile("BX LR");
}

/**
 * @brief Initialize the SysTick timer, switch from using the Main Stack Pointer (MSP) to
 *        the Process Stack Pointer (PSP), and call the task handler of the current task.
 * @param tick_hz Value in cycles per second the SysTick interrupt should trigger.
 * @retval None
 */
void launch_scheduler(uint32_t systick_hz) {
    init_systick_timer(systick_hz);
    switch_sp_to_psp();
    user_tasks[current_task].task_handler();
}

/**
 * @brief Get the Process Stack Pointer (PSP) address of the current running task.
 * @param None
 * @retval The address of the current task's stack pointer.
 */
static uint32_t get_psp_value(void) {
    return user_tasks[current_task].psp_value;
}

/**
 * @brief Update the Process Stack Pointer (PSP) address of the current running task to a new value.
 * @param current_psp_value The new address of the current task's stack pointer.
 * @retval None
 */
static void save_psp_value(uint32_t current_psp_value) {
    user_tasks[current_task].psp_value = current_psp_value;
}

/**
 * @brief Update the value of `current_task` to the next task in the READY state
 *        in a round robin fashion. If the state of all user-defined tasks are set
 *        to BLOCKED, the idle task is chosen.
 * @param None
 * @retval None
 */
static void update_next_task(void) {
    int state = BLOCKED;

    for (size_t i = 0; i < MAX_TASKS; ++i) {
        current_task = (current_task + 1) % MAX_TASKS; // attempt to set current_task to the next task
        state = user_tasks[current_task].current_state;
        if ((state == READY) && (current_task != 0)) // check if this task is marked as READY; IDLE task is always ready
            break; // if any task is ready, we exit loop and local variable `state` will be assigned READY
    }

    if (state != READY)   // all tasks blocked
        current_task = 0; // set current_task to the idle task
}

/**
 * @brief Interrupt Service Routine for the PendSV exception which handles the
 *        context switching between tasks. The PendSV exception is chosen to do
 *        the context switching due to the exception having the lowest priority.
 *        If the context switching was carried out in an interrupt with a very
 *        high priority like the SysTick handler, there could be a possibility
 *        of an interrupt with a lower priority being pre-empted in the middle
 *        of an ISR by the SysTick hanlder. This would lead to the context being
 *        switched back to a task instead of returning to back the ISR that was
 *        interrupted leading to a UsageFault.
 * @param None
 * @retval None
 */
__attribute__((naked)) void PendSV_Handler(void) {
    /* Save the context of current_task */
    // get current running task's PSP value
    __asm volatile("MRS R0, PSP");

    // using that PSP value, store SF2 [R4:R11]
    // STMDB = store multiple registers and decrement before
    __asm volatile("STMDB R0!, {R4-R11}");

    // save the current value of PSP
    __asm volatile("PUSH {LR}");
    __asm volatile("BL save_psp_value");

    /* Retrieve the context of next task */
    // decide next task to run
    __asm volatile("BL update_next_task");

    // get its past PSP value
    __asm volatile("BL get_psp_value");

    // using that PSP value, retrieve SF2 [R4:R11]
    // LDMIA = load multiple registers and increment after
    __asm volatile("LDMIA R0!, {R4-R11}");

    // update PSP and exit
    __asm volatile("MSR PSP, R0");
    __asm volatile("POP {LR}");
    __asm volatile("BX LR");
}

/**
 * @brief Update the the global tick count.
 * @param None
 * @retval None
 */
static void update_global_tick_count(void) {
    g_tick_count++;
}

/**
 * @brief Cycles through all tasks to mark any/all task states to READY, if possible.
 * @param None
 * @retval None
 */
static void unblock_tasks(void) {
    for (size_t i = 1; i < MAX_TASKS; ++i) {
        if (user_tasks[i].current_state != READY)
            if (user_tasks[i].block_count == g_tick_count)
                user_tasks[i].current_state = READY;
    }
}

/**
 * @brief Interrupt Service Routine for the SysTick exception which updates the
 *        global tick count, marks any/all task states to READY, if possible,
 *        and pends the PendSV exception to perform the context switching in a
 *        round robin fashion.
 * @param None
 * @retval None
 */
void SysTick_Handler(void) {
    update_global_tick_count();
    unblock_tasks();
    SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}
