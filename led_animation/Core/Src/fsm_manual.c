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
		if(isButtonPress(2)){
			updatePrevStatus();
			status= SET_MANUAL;
			return;
		}
		if(timer_flag[1] ==1){
			updatePrevStatus();
			status = AUTO_RED_GREEN;
			return;
		}
		if(isButtonPress(1)){
			led_traffic(RED_YELLOW);
			updatePrevStatus();
			status = MANUAL_RED_YELLOW;
			set_timer(1, duration[0]);
		}
		break;
	case MANUAL_RED_YELLOW:
		if(isButtonPress(2)){
			updatePrevStatus();
			status= SET_MANUAL;
			return;
		}
		if(timer_flag[1] ==1){
			updatePrevStatus();
			status = AUTO_RED_YELLOW;
			return;
		}
		if(isButtonPress(1)){
			led_traffic(GREEN_RED);
			updatePrevStatus();
			status = MANUAL_GREEN_RED;
			set_timer(1, duration[0]);
		}
		break;
	case MANUAL_GREEN_RED:
		if(isButtonPress(2)){
			updatePrevStatus();
			status= SET_MANUAL;
			return;
		}
		if(timer_flag[1] ==1){
			updatePrevStatus();
			status = AUTO_GREEN_RED;
			return;
				}
		if(isButtonPress(1)){
			led_traffic(YELLOW_RED);
			updatePrevStatus();
			status = MANUAL_YELLOW_RED;
			set_timer(1, duration[0]);
		}
		break;
	case MANUAL_YELLOW_RED:
		if(isButtonPress(2)){
			updatePrevStatus();
			status= SET_MANUAL;
			return;
		}
		if(timer_flag[1] ==1){
			updatePrevStatus();
			status = AUTO_YELLOW_RED;
			return;
		}
		if(isButtonPress(1)){
			led_traffic(RED_GREEN);
			updatePrevStatus();
			status = MANUAL_RED_GREEN;
			set_timer(1, duration[0]);
		}
		break;
	default:
		break;
	}
}
