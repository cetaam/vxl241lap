/*
 * fsm_auto.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_auto.h"
int duration[10];
int counter[2];
void fsm_auto_run(){
	switch (status){
	case INIT:
		resetled();
		status=AUTO_RED_GREEN;
		duration[0] = 200;
		duration[1] = DEFAULT_GREEN;
		duration[2] = DEFAULT_YELLOW;
		counter[1] = duration[1]/100;
		counter[2] = duration[2]/100;
		set_timer(0, 25);
		set_timer(1, duration[1]);
		break;
	case AUTO_RED_GREEN:
		led_traffic(RED_GREEN);
		updateClockBuffer(counter);
		if(isButtonPress(2)){
			updatePrevStatus();
			status= SET_GREEN;
			return;
		}
		if(isButtonPress(0)){
			updatePrevStatus();
			status = MANUAL_RED_GREEN;
			set_timer(1, duration[0]);

		}
		if(timer_flag[1]==1){
			updatePrevStatus();
			status=AUTO_RED_YELLOW;
			set_timer(1, duration[2]);
		}

		break;
	case AUTO_RED_YELLOW:
		led_traffic(RED_YELLOW);
		if(isButtonPress(2)){
			updatePrevStatus();
			status= SET_GREEN;
			return;
		}

		if(isButtonPress(0)){
			updatePrevStatus();
			status = MANUAL_RED_YELLOW;
			set_timer(1, duration[0]);
		}
		if(timer_flag[1]==1){
			updatePrevStatus();
			status = AUTO_GREEN_RED;
			set_timer(1, duration[1]);
		}
		break;
	case AUTO_GREEN_RED:
		led_traffic(GREEN_RED);
		if(isButtonPress(2)){
			updatePrevStatus();
			status= SET_GREEN;
			return;
		}

		if(isButtonPress(0)){
			updatePrevStatus();
			status = MANUAL_GREEN_RED;
			set_timer(1, duration[0]);
		}
		if(timer_flag[1]==1){
			updatePrevStatus();
			status = AUTO_YELLOW_RED;
			set_timer(1, duration[2]);
		}
		break;
	case AUTO_YELLOW_RED:
		led_traffic(YELLOW_RED);
		if(isButtonPress(2)){
			updatePrevStatus();
			status= SET_GREEN;
			return;
		}
		if(isButtonPress(0)){
			updatePrevStatus();
			status = MANUAL_YELLOW_RED;
			set_timer(1, duration[0]);
		}
		if(timer_flag[1]==1){
			updatePrevStatus();
			status = AUTO_RED_GREEN;
			set_timer(1,duration[1]);
		}
		break;
	default:
		break;

	}


}
