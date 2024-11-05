/*
 * global.h
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "timer.h"
#include "button.h"
#include "traffic_light.h"
#include "led7_seg.h"

#define PRESSED 0
#define NORMAL 1



#define INIT 			1
#define AUTO_RED_GREEN 	2
#define AUTO_RED_YELLOW 3
#define AUTO_GREEN_RED 	4
#define AUTO_YELLOW_RED 5

#define SET_GREEN		11
#define SET_YELLOW		12
#define SET_MANUAL		13



#define MANUAL_RED_GREEN	32
#define MANUAL_RED_YELLOW	33
#define MANUAL_GREEN_RED	34
#define MANUAL_YELLOW_RED	35

#define SLOW 				25

#define RED_GREEN 	2
#define RED_YELLOW 	3
#define GREEN_RED	4
#define	YELLOW_RED 	5




extern int status;
extern int counter[3];
extern int time_green;
extern int time_yellow;
extern int time_manual;



#endif /* INC_GLOBAL_H_ */
