/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "P10.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
Pixel pix[20];
uint8_t data1[16], flag;
int8_t rad = 2;
uint32_t joy_data[3] = {0,};
uint32_t joy_x;
uint32_t joy_y;
int8_t count_x = 0, count_y = 0;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM2_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void delay(double_t time_delay)
{    
    double_t i;
    for(i = 0; i < time_delay; i++);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
//	pix[0].x=4;
//	pix[0].y=3;
//	pix[1].x=4;
//	pix[1].y=4;
//	pix[2].x=6;
//	pix[2].y=3;
//	pix[3].x=3;
//	pix[3].y=4;
//	pix[4].x=3;
//	pix[4].y=5;
//	pix[5].x=3;
//	pix[5].y=6;
//	pix[6].x=7;
//	pix[6].y=4;
//	pix[7].x=7;
//	pix[7].y=5;
//	pix[8].x=7;
//	pix[8].y=6;
//	pix[9].x=4;
//	pix[9].y=7;
//	pix[10].x=5;
//	pix[10].y=7;
//	pix[11].x=6;
//	pix[11].y=7;

	pix[12].x=4;
	pix[12].y=4;
	
	pix[13].x=3;
	pix[13].y=3;
	pix[14].x=4;
	pix[15].y=1;

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
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
	HAL_ADC_Start(&hadc1);
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&joy_data, 2);
	HAL_TIM_Base_Start_IT(&htim2);
//	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		clearScreen((uint8_t*)&data1);
		drawPixel(pix[13],(uint8_t*)&data1,P10AB_00);
		HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, (uint8_t*)&data1, 16, 10);
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
		
		clearScreen((uint8_t*)&data1);
		drawPixel(pix[13],(uint8_t*)&data1,P10AB_10);
		HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, (uint8_t*)&data1, 16, 10);			
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
		

		clearScreen((uint8_t*)&data1);
		drawPixel(pix[13],(uint8_t*)&data1,P10AB_01);
		HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, (uint8_t*)&data1, 16, 10);				
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_SET);
		HAL_Delay(1);
		
		
		clearScreen((uint8_t*)&data1);
		drawPixel(pix[13],(uint8_t*)&data1,P10AB_11);
		HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, (uint8_t*)&data1, 16, 10);				
		HAL_GPIO_WritePin(SCLK_GPIO_Port, SCLK_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(nOE_GPIO_Port, nOE_Pin, GPIO_PIN_SET);
		HAL_Delay(1);

		if (joy_x>=4000) count_x += 1;
		if (joy_x<=800) count_x -=1;

		if (joy_y>=4000) count_y += 1;
		if (joy_y<=800) count_y -=1;
		
		if (count_x > 10)
		{
				pix[13].x += 1;
				count_x = 0;
		}
		
		if (count_x < -10)
		{
				pix[13].x -= 1;
				count_x = 0;
		}
		
		if (count_y > 10)
		{
				pix[13].y += 1;
				count_y = 0;
		}
		
		if (count_y < -10)
		{
				pix[13].y -= 1;
				count_y = 0;
		}
		
		if (pix[13].x > 32) pix[13].x = 1;
		if (pix[13].x < 1) pix[13].x = 32;
		if (pix[13].y > 16) pix[13].y = 1;
		if (pix[13].y < 1) pix[13].y = 16;
			
		if(flag)
		{
				flag = 0;
				HAL_ADC_Stop_DMA(&hadc1);
				joy_x = joy_data[0];
				joy_y = joy_data[1];
				joy_data[0] = 0;
				joy_data[1] = 0;
				HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&joy_data, 2);
		}
		
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 160;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV16;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 2;
  hadc1.Init.DMAContinuousRequests = ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = 2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 100-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1000-1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream4_IRQn);

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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, nOE_Pin|A_Pin|B_Pin|SCLK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : nOE_Pin A_Pin B_Pin SCLK_Pin */
  GPIO_InitStruct.Pin = nOE_Pin|A_Pin|B_Pin|SCLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

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
