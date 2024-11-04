/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_manual.h"
int duration[10];

void fsm_manual_run(){
	switch(status){
	case MANUAL_RED_GREEN:

		if(isButtonPress(1)){
			led_traffic(RED_YELLOW);
			prev_status=status;
			status = MANUAL_RED_YELLOW;
			set_timer(1, duration[0]);
		}
		break;
	case MANUAL_RED_YELLOW:
		if(isButtonPress(1)){
			led_traffic(GREEN_RED);
			prev_status=status;
			status = MANUAL_GREEN_RED;
			set_timer(1, duration[0]);
		}
		break;
	case MANUAL_GREEN_RED:
		if(isButtonPress(1)){
			led_traffic(YELLOW_RED);
			prev_status=status;
			status = MANUAL_YELLOW_RED;
			set_timer(1, duration[0]);
		}
		break;
	case MANUAL_YELLOW_RED:
		if(isButtonPress(1)){
			led_traffic(RED_GREEN);
			prev_status=status;
			status = MANUAL_RED_GREEN;
			set_timer(1, duration[0]);
		}
		break;
	default:
		return;

		}
	if(timer_flag[1] ==1){
		prev_status=status;
		status -=30;
		return;
	}

	if(isButtonPress(2)){
		prev_status=status;
		status= SET_MANUAL;
		return;
	}
}
