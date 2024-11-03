/*
 * button.h
 *
 *  Created on: Oct 30, 2024
 *      Author: xjkpr
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define MAX_NUM_BUTTON 3


#include "global.h"




extern int buttonFlag[10];
extern int buttonkey[10][4];
extern int timePress[10];

void getkeyInput();
int isButtonPress(int i);
#endif /* INC_BUTTON_H_ */
