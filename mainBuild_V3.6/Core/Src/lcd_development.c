/*
 * lcd_development.c
 *
 *  Created on: Sep 13, 2022
 *      Author: asumo
 */
#include "lcd_development.h"


extern I2C_HandleTypeDef hi2c2;  // change your handler here accordingly

static char cursor_pos = 0;


void lcd_send_cmd (char cmd)
{
  char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c2, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}


void lcd_send_data (char data)
{
	lcd_put_cursor((int)cursor_pos/20,(int)cursor_pos%20);

	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=1
	data_t[1] = data_u|0x09;  //en=0, rs=1
	data_t[2] = data_l|0x0D;  //en=1, rs=1
	data_t[3] = data_l|0x09;  //en=0, rs=1
	HAL_I2C_Master_Transmit (&hi2c2, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
	if (cursor_pos<79)
		cursor_pos++;
	else
		cursor_pos=0;

}

void lcd_clear (void)
{
	lcd_send_cmd (0x00);
	for (int i=0; i<100; i++)
	{
		lcd_send_data (' ');
	}
}

void lcd_init (void)
{
	// 4 bit initialisation
	HAL_Delay(50);  // wait for >40ms
	lcd_send_cmd (0x30);
	HAL_Delay(5);  // wait for >4.1ms
	lcd_send_cmd (0x30);
	HAL_Delay(1);  // wait for >100us
	lcd_send_cmd (0x30);
	HAL_Delay(10);
	lcd_send_cmd (0x20);  // 4bit mode
	HAL_Delay(10);

  // dislay initialisation
	lcd_send_cmd (0x29); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	HAL_Delay(1);
	lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
	HAL_Delay(1);
	lcd_send_cmd (0x01);  // clear display
	HAL_Delay(1);
	HAL_Delay(1);
	lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	HAL_Delay(1);
	lcd_send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)

}

void lcd_send_string (char *str,bool adjust_to_line)
{
	int contador=0;
	while (*str){
		lcd_send_data (*str++);
		contador++;

	}
	if(adjust_to_line== true)
	{
		int blank_spaces = 20- contador%20;

		while (blank_spaces >0){

			lcd_send_data (' ');
			blank_spaces--;
		}

	}

}

void lcd_put_cursor(int row, int col)
{
    switch (row)
    {
        case 0:
            col += 0x00;
            break;
        case 1:
            col += 0x40;
            break;
				case 2:
            col += 0x14;
            break;
				case 3:
            col += 0x54;
            break;
    }

    lcd_send_cmd (col|=0x80);
}

//FUNCIONES PROPIAS




