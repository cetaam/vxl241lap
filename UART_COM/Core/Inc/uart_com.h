/*
 * uart_communication_fsm.h
 *
 *  Created on: Dec 8, 2024
 *      Author: xjkpr
 */

#ifndef INC_UART_COM_H_
#define INC_UART_COM_H_

#include "main.h"



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void uart_communication_fsm();


#endif /* INC_UART_COM_H_ */
