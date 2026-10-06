/* Fuente: fseek.c
   Programa: EJEMPLO USO FUNCION fseek
   Descripción: Lee de forma directa los registros de un fichero binario, accediendo a cada registro
   por la posición que ocupa dentro del archivo, determinada ésta a partir del número de registro,
   que se lee de teclado.
   Para terminar debe teclearse un valor negativo como número de registro.
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
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
void Presentacion (void);
long TamannoFichero      (FILE *);
long NumRegistrosFichero (FILE *, long);
long PedirNumeroRegistro (long);
int  ErrorComprobarStat (int);
void ImprimeFicha (Persona);


/* ---------------------------------------------------------- */
   int main(void) {
/* ---------------------------------------------------------- */
     const char FICHERO[] = "c:\\temp\\agenda.bin";
     FILE *fd;

     Persona ficha;

     int stat;
     long numreg;     /* Número de registro a leer */
     long numreg_tot; /* Número de registros totales del fichero */

     system ("cls");

     if ((fd = fopen (FICHERO, "rb")) == NULL)
	{ printf("ERROR. NO se puede abrir el fichero %s\n", FICHERO);
	  printf ("\n\n");
      system ("pause");
      return 1; /* Terminamos el programa */
	}

     Presentacion();

     /* Calculamos el número total de registros del fichero */
     numreg_tot = NumRegistrosFichero (fd, sizeof(Persona));
     printf("Número de registros totales del fichero: %d\n", numreg_tot);

     numreg = PedirNumeroRegistro(numreg_tot);

     while (numreg > 0) {
	     /* Para leer el registro n nos posicionamos en el n-1
	        desde el principio del archivo ------------------- */
	     stat = fseek(fd, (numreg-1)* sizeof(ficha), SEEK_SET);

	     if (!ErrorComprobarStat(stat))
	     { fread(&ficha, sizeof(ficha), 1, fd);
	       ImprimeFicha (ficha);
	     }
   
        numreg = PedirNumeroRegistro(numreg_tot);
     }

     fclose(fd); 
     
     printf ("\n\n");
     system ("pause");
     return 0;
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
   long NumRegistrosFichero (FILE *f, long longitud_registro) {
/* ---------------------------------------------------------- */
     long   longitud_fichero;

     longitud_fichero = TamannoFichero (f);
     return (longitud_fichero/longitud_registro);
}

/* ---------------------------------------------------------- */
   long PedirNumeroRegistro (long numreg_max) {
/* ---------------------------------------------------------- */
/* Solicita el número de registro a leer. Lo valida contra    */
/* un número máximo (número de registros totales del fichero  */
     long nreg;

     do
     { printf("Número de registro a leer?: ");
       scanf("%ld", &nreg);
       if (nreg > numreg_max)
	  printf("El número de registro a leer debe ser menor o igual a %ld.\n", numreg_max);
     } while (nreg > numreg_max);

     return (nreg);
}

/* ---------------------------------------------------------- */
   int ErrorComprobarStat (int st) {
/* ---------------------------------------------------------- */
     if (st)
	     printf("Error. Puntero desplazado fuera del archivo.\n ");
     return (st);
}

/* ---------------------------------------------------------- */
   void ImprimeFicha (Persona fch) {
/* ---------------------------------------------------------- */
      printf("Nombre: %10s F.nac: %02d/%02d/%4d\n",
	      fch.nombre, fch.fnacimiento.dia,
	      fch.fnacimiento.mes, fch.fnacimiento.anio);
}

/* ---------------------------------------------------------- */
   void Presentacion (void) {
/* ---------------------------------------------------------- */
     puts("LECTURA DIRECTA DE REGISTROS (FSEEK)");
     puts("====================================");
     puts("");
     puts("Lee de forma directa los registros de un fichero binario, accediendo a cada");
     puts("registro por la posición que ocupa dentro del archivo, determinada ésta a  ");
     puts("partir del número de registro, que se lee de teclado.");
     puts("Para terminar debe teclearse un valor negativo como número de registro. ");
     puts("");
}
