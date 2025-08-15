/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
//各个口子上的大小范围
extern uint16_t DAC_HIGH_COUNT[12];
extern uint16_t DAC_LOW_COUNT[12];
//各个DAC通道的选择
extern long int DAC_Channel[4];
//各个DAC的输出值
extern long int DAC_HIGH_Value[12];
extern long int DAC_LOW_Value[12];
//片选端口
extern uint16_t DAC_CS_Port[3];
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CLR_Pin GPIO_PIN_0
#define CLR_GPIO_Port GPIOA
#define LDAC_Pin GPIO_PIN_1
#define LDAC_GPIO_Port GPIOA
#define SYNC3_Pin GPIO_PIN_2
#define SYNC3_GPIO_Port GPIOA
#define SYNC2_Pin GPIO_PIN_3
#define SYNC2_GPIO_Port GPIOA
#define SYNC1_Pin GPIO_PIN_4
#define SYNC1_GPIO_Port GPIOA
#define SCK_Pin GPIO_PIN_5
#define SCK_GPIO_Port GPIOA
#define SDIN_Pin GPIO_PIN_7
#define SDIN_GPIO_Port GPIOA
#define SDO1_Pin GPIO_PIN_0
#define SDO1_GPIO_Port GPIOB
#define SDO2_Pin GPIO_PIN_1
#define SDO2_GPIO_Port GPIOB
#define SDO3_Pin GPIO_PIN_2
#define SDO3_GPIO_Port GPIOB
#define L_CTL_Pin GPIO_PIN_9
#define L_CTL_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
