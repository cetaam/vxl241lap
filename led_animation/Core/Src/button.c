/*
 * button.c
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */

#include "button.h"




int timePress[10];
int buttonFlag[10];
int buttonkey[10][4];

void getkeyInput(){
	//-----PROCESS BUTTON 1------------
	/*key1_temp0 = key1_temp1;
	key1_temp1 = key1_temp2;
	key1_temp2 = HAL_GPIO_ReadPin(BT0_GPIO_Port, BT0_Pin);
*/
//	buttonkey[0][2]=HAL_GPIO_ReadPin(BT0_GPIO_Port, BT0_Pin);
//	buttonkey[1][2]=HAL_GPIO_ReadPin(BT1_GPIO_Port, BT1_Pin);
//	buttonkey[2][2]=HAL_GPIO_ReadPin(BT2_GPIO_Port, BT2_Pin);
//	for(int j=0;j< MAX_NUM_BUTTON;j++){
//		buttonkey[j][0]=buttonkey[j][1];
//		buttonkey[j][1]=buttonkey[j][2];
//		if(buttonkey[j][0]!=buttonkey[j][1]||buttonkey[j][1]!=buttonkey[j][2]){
//			continue;
//		}
//
//			timePress[j]--;
//		if(buttonkey[j][2]==PRESSED){
//			buttonFlag[j]=1;
//			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
//			timePress[j]=100;
//		}
//		if(timePress<=0){
//			buttonkey[j][3]=NORMAL;
//			timePress[j]=100;
//		}
//	}
	if(timer_flag[5]==1&& HAL_GPIO_ReadPin(BT0_GPIO_Port, BT0_Pin)==0){
		buttonFlag[0]=1;
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		set_timer(5, 50);
	}
	if(timer_flag[6]==1&& HAL_GPIO_ReadPin(BT1_GPIO_Port, BT1_Pin)==0){
		buttonFlag[1]=1;
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		set_timer(6, 50);
	}
	if(timer_flag[7]==1&& HAL_GPIO_ReadPin(BT2_GPIO_Port, BT2_Pin)==0){
		buttonFlag[2]=1;
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		set_timer(7, 50);
	}
//	key2_temp0 = key2_temp1;
//	key2_temp1 = key2_temp2;
//	key2_temp2 = HAL_GPIO_ReadPin(BT1_GPIO_Port, BT1_Pin);
//	// ----PROCESS BUTTON 2-----------
//
//	if((key2_temp0 == key2_temp1) && (key2_temp1 == key2_temp2)){
//		if(key2_temp3 != key2_temp2){
//			key2_temp3 = key2_temp2;
//			if(key2_temp2 == PRESSED){
//				buttonFlag[1] = 1;
//				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // DEBUG
//				timePress = 200;
//			}
//		}
//		else{
//			timePress--;
//			if(timePress <= 0){
//				key2_temp3 = NORMAL;
//				timePress = 200;
//			}
//		}
//	}
//	 ----- PROCESS BUTTON 3 -----------
//	key3_temp0 = key3_temp1;
//	key3_temp1 = key3_temp2;
//	key3_temp2 = HAL_GPIO_ReadPin(BT2_GPIO_Port, BT2_Pin);
//	if((key3_temp0 == key3_temp1) && (key3_temp1 == key3_temp2)){
//		if(key3_temp3 != key3_temp2){
//			key3_temp3 = key3_temp2;
//			if(key3_temp2 == PRESSED){
//				buttonFlag[2] = 1;
//				HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2); // DEBUG
//			}
//		}
//		else{
//			timePress--;
//			if(timePress <= 0){
//				key3_temp3 = NORMAL;
//				timePress = 200;
//			}
//		}
//	}



}
int isButtonPress(int i){
	if(buttonFlag[i] == 1){
		buttonFlag[i] = 0;
		return 1;
	}
	return 0;
}

