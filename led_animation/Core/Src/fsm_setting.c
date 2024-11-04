/*
 * fsm_setting.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_setting.h"

int temp=0;


void fsm_setting_run(){
	switch(status){
	case SET_GREEN://green<=98
		led_setting(SET_GREEN);
		if(isButtonPress(1)){
			temp++;
			if(temp>98){
				temp=0;
			}
		updateClockBuffer(0, temp);

		}
		if(isButtonPress(0)){
			status = SET_YELLOW;
			temp*=100;
			//SWAP
			temp = temp^duration[1];
			duration[1] = temp^duration[1];
			temp = temp^duration[1];
			if(duration[1]<=0){//no changes=old value
				duration[1]=temp;
			}
		}
		if(isButtonPress(2)){
			temp=0;
		}

		break;
	case SET_YELLOW://yellow<=99-green
		led_setting(SET_YELLOW);
		if(isButtonPress(1)){
			temp++;
			if(temp>(99-duration[1]/100)){
				temp=0;
			}
			updateClockBuffer(0, temp);
		}
		if(isButtonPress(0)){
			status =prev_status;
			led_traffic_back(status);
			temp*=100;
			//SWAP
			temp = temp^duration[2];
			duration[2] = temp^duration[2];
			temp = temp^duration[2];
			if(duration[2]<=0){
				duration[2]=temp;
			}
			counter_reset();
			set_timer(0, 24);
			set_timer(2, 100);
		}

		if(isButtonPress(2)){
			temp=0;
		}
		break;
	case SET_MANUAL:
		if(isButtonPress(1)){
			temp++;
			if(temp>99){
				temp=0;
			}
		}
		if(isButtonPress(0)){
			status = prev_status;
			temp*=100;
			//SWAP
			temp = temp^duration[0];
			duration[0] = temp^duration[0];
			temp = temp^duration[0];
			if(!duration[0]){
				duration[0]=temp;
			}
		}

		if(isButtonPress(2)){
			temp=0;
		}

		break;
	default:
		return;


	}
	if(timer_flag[2]==1){
		updateClockBuffer(0, temp);
		set_timer(2, 100);
		set_timer(0, 24);
		led_index=0;
	}
	if(timer_flag[0]==1){
		update7SEG(led_index++);
		set_timer(0, 24);
	}
}
