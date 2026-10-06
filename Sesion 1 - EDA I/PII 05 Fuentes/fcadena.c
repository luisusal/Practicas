/* Fuente: fcadena.c
   Programa: PROCESAR FICHERO DE CADENAS DE CARACTERES
   Descripción: Procesa en entrada un fichero de cadenas de caracteres.
   Genera un fichero de salida encolumnado, en el que se escribe en cada línea:
     - la cadena de entrada en mayúsculas
     - la longitud de la cadena
     - el número de palabras de la cadena (cuenta para ello el número de espacios
       de la cadena + 1)
   Presenta además en pantalla:
     - el número de registros leídos
     - la media de la longitud de las cadenas
     - la media de palabras por línea
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define N 200

/* ---------------------------------------------------------- */
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
void convertir_mayusculas (char *);
long contar_palabras (char *);
void presentacion (const char *, const char *);

/* ---------------------------------------------------------- */
   int main (void) {
/* ---------------------------------------------------------- */
     FILE *fpe;
     FILE *fps;
     const char FICHERO_ENTRADA[] = "c:\\temp\\entrada.txt";
     const char FICHERO_SALIDA[] = "c:\\temp\\salida.txt";

     char   cadena[N+1];
     long   cuantos;
     long   lntemp, longitud;
     float  media_longitud;
     long   num_palabras;
     float  media_palabras;


     system ("cls");
     presentacion (FICHERO_ENTRADA, FICHERO_SALIDA);

     if ( (fpe=fopen(FICHERO_ENTRADA, "r")) == NULL )
	{	 printf("ERROR. NO se puede leer el fichero %s\n", FICHERO_ENTRADA);
         printf ("\n\n");
         system ("pause");
         return 1; /* Salimos de la función main. Terminamos el programa */

	}

     if ( (fps=fopen(FICHERO_SALIDA, "w")) == NULL )
	{	 printf("ERROR. NO se puede crear el fichero %s\n", FICHERO_SALIDA);
         printf ("\n\n");
         system ("pause");
         return 1; /* Salimos de la función main. Terminamos el programa */
	}

     cuantos = 0;
     media_longitud = media_palabras = 0;

     while ( fgets(cadena, N, fpe) != NULL ) {
	      cuantos++;
	      
             /* fgets alcanema el carácter \n en el argumento cadena. */
             /* Lo eliminamos mediante la siguiente sentencia.        */
	      lntemp = strlen(cadena);
          cadena[lntemp-1] = '\0';

          convertir_mayusculas(cadena);
	      num_palabras = contar_palabras(cadena);
	      media_palabras += num_palabras;
	      longitud = strlen(cadena);
          media_longitud += longitud;
	      fprintf(fps, "%-80s%4ld%4ld\n", cadena, longitud, num_palabras);
     } /* Fin del while */

     fclose(fpe);
     fclose(fps);

     /* Presentamos resultados */

     media_palabras /= cuantos;
     media_longitud /= cuantos;

     printf("Resultados tratamiento del fichero %s\n", FICHERO_ENTRADA);
     printf("----------------------------------------------------------\n");
     printf("Registros leídos......................: %3ld\n", cuantos);
     printf("Media de la longitud de las cadenas...: %6.2f\n", media_longitud);
     printf("Media de palabras por línea...........: %6.2f\n", media_palabras);
     
     printf ("\n\n");
     system ("pause");
     return 0;
}

/* ---------------------------------------------------------- */
void convertir_mayusculas (char *cad) {
/* ---------------------------------------------------------- */
     const char NULO = '\0';
     long k = 0;

     while (cad[k] != NULO)
     {  cad[k] = toupper(cad[k]);
	    k++;
     }
}

/* ---------------------------------------------------------- */
long contar_palabras (char *cad) {
/* ---------------------------------------------------------- */
     const char NULO = '\0';
     const char ESPACIO = '\x20';
     long k = 0;
     long pal = 0;

     while (cad[k] != NULO)
     {  if (cad[k] == ESPACIO) pal++;
        k++;
     }

     if (pal == 0) /* Si no hay espacios, el número de palabras sera cero */
          return 0;
     else return(pal+1);
}

/* ---------------------------------------------------------- */
   void presentacion (const char *fent, const char *fsal) {
/* ---------------------------------------------------------- */
     puts("TRATAMIENTO FICHERO DE CADENAS DE CARACTERES");
     puts("============================================");
     puts("");
     puts("Procesa en entrada un fichero de cadenas de caracteres. Genera un fichero de");
     puts("salida encolumnado, en el que se escribe en cada línea:");
     puts("    - la cadena de entrada en mayúsculas.");
     puts("    - la longitud de la cadena.");
     puts("    - el número de palabras de la cadena.");
     puts("");
     printf("Fichero de entrada: %s\n", fent);
     printf("Fichero de salida : %s\n", fsal);
     puts("");
}
