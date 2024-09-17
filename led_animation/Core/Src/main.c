/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
int counter=9;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

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

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  void display7SEG1(int num)
  {
	  if(num==0)
	  	 {
		  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 	SET);
	  	 }
	  else if(num==1)
	  	 {
		  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, 	SET);
		  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 	SET);
		  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 	SET);
		  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 	SET);
	  	 }
	  else if(num==2)
	  	 {
		  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 	SET);
		  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 	SET);
		  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
	  	 }
	  else if(num==3)
	  	 {
		  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 	SET);
		  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
	  	 }
	  else if(num==4)
	  	 {
		  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, 	SET);
		  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 	SET);
		  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
	  	 }
	  else if(num==5)
	  	 {
		  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 	SET);
		  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
	  	 }
	  else if(num==6)
	  	 {
		  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 	SET);
		  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
	  	 }
	  else if(num==7)
	  	 {
		  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 	SET);
		  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin,	SET);
		  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin,	SET);
		  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin,	SET);
	  	 }
	  else if(num==8)
	  	 {
		  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
	  	 }
	  else if(num==9)
	  	 {
		  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
	  	 }
	  else
	  	  {
		  HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, 	SET);
		  HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 	SET);
		  HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 	SET);
		  HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 	SET);
		  HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		  HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 	SET);
		  HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 	SET);
	  	  }
  }
  void display7SEG2(int num)
    {
  	  if(num==0)
  	  	 {
  		  HAL_GPIO_WritePin(S0B_GPIO_Port, S0B_Pin, RESET);
  		  HAL_GPIO_WritePin(S1B_GPIO_Port, S1B_Pin, RESET);
  		  HAL_GPIO_WritePin(S2B_GPIO_Port, S2B_Pin, RESET);
  		  HAL_GPIO_WritePin(S3B_GPIO_Port, S3B_Pin, RESET);
  		  HAL_GPIO_WritePin(S4B_GPIO_Port, S4B_Pin, RESET);
  		  HAL_GPIO_WritePin(S5B_GPIO_Port, S5B_Pin, RESET);
  		  HAL_GPIO_WritePin(S6B_GPIO_Port, S6B_Pin, SET);
  	  	 }
  	  else if(num==1)
  	  	 {
  		  HAL_GPIO_WritePin(S0B_GPIO_Port, S0B_Pin, SET);
  		  HAL_GPIO_WritePin(S1B_GPIO_Port, S1B_Pin, RESET);
  		  HAL_GPIO_WritePin(S2B_GPIO_Port, S2B_Pin, RESET);
  		  HAL_GPIO_WritePin(S3B_GPIO_Port, S3B_Pin, SET);
  		  HAL_GPIO_WritePin(S4B_GPIO_Port, S4B_Pin, SET);
  		  HAL_GPIO_WritePin(S5B_GPIO_Port, S5B_Pin, SET);
  		  HAL_GPIO_WritePin(S6B_GPIO_Port, S6B_Pin, SET);
  	  	 }
  	  else if(num==2)
  	  	 {
  		  HAL_GPIO_WritePin(S0B_GPIO_Port, S0B_Pin, RESET);
  		  HAL_GPIO_WritePin(S1B_GPIO_Port, S1B_Pin, RESET);
  		  HAL_GPIO_WritePin(S2B_GPIO_Port, S2B_Pin, SET);
  		  HAL_GPIO_WritePin(S3B_GPIO_Port, S3B_Pin, RESET);
  		  HAL_GPIO_WritePin(S4B_GPIO_Port, S4B_Pin, RESET);
  		  HAL_GPIO_WritePin(S5B_GPIO_Port, S5B_Pin, SET);
  		  HAL_GPIO_WritePin(S6B_GPIO_Port, S6B_Pin, RESET);
  	  	 }
  	  else if(num==3)
  	  	 {
  		  HAL_GPIO_WritePin(S0B_GPIO_Port, S0_Pin, RESET);
  		  HAL_GPIO_WritePin(S1B_GPIO_Port, S1_Pin, RESET);
  		  HAL_GPIO_WritePin(S2B_GPIO_Port, S2_Pin, RESET);
  		  HAL_GPIO_WritePin(S3B_GPIO_Port, S3_Pin, RESET);
  		  HAL_GPIO_WritePin(S4B_GPIO_Port, S4_Pin, SET);
  		  HAL_GPIO_WritePin(S5B_GPIO_Port, S5_Pin, SET);
  		  HAL_GPIO_WritePin(S6B_GPIO_Port, S6_Pin, RESET);
  	  	 }
  	  else if(num==4)
  	  	 {
  		  HAL_GPIO_WritePin(S0B_GPIO_Port, S0B_Pin, SET);
  		  HAL_GPIO_WritePin(S1B_GPIO_Port, S1B_Pin, RESET);
  		  HAL_GPIO_WritePin(S2B_GPIO_Port, S2B_Pin, RESET);
  		  HAL_GPIO_WritePin(S3B_GPIO_Port, S3B_Pin, SET);
  		  HAL_GPIO_WritePin(S4B_GPIO_Port, S4B_Pin, SET);
  		  HAL_GPIO_WritePin(S5B_GPIO_Port, S5B_Pin, RESET);
  		  HAL_GPIO_WritePin(S6B_GPIO_Port, S6B_Pin, RESET);
  	  	 }
  	  else if(num==5)
  	  	 {
  		  HAL_GPIO_WritePin(S0B_GPIO_Port, S0B_Pin, RESET);
  		  HAL_GPIO_WritePin(S1B_GPIO_Port, S1B_Pin, SET);
  		  HAL_GPIO_WritePin(S2B_GPIO_Port, S2B_Pin, RESET);
  		  HAL_GPIO_WritePin(S3B_GPIO_Port, S3B_Pin, RESET);
  		  HAL_GPIO_WritePin(S4B_GPIO_Port, S4B_Pin, SET);
  		  HAL_GPIO_WritePin(S5B_GPIO_Port, S5B_Pin, RESET);
  		  HAL_GPIO_WritePin(S6B_GPIO_Port, S6B_Pin, RESET);
  	  	 }
  	  else if(num==6)
  	  	 {
  		  HAL_GPIO_WritePin(S0B_GPIO_Port, S0B_Pin, RESET);
  		  HAL_GPIO_WritePin(S1B_GPIO_Port, S1B_Pin, SET);
  		  HAL_GPIO_WritePin(S2B_GPIO_Port, S2B_Pin, RESET);
  		  HAL_GPIO_WritePin(S3B_GPIO_Port, S3B_Pin, RESET);
  		  HAL_GPIO_WritePin(S4B_GPIO_Port, S4B_Pin, RESET);
  		  HAL_GPIO_WritePin(S5B_GPIO_Port, S5B_Pin, RESET);
  		  HAL_GPIO_WritePin(S6B_GPIO_Port, S6B_Pin, RESET);
  	  	 }
  	  else if(num==7)
  	  	 {
  		  HAL_GPIO_WritePin(S0B_GPIO_Port, S0B_Pin, RESET);
  		  HAL_GPIO_WritePin(S1B_GPIO_Port, S1B_Pin, RESET);
  		  HAL_GPIO_WritePin(S2B_GPIO_Port, S2B_Pin, RESET);
  		  HAL_GPIO_WritePin(S3B_GPIO_Port, S3B_Pin, SET);
  		  HAL_GPIO_WritePin(S4B_GPIO_Port, S4B_Pin, SET);
  		  HAL_GPIO_WritePin(S5B_GPIO_Port, S5B_Pin, SET);
  		  HAL_GPIO_WritePin(S6B_GPIO_Port, S6B_Pin, SET);
  	  	 }
  	  else if(num==8)
  	  	 {
  		  HAL_GPIO_WritePin(S0B_GPIO_Port, S0B_Pin, RESET);
  		  HAL_GPIO_WritePin(S1B_GPIO_Port, S1B_Pin, RESET);
  		  HAL_GPIO_WritePin(S2B_GPIO_Port, S2B_Pin, RESET);
  		  HAL_GPIO_WritePin(S3B_GPIO_Port, S3B_Pin, RESET);
  		  HAL_GPIO_WritePin(S4B_GPIO_Port, S4B_Pin, RESET);
  		  HAL_GPIO_WritePin(S5B_GPIO_Port, S5B_Pin, RESET);
  		  HAL_GPIO_WritePin(S6B_GPIO_Port, S6B_Pin, RESET);
  	  	 }
  	  else if(num==9)
  	  	 {
  		  HAL_GPIO_WritePin(S0B_GPIO_Port, S0B_Pin, RESET);
  		  HAL_GPIO_WritePin(S1B_GPIO_Port, S1B_Pin, RESET);
  		  HAL_GPIO_WritePin(S2B_GPIO_Port, S2B_Pin, RESET);
  		  HAL_GPIO_WritePin(S3B_GPIO_Port, S3B_Pin, RESET);
  		  HAL_GPIO_WritePin(S4B_GPIO_Port, S4B_Pin, SET);
  		  HAL_GPIO_WritePin(S5B_GPIO_Port, S5B_Pin, RESET);
  		  HAL_GPIO_WritePin(S6B_GPIO_Port, S6B_Pin, RESET);
  	  	 }
  	  else
  	  	  {
  		  HAL_GPIO_WritePin(S0B_GPIO_Port, S0B_Pin, SET);
  	  	  HAL_GPIO_WritePin(S1B_GPIO_Port, S1B_Pin, SET);
  	  	  HAL_GPIO_WritePin(S2B_GPIO_Port, S2B_Pin, SET);
  	  	  HAL_GPIO_WritePin(S3B_GPIO_Port, S3B_Pin, SET);
  	  	  HAL_GPIO_WritePin(S4B_GPIO_Port, S4B_Pin, SET);
  	  	  HAL_GPIO_WritePin(S5B_GPIO_Port, S5B_Pin, SET);
  	  	  HAL_GPIO_WritePin(S6B_GPIO_Port, S6B_Pin, SET);
  	  	  }
    }
  //PRESET ALL LEDS
  	  	  	  HAL_GPIO_WritePin(LG_GPIO_Port, LG_Pin, SET);
  	  	  	  HAL_GPIO_WritePin(LY_GPIO_Port, LY_Pin, SET);
  	  	  	  HAL_GPIO_WritePin(LR_GPIO_Port, LR_Pin, SET);
  	  	  	  HAL_GPIO_WritePin(LGB_GPIO_Port, LGB_Pin, SET);
  	  	  	  HAL_GPIO_WritePin(LYB_GPIO_Port, LYB_Pin, SET);
  	  	  	  HAL_GPIO_WritePin(LRB_GPIO_Port, LRB_Pin, SET);
  	  	  	  HAL_GPIO_WritePin(S0B_GPIO_Port, S0B_Pin, SET);
    	  	  HAL_GPIO_WritePin(S1B_GPIO_Port, S1B_Pin, SET);
    	  	  HAL_GPIO_WritePin(S2B_GPIO_Port, S2B_Pin, SET);
    	  	  HAL_GPIO_WritePin(S3B_GPIO_Port, S3B_Pin, SET);
    	  	  HAL_GPIO_WritePin(S4B_GPIO_Port, S4B_Pin, SET);
    	  	  HAL_GPIO_WritePin(S5B_GPIO_Port, S5B_Pin, SET);
    	  	  HAL_GPIO_WritePin(S6B_GPIO_Port, S6B_Pin, SET);
  while (1)
  {
	  if(counter>=7)
	  {
		  HAL_GPIO_WritePin(LY_GPIO_Port, LY_Pin, RESET);
		  HAL_GPIO_WritePin(LR_GPIO_Port, LR_Pin, 	SET);
		  HAL_GPIO_WritePin(LG_GPIO_Port, LG_Pin, RESET);
		  display7SEG1(counter-5);


		  HAL_GPIO_WritePin(LYB_GPIO_Port, LYB_Pin, RESET);
		  HAL_GPIO_WritePin(LRB_GPIO_Port, LRB_Pin,	RESET);
		  HAL_GPIO_WritePin(LGB_GPIO_Port, LGB_Pin, SET);
		  display7SEG2(counter-7);
	  }
	  else if(counter>=5)
	  {

		  HAL_GPIO_WritePin(LR_GPIO_Port, LR_Pin, 	SET);
		  HAL_GPIO_WritePin(LG_GPIO_Port, LG_Pin, RESET);
		  display7SEG1(counter-5);


		  HAL_GPIO_WritePin(LYB_GPIO_Port, LYB_Pin,	SET);
		  HAL_GPIO_WritePin(LGB_GPIO_Port, LGB_Pin, RESET);
		  display7SEG2(counter-5);
	  }
	  else if(counter>=2)
	  {
		  HAL_GPIO_WritePin(LR_GPIO_Port, LR_Pin, RESET);
		  HAL_GPIO_WritePin(LG_GPIO_Port, LG_Pin, 	SET);
		  display7SEG1(counter-2);

		  HAL_GPIO_WritePin(LYB_GPIO_Port,LYB_Pin, RESET);
		  HAL_GPIO_WritePin(LRB_GPIO_Port, LRB_Pin,	SET);
		  display7SEG2(counter);
	  }
	  else
	  {
		  HAL_GPIO_WritePin(LY_GPIO_Port, LY_Pin, 	SET);
		  HAL_GPIO_WritePin(LG_GPIO_Port, LG_Pin, RESET);
		  display7SEG1(counter);

		  HAL_GPIO_WritePin(LYB_GPIO_Port, LYB_Pin, RESET);
		  HAL_GPIO_WritePin(LRB_GPIO_Port, LRB_Pin, SET);
		  display7SEG2(counter);
	  }
	  if(counter<=0)
	  {
		  counter=10;

	  }

	  counter--;
	  HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LG_Pin|LR_Pin|LY_Pin|S0_Pin
                          |S1_Pin|S2_Pin|S3_Pin|S4_Pin
                          |S5_Pin|S6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, S3B_Pin|S4B_Pin|S5B_Pin|S6B_Pin
                          |LGB_Pin|LRB_Pin|LYB_Pin|S0B_Pin
                          |S1B_Pin|S2B_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LG_Pin LR_Pin LY_Pin S0_Pin
                           S1_Pin S2_Pin S3_Pin S4_Pin
                           S5_Pin S6_Pin */
  GPIO_InitStruct.Pin = LG_Pin|LR_Pin|LY_Pin|S0_Pin
                          |S1_Pin|S2_Pin|S3_Pin|S4_Pin
                          |S5_Pin|S6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : S3B_Pin S4B_Pin S5B_Pin S6B_Pin
                           LGB_Pin LRB_Pin LYB_Pin S0B_Pin
                           S1B_Pin S2B_Pin */
  GPIO_InitStruct.Pin = S3B_Pin|S4B_Pin|S5B_Pin|S6B_Pin
                          |LGB_Pin|LRB_Pin|LYB_Pin|S0B_Pin
                          |S1B_Pin|S2B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
