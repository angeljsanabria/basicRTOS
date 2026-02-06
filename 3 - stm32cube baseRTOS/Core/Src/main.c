/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "bsp.h"
#include "clock_config.h"
#include "FreeRTOS.h"
#include "task.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
/* FreeRTOS task prototypes */
void vLED2_Task(void *pvParameters);
void vLED3_Task(void *pvParameters);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock to 120MHz */
  Clock_Config();
  SystemCoreClockUpdate();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  /* USER CODE BEGIN 2 */
  /* Initialize Board Support Package (LEDs, buttons, etc.) */
  BSP_Init();
  
  /* Create FreeRTOS tasks */
  /* Task 1: Blink LED2 every 500ms */
  /* Use larger stack size (256 words = 1024 bytes) for safety */
  /* Task 1: Blink LED2 every 500ms */
  if (xTaskCreate(vLED2_Task,                    /* Task function */
                  "LED2_Task",                   /* Task name (for debugging) */
                  256,                           /* Stack size (in words) - increased from minimal */
                  NULL,                          /* Parameters passed to task */
                  tskIDLE_PRIORITY + 1,          /* Priority (higher than idle) */
                  NULL) != pdPASS)               /* Task handle (optional) */
  {
    /* Task creation failed - this should not happen */
    Error_Handler();
  }
  
  /* Task 2: Blink LED3 every 1000ms */
  if (xTaskCreate(vLED3_Task,                    /* Task function */
                  "LED3_Task",                   /* Task name (for debugging) */
                  256,                           /* Stack size (in words) - increased from minimal */
                  NULL,                          /* Parameters passed to task */
                  tskIDLE_PRIORITY + 1,          /* Priority (same as LED2) */
                  NULL) != pdPASS)               /* Task handle (optional) */
  {
    /* Task creation failed - this should not happen */
    Error_Handler();
  }
  
  /* Start the FreeRTOS scheduler */
  /* NO usar HAL_Delay() aqui - FreeRTOS reconfigurara SysTick */
  /* This function will NOT return - control passes to tasks */
  /* FreeRTOS will configure SysTick automatically */
  vTaskStartScheduler();
  
  /* If we reach here, the scheduler failed to start */
  /* This should never happen if FreeRTOS is configured correctly */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    /* This code should never execute if scheduler started successfully */
    /* USER CODE END 3 */
  }
  /* USER CODE END 3 */
}

/* SystemClock_Config() removed - using Clock_Config() from System/Src/clock_config.c instead */

/* USER CODE BEGIN 4 */

/**
  * @brief  FreeRTOS Task: Blink LED2 every 500ms
  * @param  pvParameters: Task parameters (unused)
  * @retval None
  * @note   This task runs independently and can be preempted by higher priority tasks
  */
void vLED2_Task(void *pvParameters)
{
  (void)pvParameters;  /* Unused parameter */
  
  /* Infinite loop - task never exits */
  for(;;)
  {
    /* Toggle LED2 */
    BSP_LED_Toggle(BSP_LED2);

    
    /* Delay for 500ms (non-blocking for other tasks) */
    /* pdMS_TO_TICKS converts milliseconds to FreeRTOS ticks */
    vTaskDelay(pdMS_TO_TICKS(1500));
  }
}

/**
  * @brief  FreeRTOS Task: Blink LED3 every 1000ms
  * @param  pvParameters: Task parameters (unused)
  * @retval None
  * @note   This task runs independently and can be preempted by higher priority tasks
  */
void vLED3_Task(void *pvParameters)
{
  (void)pvParameters;  /* Unused parameter */

  /* Infinite loop - task never exits */
  for(;;)
  {
    /* Toggle LED3 */
    BSP_LED_Toggle(BSP_LED2);

    /* Delay for 1000ms (non-blocking for other tasks) */
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

#ifdef DEBUG
/**
  * @brief  FreeRTOS assert failed callback
  * @param  pcFile: pointer to the source file name
  * @param  ulLine: assert error line source number
  * @retval None
  * @note   This function is called when a FreeRTOS configASSERT() fails
  */
void vAssertCalled( const char *pcFile, unsigned long ulLine )
{
  /* Disable interrupts */
  taskDISABLE_INTERRUPTS();
  
  /* User can add his own implementation to report the file name and line number,
     ex: printf("FreeRTOS assert failed: file %s on line %lu\r\n", pcFile, ulLine) */
  
  /* Infinite loop - halt execution */
  for( ;; )
  {
    /* Optionally blink LED to indicate error */
    BSP_LED_Toggle(BSP_LED2);
    HAL_Delay(100);
  }
}
#endif /* DEBUG */

/* USER CODE BEGIN StackOverflowHook */
#if ( configCHECK_FOR_STACK_OVERFLOW > 0 )
/**
  * @brief  FreeRTOS stack overflow hook
  * @param  xTask: Handle of the task that overflowed its stack
  * @param  pcTaskName: Name of the task that overflowed its stack
  * @retval None
  * @note   This function is called when FreeRTOS detects a stack overflow
  */
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName )
{
  (void)xTask;
  (void)pcTaskName;
  
  /* Disable interrupts */
  taskDISABLE_INTERRUPTS();
  
  /* User can add his own implementation to report the task name,
     ex: printf("Stack overflow in task: %s\r\n", pcTaskName) */
  
  /* Infinite loop - halt execution */
  for( ;; )
  {
    /* Blink LED to indicate stack overflow error */
    BSP_LED_Toggle(BSP_LED2);
    HAL_Delay(200);
  }
}
#endif /* configCHECK_FOR_STACK_OVERFLOW */
/* USER CODE END StackOverflowHook */
