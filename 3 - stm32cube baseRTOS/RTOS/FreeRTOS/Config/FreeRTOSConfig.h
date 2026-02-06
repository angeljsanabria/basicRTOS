/*
 * FreeRTOS Kernel V10.5.1
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

/* Ensure stdint.h is available for all compilers. */
#include <stdint.h>

/*-----------------------------------------------------------
 * Clock Configuration
 *----------------------------------------------------------*/
/* System clock is 120MHz */
#define configCPU_CLOCK_HZ                ( 120000000UL )
#define configSYSTICK_CLOCK_HZ            ( configCPU_CLOCK_HZ )

/*-----------------------------------------------------------
 * FreeRTOS Kernel Configuration
 *----------------------------------------------------------*/
/* Tick rate in Hz */
#define configTICK_RATE_HZ                ( ( TickType_t ) 1000 )

/* Maximum priority levels */
#define configMAX_PRIORITIES              ( 5 )

/* Minimal stack size (in words, not bytes) */
#define configMINIMAL_STACK_SIZE          ( ( uint16_t ) 128 )

/* Total heap size (in bytes) */
#define configTOTAL_HEAP_SIZE             ( ( size_t ) ( 32 * 1024 ) )

/*-----------------------------------------------------------
 * Scheduler Configuration
 *----------------------------------------------------------*/
/* Use preemptive scheduler */
#define configUSE_PREEMPTION              1

/* Use time slicing */
#define configUSE_TIME_SLICING           1

/* Use tickless idle (low power) */
#define configUSE_TICKLESS_IDLE          0

/*-----------------------------------------------------------
 * Task Configuration
 *----------------------------------------------------------*/
/* Maximum task name length */
#define configMAX_TASK_NAME_LEN           ( 16 )

/* Use task notifications */
#define configUSE_TASK_NOTIFICATIONS     1

/* Task notification array entries */
#define configTASK_NOTIFICATION_ARRAY_ENTRIES 1

/*-----------------------------------------------------------
 * Memory Management
 *----------------------------------------------------------*/
/* Support dynamic allocation */
#define configSUPPORT_DYNAMIC_ALLOCATION 1

/* Support static allocation */
#define configSUPPORT_STATIC_ALLOCATION  0

/* Check for stack overflow */
#define configCHECK_FOR_STACK_OVERFLOW   1

/*-----------------------------------------------------------
 * Hook Functions
 *----------------------------------------------------------*/
/* Idle task hook */
#define configUSE_IDLE_HOOK              0

/* Tick hook */
#define configUSE_TICK_HOOK              0

/* Malloc failed hook */
#define configUSE_MALLOC_FAILED_HOOK     0

/*-----------------------------------------------------------
 * Queue Configuration
 *----------------------------------------------------------*/
/* Maximum queue length */
#define configQUEUE_REGISTRY_SIZE        10

/*-----------------------------------------------------------
 * Timer Configuration
 *----------------------------------------------------------*/
/* Use software timers */
#define configUSE_TIMERS                 0

/* Timer task priority */
#define configTIMER_TASK_PRIORITY        ( configMAX_PRIORITIES - 1 )

/* Timer queue length */
#define configTIMER_QUEUE_LENGTH         10

/* Timer task stack depth */
#define configTIMER_TASK_STACK_DEPTH     ( configMINIMAL_STACK_SIZE * 4 )

/*-----------------------------------------------------------
 * Interrupt Configuration
 *----------------------------------------------------------*/
/* Include CMSIS header to get __NVIC_PRIO_BITS */
#include "stm32l4xx.h"

/* Lowest interrupt priority that can call FreeRTOS API functions */
/* Value: 5 (0-15 range, where 0 is highest priority) */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 5

/* Kernel interrupt priority (must be >= configMAX_SYSCALL_INTERRUPT_PRIORITY) */
/* For STM32L4: __NVIC_PRIO_BITS = 4, so shift by (8-4) = 4 bits */
#define configKERNEL_INTERRUPT_PRIORITY  ( configMAX_SYSCALL_INTERRUPT_PRIORITY << (8 - __NVIC_PRIO_BITS) )

/*-----------------------------------------------------------
 * Cortex-M Specific Configuration
 *----------------------------------------------------------*/
/* Use 32-bit tick type */
#define configUSE_16_BIT_TICKS           0

/* Use port optimized task selection (Cortex-M specific) */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1

/*-----------------------------------------------------------
 * Optional Features
 *----------------------------------------------------------*/
