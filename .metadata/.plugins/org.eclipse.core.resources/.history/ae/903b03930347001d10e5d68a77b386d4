/*
 * lcd_development.h
 *
 *  Created on: Sep 13, 2022
 *      Author: alexSumozas
 */
#define SLAVE_ADDRESS_LCD 0X4E
#define LCD_ROWS 4
#define LCD_COLS 20
#define LCD_BLINK_ON 0x0F
#define LCD_CLEAR 0x00
#define LCD_BLINK_OFF 0x0E


#include  "stm32f4xx_hal.h"
#include "auxfunc_development.h"


#ifndef INC_LCD_DEVELOPMENT_H_
#define INC_LCD_DEVELOPMENT_H_

void lcd_send_cmd (char cmd);


void lcd_send_data (char data);


void lcd_clear (void);


void lcd_init (void);

void lcd_send_string (char *str,bool adjust_to_line);
void lcd_put_cursor(int row, int col);

//FUNCIONES PROPIAS

void LCD_displayONOFF (int a);

#endif /* INC_LCD_DEVELOPMENT_H_ */
