/*
 * tim.c
 *
 *  Created on: Oct 20, 2024
 *      Author: xjkpr
 */

#include "timer.h"


int timer_flag[10];
int timer_counter[10];

void set_timer(int i, int durr){
	timer_flag[i]=0;
	timer_counter[i]=durr;
}
void timerrun(int i){

		timer_counter[i]--;
		if(timer_counter[i]<=0)
			timer_flag[i]=1;

}
void timer_init(){
	set_timer(0, 25);
	set_timer(1, 100);

}

