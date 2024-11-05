/*
 * traffic_light.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */
#include "traffic_light.h"

void led_traffic(int i){
	switch (i){
	case RED_GREEN:
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);
		break;
	case RED_YELLOW:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);
		break;
	case GREEN_RED:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,RESET);
		break;
	case YELLOW_RED:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
		break;
	default:
		break;
	}
}
void led_setting(int i){

	switch(i){
case SET_GREEN:
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,SET);
	break;
case SET_YELLOW:
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,RESET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,RESET);

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,SET);
	break;
default :
	break;
	}
}
