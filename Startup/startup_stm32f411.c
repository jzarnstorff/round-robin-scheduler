#include <stdint.h>

#define SRAM_START 0x20000000UL
#define SRAM_SIZE (128U * 1024U)
#define STACK_START ((SRAM_START) + (SRAM_SIZE))

int main(void);
void __libc_init_array(void);

void Reset_Handler(void);

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));
void WWDG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ADC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SDIO_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
    STACK_START,
    (uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemManage_Handler,
    (uint32_t)BusFault_Handler,
    (uint32_t)UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)SVC_Handler,
    (uint32_t)DebugMon_Handler,
    0,
    (uint32_t)PendSV_Handler,
    (uint32_t)SysTick_Handler,
    (uint32_t)WWDG_IRQHandler,               /* Window Watchdog interrupt */
    (uint32_t)PVD_IRQHandler,                /* EXTI Line 16 interrupt / PVD through EXTI */
    (uint32_t)TAMP_STAMP_IRQHandler,         /* Tamper and TimeStamp interrupts through */
    (uint32_t)RTC_WKUP_IRQHandler,           /* RTC Wakeup interrupt through the EXTI line */
    (uint32_t)FLASH_IRQHandler,              /* FLASH global interrupt */
    (uint32_t)RCC_IRQHandler,                /* RCC global interrupt */
    (uint32_t)EXTI0_IRQHandler,              /* EXTI Line0 interrupt */
    (uint32_t)EXTI1_IRQHandler,              /* EXTI Line1 interrupt */
    (uint32_t)EXTI2_IRQHandler,              /* EXTI Line2 interrupt */
    (uint32_t)EXTI3_IRQHandler,              /* EXTI Line3 interrupt */
    (uint32_t)EXTI4_IRQHandler,              /* EXTI Line4 interrupt */
    (uint32_t)DMA1_Stream0_IRQHandler,       /* DMA1 Stream0 global interrupt */
    (uint32_t)DMA1_Stream1_IRQHandler,       /* DMA1 Stream1 global interrupt */
    (uint32_t)DMA1_Stream2_IRQHandler,       /* DMA1 Stream2 global interrupt */
    (uint32_t)DMA1_Stream3_IRQHandler,       /* DMA1 Stream3 global interrupt */
    (uint32_t)DMA1_Stream4_IRQHandler,       /* DMA1 Stream4 global interrupt */
    (uint32_t)DMA1_Stream5_IRQHandler,       /* DMA1 Stream5 global interrupt */
    (uint32_t)DMA1_Stream6_IRQHandler,       /* DMA1 Stream6 global interrupt */
    (uint32_t)ADC_IRQHandler,                /* ADC1 global interrupt */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    (uint32_t)EXTI9_5_IRQHandler,            /* EXTI Line[9:5] interrupts */
    (uint32_t)TIM1_BRK_TIM9_IRQHandler,      /* TIM1 Break interrupt and TIM9 global interrupt */
    (uint32_t)TIM1_UP_TIM10_IRQHandler,      /* TIM1 Update interrupt and TIM10 global interrupt */
    (uint32_t)TIM1_TRG_COM_TIM11_IRQHandler, /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
    (uint32_t)TIM1_CC_IRQHandler,            /* TIM1 Capture Compare interrupt */
    (uint32_t)TIM2_IRQHandler,               /* TIM2 global interrupt */
    (uint32_t)TIM3_IRQHandler,               /* TIM3 global interrupt */
    (uint32_t)TIM4_IRQHandler,               /* TIM4 global interrupt */
    (uint32_t)I2C1_EV_IRQHandler,            /* I2C1 event interrupt */
    (uint32_t)I2C1_ER_IRQHandler,            /* I2C1 error interrupt */
    (uint32_t)I2C2_EV_IRQHandler,            /* I2C2 event interrupt */
    (uint32_t)I2C2_ER_IRQHandler,            /* I2C2 error interrupt */
    (uint32_t)SPI1_IRQHandler,               /* SPI1 global interrupt */
    (uint32_t)SPI2_IRQHandler,               /* SPI2 global interrupt */
    (uint32_t)USART1_IRQHandler,             /* USART1 global interrupt */
    (uint32_t)USART2_IRQHandler,             /* USART2 global interrupt */
    0,                                       /* Reserved */
    (uint32_t)EXTI15_10_IRQHandler,          /* EXTI Line[15:10] interrupts */
    (uint32_t)RTC_Alarm_IRQHandler,          /* RTC Alarms (A and B) through EXTI line interrupt */
    (uint32_t)OTG_FS_WKUP_IRQHandler,        /* USB On-The-Go FS Wakeup through EXTI line interrupt */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    (uint32_t)DMA1_Stream7_IRQHandler,       /* DMA1 Stream7 global interrupt */
    0,                                       /* Reserved */
    (uint32_t)SDIO_IRQHandler,               /* SDIO global interrupt */
    (uint32_t)TIM5_IRQHandler,               /* TIM5 global interrupt */
    (uint32_t)SPI3_IRQHandler,               /* SPI3 global interrupt */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    (uint32_t)DMA2_Stream0_IRQHandler,       /* DMA2 Stream0 global interrupt */
    (uint32_t)DMA2_Stream1_IRQHandler,       /* DMA2 Stream1 global interrupt */
    (uint32_t)DMA2_Stream2_IRQHandler,       /* DMA2 Stream2 global interrupt */
    (uint32_t)DMA2_Stream3_IRQHandler,       /* DMA2 Stream3 global interrupt */
    (uint32_t)DMA2_Stream4_IRQHandler,       /* DMA2 Stream4 global interrupt */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    (uint32_t)OTG_FS_IRQHandler,             /* USB On The Go FS global interrupt */
    (uint32_t)DMA2_Stream5_IRQHandler,       /* DMA2 Stream5 global interrupt */
    (uint32_t)DMA2_Stream6_IRQHandler,       /* DMA2 Stream6 global interrupt */
    (uint32_t)DMA2_Stream7_IRQHandler,       /* DMA2 Stream7 global interrupt */
    (uint32_t)USART6_IRQHandler,             /* USART6 global interrupt */
    (uint32_t)I2C3_EV_IRQHandler,            /* I2C3 event interrupt */
    (uint32_t)I2C3_ER_IRQHandler,            /* I2C3 error interrupt */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    0,                                       /* Reserved */
    (uint32_t)SPI4_IRQHandler,               /* SPI 4 global interrupt */
    (uint32_t)SPI5_IRQHandler                /* SPI 5 global interrupt  */
};

void Default_Handler(void) {
    while (1)
        ;
}

//*****************************************************************************
//
// The following are constructs created by the linker, indicating where
// the "data" and "bss" segments reside in memory. The initializers for
// the "data" segment resides immediately following the "text" segment.
//
//*****************************************************************************
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _data_load_address;

void Reset_Handler(void) {
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;

    // copy .data section to SRAM
    uint8_t *p_source = (uint8_t *)&_data_load_address; // FLASH
    uint8_t *p_destination = (uint8_t *)&_sdata;        // SRAM
    for (uint32_t i = 0; i < size; ++i)
        *p_destination++ = *p_source++;

    // initialize the .bss section to zero in SRAM
    size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    p_destination = (uint8_t *)&_sbss;
    for (uint32_t i = 0; i < size; ++i)
        *p_destination++ = 0;

    __libc_init_array();

    main();
}
