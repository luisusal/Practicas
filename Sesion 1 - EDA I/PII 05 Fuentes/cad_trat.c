/* Fuente: cad_trat.c
   Programa: CALCULO DEL NUMERO DE CARACTERES E INDICADOR DE PALINDROMO
   Descripción: Trata en entrada/salida un fichero que contienen una cadena por 
   registro, calculando su número de caracteres y si la cadena es un  
   palíndromo. Regraba estos dos conceptos en cada uno de los registros
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ---------------------------------------------------------- */
/* Declaraciones globales                                     */
/* ---------------------------------------------------------- */
    typedef struct reg 
    { char  rcadena[16]; /* cadena de caracteres    */
      int   rnumchar;    /* número de caracteres    */
      int   rpalindromo; /* indicador de palíndromo */
    } Registro; 

/* ---------------------------------------------------------- */
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
   void modulo_principal (void);
   void Presentacion (void);
   int EsPalindromo (char *); 
   
/* ---------------------------------------------------------- */
   int main (void) {
/* ---------------------------------------------------------- */
     char respuesta;

     system ("cls");
     Presentacion();
     do
       { printf("\n");
	     modulo_principal();
	     printf("\n");
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
     char nombre_fichero[50];                                            
     FILE *fd;                                                           
     Registro vreg;                                                      
                                                                         
     int stat;                                                           
     long leidos;                                                        
                                                                         
     printf("Introduzca nombre del fichero: ");                      
     fflush(stdin);  /* Vaciado del buffer de teclado */             
     gets(nombre_fichero);                                           
                                                                         
     if ((fd = fopen (nombre_fichero, "r+b")) == NULL)               
          printf("No se puede abrir el fichero %s\n", nombre_fichero);
     else                                                            
        { fread(&vreg, sizeof(vreg), 1, fd);                         
          leidos=1;                                                  
          while (!feof(fd))                                          
          { vreg.rnumchar    = strlen(vreg.rcadena);
            vreg.rpalindromo = EsPalindromo(vreg.rcadena);
         
            fseek(fd, (leidos-1)*sizeof(vreg), SEEK_SET);
            fwrite(&vreg, sizeof(vreg), 1, fd);
         
            fseek(fd, leidos*sizeof(vreg), SEEK_SET);
            fread(&vreg, sizeof(vreg), 1, fd);
            leidos++;
          }
         
	      fclose(fd);
	      printf("Fichero %s tratado correctamente.\n", nombre_fichero);

        }
}

/* ---------------------------------------------------------- */
   int EsPalindromo (char *cad) {
/* ---------------------------------------------------------- */
     long lm = strlen(cad);
     long i; 
     int  pal = 1;

     for (i=0; i < lm/2; i ++)
        if (cad[i] != cad[lm-i-1])
            pal = 0;
     return (pal);
}

/* ---------------------------------------------------------- */
   void Presentacion (void) {
/* ---------------------------------------------------------- */
     puts("TRATAMIENTO FICHERO CADENAS");
     puts("===========================");
     puts("");
     puts("Trata en entrada/salida un fichero que contienen una cadena por registro,");
     puts("calculando su número de caracteres y si la cadena es un palíndromo.");
     puts("Regraba estos dos conceptos en cada uno de los registros");
     puts("");
}
