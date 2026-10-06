/* Fuente: verfich1.c
   Programa: LEER FICHERO DE TEXTO MEDIANTE fgetc
   Descripción: Presenta en pantalla un fichero texto, leyendo carácter 
   a carácter mediante getc, y presentando el carácter leído en pantalla
   mediante putchar.
*/
#include <stdio.h>
#include <stdlib.h>

int main (void) {
     FILE *fp;
     char nombre_fichero[] = "c:\\temp\\frases.txt";
     char c; /* Variable carácter para lectura del fichero */
     
     system ("cls");

     if ( (fp=fopen(nombre_fichero, "r")) == NULL )
 	 { printf("ERROR. NO se puede abrir el fichero %s\n", nombre_fichero);
       printf ("\n");
       system ("pause");
       return 1;
	 }
	 
     printf ("CONTENIDO DEL FICHERO %s\n", nombre_fichero);
     printf ("========================================\n");

     while ( (c = fgetc(fp)) != EOF )
  	     putchar(c);

     fclose(fp);

     printf ("\n========================================\n");

     printf("\n\n");
     system ("pause");
     return 0;
}

