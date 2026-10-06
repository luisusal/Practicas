/* Fuente: verfich3.c
   Programa: LEER FICHERO DE TEXTO MEDIANTE fgets
   Descripción: Lee y presenta en pantalla un fichero texto.
   Utiliza la función fgets para leer línea a línea el fichero.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 200

int main(void) {
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
     
     while ( fgets(cadena, N, fp) != NULL )
        printf("%s", cadena);
     
     /* N es el número de caracteres a leer por la función fgets
        Si encuentra un retorno de carro (\n) en el fichero, no se leen
        más caracteres, almacenando, además, dicho carácter \n en el
        argumento cadena. Por ello, en la siguiente sentencia para pesentar
        la cadena en pantalla --printf("%s", cadena);-- no se incluye \n en la 
        cadena de control.
        La cadena leída será terminada con el correspondiente carácter nulo.
     */
     
     fclose(fp);
     
     printf ("\n========================================\n");

     printf("\n\n");
     system ("pause");
     return 0;
}