/* Use mutexes */
#define configUSE_MUTEXES                1

/* Use recursive mutexes */
#define configUSE_RECURSIVE_MUTEXES      1

/* Use counting semaphores */
#define configUSE_COUNTING_SEMAPHORES    1

/* Use event groups */
#define configUSE_EVENT_GROUPS          1

/* Use stream buffers */
#define configUSE_STREAM_BUFFERS        1

/* Use message buffers */
#define configUSE_MESSAGE_BUFFERS       1

/*-----------------------------------------------------------
 * Include/Exclude API Functions
 *----------------------------------------------------------*/
/* Include vTaskPrioritySet */
#define INCLUDE_vTaskPrioritySet         1

/* Include uxTaskPriorityGet */
#define INCLUDE_uxTaskPriorityGet         1

/* Include vTaskDelete */
#define INCLUDE_vTaskDelete              1

/* Include vTaskSuspend */
#define INCLUDE_vTaskSuspend            1

/* Include xTaskDelayUntil */
#define INCLUDE_xTaskDelayUntil          1

/* Include xTaskDelay */
#define INCLUDE_vTaskDelay               1

/* Include xTaskGetIdleTaskHandle */
#define INCLUDE_xTaskGetIdleTaskHandle  0

/* Include xTaskAbortDelay */
#define INCLUDE_xTaskAbortDelay          0

/* Include xTaskGetHandle */
#define INCLUDE_xTaskGetHandle           0

/* Include uxTaskGetStackHighWaterMark */
#define INCLUDE_uxTaskGetStackHighWaterMark 1

/* Include uxTaskGetStackHighWaterMark2 */
#define INCLUDE_uxTaskGetStackHighWaterMark2 1

/* Include eTaskGetState */
#define INCLUDE_eTaskGetState            1

/* Include xTaskResumeFromISR */
#define INCLUDE_xTaskResumeFromISR       1

/* Include xTimerPendFunctionCall */
#define INCLUDE_xTimerPendFunctionCall    0

/* Include xTaskGetSchedulerState */
#define INCLUDE_xTaskGetSchedulerState   1

/* Include xTaskGetCurrentTaskHandle */
#define INCLUDE_xTaskGetCurrentTaskHandle 1

/*-----------------------------------------------------------
 * Assert and Trace
 *----------------------------------------------------------*/
/* Assert configuration */
#ifdef DEBUG
    extern void vAssertCalled( const char *pcFile, unsigned long ulLine );
    #define configASSERT( x ) if( ( x ) == 0 ) vAssertCalled( __FILE__, __LINE__ )
#else
    #define configASSERT( x )
#endif

/* Trace facility */
#define configUSE_TRACE_FACILITY         0

/* Generate run time stats */
#define configGENERATE_RUN_TIME_STATS    0

/*-----------------------------------------------------------
 * Co-routines (deprecated, not recommended)
 *----------------------------------------------------------*/
#define configUSE_CO_ROUTINES            0
#define configMAX_CO_ROUTINE_PRIORITIES  ( 2 )

/*-----------------------------------------------------------
 * Software Timer Definitions
 *----------------------------------------------------------*/
/* Backward compatibility */
#define xTimerGetTimerDaemonTaskHandle   xTimerGetTimerTaskHandle

/*-----------------------------------------------------------
 * Error Handling
 *----------------------------------------------------------*/
/* Application heap allocated externally */
#define configAPPLICATION_ALLOCATED_HEAP 0

/*-----------------------------------------------------------
 * Platform Specific Definitions
 *----------------------------------------------------------*/
/* Set to 1 if the port being used includes an MPU */
#define configENABLE_MPU                 0

/* Set to 1 if the port being used includes an FPU */
#define configENABLE_FPU                 1

/* Set to 1 if the port being used includes an MVE */
#define configENABLE_MVE                 0

/* Set to 1 if the port being used includes TrustZone */
#define configENABLE_TRUSTZONE           0

/*-----------------------------------------------------------
 * Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
 * standard names.
 * 
 * NOTE: These are commented out because we call the port functions directly
 * from the interrupt handlers in stm32l4xx_it.c
 *----------------------------------------------------------*/
/* #define vPortSVCHandler    SVC_Handler */
/* #define xPortPendSVHandler PendSV_Handler */

/*-----------------------------------------------------------
 * Memory barrier definitions
 *----------------------------------------------------------*/
/* portMEMORY_BARRIER is already defined in portmacro.h, do not redefine here */

#endif /* FREERTOS_CONFIG_H */
