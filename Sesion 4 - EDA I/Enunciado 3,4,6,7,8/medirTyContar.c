/*
 * medirTyContarBur.c
 *
 *  Created on: 29/09/2014
 *      Author: M.J. Polo
 */

#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"
#include <time.h>

long int contadorInterno, contadorExterno, contadorK;

int main(int argc, char *argv[])
{ 
	//clock_t tiempoInicial , tiempoFinal ;

	int t;

	double tiempoInicial , tiempoFinal, tiempoMinimo=10*CLOCKS_PER_SEC ;
	
        double tiempo;

	int rango=100000, n=10000,i,repeticiones=0;
        
 	FILE *f;  
 	
	if (argc != 2) {
            printf("\n Uso: ./medirTyContarV <nombre fichero resultados>\n\n");
            return -1;
        }

        f = fopen(argv[1], "w+");
        fprintf(f,"n;tiempoMedio;Externo;Interno;k\n");

        for (n=2;n<=1024;n=n*2) { // (n=5000;n<=50000;n=5000+n) -- (n=1;n<=10;n++) fibonnacci
                repeticiones=contadorInterno=contadorExterno=contadorK=0;

     		tiempoInicial = tiempoFinal= (double)clock();
		while ((tiempoFinal-tiempoInicial < tiempoMinimo) || (repeticiones < 5))
		{ 	
			algJ(n);  // **** ALGORITMO DE ESTUDIO ****
			repeticiones++;
	     		tiempoFinal = (double) clock();
		}

     		tiempo =  (tiempoFinal - tiempoInicial ) / (double)CLOCKS_PER_SEC /repeticiones;
		if(contadorK!=0)
		{
		printf("\n %d \t %e \t %ld \t %ld \t %ld", n,tiempo,contadorExterno/repeticiones,contadorInterno/repeticiones,contadorK/repeticiones);
		fprintf(f,"\n %d \t %e \t %ld \t %ld \t %ld", n,tiempo,contadorExterno/repeticiones,contadorInterno/repeticiones,contadorK/repeticiones);
		}
		else
		{
		printf("\n %d \t %e \t %ld \t %ld", n,tiempo,contadorExterno/repeticiones,contadorInterno/repeticiones);
		fprintf(f,"\n %d \t %e \t %ld \t %ld", n,tiempo,contadorExterno/repeticiones,contadorInterno/repeticiones);
		}
      }

printf("\n");
fprintf(f,"\n");

fclose(f);

   
return 0;
}
