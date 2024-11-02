/*
 * global.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */


#include "global.h"
int status = 0;
int prev_status=0;

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
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, RESET);
}
void updatePrevStatus(){
	if(prev_status!=status)
	prev_status=status;
}
