/*
 * Pedestrian.c
 *
 *  Created on: Dec 2, 2022
 *      Author: HAU
 */
#include "Pedestrian.h"

TIM_HandleTypeDef htim3;

int duty_cycle = 0;

void Pedestrian_run(){
	switch(status)
	{
	case Auto_red:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);

		if(timer2_flag == 1){
			ped_flag = 0;
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
		}

		break;
	case Auto_change:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,  SET);
		if(timer2_flag == 1){
			ped_flag = 0;
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
		}
		break;
	case Auto_green:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 	SET);
		if(timer2_flag == 1){
			ped_flag = 0;
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
		}
		break;
	case Auto_yellow:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,  SET);
		if(timer2_flag == 1){
			ped_flag = 0;
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
		}
		break;
	}
}
void buzzer_run(){
	__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, duty_cycle);
	if(duty_cycle > 999) duty_cycle = 0 ;
}

float mapFloat(float x, float x_min, float x_max, float y_min, float y_max){
  float y;
  y = y_min + (x - x_min)/(x_max - x_min)*(y_max - y_min);
  y = (y>y_max)?y_max:((y<y_min)?y_min:y);
  return y;
}
