/* Fuente: paginaf.c
   Programa: MOSTRAR CONTENIDO FICHERO DE TEXTO
   Descripción: Presenta en pantalla un fichero texto, página a página
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMLIN  22
#define N 200

/* ---------------------------------------------------------- */
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
   void modulo_principal (void);
   void presentacion     (void);

/* ---------------------------------------------------------- */
   int main (void) {
/* ---------------------------------------------------------- */
     char respuesta;

     system ("cls");
     presentacion();
     do
       { printf("\n");
	     modulo_principal();
	     printf("\n\n");
	     do
	       { printf("¿Otra ejecución (S/N)?: ");
	         fflush(stdin); /* Limpia el buffer de teclado */
	         respuesta = toupper(getchar());
	       }
	     while (respuesta != 'S' && respuesta != 'N');

       }
     while (respuesta != 'N');
     
     return 0;

} /* Fin del main */

/* ---------------------------------------------------------- */
   void modulo_principal (void) {
/* ---------------------------------------------------------- */
     FILE *fp;
     char nombre_fichero[60];
     char cadena[N+1];
     char caracter;
     int lineas;
     int lineatot;

     fflush(stdin); /* Limpia el buffer de teclado de entrada */
     printf("Nombre de archivo: ");
     gets(nombre_fichero);

     if ( (fp=fopen(nombre_fichero, "r")) == NULL )
 	 { printf("ERROR. NO se puede abrir el fichero %s\n", nombre_fichero);
	   return;
	 }
       
     system ("cls");
     lineas = lineatot = 0;
     printf("****** CONTENIDO DEL FICHERO %s ******\n", nombre_fichero);
     while ( fgets(cadena, N, fp) != NULL )
     { lineas++;
       lineatot++;
       printf("LINEA %d: %s", lineatot, cadena);

       if (lineas == NUMLIN)
       { printf("\n\n");
         system ("pause");
         lineas = 0;
	     system ("cls");
	   }
     }

     printf("\n****** FIN DEL FICHERO %s ******\n", nombre_fichero);
     fclose(fp);
}

/* ---------------------------------------------------------- */
   void presentacion (void) {
/* ---------------------------------------------------------- */
     puts("MUESTRA CONTENIDO FICHERO DE TEXTO");
     puts("==================================");
     puts("");
     puts("El programa le presentará página a página el contenido de un fichero de texto");
     puts("cuyo nombre se solicita por teclado.");
     puts("");
}
