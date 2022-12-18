/*
 * Pedestrian.h
 *
 *  Created on: Dec 2, 2022
 *      Author: HAU
 */

#ifndef INC_PEDESTRIAN_H_
#define INC_PEDESTRIAN_H_

#include "global.h"

extern int duty_cycle;

void Pedestrian_run();
void buzzer_run();
float mapFloat(float x, float x_min, float x_max, float y_min, float y_max);

#endif /* INC_PEDESTRIAN_H_ */
