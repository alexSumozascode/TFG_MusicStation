/*
 * keypad_development.c
 *
 *  Created on: 21 sept. 2022
 *      Author: asumo
 */
#include "keypad_development.h"

//------------------REIMPLEMENTAR---------------------
/*
void initKeyPad(uint16_t* row_pins_in,uint16_t* col_pins_in){
	row_pins = row_pins_in;
	col_pins = col_pins_in;
	for (int i =0;i<4;i++)
	{
		HAL_GPIO_WritePin(row_ports[i],row_pins[i],GPIO_PIN_SET);
	}


}*/
void initKeyPad(){
	for (int i =0;i<4;i++)
		{
			HAL_GPIO_WritePin(row_ports[i],row_pins[i],GPIO_PIN_SET);
		}
}
char readKeyPad()
{
	char key_default = 111;
	for (int i =0;i<4;i++){
		for (int j =0;j<4;j++){
			if (i==j)
				HAL_GPIO_WritePin(row_ports[i],row_pins[i],GPIO_PIN_RESET);

			else{
				HAL_GPIO_WritePin(row_ports[j],row_pins[j],GPIO_PIN_SET);
			}
		}

		char key_pressed = getKeyPad();
		if (key_pressed !=111){
			return interfaceValueKey(key_pressed+4*i);
		}
	}
	return interfaceValueKey(key_default);
}

char getKeyPad(){
	char key_default = 111;
		for (int i =0;i<4;i++){
			if (HAL_GPIO_ReadPin(col_ports[i],col_pins[i]) == GPIO_PIN_RESET)
				return (char)i;
		}
	return key_default;
}

char interfaceValueKey(char value_pressed){

	switch (value_pressed){
	case 0: return 49; break;
	case 1: return 50; break;
	case 2: return 51; break;
	case 3: return 65; break;
	case 4: return 52; break;
	case 5: return 53; break;
	case 6: return 54; break;
	case 7: return 66; break;
	case 8: return 55; break;
	case 9: return 56; break;
	case 10: return 57; break;
	case 11: return 67; break;
	case 12: return 42; break;
	case 13: return 48; break;
	case 14: return 35; break;
	case 15: return 68; break;
	default: return 111;
	}
	return (char)111;
}
