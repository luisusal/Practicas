/*
 * listado4.c
 *
 *  Created on: 20/09/2013
 *      Author: M José Polo
 */

#include <stdio.h>
#include <stdlib.h>
#include "ordenacion.h"
#include <time.h>


int main(int argc, char *argv[])
{ 
	//clock_t tiempoInicial , tiempoFinal ;
	double tiempoInicial , tiempoFinal ;
	double tiempo;

	int *vector, *vectorOrdenado, rango=100000, numElementos=10000,i;
        

	if (argc > 2) {
            printf("\n Uso: ./prueba2 <número de elementos a ordenar>\n\n");
            return -1;
        }
       if (argc==2) 
		numElementos=atoi(argv[1]); 



	vector = crearVector(numElementos,rango);
        printf( "\nVector DESORDENADO de %d elementos: \n", numElementos);
        for (i=0;i<numElementos;i++) printf("%d \t",vector[i]);

        printf( "\n %d elementos...ORDENANDO...  \n", numElementos);	

     	tiempoInicial = (double)clock();
	vectorOrdenado = ordenarBurbuja(vector,numElementos);
     	tiempoFinal = (double) clock();
	
        printf( "\nVector ORDENADO de %d elementos: \n", numElementos);
        for (i=0;i<numElementos;i++) printf("%d \t",vectorOrdenado[i]);

     	tiempo =  (tiempoFinal - tiempoInicial ) / (double)CLOCKS_PER_SEC;

	printf( "\n\n\nTiempo de ejecución en ordenar %d elementos: %f)\n (inicio: %g, fin: %g, CLOCKS_PER_SEC: %ld)\n", 		numElementos,tiempo,tiempoInicial,tiempoFinal, CLOCKS_PER_SEC);
	printf("%d ; %e \n", numElementos,tiempo);
 	printf("%d ; %g \n\n\n", numElementos,tiempo);


      free(vector);
      free(vectorOrdenado);
   
return 0;
}


