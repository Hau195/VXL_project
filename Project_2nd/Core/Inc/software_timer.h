/*
 * software_timer.h
 *
 *  Created on: Nov 2, 2022
 *      Author: HAU
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;
extern int timer1_counter ;

void Set_timer1(int Time_set);
void Set_timer2(int Time_set);
void Set_timer3(int Time_set);
void Set_timer4(int Time_set);
void Timer_run();


#endif /* INC_SOFTWARE_TIMER_H_ */
