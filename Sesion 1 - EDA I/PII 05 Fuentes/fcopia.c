/* Fuente: fcopia.c
   Programa: COPIA DE UN FICHERO
   Descripción: Genera una copia de un fichero existente.
   Los nombres del fichero origen y destino se introducen por teclado.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fpi; /* Fichero de input: origen  */
  FILE *fpo; /* Fichero de output: destino */

  char c;
  char nfich_input[60];
  char nfich_output[60];

  system ("cls");

  printf("COPIA DE FICHEROS.\n");
  printf("Copia un fichero de texto origen existente en un nuevo fichero destino.\n\n");
  printf("Nombre de fichero origen: ");
  scanf("%s", nfich_input);
  if ( (fpi = fopen (nfich_input, "r")) == NULL )
     { printf("ERROR. NO se puede abrir el fichero origen %s\n", nfich_input);
       printf ("\n\n");
       system ("pause");
       return 1; /* Salimos de la funcion main. Terminamos el programa */
     }

  printf("Nombre de fichero destino: ");
  scanf("%s", nfich_output);
  if ( (fpo = fopen (nfich_output, "w")) == NULL )
     { printf("ERROR. NO se puede crear el fichero destino %s\n", nfich_output);
       printf ("\n\n");
       system ("pause");
       return 1; /* Salimos de la funcion main. Terminamos el programa */
     }

  /* Lee carácter a carácter del fichero de input y
      escribe carácter a carácter en el fichero de output    */
   while ( (c = fgetc(fpi)) != EOF )
	fputc(c, fpo);

   printf("Copia realizada con éxito.\n");
   fclose (fpi);
   fclose (fpo);
   
   printf ("\n\n");
   system ("pause");
   return 0;
}
