/**
 ******************************************************************************
 * @file    bsp.c
 * @brief   Board Support Package - Main implementation
 * @details This file provides the main BSP initialization function that
 *          initializes all board peripherals (LEDs, button, USART3, etc.)
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp.h"
#include "bsp_leds.h"
#include "bsp_button.h"
#include "bsp_uart3.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Initialize all board peripherals
 * @retval None
 * @note   This function initializes:
 *         - LEDs
 *         - Buttons
 *         - Other board peripherals (if any)
 */
void BSP_Init(void)
{
    /* Initialize LEDs */
    BSP_LED_Init();

    /* Initialize Button */
    BSP_Button_Init();

    /* USART3 (virtual COM via ST-LINK) */
    BSP_USART3_Init();
}
