/*
 * button.c
 *
 *  Created on: Nov 2, 2022
 *      Author: HAU
 */
#include "button.h"

int State0[4] = {Normal_state,Normal_state,Normal_state,Normal_state};
int State1[4] = {Normal_state,Normal_state,Normal_state,Normal_state};
int State2[4] = {Normal_state,Normal_state,Normal_state,Normal_state};
int State3[4] = {Normal_state,Normal_state,Normal_state,Normal_state};

int Waiting_time = 200;

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;
int buttonPED_flag = 0;

int button1_long_pressed_flag = 0;
int button2_long_pressed_flag = 0;
int button3_long_pressed_flag = 0;
int buttonPED_long_pressed_flag = 0;


int Is_button1_pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	else{
		return 0;
	}
}
int Is_button2_pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	else{
		return 0;
	}
}
int Is_button3_pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	else{
		return 0;
	}
}
int Is_buttonPED_pressed(){
	if(buttonPED_flag == 1){
		buttonPED_flag = 0;
		return 1;
	}
	else{
		return 0;
	}
}

int Is_button1_long_pressed(){
	if(button1_long_pressed_flag == 1){
		button1_long_pressed_flag = 0;
		return 1;
	}
	else{
		return 0;
	}
}
int Is_button2_long_pressed(){
	if(button2_long_pressed_flag == 1){
		button2_long_pressed_flag = 0;
		return 1;
	}
	else{
		return 0;
	}
}
int Is_button3_long_pressed(){
	if(button3_long_pressed_flag == 1){
		button3_long_pressed_flag = 0;
		return 1;
	}
	else{
		return 0;
	}
}
int Is_buttonPED_long_pressed(){
	if(buttonPED_long_pressed_flag == 1){
		buttonPED_long_pressed_flag = 0;
		return 1;
	}
	else{
		return 0;
	}
}


void Sub_key_pressed(int index){
	if(index == 0)	button1_flag = 1;
	if(index == 1)	button2_flag = 1;
	if(index == 2)	button3_flag = 1;
	if(index == 3)	buttonPED_flag = 1;
}
void Sub_long_pressed(int index){
	if(index == 0)	button1_long_pressed_flag = 1;
	if(index == 1)	button2_long_pressed_flag = 1;
	if(index == 2)	button3_long_pressed_flag = 1;
	if(index == 3)	buttonPED_long_pressed_flag = 1;
}
void Button_undebounce(){
	for(int i= 0; i<= 3;i++){
	State0[i] = State1[i];
	State1[i] = State2[i];
	State2[0]  = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
	State2[1]  = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
	State2[2]  = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0);
	State2[3]  = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

	if((State0[i] == State1[i]) && (State1[i] == State2[i])){
		if(State2[i] != State3[i]){
			State3[i] = State2[i];
			if(State3[i] == Press_state){
				//TODO
				Waiting_time = 300;
				Sub_key_pressed(i);
			}
		}
		else{
			if(State3[i] == Press_state){
			Waiting_time --;
			if(Waiting_time == 0){
				//TODO
				Waiting_time = 100;
				//Sub_long_pressed(i);
				State3[i] = Normal_state;
			}
			}
		}

	}
}
}
