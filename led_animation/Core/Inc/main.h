/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EN0_Pin GPIO_PIN_1
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_2
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_3
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_4
#define EN3_GPIO_Port GPIOA
#define TEST_PIN_Pin GPIO_PIN_5
#define TEST_PIN_GPIO_Port GPIOA
#define LR_X_Pin GPIO_PIN_6
#define LR_X_GPIO_Port GPIOA
#define LG_X_Pin GPIO_PIN_7
#define LG_X_GPIO_Port GPIOA
#define S0_Pin GPIO_PIN_0
#define S0_GPIO_Port GPIOB
#define S1_Pin GPIO_PIN_1
#define S1_GPIO_Port GPIOB
#define S2_Pin GPIO_PIN_2
#define S2_GPIO_Port GPIOB
#define LY_X_Pin GPIO_PIN_8
#define LY_X_GPIO_Port GPIOA
#define LR_Y_Pin GPIO_PIN_9
#define LR_Y_GPIO_Port GPIOA
#define LG_Y_Pin GPIO_PIN_10
#define LG_Y_GPIO_Port GPIOA
#define LY_Y_Pin GPIO_PIN_11
#define LY_Y_GPIO_Port GPIOA
#define BT0__Pin GPIO_PIN_15
#define BT0__GPIO_Port GPIOA
#define S3_Pin GPIO_PIN_3
#define S3_GPIO_Port GPIOB
#define S4_Pin GPIO_PIN_4
#define S4_GPIO_Port GPIOB
#define S5_Pin GPIO_PIN_5
#define S5_GPIO_Port GPIOB
#define S6_Pin GPIO_PIN_6
#define S6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
