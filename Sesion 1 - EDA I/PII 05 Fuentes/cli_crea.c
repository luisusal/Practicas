/* Fuente: cli_crea.c
   Programa: PROGRAMA AUXILIAR PARA CREAR EL FICHERO clientes.bin
   Descripción: Este programa crea un fichero ejemplo clientes.bin para se usado posteriormente
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

     FILE *fd;
     Cliente lista[] = {"1111111", "AA1A", 10, 11.22,
                        "2222222", "BB2B", 20, 22.33,
                        "3333333", "CC3C", 30, 33.44,
                        "4444444", "DD4D", 40, 44.55,
                        "5555555", "EE5E", 50, 55.66,
                        "6666666", "FF6F", 60, 66.77,
                        "7777777", "GG7G", 70, 77.88,
                        "8888888", "HH8H", 80, 88.99};

     system ("cls");

     if ((fd = fopen (FICHERO, "wb")) == NULL)
        { printf("ERROR. No se puede crear el fichero %s", FICHERO);
          printf ("\n\n");
          system ("pause");
          return 1; /* Terminamos el programa */
        }

     fwrite(&lista[0], sizeof(lista[0]), 8, fd);
     
     printf("Fichero %s creado correctamente.\n", FICHERO);
     fclose(fd);
     
     printf ("\n\n");
     system ("pause");
     return 0;
}


