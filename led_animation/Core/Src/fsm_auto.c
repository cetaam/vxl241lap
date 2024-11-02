/*
 * fsm_auto.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_auto.h"
int duration[10];
int counter[10];
int led_index=0;
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
		updateClockBuffer(counter[1]+counter[2], counter[1]);
		set_timer(0, 25);
		set_timer(1, duration[1]);//led
		set_timer(2,100);
		countdown();
		break;
	case AUTO_RED_GREEN:
		led_traffic(RED_GREEN);
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
			updateClockBuffer(counter[1]+duration[2]/100, counter[2]);
		}
		//show red=green+yellow time  adn green
		break;
	case AUTO_RED_YELLOW:
		led_traffic(RED_YELLOW);
		countdown();
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
			updateClockBuffer(counter[1], counter[1]+counter[2]);
		}
		break;
		// same but yellow
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
			updateClockBuffer(counter[1], counter[1]+counter[2]);
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
			updateClockBuffer(counter[1]+counter[2], counter[1]);
		}
		break;
	default:
		break;

	}

}

void countdown(){
	if(timer_flag[0]==1){
		set_timer(0, 25);
		update7SEG(led_buffer[led_index++]);
	}
	if(timer_flag[2]==1){
		set_timer(2,100);
		counter[1]--;
		counter[2]--;
		if(counter[1]<0){
			counter[1]=duration[1];
		}
		if(counter[1]<0){
			counter[2]=duration[2];
		}
		led_index=0;
		updateClockBuffer(counter);
	}
	}
