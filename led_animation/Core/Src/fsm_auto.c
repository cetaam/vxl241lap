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
		reset7seg();
		duration[0] = 200;
		duration[1] =1200; //DEFAULT_GREEN;
		duration[2] =1300; //DEFAULT_YELLOW;
		counter_reset();
		updateClockBuffer(counter[3]--, counter[1]--);
		status=AUTO_RED_GREEN;
		led_traffic(RED_GREEN);
		set_timer(0, 24);
		set_timer(1, duration[1]);//led
		set_timer(2,100);
		break;
	case AUTO_RED_GREEN:


		if(timer_flag[1]==1){
			updatePrevStatus();
			set_timer(1, duration[2]);
			status=AUTO_RED_YELLOW;
		}
		if(timer_flag[2]==1){
			updateClockBuffer(counter[3]--, counter[1]--);
			led_index=0;
			set_timer(2, 100);

			if(isButtonPress(0)){
				updatePrevStatus();
				counter_reset();
				status = MANUAL_RED_GREEN;
				set_timer(1, duration[0]);
				counter_reset();
			}
		}
		led_traffic(RED_GREEN);
		break;
	case AUTO_RED_YELLOW:

		if(timer_flag[1]==1){
			updatePrevStatus();
			status = AUTO_GREEN_RED;
			set_timer(1, duration[1]);
			counter_reset();
		}
		if(timer_flag[2]==1){
			updateClockBuffer(counter[3]--, counter[2]--);
			led_index=0;
			set_timer(2, 100);


			if(isButtonPress(0)){
				updatePrevStatus();
				counter_reset();
				status = MANUAL_RED_YELLOW;
				set_timer(1, duration[0]);
			}
		}
			led_traffic(RED_YELLOW);
		break;
		// same but yellow
	case AUTO_GREEN_RED:

		if(timer_flag[1]==1){
			updatePrevStatus();
			status = AUTO_YELLOW_RED;
			set_timer(1, duration[2]);
		}
		if(timer_flag[2]==1){
			updateClockBuffer(counter[1]--, counter[3]--);
			led_index=0;
			set_timer(2, 100);

			if(isButtonPress(0)){
				updatePrevStatus();
				counter_reset();
				status = MANUAL_GREEN_RED;
				set_timer(1, duration[0]);
			}
		}
			led_traffic(GREEN_RED);
		break;
	case AUTO_YELLOW_RED:

		if(timer_flag[1]==1){
			updatePrevStatus();
			status = AUTO_RED_GREEN;
			set_timer(1,duration[1]);
			counter_reset();
			led_traffic(RED_GREEN);
		}
		if(timer_flag[2]==1){
			updateClockBuffer(counter[2]--, counter[3]--);
			led_index=0;
			set_timer(2, 100);

			if(isButtonPress(0)){
				updatePrevStatus();
				counter_reset();
				status = MANUAL_YELLOW_RED;
				set_timer(1, duration[0]);
				buttonFlag[0]=0;
			}
		}
			led_traffic(YELLOW_RED);
		break;
	default:
		break;
	}

		if(isButtonPress(2)){
			updatePrevStatus();
			status= SET_GREEN;
			buttonFlag[2]=0;
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
	counter[3]=counter[1]+counter[2];
	counter[1]--;
	counter[2]--;
	counter[3]--;

	}
