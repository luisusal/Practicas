/*
 * ordenacion.c
 *
 *  Created on:
 *      Author:
 */

#include <stdlib.h>
#include "ordenacion.h"

/*
== GENERADOR VECTOR ALEATORIO ==
Crea y devuelve un vector de numElementos asignando a cada elemento del 
vector un numero aleatorio entre 0 y rango-1
*/

int *crearVector(int numElementos, int rango)
{
	int *vector, i;

	// Reserva memoria dinamica
	vector = malloc(numElementos * sizeof (int));

	// Generacion vector aleatorio
	for (i = 0;i < numElementos; i++)
		vector[i] = rand() % rango;

	return vector;
}

/*
== INTERCAMBIADOR VALORES ==
Intercambia los valores de sus dos argumentos
*/

void intercambiar(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
 	*y = temp;
}

// ------ ENUNCIADO 2 ------

/*
== METODO BURBUJA ==
Crea y devuelve un vector de numElementos donde ordenada los elementos del 
vector desordenado que se le pasa en el primer argumento
OJO: se reserva memoria de forma dinámica, hay que liberarla después de su uso
*/

int *ordenarBurbuja (int *vector, int numElementos)
{
	int *nuevo , i, j;

	// Reserva memoria dinamica
	nuevo = ( int *) malloc ( numElementos * sizeof (int));

	for (i = 0; i < numElementos ; i++)
		nuevo [i] = vector [i];
	
	// Metodo Burbuja
    for (i = 0; i < numElementos ; i++)
	{
		contadorExterno++; // Contador Externo
		for (j = 0; j < numElementos -1-i; j++)
		{
			contadorMedio++; // Contador Medio
			if ( nuevo [j] > nuevo [j +1])
			{
				contadorInterno++; // Contador Interno
				intercambiar (&( nuevo [j]) ,&( nuevo [j +1]) );
			}
        }
	}

	return nuevo;
}

/*
== METODO SELECCION ==
Crea y devuelve un vector de numElementos donde ordenada los elementos del 
vector desordenado que se le pasa en el primer argumento
*/

int *ordenacionSeleccion(int *vector, int numElementos)
{
	int *nuevo , i, j, posSeleccion, valorSeleccion;

	// Reserva memoria dinamica
	nuevo = ( int *) malloc ( numElementos * sizeof (int));

	for(i = 0; i < numElementos; i++)
		nuevo [i] = vector [i];

	// Metodo Seleccion
	for(i = 1; i < numElementos-1; i++)
	{
		posSeleccion = i;
		valorSeleccion = nuevo[i];
		for(j = i+1; j < numElementos; j++)
		{
			if(nuevo[j] < valorSeleccion)
			{
				posSeleccion = j;
				valorSeleccion = nuevo[j];
			}
		}
		nuevo[posSeleccion] = nuevo[i];
		nuevo[i] = valorSeleccion;
	}

	return nuevo;
}

























