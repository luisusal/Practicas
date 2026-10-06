/* Fuente: verfich5.c
   Programa: LEER FICHERO DE TEXTO MEDIANTE fscanf
   Descripción: Presenta en pantalla un fichero texto.
   Utiliza la función fscanf para leer línea a línea el fichero.
*/
#include <stdio.h>
#include <stdlib.h>

#define N 200

int main (void) {
     FILE *fp;
     char nombre_fichero[] = "c:\\temp\\frases.txt";
     char cadena[N+1];
     
     system ("cls");

     if ( (fp=fopen(nombre_fichero, "r")) == NULL )
 	 { printf("ERROR. NO se puede abrir el fichero %s\n", nombre_fichero);
       printf ("\n");
       system ("pause");
       return 1;
	 }
	 
     printf ("CONTENIDO DEL FICHERO %s\n", nombre_fichero);
     printf ("========================================\n");

     while ( fscanf(fp, "%[^\n] ", cadena) != EOF)
        printf("%s\n", cadena);

     /* fscanf lee hasta encontrar un retorno de carro en el fichero.
        El espacio en la cadena de control de fscanf indica que porteriormente
        todos los caracteres delimitadores (por ejemplo el retorno de carro),
        serán detectados y desechados. 
        Por ello, en la pantalla de salida se presenta el fichero sin
        las "líneas en blanco", es decir, sin las líneas generadas por el
        editor con sólo un retorno de carro.
        La cadena leída será terminada con el correspondiente carácter nulo.
     */

     fclose(fp);

     printf ("\n========================================\n");

     printf("\n\n");
     system ("pause");
     return 0;
}

