/*
 * trafficlight.c
 *
 *  Created on: Nov 12, 2022
 *      Author: HAU
 */
#include "fsm_trafficlight.h"

int TCNT1 = 0;
char str[50];
uint32_t ADC_value = 0;
UART_HandleTypeDef huart2;

void auto_tracffic_run(){
	switch(status){
	case Auto_init:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);

		status = Auto_red;

		Set_timer1(Red_duration);
		TCNT1 = (timer1_counter/100)*100;
		Set_timer3(5);

		break;
	case Auto_red:
		//TL1
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		//TL2
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);

		if(timer1_flag == 1){
			status = Auto_change;
			Set_timer1(Yellow_duration);
			Set_timer3(5);
		}

		if(Is_button1_pressed() == 1){
			status = Man_red;
			Set_timer2(20);
		}

		if(Is_button2_pressed() == 1){
			status = Red_Modify;
			traffic_light(Reset);
			duration_value = Red_duration + Yellow_duration;
			Set_timer4(2);
		}

		if(Is_buttonPED_pressed() == 1){
			ped_flag = 1;
			Set_timer2(200);

		}
		if(ped_flag == 1){
			Pedestrian_run();
			buzzer_run();
		}


		duty_cycle = mapFloat(timer1_counter, 0, TCNT1, 0, 999);

		duration = timer1_counter/100 + Yellow_duration;
		duration2 = timer1_counter/100;

		red_seg_update();

		if(timer3_flag == 1){
			Set_timer3(5);
		HAL_UART_Transmit (& huart2 , ( void *) str , sprintf (str , "!7SEG=%d#\n", duration ), 1000) ;
		}
		break;
	case Auto_change:
		//TL1
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
		//TL2
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);

		if(timer1_flag == 1){
			status = Auto_green;
			Set_timer1(Green_duration);
			Set_timer3(5);
		}

		if(Is_button1_pressed() == 1){
			status = Man_yellow;
			Set_timer2(20);
		}

		if(Is_button2_pressed() == 1){
			status = Red_Modify;
			traffic_light(Reset);
			duration_value = Red_duration + Yellow_duration;
			Set_timer4(2);
		}

		if(Is_buttonPED_pressed() == 1){
			ped_flag = 1;
			Set_timer2(200);

		}
		if(ped_flag == 1){
			Pedestrian_run();

		}

		duration = timer1_counter/100;

		yellow_seg_update();
		if(timer3_flag == 1){
			Set_timer3(5);
		HAL_UART_Transmit (& huart2 , ( void *) str , sprintf (str , "!7SEG=%d#\n", duration ), 1000) ;
		}
		break;
	case Auto_green:
		//TL1
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
		//TL2
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);

		if(timer1_flag == 1){
			status = Auto_yellow;
			Set_timer1(Yellow_duration);
			Set_timer3(5);
		}

		if(Is_button1_pressed() == 1){
			status = Man_green;
			Set_timer2(20);
		}

		if(Is_button2_pressed() == 1){
			status = Red_Modify;
			traffic_light(Reset);
			duration_value = Red_duration + Yellow_duration;
			Set_timer4(2);
		}

		if(Is_buttonPED_pressed() == 1){
			ped_flag = 1;
			Set_timer2(200);

		}
		if(ped_flag == 1){
			Pedestrian_run();

		}

		duration  = timer1_counter/100 ;
		duration2 = timer1_counter/100 + Yellow_duration;

		green_seg_update();
		if(timer3_flag == 1){
			Set_timer3(5);
		HAL_UART_Transmit (& huart2 , ( void *) str , sprintf (str , "!7SEG=%d#\n", duration ), 1000) ;
		}
		break;

	case Auto_yellow:
		//TL1
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
		//TL2
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);

		if(timer1_flag == 1){
			status = Auto_red;
			Set_timer1(Red_duration);
			Set_timer3(5);
		}

		if(Is_button1_pressed() == 1){
			status = Man_yellow;
			Set_timer2(20);
		}

		if(Is_button2_pressed() == 1){
			status = Red_Modify;
			traffic_light(Reset);
			duration_value = Red_duration + Yellow_duration;
			Set_timer4(2);
		}

		if(Is_buttonPED_pressed() == 1){
			ped_flag = 1;
			Set_timer2(200);
		}
		if(ped_flag == 1){
			Pedestrian_run();
		}

		duration = timer1_counter/100;

		yellow_seg_update();
		if(timer3_flag == 1){
			Set_timer3(5);
		HAL_UART_Transmit (& huart2 , ( void *) str , sprintf (str , "!7SEG=%d#\n", duration ), 1000) ;
		}
		break;

	}
 }

