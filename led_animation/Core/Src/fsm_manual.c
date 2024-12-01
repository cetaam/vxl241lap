/*
 * fsm_manual.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_manual.h"


void fsm_manual_run(){//BUTTON 0 RETURN TO AUTO//BUTTON 1 SWITCH LIGHTS
	switch(status){
	case MANUAL_RED_GREEN:
		if(isButtonPress(1)){
			led_traffic(RED_YELLOW);
			status = MANUAL_RED_YELLOW;
			previous_task=auto_red_yellow_run;
		}
		break;
	case MANUAL_RED_YELLOW:
		if(isButtonPress(1)){
			led_traffic(GREEN_RED);
			status = MANUAL_GREEN_RED;
			previous_task=auto_green_red_run;
		}
		break;
	case MANUAL_GREEN_RED:
		if(isButtonPress(1)){
			led_traffic(YELLOW_RED);
			status = MANUAL_YELLOW_RED;
			previous_task=auto_yellow_red_run;
		}
		break;
	case MANUAL_YELLOW_RED:
		if(isButtonPress(1)){
			led_traffic(RED_GREEN);
			status = MANUAL_RED_GREEN;
			previous_task=auto_red_green_run;
		}
		break;
	default:
		return;
		}

	if(isButtonPress(0)){
		led_index=0;

		SCH_Add_Task(previous_task, 0, 0);//auto_previous_state_run
		SCH_Add_Task(per_second, 10, 1000);
		SCH_Add_Task(scanled, 10, 250);

		}

}
