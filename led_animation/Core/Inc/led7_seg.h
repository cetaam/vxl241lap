/*
 * led7_seg.h
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */

#ifndef INC_LED7_SEG_H_
#define INC_LED7_SEG_H_

#include "global.h"


extern int led_index;
extern int led_buffer[4];


void display7SEG(int num);
void update7SEG(int index);



void updateClockBuffer();
#endif /* INC_LED7_SEG_H_ */
