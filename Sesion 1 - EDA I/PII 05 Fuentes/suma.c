/* Fuente: suma.c
   Programa: SUMA TODOS LOS PARÁMETROS DE LA LINEA DE COMANDOS
   Descripción: El programa presenta el valor de la suma de todos los parámetros que se
   tecleen en la línea de comandos.
*/

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  int i;
  float sum = 0;

  if (argc < 2)
   { puts("Error en la línea de órdenes. Parámetros insuficientes.");
     return -1;
   }

   for (i=1; i < argc; i++)
	sum += atof(argv[i]);

   printf("\nSuma de los argumentos: %g \n", sum);
   
   return 0;
}	  
