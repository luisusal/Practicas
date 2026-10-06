/*
 * listado1.c
 *
 *  Created on: 20/09/2013
 *      Author: M José Polo
 */

#include <stdio.h>
#include <stdlib.h>
#include "ordenacion.h"

int main(int argc, char *argv[])
{ 
	int *vector, *vectorOrdenado, rango=100000, numElementos=1000,i;


	if (argc > 2) {
            printf("\n Uso: ./prueba1 <número de elementos a ordenar>\n\n");
            return -1;
        }
       if (argc==2) 
		numElementos=atoi(argv[1]); 



	vector = crearVector(numElementos,rango);
        printf( "\nVector DESORDENADO de %d elementos:\n", numElementos);
        for (i=0;i<numElementos;i++) printf("%d \t",vector[i]);
     	vectorOrdenado = ordenarBurbuja(vector,numElementos);
        printf( "\nVector ORDENADO de %d elementos:\n", numElementos);
        for (i=0;i<numElementos;i++) printf("%d \t",vectorOrdenado[i]);

      printf("\n");
      free(vector);
      free(vectorOrdenado);
   
return 0;
}


