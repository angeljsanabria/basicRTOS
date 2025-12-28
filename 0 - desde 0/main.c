#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include <stdint.h>

/* Prototipos */
void vApplicationIdleHook(void);
void hello_task(void *pvParameters);

int main(void)
{
    /* Crear tarea Hello World */
    xTaskCreate(hello_task,           /* Funcion de la tarea */
                "HelloTask",          /* Nombre de la tarea */
                configMINIMAL_STACK_SIZE, /* Tamano del stack */
                NULL,                 /* Parametros */
                tskIDLE_PRIORITY + 1, /* Prioridad */
                NULL);                /* Handle (opcional) */

    /* Iniciar el scheduler */
    vTaskStartScheduler();

    /* No deberia llegar aqui */
    while(1)
    {
        /* Si el scheduler falla, quedamos aqui */
    }
}

/* Tarea Hello World */
void hello_task(void *pvParameters)
{
    (void)pvParameters;

    while(1)
    {
        /* Aqui iria el codigo para enviar "Hello World" via UART/Serial */
        /* Por ahora, solo hace un delay */
        
        vTaskDelay(pdMS_TO_TICKS(1000)); /* Delay de 1 segundo */
    }
}

/* Hook de Idle (opcional) */
void vApplicationIdleHook(void)
{
    /* Se ejecuta cuando no hay tareas listas para ejecutar */
}
