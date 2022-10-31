/*
 * auxfunc_development.h
 *
 *  Created on: 14 sept. 2022
 *      Author: asumo
 */


#ifndef INC_AUXFUNC_DEVELOPMENT_H_
#define INC_AUXFUNC_DEVELOPMENT_H_

#include <stdbool.h>
#include <math.h>

#define PI 3.14159265
#define SAMPLE_FREQ 48000
/*
bool get_bit(int num,int position){
	bool bit = num &(1<<position);
	return bit;
}

int set_bit (int num,int position)
{
	int mask= 1<<position;
	return num | mask;
}

int clear_bit(int num, int position){
	int mask = 1 << position;
	return num & ~mask;
}*/

double* getSinSignal(int Amp,int F, float t);
#endif /* INC_AUXFUNC_DEVELOPMENT_H_ */
