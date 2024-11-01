/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_manual.h"

void fsm_manual(){
	switch(status){
	case MANUAL_RED_GREEN:
		if(timer_flag[1] ==1){
			status = AUTO_RED_GREEN;
			return;
		}
		if(isButtonPress(1)){
			status = MANUAL_RED_YELLOW;
			set_timer(1, 500);
		}
		break;
	case MANUAL_RED_YELLOW:
		if(timer_flag[1] ==1){
					status = AUTO_RED_YELLOW;
					return;
				}
				if(isButtonPress(1)){
					status = MANUAL_GREEN_RED;
					set_timer(1, 500);
				}
		break;
	case MANUAL_GREEN_RED:
		if(timer_flag[1] ==1){
					status = AUTO_GREEN_RED;
					return;
				}
				if(isButtonPress(1)){
					status = MANUAL_YELLOW_RED;
					set_timer(1, 500);
				}
		break;
	case MANUAL_YELLOW_RED:
		if(timer_flag[1] ==1){
					status = AUTO_YELLOW_RED;
					return;
				}
				if(isButtonPress(1)){
					status = MANUAL_RED_GREEN;
					set_timer(1, 500);
				}
		break;
	default:
		break;
	}
	if(isButtonPress(0)){
		status = SLOW;
	}
}
