/*
 * fsm_modify_green.c
 *
 *  Created on: Nov 19, 2022
 *      Author: HAU
 */
#include "fsm_modify_green.h"
char str[50];

UART_HandleTypeDef huart2;
void fsm_modify_green_run(){
	switch(status){
	case Green_Modify:
		if(timer4_flag == 1){
			Set_timer4(2);
			//TL1
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
			//TL2
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
		}
		if(Is_button2_pressed() == 1){
			status = Normal;
		}
		if(Is_button1_pressed() == 1){
			Green_duration -= 1;
			if(duration_value > 99) duration_value = 0;
			if(duration_value < 0 ) duration_value = 99;
		}
		if(Is_button3_pressed() == 1){
			Green_duration += 1;
			if(duration_value > 99) duration_value = 0;
			if(duration_value < 0 ) duration_value = 99;
		}
		if(timer3_flag == 1){
			Set_timer3(5);
		HAL_UART_Transmit (& huart2 , ( void *) str , sprintf (str , "!7SEG=%d#\n", Green_duration ), 1000) ;
		}
		green_modify_update();

		break;
	}
}

