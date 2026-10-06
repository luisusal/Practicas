/* Fuente: cli_ver.c
   Programa: PROGRAMA AUXILIAR PARA VISUALIZAR EL FICHERO clientes.bin
   Descripción: Este programa visualiza el fichero ejemplo clientes.bin, usado 
   por el programa ejemplo cli_trat.c
*/

#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------------------------- */
/* Declaraciones globales                                     */
/* ---------------------------------------------------------- */
     typedef struct clie
     {   char  rcodigo[10]; /* código de cliente  */
         char  rnombre[21]; /* nombre de cliente  */
         int   rnpedido;    /* numero de pedido   */
         float rimporte;    /* importe del pedido */
     } Cliente;

/* ---------------------------------------------------------- */
   int main(void) {
/* ---------------------------------------------------------- */
     const char FICHERO[] = "clientes.bin";
     Cliente ficha;
     FILE *fd;

     int leidos =0;

     system ("cls");

     if ((fd = fopen (FICHERO, "rb")) == NULL)
	{ printf("ERROR. No se puede leer el fichero %s", FICHERO);
	  printf ("\n\n");
      system ("pause");
      return 1; /* Terminamos el programa */
	}

     printf("Contenido del fichero %s:\n\n", FICHERO);

     fread(&ficha, sizeof(ficha), 1, fd);
     while (!feof(fd))
       { leidos++;
	 printf ("Registro %2d: ", leidos);
	 printf ("%s - %s - %d - %g\n", ficha.rcodigo,  ficha.rnombre,
				  ficha.rnpedido, ficha.rimporte);
	 fread(&ficha, sizeof(ficha), 1, fd);
       }

     printf("\nFichero %s leído correctamente.\n", FICHERO);
     fclose(fd);

     printf ("\n\n");
     system ("pause");
     return 0;
}


