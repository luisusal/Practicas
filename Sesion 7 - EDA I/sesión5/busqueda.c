/*
 * busqueda.c
 *
 *  Created on:
 *      Author:
 */

#include <stdlib.h>
#include "busqueda.h"

// ------ ENUNCIADO 1 ------

// Busqueda Secuencial - Tipo 1

int bSecuencial(int * vector,int numElementos, int valor)
{
	int i;

	for(i=1; i<=numElementos; i++)
	{
		contadorExterno++; // Contador Externo
		if (vector[i] == valor)
			{
			contadorInterno++; // Contador Interno
			return i;
			}
	}
	return 0;
}

// Busqueda Secuencial - Tipo 2

int bSecuencial2(int * vector,int numElementos, int valor)
{
	int posicion,i;
	posicion = 0;

	for (i=1; i<=numElementos; i++)
	{
		contadorExterno++; // Contador Externo
		if (vector[i] == valor)
		{
			contadorInterno++; // Contador Interno
			posicion = i;
		}
	}
	return posicion;
}

// Busqueda Binaria - Iterativa

int bBinariaI(int * vector,int numElementos, int valor)
{
	int i,j,k;
	i=1;
	j=numElementos;

	while(i<j)
	{
		contadorExterno++; // Contador Externo
		k=(i+j)/2;
		if (valor < vector[k])
		{
			contadorInterno++; // Contador Interno
			j=k-1;
		}		
		else if (valor > vector[k])
			{
				contadorInterno++; // Contador Interno
				i=k+1;
			}
			else if (valor == vector[k])
				{	
					contadorInterno++; // Contador Interno
					i=k;
					j=k;
				}	
	}

	if(valor == vector[i])
		return i;
	else
		return 0;
}

// Busqueda Binaria - Recursiva

int bBinariaR(int * vector,int inicio,int fin, int valor)
{
	int k;

	if(inicio>fin)
		return 0;
	else
	{
		contadorExterno++; // Contador Externo
		k=(inicio+fin)/2;
		if (valor < vector[k])
		{
			contadorInterno++; // Contador Interno
			fin=k-1;
		}
		else if (valor > vector[k])
			{
				contadorInterno++; // Contador Interno
				inicio=k+1;
			}
			else if (valor == vector[k])
				{
					contadorInterno++; // Contador Interno
					return k;
				}
		return bBinariaR(vector,inicio,fin,valor);
	}
}
