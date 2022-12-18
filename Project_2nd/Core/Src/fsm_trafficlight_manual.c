/*
 * trafficlight_manual.c
 *
 *  Created on: Dec 1, 2022
 *      Author: HAU
 */
#include "fsm_trafficlight_manual.h"

void fsm_trafficlight_manual_run(){
	switch(status){
	case Man_red:
		//TL1
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		//TL2
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);

		if(Is_button1_pressed() == 1){
			status = Man_green;
			Set_timer2(20);
		}

		if(timer2_flag == 1){
			status = Auto_init;
		}

		break;

	case Man_green:
		//TL1
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
		//TL2
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);

		if(Is_button1_pressed() == 1){
			status = Man_yellow;
			Set_timer2(20);
		}

		if(timer2_flag == 1){
			status = Auto_init;
		}

		break;

	case Man_yellow:
		//TL1
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
		//TL2
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);

		if(Is_button1_pressed() == 1){
			status = Man_red;
			Set_timer2(20);
		}

		if(timer2_flag == 1){
			status = Auto_init;
		}

		break;
	}
}

