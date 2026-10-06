/* Fuente: fwrite2.c
   Programa: EJEMPLO USO FUNCION fwrite
   Descripción: Genera un fichero binario donde cada registro es una estructura.
   Graba de una sola vez todo un vector de estructuras.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

/* ---------------------------------------------------------- */
/* Declaraciones globales                                     */
/* ---------------------------------------------------------- */
     struct fecha {
       int dia;
       int mes;
       int anio;
     };
 
     typedef struct Per {
       char nombre[81];
       struct fecha fnacimiento;
     } Persona;
                  
/* ---------------------------------------------------------- */
   int main(void) {
/* ---------------------------------------------------------- */
     const char FICHERO[] = "c:\\temp\\agenda.bin";
     FILE *fd;

     Persona agenda[MAX] = {"ANA", 30, 12, 1973,
                            "JOSE", 13, 5, 1966,
                            "ROSA", 4, 2, 1977,
                            "SARA", 29, 7, 1963,
                            "ANTONIO", 31, 3, 1974};

     if ( (fd = fopen(FICHERO, "wb")) == NULL )
	{ printf("ERROR. NO se puede crear el fichero %s\n", FICHERO);
	  printf ("\n\n");
      system ("pause");
      return 1; /* Terminamos el programa */
	}
     
     fwrite (&agenda[0], sizeof(agenda[0]), MAX, fd);

     printf("Fichero %s creado correctamente.\n", FICHERO);
     fclose(fd); 
     
     printf ("\n\n");
     system ("pause");
     return 0;
}
