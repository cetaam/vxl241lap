/*
 * fsm_auto.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_auto.h"
int duration[10];

int led_index=0;
void fsm_auto_run(){
	switch (status){
	case INIT:
		resetled();
		reset7seg();
		duration[0] = 200;
		duration[1] =200; //DEFAULT_GREEN;
		duration[2] =300; //DEFAULT_YELLOW;
		status=AUTO_RED_GREEN;
		led_traffic(RED_GREEN);
		set_timer(0, 24);
		set_timer(1, duration[1]);//led
		set_timer(2,100);
		counter_reset();
		updateClockBuffer(--counter[0], --counter[1]);
		break;
	case AUTO_RED_GREEN:
		if(timer_flag[2]==1){//every 1s
			updateClockBuffer(--counter[0], --counter[1]);
			set_timer(2, 100);
			set_timer(0, 24);
			led_index=0;

		if(timer_flag[1]==1){
			prev_status=status;
			status=AUTO_RED_YELLOW;
			updateClockBuffer(--counter[2], counter[2]);
			set_timer(1, duration[2]);
			set_timer(2,100);
			set_timer(0, 24);
			led_traffic(RED_YELLOW);
			}
		}
		break;
	case AUTO_RED_YELLOW:

		if(timer_flag[2]==1){//every 1s
			updateClockBuffer(--counter[2], counter[2]);
			set_timer(2, 100);
			set_timer(0, 24);
			led_index=0;
		if(timer_flag[1]==1){
			prev_status=status;
			status = AUTO_GREEN_RED;
			counter_reset();
			updateClockBuffer(--counter[1], --counter[0]);
			set_timer(1, duration[1]);
			set_timer(2,100);
			set_timer(0, 24);
			led_traffic(GREEN_RED);
		}
		}

		break;

	case AUTO_GREEN_RED:
		if(timer_flag[2]==1){//every 1s
			updateClockBuffer(--counter[1], --counter[0]);
			set_timer(2, 100);
			set_timer(0, 24);
			led_index=0;
		if(timer_flag[1]==1){
			prev_status=status;
			status = AUTO_YELLOW_RED;
			updateClockBuffer(--counter[2], counter[2]);
			set_timer(1, duration[2]);
			set_timer(2,100);
			set_timer(0, 24);
			led_traffic(YELLOW_RED);
		}
		}

		break;
	case AUTO_YELLOW_RED:
		if(timer_flag[2]==1){//every 1s
			updateClockBuffer(--counter[2], counter[2]);
			set_timer(2, 100);
			set_timer(0, 24);
			led_index=0;
		if(timer_flag[1]==1){
			prev_status=status;
			status = AUTO_RED_GREEN;
			counter_reset();
			updateClockBuffer(--counter[0], --counter[1]);
			set_timer(1,duration[1]);
			set_timer(2,100);
			set_timer(0, 24);
			led_traffic(RED_GREEN);
		}

		}
		break;
	default:
		return;
		break;
	}
	//SWITCH TO MANUAL
	if(isButtonPress(0)){
		counter_reset();
		prev_status=status;
		status += 30;//correspond status in manual
		set_timer(1, duration[0]);
		return;
	}
	//SWITCH TO SETTING
	if(isButtonPress(2)){
		prev_status=status;
		counter_reset();
		resetled();
		reset7seg();
		status= SET_GREEN;
		return;
	}
	if(timer_flag[0]==1){
		update7SEG(led_index++);
		set_timer(0, 24);
	}

}

void counter_reset(){
	counter[1]=duration[1]/100;
	counter[2]=duration[2]/100;
	counter[0]=counter[1]+counter[2];


	}
