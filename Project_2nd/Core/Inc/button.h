/*
 * button.h
 *
 *  Created on: Nov 2, 2022
 *      Author: HAU
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"

#define Normal_state SET
#define Press_state RESET

extern int buttonPED_flag;

void Button_undebounce();
int Is_button1_pressed();
int Is_button2_pressed();
int Is_button3_pressed();
int Is_buttonPED_pressed();

int Is_button1_long_pressed();
int Is_button2_long_pressed();
int Is_button3_long_pressed();
int Is_buttonPED_long_pressed();

#endif /* INC_BUTTON_H_ */
