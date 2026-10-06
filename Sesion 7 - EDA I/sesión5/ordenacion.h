/*
 * ordenacion.h 
 *
 *  Created on:
 *      Author:
 */

#ifndef __ORDENACION_H
#define __ORDENACION_H

extern long int contadorInterno,contadorMedio, contadorExterno;

// Funciones Auxiliares
int *crearVector(int numElementos, int rango);
void intercambiar(int *x, int *y);

// Funciones de Ordenacion
int *ordenarBurbuja(int *vector, int numElementos);
int *ordenacionSeleccion(int *vector, int numElementos);

#endif // ORDENACION_H
