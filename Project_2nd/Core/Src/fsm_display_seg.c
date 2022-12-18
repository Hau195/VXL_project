/*
 * fsm_display_seg.c
 *
 *  Created on: Nov 13, 2022
 *      Author: HAU
 */
#include "fsm_display_seg.h"


void fsm_display_seg(){
	switch(duration){
	case 0:
		buffer_led[0] = 5;
		buffer_led[1] = 0;

		break;
	case 1:
		buffer_led[0] = 1;
		buffer_led[1] = 0;
		break;
}
}
void red_seg_update(){
	buffer_led[0] = duration/10;
	buffer_led[1] = duration%10;
	buffer_led[2] = duration2/10;
	buffer_led[3] = duration2%10;
}
void red_modify_update(){
	buffer_led[0] = duration_value/10;
	buffer_led[1] = duration_value%10;
	buffer_led[2] = 0;
	buffer_led[3] = 1;
}
void yellow_seg_update(){
	buffer_led[0] = duration/10;
	buffer_led[1] = duration%10;
	buffer_led[2] = duration/10;
	buffer_led[3] = duration%10;
}
void yellow_modify_update(){
	buffer_led[0] = duration_value/10;
	buffer_led[1] = duration_value%10;
	buffer_led[2] = 0;
	buffer_led[3] = 2;
}
void green_seg_update(){
	buffer_led[0] = duration/10;
	buffer_led[1] = duration%10;
	buffer_led[2] = duration2/10;
	buffer_led[3] = duration2%10;
}
void green_modify_update(){
	buffer_led[0] = duration_value/10;
	buffer_led[1] = duration_value%10;
	buffer_led[2] = 0;
	buffer_led[3] = 3;
}
void traffic_light(int colour){
	switch(colour){
	case Reset:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		break;
	case Red:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		break;
	case Yellow:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		break;
	case Green:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		break;
	}
}
