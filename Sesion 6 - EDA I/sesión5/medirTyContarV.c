/*
 * merdirTiemposV.c
 *
 *  Created on: 20/09/2013
 *      Author: M José Polo
 */

#include <stdio.h>
#include <stdlib.h>
#include "busqueda.h"
#include "ordenacion.h"
#include <time.h>

long int contadorInterno, contadorMedio, contadorExterno;

int main(int argc, char *argv[])
{
	// Declaracion de variables

	//clock_t tiempoInicial , tiempoFinal ;
	double tiempoInicial , tiempoFinal, tiempoMinimo=10*CLOCKS_PER_SEC ;
	
    double tiempo;

	int *vector, *vectorOrdenado, rango=100000, numElementos=10000,i,repeticiones=0;
	int valorBuscado;
   
	// Archivo

	FILE *f;  
 	
	if (argc != 2)
		{
			printf("\n Uso: ./eje1 <nombre fichero resultados>\n\n");
			return -1;
        }

        f = fopen(argv[1], "w+");
        fprintf(f,"n\ttiempoMedio\trepeticiones\n");

	// Analisis Algoritmos

	for (numElementos=5000;numElementos<=60000;numElementos=5000+numElementos)
		{
       		repeticiones=0;
			
			// Creacion de vector aleatorio

			vector = crearVector(numElementos,rango);
			
			// Ordenacion vector 

			//vectorOrdenado = ordenarBurbuja(vector,numElementos); // Para busquedas (binarias)

     		tiempoInicial = tiempoFinal= (double)clock();

			while (tiempoFinal-tiempoInicial < tiempoMinimo) 
			{ 	
				valorBuscado = bSecuencial(vector,numElementos,15);// ALGORITMO DE ESTUDIO
		        //free(vectorOrdenado); // Cuando se analiza algoritmos de ordenacion	  
				repeticiones++;
		     	tiempoFinal = (double) clock();
			}

			tiempo =  (tiempoFinal - tiempoInicial ) / (double)CLOCKS_PER_SEC /repeticiones;
	
			// Impresion por panatalla

			printf("\n %d \t %e \t %ld \t %ld \t %ld", numElementos,tiempo,contadorExterno/repeticiones,contadorMedio/repeticiones,contadorInterno/repeticiones);

			// Impresion en archivo

			fprintf(f,"\n %d \t %e \t %ld \t %ld \t %ld", numElementos,tiempo,contadorExterno/repeticiones,contadorMedio/repeticiones,contadorInterno/repeticiones);

			// Liberacion memoria dinamica

			//free(vectorOrdenado) // Para algoritmos de busqueda
			free(vector);
		}

	// Cierre de archivo   	
	fclose(f);

return 0;
}


