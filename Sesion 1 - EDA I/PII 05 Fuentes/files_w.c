/* ======================================================================================= */
/* Ejemplo de creación de ficheros de formato libre, encolumnados, tabulados y delimitados */
/* ======================================================================================= */

#include <stdio.h>
#include <stdlib.h>
#define INTRO '\n'
#define DIM 5

/* ---------------------------------------------------------- */
/* Declaraciones globales                                     */
/* ---------------------------------------------------------- */
typedef struct {
  char  st_nombre [45];
  char  st_provincia[15];
  int   st_edad;
  float st_talla;
} Persona;

/* ---------------------------------------------------------- */
   int main (void) {
/* ---------------------------------------------------------- */
  FILE *fp;
  const char FICH_LIBR[] = "c:\\alumnos\\libr.txt";
  const char FICH_ENCO[] = "c:\\alumnos\\enco.txt";
  const char FICH_DELI[] = "c:\\alumnos\\deli.txt";
  const char FICH_TABU[] = "c:\\alumnos\\tabu.txt";


  Persona lista[DIM] = {
		  "ANTONIO GARCIA PEREZ",    "MADRID", 23, 1.7,
		  "PEDRO RUIZ PABLOS",       "AVILA",  22, 1.85,
		  "MARIA SARMIENTOS BLANCO", "SORIA",   8, 1.93,
		  "FRANKLIN VAN VANTEN",     "CADIZ",  25, 1.69,
		  "EVA SANCHEZ SAN ROMAN",   "BURGOS", 19, 1.8};

  int i;

  if ( (fp=fopen(FICH_LIBR, "w")) == NULL )
	 printf("ERROR. NO se puede crear el fichero %s\n", FICH_LIBR);
  else
	 {   for (i=0; i<DIM; i++)
			fprintf(fp, "%s%s%d%.2f\n",
			 lista[i].st_nombre,
			 lista[i].st_provincia,
			 lista[i].st_edad,
			 lista[i].st_talla);
		 fclose(fp);
         printf("Fichero %s creado correctamente.\n", FICH_LIBR);
	 }

  if ( (fp=fopen(FICH_ENCO, "w")) == NULL )
	 printf("ERROR. NO se puede crear el fichero %s\n", FICH_ENCO);
  else
	 {   for (i=0; i<DIM; i++)
			fprintf(fp, "%44s%14s%3d%5.2f\n",
			 lista[i].st_nombre,
			 lista[i].st_provincia,
			 lista[i].st_edad,
			 lista[i].st_talla);
		 fclose(fp);
         printf("Fichero %s creado correctamente.\n", FICH_ENCO);
	 }

  if ( (fp=fopen(FICH_DELI, "w")) == NULL )
	 printf("ERROR. NO se puede crear el fichero %s\n", FICH_DELI);
  else
	 {   for (i=0; i<DIM; i++)
			fprintf(fp, "%s*%s*%d*%.2f\n",
			lista[i].st_nombre,
			lista[i].st_provincia,
			lista[i].st_edad,
			lista[i].st_talla);
		 fclose(fp);
         printf("Fichero %s creado correctamente.\n", FICH_DELI);
	 }

  if ( (fp=fopen(FICH_TABU, "w")) == NULL )
	 printf("ERROR. NO se puede crear el fichero %s\n", FICH_TABU);
  else
	 {   for (i=0; i<DIM; i++)
			fprintf(fp, "%s\t%s\t%d\t%.2f\n",
			lista[i].st_nombre,
			lista[i].st_provincia,
			lista[i].st_edad,
			lista[i].st_talla);
		 fclose(fp);
         printf("Fichero %s creado correctamente.\n", FICH_TABU);
	 }
  printf ("\n\n");
  system ("pause");
  return 0;
}






