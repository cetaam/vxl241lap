/*
 * fsm_auto.h
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */

#ifndef INC_FSM_AUTO_H_
#define INC_FSM_AUTO_H_


#include "global.h"


void fsm_auto_run();
void per_second();
void counter_reset();

void auto_red_green_run();
void auto_red_yellow_run();
void auto_green_red_run();
void auto_yellow_red_run();
#endif /* INC_FSM_AUTO_H_ */
