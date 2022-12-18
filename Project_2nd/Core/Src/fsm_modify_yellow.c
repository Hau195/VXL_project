/*
 * fsm_modify_yellow.c
 *
 *  Created on: Nov 19, 2022
 *      Author: HAU
 */
#include "fsm_modify_yellow.h"

void fsm_modify_yellow_run(){
	switch(status){
	case Yellow_Modify:
		if(timer4_flag == 1){
			Set_timer4(2);
			//TL1
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
			//TL2
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
			}

		if(Is_button2_pressed() == 1){
			status = Green_Modify;
			duration_value = Green_duration;
			traffic_light(Reset);
			Set_timer4(2);
			}

		if(Is_button1_pressed() == 1){
			Yellow_duration -= 1;
			if(Yellow_duration > 99) Yellow_duration = 0;
			if(Yellow_duration < 0) Yellow_duration = 99;
			}

		if(Is_button3_pressed() == 1){
			Yellow_duration += 1;
			if(Yellow_duration > 99) Yellow_duration = 0;
			if(Yellow_duration < 0)  Yellow_duration = 99;
			}

			yellow_modify_update();

			break;
	}
}
