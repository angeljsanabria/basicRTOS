/**
 ******************************************************************************
 * @file    hal_timebase_stub.c
 * @brief   Override HAL_InitTick to prevent HAL from reconfiguring SysTick
 *          when FreeRTOS is using it.
 ******************************************************************************
 */

#include "main.h"

HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
  (void)TickPriority;
  
  /* HAL_InitTick() is called by HAL_RCC_ClockConfig() after changing clock.
   * But FreeRTOS will configure SysTick itself via vPortSetupTimerInterrupt().
   * So we do nothing here - just return OK to prevent HAL from configuring SysTick.
   * HAL_IncTick() will still work because SysTick_Handler calls it. */
  
  return HAL_OK;
}
