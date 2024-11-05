/*
 * global.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "global.h"
int status = 1;
int led_index=0;

int counter[10];
int time_green=300;
int time_yellow=200;
int time_manual=200;
void resetled(){
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET);
}
void reset7seg(){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, SET);
}

