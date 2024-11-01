/*
 * button.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */

#include "button.h"


int key1_temp0 = NORMAL;
int key1_temp1 = NORMAL;
int key1_temp2 = NORMAL;
int key1_temp3 = NORMAL;
int buttonkey[4];

int key2_temp0 = NORMAL;
int key2_temp1 = NORMAL;
int key2_temp2 = NORMAL;
int key2_temp3 = NORMAL;

int key3_temp0 = NORMAL;
int key3_temp1 = NORMAL;
int key3_temp2 = NORMAL;
int key3_temp3 = NORMAL;

int timePress = 0;
int buttonFlag[10];

void getkeyInput(){
	//-----PROCESS BUTTON 1------------
	key1_temp0 = key1_temp1;
	key1_temp1 = key1_temp2;
	key1_temp2 = HAL_GPIO_ReadPin(BT0_GPIO_Port, BT0_Pin);

	key2_temp0 = key2_temp1;
	key2_temp1 = key2_temp2;
	key2_temp2 = HAL_GPIO_ReadPin(BT1_GPIO_Port, BT1_Pin);

	if((key1_temp0 == key1_temp1) && (key1_temp1 == key1_temp2)){
		if(key1_temp3 != key1_temp2){
			key1_temp3 = key1_temp2;
			if(key1_temp2 == PRESSED){
				buttonFlag[0] = 1;
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // DEBUG
				timePress = 200;
			}
		}
		else{
			timePress--;
			if(timePress <= 0){
				key1_temp3 = NORMAL;
				timePress = 200;
			}
		}

	}
	// ----PROCESS BUTTON 2-----------

	if((key2_temp0 == key2_temp1) && (key2_temp1 == key2_temp2)){
		if(key2_temp3 != key2_temp2){
			key2_temp3 = key2_temp2;
			if(key2_temp2 == PRESSED){
				buttonFlag[1] = 1;
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // DEBUG
				timePress = 200;
			}
		}
		else{
			timePress--;
			if(timePress <= 0){
				key2_temp3 = NORMAL;
				timePress = 200;
			}
		}
	}
	// ----- PROCESS BUTTON 3 -----------
	key3_temp0 = key3_temp1;
	key3_temp1 = key3_temp2;
	key3_temp2 = HAL_GPIO_ReadPin(BT2_GPIO_Port, BT2_Pin);
	if((key3_temp0 == key3_temp1) && (key3_temp1 == key3_temp2)){
		if(key3_temp3 != key3_temp2){
			key3_temp3 = key3_temp2;
			if(key3_temp2 == PRESSED){
				buttonFlag[2] = 1;
				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2); // DEBUG
			}
		}
		else{
			timePress--;
			if(timePress <= 0){
				key3_temp3 = NORMAL;
				timePress = 200;
			}
		}
	}
}
int isButtonPress(int i){
	if(buttonFlag[i] == 1){
		buttonFlag[i] = 0;
		return 1;
	}
	return 0;

}
