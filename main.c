#include "scb.h"
#include "scheduler.h"
#include "uart.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void) {
    enable_processor_faults();
    init_usart2_tx(115200);

    init_scheduler_stack(SCHED_STACK_START);
    init_tasks_stack();
    launch_scheduler(TICK_HZ_MS);
}
