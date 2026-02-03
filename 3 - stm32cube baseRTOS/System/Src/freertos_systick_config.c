/**
 ******************************************************************************
 * @file    freertos_systick_config.c
 * @brief   Override vPortSetupTimerInterrupt to use SystemCoreClock at runtime.
 ******************************************************************************
 */

#include "FreeRTOS.h"
#include "system_stm32l4xx.h"
#include "core_cm4.h"

void vPortSetupTimerInterrupt(void)
{
  uint32_t ulReloadValue;

  SystemCoreClockUpdate();
  if (SystemCoreClock == 0U)
  {
    SystemCoreClock = 120000000U;
  }

  ulReloadValue = (SystemCoreClock / configTICK_RATE_HZ) - 1UL;
  if (ulReloadValue > 0xFFFFFFUL)
  {
    ulReloadValue = 0xFFFFFFUL;
  }

  SysTick->CTRL  = 0UL;
  SysTick->VAL   = 0UL;
  SysTick->LOAD  = ulReloadValue;
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk
                   | SysTick_CTRL_TICKINT_Msk
                   | SysTick_CTRL_ENABLE_Msk;
}
