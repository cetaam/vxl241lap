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
		resetled();
		status=AUTO_RED_GREEN;
		led_traffic(RED_GREEN);
//		set_timer(0, 24);
//		set_timer(1, time_green);//led
//		set_timer(2,100);
		updateClockBuffer(counter[0], counter[1]);
		SCH_Add_Task(auto_red_green_run, 0, 0);
		SCH_Add_Task(per_second, 0, 1000);
		SCH_Add_Task(scanled, 0, 250);
		break;
	case AUTO_RED_GREEN:

		if(isButtonPress(0)){//SWITCH TO MANUAL
			SCH_Delete_Task(auto_red_yellow_run);
			SCH_Delete_Task(scanled);
			SCH_Delete_Task(per_second);
			SCH_Delete_Task(fsm_auto_run);

			SCH_Add_Task(auto_red_green_run, time_manual, 0);
			SCH_Add_Task(per_second, time_manual, 1000);
			SCH_Add_Task(scanled, time_manual, 250);

			status += 30;//correspond status in manual
			counter[0]=(time_green+time_yellow)/1000;
			counter[1]=time_green/1000;
			reset7seg();
			return;
		}
		if(isButtonPress(2)){	//SWITCH TO SETTING
			SCH_Delete_Task(auto_red_yellow_run);
			SCH_Delete_Task(per_second);

			resetled();
			status= SET_GREEN;
		}
		break;
	case AUTO_RED_YELLOW:

		if(isButtonPress(0)){//SWITCH TO MANUAL
			SCH_Delete_Task(auto_green_red_run);
			SCH_Delete_Task(scanled);
			SCH_Delete_Task(per_second);
			SCH_Delete_Task(fsm_auto_run);

			SCH_Add_Task(auto_red_yellow_run, time_manual, 0);
			SCH_Add_Task(per_second, time_manual, 1000);
			SCH_Add_Task(scanled, time_manual, 250);

			status += 30;//correspond status in manual
			counter[0]=time_yellow/1000;
			counter[1]=time_yellow/1000;
			reset7seg();
			return;
		}
		if(isButtonPress(2)){	//SWITCH TO SETTING
			SCH_Delete_Task(auto_green_red_run);
			SCH_Delete_Task(per_second);

			resetled();
			status= SET_GREEN;
		}
		break;

	case AUTO_GREEN_RED:

		if(isButtonPress(0)){//SWITCH TO MANUAL
			SCH_Delete_Task(auto_yellow_red_run);
			SCH_Delete_Task(scanled);
			SCH_Delete_Task(per_second);
			SCH_Delete_Task(fsm_auto_run);

			SCH_Add_Task(auto_green_red_run, time_manual, 0);
			SCH_Add_Task(per_second, time_manual, 1000);
			SCH_Add_Task(scanled, time_manual, 250);

			status += 30;//correspond status in manual
			counter[0]=time_green/1000;
			counter[1]=(time_green+time_yellow)/1000;
			reset7seg();
			return;
		}
		if(isButtonPress(2)){	//SWITCH TO SETTING
			SCH_Delete_Task(auto_yellow_red_run);
			SCH_Delete_Task(per_second);

			resetled();
			status= SET_GREEN;
		}

		break;
	case AUTO_YELLOW_RED:

		if(isButtonPress(0)){//SWITCH TO MANUAL
			SCH_Delete_Task(auto_red_green_run);
			SCH_Delete_Task(scanled);
			SCH_Delete_Task(per_second);
			SCH_Delete_Task(fsm_auto_run);

			SCH_Add_Task(auto_yellow_red_run, time_manual, 0);
			SCH_Add_Task(per_second, time_manual, 1000);
			SCH_Add_Task(scanled, time_manual, 250);

			status += 30;//correspond status in manual
			counter[0]=time_yellow/1000;
			counter[1]=time_yellow/1000;
			reset7seg();
			return;
		}
		if(isButtonPress(2)){	//SWITCH TO SETTING
			SCH_Delete_Task(auto_red_green_run);
			SCH_Delete_Task(per_second);

			resetled();
			status= SET_GREEN;
		}
		break;
	default:
		return;
	}



}
void per_second(){
	counter[0]--;
	counter[1]--;
	updateClockBuffer(counter[0], counter[1]);
	led_index=0;
}

void auto_red_green_run(){
	status=AUTO_RED_GREEN;
	led_traffic(RED_GREEN);
	counter[0]=(time_green+time_yellow)/1000;
	counter[1]=time_green/1000;
	SCH_Add_Task(auto_red_yellow_run, time_green, 0);

}
void auto_red_yellow_run(){
	status=AUTO_RED_YELLOW;
	led_traffic(RED_YELLOW);
	counter[0]=time_yellow/1000;
	counter[1]=time_yellow/1000;
	SCH_Add_Task(auto_green_red_run, time_yellow, 0);
}
void auto_green_red_run(){
	status=AUTO_GREEN_RED;
	led_traffic(GREEN_RED);
	counter[0]=time_green/1000;
	counter[1]=(time_green+time_yellow)/1000;
	SCH_Add_Task(auto_yellow_red_run, time_green, 0);
}
void auto_yellow_red_run(){
	status=AUTO_YELLOW_RED;
	led_traffic(YELLOW_RED);

	counter[0]=time_yellow/1000;
	counter[1]=time_yellow/1000;
	SCH_Add_Task(auto_red_green_run, time_yellow, 0);
}

