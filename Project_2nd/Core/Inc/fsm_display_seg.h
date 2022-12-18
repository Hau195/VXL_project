/*
 * fsm_display_seg.h
 *
 *  Created on: Nov 13, 2022
 *      Author: HAU
 */

#ifndef INC_FSM_DISPLAY_SEG_H_
#define INC_FSM_DISPLAY_SEG_H_

#include "global.h"


void red_seg_update();
void yellow_seg_update();
void green_seg_update();
void red_modify_update();
void yellow_modify_update();
void green_modify_update();
void traffic_light(int colour);


#endif /* INC_FSM_DISPLAY_SEG_H_ */
