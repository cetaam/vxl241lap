/*
 * fsm_setting.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_setting.h"

int temp=0;
int increased=0;

void fsm_setting_run(){
	switch(status){
	case SET_GREEN://green<=98
		led_setting(SET_GREEN);
		if(isButtonPress(1)){
			increased++;
			temp+=1;
			if(temp>98){
				temp=0;
			}
		updateClockBuffer(0, temp);

		}
		if(isButtonPress(0)){

			status = SET_YELLOW;
			temp*=100;
			//SWAP
			temp = temp^time_green;
			time_green = temp^time_green;
			temp = temp^time_green;
			if(increased<1){//no changes=old value
				time_green=temp;

			}
			increased=0;
			temp=0;
		}


		break;
	case SET_YELLOW://yellow<=99-green
		led_setting(SET_YELLOW);
		if(isButtonPress(1)){
			increased++;
			temp+=1;
			if(temp>(99-time_green/100)){
				temp=0;
			}
			updateClockBuffer(0, temp);
		}
		if(isButtonPress(0)){
			status =INIT;
			resetled();
			temp*=100;
			//SWAP
			temp = temp^time_yellow;
			time_yellow = temp^time_yellow;
			temp = temp^time_yellow;
			if(increased<1){
				time_yellow=temp;

			}
			increased=0;
			temp=0;

		}


		break;
	case SET_MANUAL:
		if(isButtonPress(1)){
			increased++;
			temp++;
			if(temp>99){
				temp=0;
			}
			updateClockBuffer(0, temp);
		}
		if(isButtonPress(0)){

			status = MANUAL_RED_GREEN;
			temp*=100;
			//SWAP
			temp = temp^time_manual;
			time_manual = temp^time_manual;
			temp = temp^time_manual;
			if(increased<1){
				time_manual=temp;
			}
			set_timer(1, time_manual);
			reset7seg();
			increased=0;
			temp=0;
		}



		break;
	default:
		return;


	}
	if(isButtonPress(2)){
			increased=0;
				temp=0;
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
