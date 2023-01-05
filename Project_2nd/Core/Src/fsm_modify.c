/*
 * fsm_modify.c
 *
 *  Created on: Nov 13, 2022
 *      Author: HAU
 */
#include "fsm_modify.h"
char str[50];

UART_HandleTypeDef huart2;
void fsm_modify_run(){
	switch(status){
	case Normal:
		status = Auto_init;

		if(Is_button2_pressed() == 1){
			status = Red_Modify;
			Set_timer4(2);
		}

		break;

	case Red_Modify:
		if(timer4_flag == 1){
			Set_timer4(2);
			//TL1
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
			//TL2
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		}

		if(Is_button2_pressed() == 1){
			status = Yellow_Modify;
			traffic_light(Reset);
			Set_timer4(2);
		}

		if(Is_button1_pressed() == 1){
			Red_duration --;
			if(Red_duration > 99) Red_duration = 0;
			if(Red_duration < 0) Red_duration = 0;
		}

		if(Is_button3_pressed() == 1){
			Red_duration ++;
			if(Red_duration > 99) Red_duration = 0;
			if(Red_duration < 0) Red_duration = 0;
		}
		duration_value = Red_duration + Yellow_duration;
		if(timer3_flag == 1){
			Set_timer3(5);
		HAL_UART_Transmit (& huart2 , ( void *) str , sprintf (str , "!7SEG=%d#\n", duration_value ), 1000) ;
		}
		red_modify_update();

		break;
	}
}

