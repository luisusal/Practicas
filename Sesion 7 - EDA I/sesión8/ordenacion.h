/*
 * ordenacion.h 
 *
 *  Created on: 03/11/2014
 *      Author: M.J. Polo
 */


#ifndef __ORDENACION_H
#define __ORDENACION_H

extern long int contadorExterno,contadorInterno;

// Sesión 6 - Iterativos ¡¡Ordenan un vector copia del vector de entrada!!

int * ordenarInsercion(int *vector , int numElementos );
int * ordenarSeleccion(int *vector , int numElementos );
int * ordenarBurbuja(int *vector , int numElementos );

void intercambiar (int *x, int *y);

// Sesión 7 - Recursivos ¡¡Ordenan el vector de entrada!!!! ¡¡No ejecutar repeticiones!!

void  QuickSort(int *vector,int base,int tope);
int colocar(int *vector,int base, int tope);
void  MergeSort(int *vector,int inicio,int fin );
void  fusion(int *vector,int base,int mitad,int tope );

// Sesión 8 - RadixSort ¡¡ Ordena una lista enlazada de enteros!!
#include "lista.h"
void radixSort(nodo **lista,int numGrupos,int numCifras);

#endif // ORDENACION_H



 











