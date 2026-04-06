/**
 ******************************************************************************
 * @file    bsp_uart3.h
 * @brief   BSP - USART3 (ST-LINK VCP on NUCLEO-L4R5ZI, PD8/PD9)
 ******************************************************************************
 */

#ifndef BSP_UART3_H
#define BSP_UART3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32l4xx_hal.h"

extern UART_HandleTypeDef huart3;

void BSP_USART3_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* BSP_UART3_H */
