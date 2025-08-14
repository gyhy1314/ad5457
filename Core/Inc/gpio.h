/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

//Æ¬Ñ¡ÐÅºÅ
#define SET_SYNC1()		HAL_GPIO_WritePin(SYNC1_GPIO_Port, SYNC1_Pin, GPIO_PIN_SET)
#define CLR_SYNC1()		HAL_GPIO_WritePin(SYNC1_GPIO_Port, SYNC1_Pin, GPIO_PIN_RESET)

#define SET_SYNC2()		HAL_GPIO_WritePin(SYNC2_GPIO_Port, SYNC2_Pin, GPIO_PIN_SET)
#define CLR_SYNC2()		HAL_GPIO_WritePin(SYNC2_GPIO_Port, SYNC2_Pin, GPIO_PIN_RESET)

#define SET_SYNC3()		HAL_GPIO_WritePin(SYNC3_GPIO_Port, SYNC1_Pin, GPIO_PIN_SET)
#define CLR_SYNC3()		HAL_GPIO_WritePin(SYNC3_GPIO_Port, SYNC1_Pin, GPIO_PIN_RESET)


#define SET_SCLK()	    HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_SET)
#define CLR_SCLK()		HAL_GPIO_WritePin(SCK_GPIO_Port, SCK_Pin, GPIO_PIN_RESET)


#define	SET_SDIN()	    HAL_GPIO_WritePin(SDIN_GPIO_Port, SDIN_Pin, GPIO_PIN_SET)
#define	CLR_SDIN()		HAL_GPIO_WritePin(SDIN_GPIO_Port, SDIN_Pin, GPIO_PIN_RESET)

//functions' prototype
void WriteToAD5754RViaSpi(long int *RegisterData);
void ConfigAD5754R(void);
void delay(int length);

#define Read  0x800000
#define Write 0x000000

//Channel Select
#define DAC_Channel_A    0x000000
#define DAC_Channel_B    0x010000
#define DAC_Channel_C    0x020000
#define DAC_Channel_D    0x030000
#define DAC_Channel_ALL  0x040000

//Register Select
#define DAC_Register                  0x000000
#define Output_Range_Select_Register  0x080000
#define Power_Control_Register        0x100000
#define Control_Register              0x180000

// Output Range Config
/*
Range1: 0~5V
Range2: 0~10V
Range3: 0~10.8V
Range4: -5~+5V
Range5: -10~+10V
Range6: -10.8~+10.8V
*/

#define Range1_Select 0x000000
#define Range2_Select 0x000001
#define Range3_Select 0x000002
#define Range4_Select 0x000003
#define Range5_Select 0x000004
#define Range6_Select 0x000005

// Power Control
#define PowerUp_ALL         0x00001F

#define PowerUp_Channel_A   0x000001
#define PowerDown_Channel_A 0xFFFFFE

#define PowerUp_Channel_B   0x000002
#define PowerDown_Channel_B 0xFFFFFD

#define PowerUp_Channel_C   0x000004
#define PowerDown_Channel_C 0xFFFFFB

#define PowerUp_Channel_D   0x000008
#define PowerDown_Channel_D 0xFFFFF7

#define PowerUp_REF         0x000010
#define PowerDown_REF       0xFFFFEF

//General Config

#define Nop 0x180000 //for readback

//Control Register

#define Control        0x190000

#define TSD_Enable     0x000008
#define TSD_Disable    0x000000

#define Clamp_Enable   0x000004
#define TSD_Disable    0x000000

#define Clear_Select0  0x000002
#define Clear_Select1  0x000000

#define SDO_Disable    0x000001
#define SDO_Enable     0x000000

//Clear

#define Clear 0x1C0000

//Load

#define Load 0x1D0000
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

