/* Fuente: cli_trat.c
   Programa TRATAMIENTO FICHERO clientes.bin
   Descripción: Realiza distintas acciones sobre el fichero clientes.bin
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------------------------------------------------------- */
/* Declaraciones globales                                     */
/* ---------------------------------------------------------- */
     typedef struct clie
     { char  rcodigo[10]; /* código de cliente  */
       char  rnombre[21]; /* nombre de cliente  */
       int   rnpedido;    /* numero de pedido   */
       float rimporte;    /* importe del pedido */
     } Cliente;

/* ---------------------------------------------------------- */
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
void ImprimeRegistro     (Cliente);
long TamannoFichero      (FILE *);
long TamannoFichero2     (FILE *);
long NumRegistrosFichero (FILE *, long);
int  ErrorComprobarStat  (int);
void Presentacion (void);

/* ---------------------------------------------------------- */
   int main(void) {
/* ---------------------------------------------------------- */
     const char FICHERO[] = "clientes.bin";

     FILE *fd;
     long numreg_tot;  /* Número de registros del fichero */
     long i;

     Cliente regclie;
     int stat;

     system ("cls");

     if ((fd = fopen (FICHERO, "r+b")) == NULL)
	{ printf("ERROR. NO se puede abrir el fichero %s\n", FICHERO);
	  printf ("\n\n");
      system ("pause");
      return 1; /* Terminamos el programa */
	}

     Presentacion();

     /* ------------------------------------------------------------------ */
     /* --- 1: Número de registros del fichero.                        --- */
     /* ------------------------------------------------------------------ */
     printf("Tamaño registro: %d\n", sizeof(Cliente));
     numreg_tot = NumRegistrosFichero (fd, sizeof(Cliente));
     printf("Número de registros del fichero: %ld\n", numreg_tot);


     /* ------------------------------------------------------------------ */
     /* --- 2: Listado de todos los registros del fichero              --- */
     /* ------------------------------------------------------------------ */
     rewind(fd); /* Nos posicionamos al principio del fichero */
     printf("Registros del fichero:\n");

     fread(&regclie, sizeof(regclie), 1, fd);
     while (!feof(fd))
	 { ImprimeRegistro (regclie);
	   fread(&regclie, sizeof(regclie), 1, fd);
	 }


     /* ------------------------------------------------------------------ */
     /* --- 3: Ocupación del fichero en disco                          --- */
     /* ------------------------------------------------------------------ */
     printf("Tamaño del fichero: %ld\n", TamannoFichero(fd));

     /* ------------------------------------------------------------------ */
     /* --- 3-bis: Ocupación del fichero en disco                          --- */
     /* ------------------------------------------------------------------ */
     printf("Tamaño del fichero (2): %ld\n", TamannoFichero2(fd));

     /* ------------------------------------------------------------------ */
     /* --- 4: Ultimo registro y primer registro                       --- */
     /* ------------------------------------------------------------------ */
     printf("Ultimo registro: \n");
     stat = fseek(fd, -1*sizeof(regclie), SEEK_END);
     /* O bien:
	stat = fseek(fd, (numreg-1)* sizeof(regclie), SEEK_SET); */
     if (ErrorComprobarStat(stat))
	 exit (-1);

     fread(&regclie, sizeof(regclie), 1, fd);
     ImprimeRegistro (regclie);


     printf("Primer registro: \n");
     stat = fseek(fd, 0, SEEK_SET);
     if (ErrorComprobarStat(stat))
	 exit (-1);

     fread(&regclie, sizeof(regclie), 1, fd);
     ImprimeRegistro (regclie);


     /* ------------------------------------------------------------------ */
     /* --- 5: Registros del fichero en orden inverso                  --- */
     /* ------------------------------------------------------------------ */
     printf("Registros en orden inverso: \n");
     for (i = numreg_tot-1; i >= 0; i--)
     { stat = fseek(fd, i* sizeof(regclie), SEEK_SET);
       if (ErrorComprobarStat(stat)) return 1;
       fread(&regclie, sizeof(regclie), 1, fd);
       ImprimeRegistro (regclie);
     }


     /* ------------------------------------------------------------------ */
     /* --- 6: Insertamos el registro al final del fichero             --- */
     /* ------------------------------------------------------------------ */
     strcpy(regclie.rcodigo, "X15000068");
     strcpy(regclie.rnombre, "Fernando Torres");
     regclie.rnpedido = 14;
     regclie.rimporte = 461.89;

     /* Nos posicionamos al final del fichero */
     stat = fseek(fd, 0L, SEEK_END);
     /* O bien:
	    stat = fseek(fd, numreg * sizeof(regclie), SEEK_SET); */

     if (ErrorComprobarStat(stat))
	 exit (-1);

     fwrite (&regclie, sizeof(regclie), 1, fd);


     /* ------------------------------------------------------------------ */
     /* --- 7: Número registros del fichero después de añadir uno al final */
     /* ------------------------------------------------------------------ */
     numreg_tot = NumRegistrosFichero(fd, sizeof(Cliente));
     printf("Número de registros del fichero: %ld\n", numreg_tot);

     /* Listado de todos los registros del fichero */
     rewind(fd); /* Nos posicionamos al principio del fichero */
     printf("Registros del fichero:\n");

     fread(&regclie, sizeof(regclie), 1, fd);
     while (!feof(fd))
	 { ImprimeRegistro (regclie);
	   fread(&regclie, sizeof(regclie), 1, fd);
	 }


     /* ------------------------------------------------------------------ */
     /* --- 8: Modificamos el tercer registro del fichero              --- */
     /* ------------------------------------------------------------------ */
     /* Nos posicionamos antes del tercer registro */
     stat = fseek(fd, 2 * sizeof(regclie), SEEK_SET);
     if (ErrorComprobarStat(stat))
	 exit (-1);

     /* Leemos el tercer registro. Modificamos el campo correspondiente */
     fread(&regclie, sizeof(regclie), 1, fd);
     regclie.rnpedido = 86;

     /* Nos volvemos a posicionar antes del tercer registro */
     stat = fseek(fd, 2 * sizeof(regclie), SEEK_SET);
     if (ErrorComprobarStat(stat))
	 exit (-1);

     /* Regrabamos el tercer registro */
     fwrite (&regclie, sizeof(regclie), 1, fd);


     /* ------------------------------------------------------------------ */
     /* 9: Visualizamos el tercer registro para comprobar la modificación  */
     /* ------------------------------------------------------------------ */
     printf("Tercer registro del fichero:\n");

     stat = fseek(fd, 2 * sizeof(regclie), SEEK_SET);
     if (ErrorComprobarStat(stat))
	 exit (-1);

     fread(&regclie, sizeof(regclie), 1, fd);
     ImprimeRegistro (regclie);

     /* ------------------------------------------------------------------ */
     /* --- Finalizamos el programa                                    --- */
     /* ------------------------------------------------------------------ */
     printf("Fichero %s tratado correctamente.\n", FICHERO);
     fclose(fd);
     
     printf ("\n\n");
     system ("pause");
     return 0;
}


