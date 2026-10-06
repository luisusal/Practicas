#include <stdio.h>
#include <stdlib.h>
#include "ordenacion.h"

long int contadorInterno, contadorMedio, contadorExterno;

int main(int argc, char *argv[])
{

	int i, valorBuscado, numElementos=5, rango=20;
	int *vector, *vectorOrdenado;
   	
	// Creaccion vector aleatorio

	vector = crearVector(numElementos,rango);

	// Ordenacion vector 

	vectorOrdenado = ordenacionSeleccion(vector,numElementos);

	// Impresion de datos

	printf("Vector\n");
	for(i=0; i<numElementos; i++)
		printf("%d\t",vector[i]);
	
	printf("\n\n");

	printf("Vector Ordenado\n");
	for(i=0; i<numElementos; i++)
		printf("%d\t",vectorOrdenado[i]);

	printf("\n");

	// Liberacin de memoria dinamica

	free(vector);
	free(vectorOrdenado);

	return 0;
}
