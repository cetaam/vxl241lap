/*
 * button.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */

#include "button.h"





int buttonFlag[10];
uint8_t count = 0;

void getkeyInput(){
	if (count > 0 ) count--;
	if(count==0&& HAL_GPIO_ReadPin(BT0_GPIO_Port, BT0_Pin)==0){
		buttonFlag[0]=1;
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		count=50;
	}
	if(count==0&& HAL_GPIO_ReadPin(BT1_GPIO_Port, BT1_Pin)==0){
		buttonFlag[1]=1;
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		count=50;
	}
	if(count==0&& HAL_GPIO_ReadPin(BT2_GPIO_Port, BT2_Pin)==0){
		buttonFlag[2]=1;
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		count=50;
	}


}
int isButtonPress(int i){
	if(buttonFlag[i] == 1){
		buttonFlag[i] = 0;
		return 1;
	}
	return 0;
}

