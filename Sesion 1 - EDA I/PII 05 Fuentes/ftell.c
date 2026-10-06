/* Fuente: ftell.c
   Programa: EJEMPLO USO FUNCION ftell
   Descripción: Lee un fichero binario donde cada registro es una estructura.
   Lee de uno en uno los registros del fichero y se comprueba con la función ftell()
   como se desplaza el puntero del archivo  
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
     const char FICHERO[] = "c:\\temp\\agenda.bin";
     FILE *fd;
     Persona ficha;

     int posicion;
     int leidos = 0;  /* Contador para registros leídos */
     
     system ("cls");
     
     if ((fd = fopen (FICHERO, "rb")) == NULL)
	{ printf("ERROR. NO se puede leer el fichero %s\n", FICHERO);
	  printf ("\n\n");
      system ("pause");
      return 1; /* Terminamos el programa */
	}

     printf("Tamaño estructura Persona: %d\n", sizeof(Persona));
     
     printf("Fichero %s recién abierto.\n", FICHERO);
     posicion = ftell (fd);
     printf("Leídos: %d. Posición: %d\n", leidos, posicion);

     fread(&ficha, sizeof(ficha), 1, fd);
     leidos++;
     posicion = ftell (fd);

     while (!feof(fd))
     { printf("Nombre: %10s F.nac: %02d/%02d/%4d ",
		 ficha.nombre, ficha.fnacimiento.dia,
		 ficha.fnacimiento.mes, ficha.fnacimiento.anio);
       printf("Leídos: %d. Posición: %d\n", leidos, posicion);

       fread(&ficha, sizeof(ficha), 1, fd);
       leidos++;
       posicion = ftell (fd);
     }

     printf("Fichero %s leído correctamente.\n", FICHERO);
     fclose(fd);
     
     printf ("\n\n");
     system ("pause");
     return 0;
}
