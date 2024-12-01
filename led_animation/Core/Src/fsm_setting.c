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

		if(isButtonPress(1)){
			increased++;
			temp+=1;
			if(temp>98){
				temp=0;
			}
		updateClockBuffer(0, temp);

		}
		if(isButtonPress(0)){


			temp*=1000;
			//SWAP
			temp = temp^time_green;
			time_green = temp^time_green;
			temp = temp^time_green;
			if(increased<1){//no changes=old value
				time_green=temp;

			}
			increased=0;
			temp=0;
			updateClockBuffer(0, temp);
			led_traffic(SET_YELLOW);
			status = SET_YELLOW;
		}


		break;
	case SET_YELLOW://yellow<=99-green

		if(isButtonPress(1)){
			increased++;
			temp+=1;
			if(temp>(99-time_green/100)){
				temp=0;
			}
			updateClockBuffer(0, temp);
		}
		if(isButtonPress(0)){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
			temp*=1000;
			//SWAP
			temp = temp^time_yellow;
			time_yellow = temp^time_yellow;
			temp = temp^time_yellow;
			if(increased<1){
				time_yellow=temp;

			}
			increased=0;
			temp=0;
			SCH_Delete_Task(scanled);
			led_index=0;

			SCH_Add_Task(previous_task, 0, 0);//auto_previous_state_run
			SCH_Add_Task(per_second, 10, 1000);
			SCH_Add_Task(scanled, 10, 250);

		}
		break;
	default:
		return;

	}
	if(isButtonPress(2)){
			increased=0;
				temp=0;
			}
	}
