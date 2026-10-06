/* Fuente: concat.c
   Programa: CONCATENAR ARCHIVOS DE TEXTO
   Descripción: El programa concatenar un número variable de archivos. Los nombres de los archivos
   se informan a través de la línea de comandos, y el nuevo archivo resultante de la concatenación
   ha de ser el último argumento de la línea de comandos.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIN 120

/* ---------------------------------------------------------- */
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
void copia_archivo (FILE *, FILE *);

/* ---------------------------------------------------------- */
   int main (int argc, char *argv[]) {
/* ---------------------------------------------------------- */
     FILE *pfe, *pfw; 
     int  i;
  
     if (argc < 3)
      { puts("Error en la línea de órdenes. Archivos insuficientes.");
        return -2;
      }	  

   /* El último archivo es donde se realiza la concatenación */

     if ( (pfw=fopen(argv[argc-1], "w")) == NULL )
      { printf("ERROR al abrir en escritura el fichero %s.\n", argv[argc-1]);
        return -3;
      }	 
 

     for (i=1 ; i<argc-1; i++)
      {
         if ( (pfe=fopen(argv[i], "r")) == NULL )
          {  printf("ERROR al abrir en lectura el fichero %s.\n", argv[i]);
             return -1;
          }	 
    
          copia_archivo (pfe, pfw);
          fclose(pfe);
      }

     fclose(pfw);
     return 0;

}  /* -- Final de main -- */


/* ---------------------------------------------------------- */
void copia_archivo (FILE *f1, FILE *f2) {
/* ---------------------------------------------------------- */
     char cad[MAX_LIN];

  /* fgets devuelve NULL cuando se alcanza el final del archivo */
     while (fgets(cad, MAX_LIN, f1) != NULL)
          fprintf(f2, "%s", cad);
}