/* ---------------------------------------------------------- */
   void ImprimeRegistro (Cliente clte) {
/* ---------------------------------------------------------- */
     printf("Código: %-9s Nombre: %-20s N.pedido: %4d Importe: %7.2f\n",
	     clte.rcodigo, clte.rnombre,
	     clte.rnpedido, clte.rimporte);
}

/* ---------------------------------------------------------- */
   long TamannoFichero (FILE *f) {
/* ---------------------------------------------------------- */
     long   cursor_posicion;
     long   longitud_fichero;

     cursor_posicion = ftell(f);  /* Guardamos la posición actual del cursor de lectura del fichero     */
     fseek(f, 0L, SEEK_END);      /* Nos desplazamos desde el principio al final del fichero            */ 
     longitud_fichero = ftell(f); /* Obtenemos la posición actual del puntero (al final del fichero)    */ 
     fseek(f, cursor_posicion, SEEK_SET); /* Volvemos a posicionar el cursor de lectura en su posición original */ 
     return (longitud_fichero);
}

/* ---------------------------------------------------------- */
   long TamannoFichero2 (FILE *f) {
/* ---------------------------------------------------------- */
     fpos_t cursor_posicion;
     long   longitud_fichero;

     fgetpos (f, &cursor_posicion); // Guardamos la posición actual del cursor de lectura del fichero
     fseek(f, 0L, SEEK_END);        // Nos desplazamos desde el principio al final del fichero
     longitud_fichero = ftell(f);   // Obtenemos la posición actual del puntero (al final del fichero)
     fsetpos (f, &cursor_posicion); // Volvemos a posicionar el cursor de lectura en su posición original
     return (longitud_fichero);
}
/* ---------------------------------------------------------- */
   long NumRegistrosFichero (FILE *f, long longitud_registro) {
/* ---------------------------------------------------------- */
     long   longitud_fichero;

     longitud_fichero = TamannoFichero (f);
     return (longitud_fichero/longitud_registro);
}

/* ---------------------------------------------------------- */
   int ErrorComprobarStat (int st) {
/* ---------------------------------------------------------- */
     if (st)
	printf("Error. Puntero desplazado fuera del archivo.\n ");
     return (st);
}

/* ---------------------------------------------------------- */
   void Presentacion (void) {
/* ---------------------------------------------------------- */
     puts("TRATAMIENTO FICHERO CLIENTES.BIN");
     puts("================================");
     puts("");
     puts("El programa realiza distintas acciones sobre el ficheo CLIENTES.BIN");
     puts("");
}



