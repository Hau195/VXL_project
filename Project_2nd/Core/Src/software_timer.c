/*
 * software_timer.c
 *
 *  Created on: Nov 2, 2022
 *      Author: HAU
 */
#include "software_timer.h"


int timer1_flag = 0;
int timer1_counter = 0;
int timer2_flag = 0;
int timer2_counter = 0;
int timer3_flag = 0;
int timer3_counter = 0;
int timer4_flag = 0;
int timer4_counter = 0;

void Set_timer1(int Time_set){
	timer1_counter = Time_set*100;
	timer1_flag = 0;
}
void Set_timer2(int Time_set){
	timer2_counter = Time_set*10;
	timer2_flag = 0;
}
void Set_timer3(int Time_set){
	timer3_counter = Time_set*10;
	timer3_flag = 0;
}
void Set_timer4(int Time_set){
	timer4_counter = Time_set*10;
	timer4_flag = 0;
}
void Timer_run(){
	if(timer1_counter >0){
		timer1_counter --;
		if(timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
	if(timer2_counter >0){
		timer2_counter --;
		if(timer2_counter <= 0){
			timer2_flag = 1;
		}
	}
	if(timer3_counter >0){
		timer3_counter --;
		if(timer3_counter <= 0){
			timer3_flag = 1;
		}
	}
	if(timer4_counter >0){
		timer4_counter --;
		if(timer4_counter <= 0){
			timer4_flag = 1;
		}
	}

}
