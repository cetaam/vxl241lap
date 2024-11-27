/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_manual.h"


void fsm_manual_run(){
	switch(status){
	case MANUAL_RED_GREEN:
		if(isButtonPress(0)){


			SCH_Add_Task(fsm_auto_run, 0, 10);
			SCH_Add_Task(auto_red_green_run, 0, 0);
			SCH_Add_Task(per_second, 0, 1000);
			SCH_Add_Task(scanled, 0, 250);
			status -=31;
			return;
			}
		if(isButtonPress(1)){
			led_traffic(RED_YELLOW);
			status = MANUAL_RED_YELLOW;
			set_timer(1, time_manual);
		}
		break;
	case MANUAL_RED_YELLOW:
		if(isButtonPress(0)){
			SCH_Add_Task(fsm_auto_run, 0, 10);
			SCH_Add_Task(auto_red_yellow_run, 0, 0);
			SCH_Add_Task(per_second, 0, 1000);
			SCH_Add_Task(scanled, 0, 250);
			status -=31;
			return;
			}
		if(isButtonPress(1)){
			led_traffic(GREEN_RED);
			status = MANUAL_GREEN_RED;
			set_timer(1, time_manual);
		}
		break;
	case MANUAL_GREEN_RED:
		if(isButtonPress(0)){
			SCH_Add_Task(fsm_auto_run, 0, 10);
			SCH_Add_Task(auto_green_red_run, 0, 0);
			SCH_Add_Task(per_second, 0, 1000);
			SCH_Add_Task(scanled, 0, 250);
			status -=31;
			return;
			}
		if(isButtonPress(1)){
			led_traffic(YELLOW_RED);
			status = MANUAL_YELLOW_RED;
			set_timer(1, time_manual);
		}
		break;
	case MANUAL_YELLOW_RED:
		if(isButtonPress(0)){
			SCH_Add_Task(auto_yellow_red_run, 0, 0);
			SCH_Add_Task(per_second, 0, 1000);
			SCH_Add_Task(scanled, 0, 250);
			status -=31;
			return;
			}
		if(isButtonPress(1)){
			led_traffic(RED_GREEN);
			status = MANUAL_RED_GREEN;
			set_timer(1, time_manual);
		}
		break;
	default:
		return;

		}


	if(isButtonPress(2)){
		status= SET_MANUAL;
	}
}
