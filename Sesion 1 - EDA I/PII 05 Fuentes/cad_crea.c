/* Fuente: cad_crea.c
   Programa: PROGRAMA AUXILIAR PARA CREAR FICHERO DE CADENAS PARA PROGRAMA cad_trat.c
   Descripción: Este programa crea ficheros ejemplos para se usados posteriormente
   por el programa ejemplo cad_trat.c
*/

#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------------------------- */
/* Declaraciones globales                                     */
/* ---------------------------------------------------------- */
     typedef struct reg 
     {   char  rcadena[16]; /* cadena de caracteres    */
         int   rnumchar;    /* número de caracteres    */
         int   rpalindromo; /* indicador de palindromo */
     } Registro; 

/* ---------------------------------------------------------- */
   int main(void) {
/* ---------------------------------------------------------- */
     const char FICHERO1[] = "c:\\temp\\prueba1.bin";
     const char FICHERO2[] = "c:\\temp\\prueba2.bin";
     
     FILE *fd;
     
     Registro vreg[] = {"ABCCDA", 0, -1,
     		            "ABCBA",  0, -1,
     			        "123322", 0, -1,
     			        "4444444444", 0, -1};
          
     Registro vreg2[] = {"ABCCDAb", 0, -1,
                         "ABfghhgfBA",  0, -1,
     			         "123567322", 0, -1,
     			         "4444444444", 0, -1};

     system ("cls");
     
     if ((fd = fopen (FICHERO2, "wb")) == NULL)
        { printf("ERROR. No se puede crear el fichero %s", FICHERO2);
  	      printf ("\n\n");
          system ("pause");
          return 1; /* Terminamos el programa */
        }
     
     fwrite(&vreg2[0], sizeof(vreg2[0]), 4, fd);
     printf("Fichero %s creado correctamente.\n", FICHERO2);
     fclose(fd);


     if ((fd = fopen (FICHERO1, "wb")) == NULL)
	{ printf("ERROR. No se puede crear el fichero %s", FICHERO1);
	  printf ("\n\n");
      system ("pause");
      return 1; /* Terminamos el programa */
	}

     fwrite(&vreg[0], sizeof(vreg[0]), 4, fd);
     printf("Fichero %s creado correctamente.\n", FICHERO1);
     fclose(fd);
     
     printf("\n\n");
     system ("pause");
     return 0;
}



