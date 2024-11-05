/*
 * led7_seg.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */
#include "led7_seg.h"
int led_buffer[4];


void updateClockBuffer(int num_X,int num_Y){
	led_buffer[3]= num_Y%10;
	led_buffer[2]= num_Y/10;

	led_buffer[1]= num_X%10;
	led_buffer[0]= num_X/10;
}
void update7SEG(int index){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);
switch (index){
case 0:
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, RESET);
	display7SEG(led_buffer[index]);
	break;
case 1:
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, RESET);
	display7SEG(led_buffer[index]);
	break;
case 2:
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, RESET);
	display7SEG(led_buffer[index]);
	break;
case 3:
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, RESET);
	display7SEG(led_buffer[index]);
	break;
	}
}


void display7SEG(int num){
	switch (num){
	case 0:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 	SET);
		break;
	case 1:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, 	SET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 	SET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 	SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, 	SET);
		break;
	case 2:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, 	SET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 	SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, 	SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin,SET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 	SET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin,RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 	SET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, 	SET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, 	SET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin,	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin,	SET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin,	SET);
		break;
	case 8:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, RESET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin,RESET);
		HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, RESET);
		HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, RESET);
		HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, RESET);
		HAL_GPIO_WritePin(S4_GPIO_Port, S4_Pin, 	SET);
		HAL_GPIO_WritePin(S5_GPIO_Port, S5_Pin, RESET);
		HAL_GPIO_WritePin(S6_GPIO_Port, S6_Pin, RESET);
		break;
	default:
		break;
	}

}
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
