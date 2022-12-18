/*
 * global.h
 *
 *  Created on: Dec 1, 2022
 *      Author: HAU
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"
#include "main.h"
#include "fsm_display_seg.h"
#include "fsm_trafficlight.h"
#include "fsm_trafficlight_manual.h"
#include "fsm_modify.h"
#include "fsm_modify_green.h"
#include "fsm_modify_yellow.h"
#include "Pedestrian.h"


#define Auto_init 		0
#define Auto_red  		1
#define Auto_change 	2
#define Auto_yellow 	3
#define Auto_green 		4

#define Reset			6
#define Red 			7
#define Yellow  		8
#define Green 			9

#define Man_red  		10
#define Man_yellow 		11
#define Man_green 		12

#define Normal 			20
#define Red_Modify 		21
#define Yellow_Modify 	22
#define Green_Modify 	23

extern int Red_duration;
extern int Yellow_duration;
extern int Green_duration;

extern int status;
extern int duration_value;
extern int duration;
extern int duration2;
extern int buffer_led[4];
extern int ped_flag;


#endif /* INC_GLOBAL_H_ */
