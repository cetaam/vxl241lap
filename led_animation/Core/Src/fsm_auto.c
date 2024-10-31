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
		set_timer(0, 50);
		set_timer(1, 500);
		break;
	case AUTO_RED_GREEN:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		if(timer_flag[1]==1){
			status=AUTO_RED_YELLOW;
			set_timer(1, 200);
		}
		break;
	case AUTO_RED_YELLOW:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);
		if(timer_flag[1]==1){
			status = AUTO_GREEN_RED;
			set_timer(1, 500);
		}
		break;
	case AUTO_GREEN_RED:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,RESET);
		if(timer_flag[1]==1){
			status = AUTO_YELLOW_RED;
			set_timer(1, 200);
		}
		break;
	case AUTO_YELLOW_RED:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
		if(timer_flag[1]==1){
			status = AUTO_RED_GREEN;
			set_timer(1,500);
		}
		break;
	case SET_RED:
		resetled();

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
