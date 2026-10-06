/* Fuente: cad_ver.c
   Programa: PROGRAMA AUXILIAR PARA VISUALIZAR LOS FICHEROS CADENA QUE TRATA EL PROGRAMA cad_trat.c
   Descripción: Este programa visualiza los ficheros ejemplos usados 
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
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
void ImprimeRegistro (Registro);

/* ---------------------------------------------------------- */
   int main(void) {
/* ---------------------------------------------------------- */
     const char FICHERO1[] = "c:\\temp\\prueba1.bin";
     const char FICHERO2[] = "c:\\temp\\prueba2.bin";

     FILE *fd;

     Registro vreg;

     system ("cls");

     if ((fd = fopen (FICHERO1, "rb")) == NULL)
	{ printf("ERROR. No se puede leer el fichero %s", FICHERO1);
	  printf ("\n\n");
      system ("pause");
      return 1; /* Terminamos el programa */
	}

     printf("Registros del fichero 1:\n\n");

     fread(&vreg, sizeof(vreg), 1, fd);
     while (!feof(fd))
     { ImprimeRegistro (vreg);
       fread(&vreg, sizeof(vreg), 1, fd);
     }

     fclose(fd);


     if ((fd = fopen (FICHERO2, "rb")) == NULL)
	{ printf("ERROR. No se puede leer el fichero %s", FICHERO2);
	  printf ("\n\n");
      system ("pause");
      return 1; /* Terminamos el programa */
	}

     printf("\n\nRegistros del fichero 2:\n\n");

    fread(&vreg, sizeof(vreg), 1, fd);
    while (!feof(fd))
    { ImprimeRegistro (vreg);
      fread(&vreg, sizeof(vreg), 1, fd);
    }
    
    fclose(fd);
    
    printf ("\n\n");
    system ("pause");
    return 0;
}

/* ---------------------------------------------------------- */
   void ImprimeRegistro (Registro rg) {
/* ---------------------------------------------------------- */
     printf("Cad: %10s Nc: %3d Pal: %2d\n",
             rg.rcadena, rg.rnumchar, rg.rpalindromo);
}

