#include <stdint.h>
#include "FreeRTOSConfig.h"

/* Funciones basicas del port para FreeRTOS */
/* Estas funciones seran llamadas por el kernel de FreeRTOS */

/* Configuracion del reloj del sistema (SysTick) */
/* Para STM32L4R5ZI, el reloj del sistema puede ser 120MHz */
#define SYSTEM_CLOCK_HZ 120000000UL

/* Configurar SysTick para generar interrupciones cada tick */
void vPortSetupTimerInterrupt(void)
{
    /* Configurar SysTick para generar interrupciones cada 1ms (1000Hz) */
    uint32_t reload_value = (SYSTEM_CLOCK_HZ / configTICK_RATE_HZ) - 1;
    
    /* SysTick Control and Status Register */
    *((volatile uint32_t *)0xE000E010) = 0;                    /* Disable SysTick */
    *((volatile uint32_t *)0xE000E014) = reload_value;         /* Reload value */
    *((volatile uint32_t *)0xE000E018) = 0;                    /* Clear current value */
    *((volatile uint32_t *)0xE000E010) = 0x00000007;           /* Enable SysTick (bit 0), enable interrupt (bit 1), use processor clock (bit 2) */
}

/* Funcion para inicializar el stack pointer */
void vPortInitialiseStack(uint32_t *pxTopOfStack)
{
    /* Esta funcion seria llamada por FreeRTOS para inicializar el stack de una tarea */
    /* El port de FreeRTOS para ARM_CM4F ya lo maneja, pero aqui tenemos un stub */
    (void)pxTopOfStack;
}

/* Otras funciones del port pueden ir aqui si son necesarias */
/* Por ahora, el port de FreeRTOS (ARM_CM4F) ya incluye todo lo necesario */

