/*
 * keypad_development.h
 *
 *  Created on: 21 sept. 2022
 *      Author: alexSumozas
 */
#include "stm32f4xx.h"
#ifndef INC_KEYPAD_DEVELOPMENT_H_
#define INC_KEYPAD_DEVELOPMENT_H_

#define ROW1 2
#define ROW2 8
#define ROW3 2
#define ROW4 8
#define COL1 32
#define COL2 128
#define COL3 32
#define COL4 2



const GPIO_TypeDef*  row_ports[] = {GPIOC,GPIOC,GPIOA,GPIOA};
const GPIO_TypeDef*  col_ports[] = {GPIOA,GPIOA,GPIOC,GPIOB};
static uint16_t row_pins[] = {ROW1,ROW2,ROW3,ROW4};
static uint16_t col_pins[] = {COL1,COL2,COL3,COL4};

void initKeyPad();

char readKeyPad();

char getKeyPad();

char interfaceValueKey(char);
#endif /* INC_KEYPAD_DEVELOPMENT_H_ */
