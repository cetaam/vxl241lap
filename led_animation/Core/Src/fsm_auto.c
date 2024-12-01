/*
 * fsm_auto.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_auto.h"

void fsm_auto_run(){
	switch (status){
	case INIT:
//		resetled();
//		status=AUTO_RED_GREEN;

//		SCH_Add_Task(auto_red_green_run, 0, 0);
//		SCH_Add_Task(per_second, 10, 1000);
//		SCH_Add_Task(scanled, 10, 250);
		break;
	case AUTO_RED_GREEN:
		break;
	case AUTO_RED_YELLOW:
		break;
	case AUTO_GREEN_RED:
		break;
	case AUTO_YELLOW_RED:
		break;
	default:
		return;
	}
	if(isButtonPress(0)){//SWITCH TO MANUAL
		SCH_Delete_Task(waiting_task);
		SCH_Delete_Task(scanled);
		SCH_Delete_Task(per_second);
		led_index=0;
		reset7seg();
		status += 30;//correspond status in manual
		return;
	}

	if(isButtonPress(2)){	//SWITCH TO SETTING
		SCH_Delete_Task(waiting_task);
		SCH_Delete_Task(per_second);
		resetled();
		led_traffic(SET_GREEN);
		updateClockBuffer(0, 0);
		status= SET_GREEN;

	}

}
void per_second(){
	counter[0]--;
	counter[1]--;
	updateClockBuffer(counter[0], counter[1]);
}

void auto_red_green_run(){
	status=AUTO_RED_GREEN;
	led_traffic(RED_GREEN);
	counter[0]=(time_green+time_yellow)/1000;
	counter[1]=time_green/1000;
	SCH_Add_Task(auto_red_yellow_run, time_green, 0);
	previous_task=auto_red_green_run;
	waiting_task=auto_red_yellow_run;
}
void auto_red_yellow_run(){
	status=AUTO_RED_YELLOW;
	led_traffic(RED_YELLOW);
	counter[0]=time_yellow/1000;
	counter[1]=time_yellow/1000;
	SCH_Add_Task(auto_green_red_run, time_yellow, 0);
	previous_task=auto_red_yellow_run;
	waiting_task=auto_green_red_run;
}
void auto_green_red_run(){
	status=AUTO_GREEN_RED;
	led_traffic(GREEN_RED);
	counter[0]=time_green/1000;
	counter[1]=(time_green+time_yellow)/1000;
	SCH_Add_Task(auto_yellow_red_run, time_green, 0);
	previous_task=auto_green_red_run;
	waiting_task=auto_yellow_red_run;
}
void auto_yellow_red_run(){
	status=AUTO_YELLOW_RED;
	led_traffic(YELLOW_RED);
	counter[0]=time_yellow/1000;
	counter[1]=time_yellow/1000;
	SCH_Add_Task(auto_red_green_run, time_yellow, 0);
	previous_task=auto_yellow_red_run;
	waiting_task=auto_red_green_run;
}


