/**
 ********************************************************
 * @file    Inc/misc.h
 * @author  Jacob Zarnstorff
 * @date    09-January-2025
 * @brief   This file contains miscellaneous defines
 *          for the Cortex M4 microcontroller.
 ********************************************************
 */

#ifndef __MISC_H__
#define __MISC_H__

#include "stm32f4xx.h"

#define KiB 1024U

#define SIZE_SRAM ((128U) * (KiB))
#define SRAM_END ((SRAM1_BASE) + (SIZE_SRAM))

#endif // __MISC_H__
