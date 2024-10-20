/*
 * FUNC.h
 *
 *  Created on: Oct 20, 2024
 *      Author: xjkpr
 */

#ifndef INC_FUNC_H_
#define INC_FUNC_H_
#include "main.h"
#define MAX_LED 4
extern int led_index;
extern int led_buffer[4];

void display7SEG(int num);
void update7SEG(int index);


#endif /* INC_FUNC_H_ */
