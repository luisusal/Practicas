/* Fuente: fread2.c
   Programa EJEMPLO USO FUNCION fread
   Descripción: Lee un fichero binario donde cada registro es una estructura.
   Lee de una sola vez todos los registros del fichero, y los almacena
   directamente en un array de longitud el número de registros del fichero
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
     const char FICHERO_ENTRADA[] = "c:\\temp\\agenda.bin";
     Persona agenda[MAX];

     FILE *fd;
     int i;

     system ("cls");

     if ((fd = fopen (FICHERO_ENTRADA, "rb")) == NULL)
        { printf("No se puede abrir el fichero %s\n", FICHERO_ENTRADA);
          printf ("\n\n");
          system ("pause");
          return 1; /* Terminamos el programa */

        }

     fread (&agenda[0], sizeof(agenda[0]), MAX, fd);

     for (i=0; i<MAX; i++)
       printf("Nombre: %10s F.nac: %02d/%02d/%4d\n",
               agenda[i].nombre, agenda[i].fnacimiento.dia,
               agenda[i].fnacimiento.mes, agenda[i].fnacimiento.anio);
  
     printf("Fichero %s leído correctamente.\n", FICHERO_ENTRADA);
     fclose(fd); 
     
     printf ("\n\n");
     system ("pause");
     return 0;
}
