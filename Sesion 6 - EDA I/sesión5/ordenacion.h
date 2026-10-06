/*
 * ordenacion.h 
 *
 *  Created on:
 *      Author:
 */

#ifndef __ORDENACION_H
#define __ORDENACION_H

extern long int contadorInterno,contadorMedio, contadorExterno;

int *crearVector(int numElementos, int rango);
void intercambiar(int *x, int *y);
int *ordenarBurbuja(int *vector, int numElementos);

#endif // ORDENACION_H
