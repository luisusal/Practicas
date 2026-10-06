/* Fuente: creafich.c
   Programa: CREA UN FICHERO DE TEXTO
   Descripción: Crea un fichero de texto línea a línea que se introduzca por teclado.
   Utiliza la función fputs para escribir en el fichero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char cadena[80];
   char FICHERO[]="c:\\temp\\muestra.txt";
   FILE * fp;

   if ((fp=fopen(FICHERO, "w")) == NULL)
      { printf("ERROR. NO se puede crear el fichero %s\n", FICHERO);
        printf ("\n\n");
        system ("pause");
        return 1; /* Salimos de la función main. Terminamos el programa */
      }

   printf("Introduzca cadenas de caracteres. Cadena vacía (sólo INTRO) para terminar.\n\n");
   printf("==> : ");
   gets(cadena);
   
   while (*cadena!='\0') /* Detecta cadena vacía */
   {  strcat(cadena, "\n");
      fputs (cadena, fp);
      printf("==> : ");
      gets(cadena);
   }   

   printf("Fichero creado correctamente.\n");
   fclose(fp);
   
   printf ("\n\n");
   system ("pause");
   return 0;
}
