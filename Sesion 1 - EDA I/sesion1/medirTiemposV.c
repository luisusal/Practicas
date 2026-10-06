/*
 * merdirTiemposV.c
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
	double tiempoInicial , tiempoFinal, tiempoMinimo=10*CLOCKS_PER_SEC ;
	
        double tiempo;

	int *vector, *vectorOrdenado, rango=100000, numElementos=10000,i,repeticiones=0;
        
	FILE *f;  
 	
	if (argc != 2) {
            printf("\n Uso: ./eje1 <nombre fichero resultados>\n\n");
            return -1;
        }

        f = fopen(argv[1], "w+");
        fprintf(f,"n           ;tiempoMedio;  repeticiones\n");

	

	for (numElementos=5000;numElementos<=60000;numElementos=5000+numElementos) {
        
	        repeticiones=0;
		vector = crearVector(numElementos,rango);
     		tiempoInicial = tiempoFinal= (double)clock();
		while (tiempoFinal-tiempoInicial < tiempoMinimo) 
		{ 	vectorOrdenado = ordenarBurbuja(vector,numElementos);
		        free(vectorOrdenado);	  
			repeticiones++;
		     	tiempoFinal = (double) clock();
		}

	tiempo =  (tiempoFinal - tiempoInicial ) / (double)CLOCKS_PER_SEC /repeticiones;
	printf( "\n Elementos: %d Tiempo :%g Repeticiones: %d \n", 
			numElementos,tiempo,repeticiones);
	fprintf(f, " %d ;%g ; %d \n", numElementos,tiempo,repeticiones);

		free(vector);
	}
   	fclose(f);
return 0;
}


