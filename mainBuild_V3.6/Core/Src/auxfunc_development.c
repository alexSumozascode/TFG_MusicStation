/*
 * auxfunc_development.c
 *
 *  Created on: 20 oct. 2022
 *      Author: asumo
 */

#include "auxfunc_development.h"

double* getSinSignal(int Amp, int F, float t) {

	double* signal = 0;
	int n = 0;
	n = (int)(t * SAMPLE_FREQ);
	// Reservamos la memoria necesaria oara almacenar la señal
	signal = (double*)malloc(n * sizeof(double));

	for (int i = 0; i < n; i++) {

		signal[i] = Amp * sin(2 * PI * F * i *((double) 1 / SAMPLE_FREQ));
	}
	return signal;
}
