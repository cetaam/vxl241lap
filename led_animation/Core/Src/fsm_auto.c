/*
 * fsm_auto.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "fsm_auto.h"
int durration[10];

void fsm_auto_run(){
	switch (status){
	case INIT:
		resetled();
		status=AUTO_RED_GREEN;
		durration[0] = 200;
		durration[1] = 200;
		set_timer(0, 50);
		set_timer(1, 200);
		break;
	case AUTO_RED_GREEN:
		led_state(RED_GREEN);

		if(isButtonPress(0)){
			status = MANUAL_RED_GREEN;
			set_timer(1, 1000);

		}
		if(timer_flag[1]==1){
			status=AUTO_RED_YELLOW;
			set_timer(1, 200);
		}

		break;
	case AUTO_RED_YELLOW:
		led_state(RED_YELLOW);

		if(isButtonPress(0)){
			status = MANUAL_RED_YELLOW;
			set_timer(1, 1000);
		}
		if(timer_flag[1]==1){
			status = AUTO_GREEN_RED;
			set_timer(1, 200);
		}
		break;
	case AUTO_GREEN_RED:
		led_state(GREEN_RED);

		if(isButtonPress(0)){
			status = MANUAL_GREEN_RED;
			set_timer(1, 1000);
		}
		if(timer_flag[1]==1){
			status = AUTO_YELLOW_RED;
			set_timer(1, 200);
		}
		break;
	case AUTO_YELLOW_RED:
		led_state(YELLOW_RED);

		if(isButtonPress(0)){
			status = MANUAL_YELLOW_RED;
			set_timer(1, 1000);
		}
		if(timer_flag[1]==1){
			status = AUTO_RED_GREEN;
			set_timer(1,200);
		}
		break;
	default:
		break;
	case SET_RED:
		resetled();
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9);

		break;
	case SET_GREEN:
		break;
	case SET_YELLOW:
		break;
	case MANUAL_RED_GREEN:
		break;
	case MANUAL_RED_YELLOW:
		break;
	case MANUAL_GREEN_RED:
		break;
	case MANUAL_YELLOW_RED:
		break;
	case SLOW:
		break;
	}
}
