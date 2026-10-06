/* Fuente: VERFICH2.C
   Programa: LEER FICHERO DE TEXTO MEDIANTE fgetc Y feof
   Descripción: Presenta en pantalla un fichero texto, leyendo carácter 
   a carácter mediante getc, y presentando el carácter leído en pantalla
   mediante putchar.
   Utiliza, combinada con fgetc, la función feof.
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

     c = fgetc(fp);
	 while ( !feof(fp) )
       { putchar(c);
         c = fgetc(fp);
       }

     fclose(fp);
     
	 printf ("\n========================================\n");

     printf("\n\n");
     system ("pause");
     return 0;
}

