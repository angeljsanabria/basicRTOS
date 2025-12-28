#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* Configuracion basica de FreeRTOS para STM32L4R5ZI */

/* Reloj del sistema */
#define configCPU_CLOCK_HZ          (120000000UL)
#define configTICK_RATE_HZ          (1000)  /* 1 ms tick */

/* Configuracion del scheduler */
#define configUSE_PREEMPTION        1
#define configUSE_TIME_SLICING      1
#define configIDLE_SHOULD_YIELD     1

/* Configuracion de memoria */
#define configTOTAL_HEAP_SIZE       ((size_t)(32*1024))  /* 32 KB */
#define configMINIMAL_STACK_SIZE    ((uint16_t)128)
#define configMAX_TASK_NAME_LEN     (16)

/* Configuracion de prioridades */
#define configMAX_PRIORITIES        (5)
#define configUSE_MUTEXES           1
#define configUSE_RECURSIVE_MUTEXES 1
#define configUSE_COUNTING_SEMAPHORES 1

/* Configuracion de interrupciones */
#define configKERNEL_INTERRUPT_PRIORITY         (7 << 5)
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    (5 << 5)

/* Hooks */
#define configUSE_IDLE_HOOK         0
#define configUSE_TICK_HOOK         0
#define configUSE_MALLOC_FAILED_HOOK 0

/* Funcionalidades */
#define configUSE_16_BIT_TICKS      0
#define configUSE_TRACE_FACILITY    0
#define configUSE_APPLICATION_TASK_TAG 0
#define configUSE_NEWLIB_REENTRANT  0
#define configCHECK_FOR_STACK_OVERFLOW 0

/* Incluir funciones en el API */
#define INCLUDE_vTaskPrioritySet    1
#define INCLUDE_uxTaskPriorityGet   1
#define INCLUDE_vTaskDelete         1
#define INCLUDE_vTaskCleanUpResources 0
#define INCLUDE_vTaskSuspend        1
#define INCLUDE_vTaskDelayUntil     1
#define INCLUDE_vTaskDelay          1
#define INCLUDE_xTaskGetIdleTaskHandle 0
#define INCLUDE_xTimerPendFunctionCall 0

#endif /* FREERTOS_CONFIG_H */

