/* Fuente: fread1.c
   Programa: EJEMPLO USO FUNCION fread
   Descripción: Lee un fichero binario donde cada registro es una estructura.
   Lee de uno en uno los registros hasta alcanzar el final del fichero.
*/

#include <stdio.h>
#include <stdlib.h>

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
     Persona ficha;

     FILE *fd;

     system ("cls");

     if ((fd = fopen (FICHERO_ENTRADA, "rb")) == NULL)
        { printf("No se puede abrir el fichero %s\n", FICHERO_ENTRADA);
          printf ("\n\n");
          system ("pause");
          return 1; /* Terminamos el programa */
        }

     fread (&ficha, sizeof(ficha), 1, fd);
     
     while (!feof(fd))
     {  printf("Nombre: %10s F.nac: %02d/%02d/%4d\n",
              ficha.nombre, ficha.fnacimiento.dia,
              ficha.fnacimiento.mes, ficha.fnacimiento.anio);
        fread(&ficha, sizeof(ficha), 1, fd);
     }


     printf("Fichero %s leído correctamente.\n", FICHERO_ENTRADA);
     fclose(fd); 
     
     printf ("\n\n");
     system ("pause");
     return 0;
}
