/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins
     PC14-OSC32_IN (OSC32_IN)   ------> RCC_OSC32_IN
     PC15-OSC32_OUT (OSC32_OUT)   ------> RCC_OSC32_OUT
     PH0-OSC_IN (PH0)   ------> RCC_OSC_IN
     PH1-OSC_OUT (PH1)   ------> RCC_OSC_OUT
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, CLR_Pin|LDAC_Pin|SYNC3_Pin|SYNC2_Pin
                          |SYNC1_Pin|SCK_Pin|SDIN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(L_CTL_GPIO_Port, L_CTL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = CLR_Pin|SYNC3_Pin|SYNC2_Pin|SYNC1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = LDAC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LDAC_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = SCK_Pin|SDIN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = SDO1_Pin|SDO2_Pin|SDO3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = L_CTL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(L_CTL_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
void delay (int length)
{
    HAL_Delay(length);
}

/********************************************************************************
Function that writes to the AD5754R via the SPI port.
********************************************************************************/


void WriteToAD5754RViaSpi(long int *RegisterData)
{
    long int ValueToWrite = *RegisterData;
    int i;
    // SPI start
    SET_SYNC1();
    delay(10);
    CLR_SYNC1();	 //bring CS low
    delay(1);
    //Write out the ControlWord
    for(i=0; i<24; i++)
    {
        SET_SCLK();
        delay(5);
        if(0x800000 == (ValueToWrite & 0x800000))
        {
            SET_SDIN();	  //Send one to SDI pin
        }
        else
        {
            CLR_SDIN();	  //Send zero to SDI pin
        }
        delay(5);
        CLR_SCLK();
        delay(5);
        ValueToWrite <<= 1;	//Rotate data
        delay(5);
    }
    // SPI ends
    SET_SYNC1();
    delay(10);
}

/********************************************************************************
Function that read from the AD5754R via the SPI port.
********************************************************************************/

//---------------------
//Configure AD5754
//---------------------

void ConfigAD5754R(void)
{
    int i;
    long int *p;
    long int ins[2] = {0, 0};
    ins[0] = Power_Control_Register | PowerUp_ALL;
    ins[1] = Output_Range_Select_Register | Range5_Select | DAC_Channel_ALL;
    p = ins;
    for(i=0; i<2; i++)
    {
        WriteToAD5754RViaSpi(p);
        delay(200);
        p++;}
}
/* USER CODE END 2 */
