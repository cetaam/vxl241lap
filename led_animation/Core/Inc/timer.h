/*
 * timer.h
 *
 *  Created on: Oct 20, 2024
 *      Author: xjkpr
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
extern int timer_flag[10];
extern int timer_counter[10];
void set_timer(int i, int durr);
void timerrun(int i);
void timer_restart();

#endif /* INC_TIMER_H_ */
