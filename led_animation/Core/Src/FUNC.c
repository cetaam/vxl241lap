/*
 * FUNC.c
 *
 *  Created on: Oct 20, 2024
 *      Author: xjkpr
 */
#include "FUNC.h"
int led_index;
int led_buffer[4];

void display7SEG(int num){
	switch (num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 	SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 	SET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 	SET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 	SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 	SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 	SET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 	SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 	SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 	SET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 	SET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 	SET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 	SET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 	SET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin,	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin,	SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin,	SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;

	}
}
void update7SEG(int index){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
switch (index){
case 0:
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
	display7SEG(led_buffer[index]);
	break;
case 1:
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
	display7SEG(led_buffer[index]);
	break;
case 2:
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	display7SEG(led_buffer[index]);
	break;
case 3:
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
	display7SEG(led_buffer[index]);
	break;
}


}
