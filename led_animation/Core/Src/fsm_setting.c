/*
 * fsm_setting.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_setting.h"
int duration[10];
int temp=0;


void fsm_setting_run(){
	switch(status){
	case SET_GREEN:
		led_setting(SET_GREEN);
		if(isButtonPress(1)){
			temp++;
			if(temp>98){
				temp=0;
			}
		}
		if(isButtonPress(0)){
			status = SET_YELLOW;
			duration[1]=temp*100;
			temp=0;
			if(!duration[1]){
				duration[1]=DEFAULT_GREEN;
			}
		}
		if(isButtonPress(2)){
			temp=0;
		}

		break;
	case SET_YELLOW://+CHECK
		led_setting(SET_YELLOW);
		if(isButtonPress(1)){
			temp++;
			if(temp>(99-duration[1])){
				temp=0;
			}
		}
		if(isButtonPress(0)){
			status =prev_status;
			led_traffic_back(status);
			duration[2]=temp*100;
			temp=0;
			if(!duration[2]){
				duration[2]=DEFAULT_YELLOW;
			}
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
			duration[1]=temp*100;
			temp=0;
			if(!duration[0]){
				duration[0]=DEFAULT_MANUAL_WAIT;
			}
		}

		if(isButtonPress(2)){
			temp=0;
		}

		break;
	default:
		break;

	}
}
