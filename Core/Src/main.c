

/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2026 STMicroelectronics.
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
#include <stdio.h>
#include <math.h>
#include "ai_model.h"
#include "arm_math.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
UART_HandleTypeDef huart1;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
double z_buffer[35];
int sample_count = 0;

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
int16_t Accel_X_RAW = 0;
int16_t Accel_Y_RAW = 0;
int16_t Accel_Z_RAW = 0;
int16_t Gyro_X_RAW = 0;
int16_t Gyro_Y_RAW = 0;
int16_t Gyro_Z_RAW = 0;
uint8_t check = 0x00;
uint8_t rec_data[14];

float Ax = 0, Ay = 0, Az = 0;
float Gx = 0, Gy = 0, Gz = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();
  HAL_NVIC_DisableIRQ(I2C1_EV_IRQn);
  HAL_NVIC_DisableIRQ(I2C1_ER_IRQn);

  // Đánh thức MPU6050
  HAL_I2C_Mem_Write(&hi2c1, 0xD0, 0x6B, I2C_MEMADD_SIZE_8BIT, &check, 1, 100);

  // Chớp đèn PC13 báo hiệu hệ thống đã khởi động an toàn
  for (int i = 0; i < 6; i++)
  {
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
    HAL_Delay(200);
  }
  while (1)
  {
    if (HAL_I2C_Mem_Read(&hi2c1, 0xD0, 0x3B, I2C_MEMADD_SIZE_8BIT, rec_data, 14, 100) == HAL_OK)
    {
      Accel_Z_RAW = (int16_t)(rec_data[4] << 8 | rec_data[5]);
      Az = Accel_Z_RAW / 16384.0f;
      z_buffer[sample_count] = (double)Az;
      sample_count++;
      if (sample_count == 35)
      {
        // a. Trích xuất 5 Đặc trưng (Mean, Std, Max, Min, Range)
        double mean = 0, max = z_buffer[0], min = z_buffer[0];
        for (int i = 0; i < 35; i++)
        {
          mean += z_buffer[i];
          if (z_buffer[i] > max)
            max = z_buffer[i];
          if (z_buffer[i] < min)
            min = z_buffer[i];
        }
        mean /= 35.0;

        double variance = 0;
        for (int i = 0; i < 35; i++)
        {
          variance += (z_buffer[i] - mean) * (z_buffer[i] - mean);
        }
        double std_dev = sqrt(variance / 35.0);
        double range = max - min;

        // b. Đưa vào mảng đầu vào cho mô hình
        double ai_input[5] = {mean, std_dev, max, min, range};
        double ai_output[3];

        // c. Gọi hàm AI suy luận
        score(ai_input, ai_output);

        // d. Tìm nhãn có điểm số cao nhất
        int predicted_class = 0;
        double max_score = ai_output[0];
        for (int i = 1; i < 3; i++)
        {
          if (ai_output[i] > max_score)
          {
            max_score = ai_output[i];
            predicted_class = i;
          }
        }

        // e. KÍCH HOẠT ĐÈN LED CẢNH BÁO
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_RESET);

        if (predicted_class == 0)
        {
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET); // LED XANH LÁ
          printf("TRANG THAI: BINH THUONG\n");
        }
        else if (predicted_class == 1)
        {
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET); // LED VÀNG
          printf("CANH BAO: RUNG NHE\n");
        }
        else if (predicted_class == 2)
        {
          HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET); // LED ĐỎ
          printf("NGUY HIEM: LAC MANH!\n");
        }

        // f. Trượt cửa sổ (Overlap 50%)
        for (int i = 0; i < 17; i++)
        {
          z_buffer[i] = z_buffer[i + 18];
        }
        sample_count = 17;
      }
    }
    else
    {
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET); // error
    }

    HAL_Delay(20); // Lấy mẫu 50Hz
  }
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
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
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
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
 * @brief I2C1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_I2C1_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
  /* USER CODE END I2C1_Init 0 */

  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART1_UART_Init(void)
{
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | ADXL_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA1 PA2 PA3 ADXL_CS_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | ADXL_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

/* USER CODE BEGIN 4 */
int _write(int file, char *ptr, int len)
{
  HAL_UART_Transmit(&huart1, (uint8_t *)ptr, len, HAL_MAX_DELAY);
  return len;
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{

  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
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
