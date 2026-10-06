/* ==================================================================== */
/* Ejemplo de lectura de ficheros encolumnados, tabulados y delimitados */
/* ==================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM 50

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
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
int leer_encolumnado    (FILE *f, char *pnom, char *pprov, int *pedad, float *ptalla);
int leer_delimitado_aste(FILE *f, char *pnom, char *pprov, int *pedad, float *ptalla);
int leer_tabulado       (FILE *f, char *pnom, char *pprov, int *pedad, float *ptalla);

void recortarizq  (char *cad);
void inicia_lista (Persona *la, int dim);
void imprime_lista(Persona *la, int dim);


/* ---------------------------------------------------------- */
   int main (void) {
/* ---------------------------------------------------------- */
  FILE *fp;
  const char FICH_ENCO[] = "c:\\alumnos\\enco.txt";
  const char FICH_DELI[] = "c:\\alumnos\\deli.txt";
  const char FICH_TABU[] = "c:\\alumnos\\tabu.txt";

  float media_edad, media_talla;
  int dim;

  Persona lista[DIM];

  system ("cls");
  if ( (fp=fopen(FICH_ENCO, "r")) == NULL )
	 printf("ERROR. NO se puede leer el fichero %s\n", FICH_ENCO);
  else
	 {   printf("Lectura fichero encolumnado %s\n", FICH_ENCO);
	     dim = 0;	     
         media_edad = media_talla = 0;
	     while ( leer_encolumnado(fp, lista[dim].st_nombre,
				                      lista[dim].st_provincia,
                                     &lista[dim].st_edad,
                                     &lista[dim].st_talla) != EOF ) {
		  media_edad  += lista[dim].st_edad;
		  media_talla += lista[dim].st_talla;
		  dim++;
	     }
	     fclose(fp);
	     imprime_lista(lista, dim);
	     media_edad  = media_edad/dim;
	     media_talla = media_talla/dim;
	     printf("Media edad: %7.2f\n", media_edad);
	     printf("Media talla: %7.2f\n", media_talla);
	 }
  
  printf("\n");
  system("pause");
  printf("\n");


  media_edad = 0;
  media_talla = 0;

  if ( (fp=fopen(FICH_DELI, "r")) == NULL )
	 printf("ERROR. NO se puede leer el fichero %s\n", FICH_DELI);
  else
	 {   printf("Lectura fichero delimitado por asteriscos %s\n", FICH_DELI);
	     dim = 0;	     
         media_edad = media_talla = 0;
	     while ( leer_delimitado_aste(fp, lista[dim].st_nombre,
                                          lista[dim].st_provincia,
                                         &lista[dim].st_edad,
                                         &lista[dim].st_talla) != EOF ) {
		  media_edad  += lista[dim].st_edad;
		  media_talla += lista[dim].st_talla;
		  dim++;
	     }
	     fclose(fp);
	     imprime_lista(lista, dim);
	     media_edad  = media_edad/dim;
	     media_talla = media_talla/dim;
	     printf("Media edad: %7.2f\n", media_edad);
	     printf("Media talla: %7.2f\n", media_talla);
	 }
  
  printf("\n");
  system("pause");
  printf("\n");


  media_edad  = 0;
  media_talla = 0;

  if ( (fp=fopen(FICH_TABU, "r")) == NULL )
	 printf("ERROR. NO se puede leer el fichero %s\n", FICH_TABU);
  else
	 {   printf("Lectura fichero tabulado %s\n", FICH_TABU);
	     dim = 0;	     
         media_edad = media_talla = 0;
	     while ( leer_tabulado(fp, lista[dim].st_nombre,
                                   lista[dim].st_provincia,
                                  &lista[dim].st_edad,
                                  &lista[dim].st_talla) != EOF ) {
		  media_edad  += lista[dim].st_edad;
		  media_talla += lista[dim].st_talla;
		  dim++;
	     }
	     fclose(fp);
	     imprime_lista(lista, dim);
	     media_edad  = media_edad/dim;
	     media_talla = media_talla/dim;
	     printf("Media edad: %7.2f\n", media_edad);
	     printf("Media talla: %7.2f\n", media_talla);
	 }
  
  printf ("\n\n");
  system ("pause");
  return 0;
}



/* ---------------------------------------------------------- */
   int leer_encolumnado(FILE *f, char *pnom, char *pprov,
                                 int *pedad, float *ptalla) {
/* ---------------------------------------------------------- */
   if ( fscanf(f, "%44[^\n]%14[^\n]%3d%5f%*c",
               pnom, pprov, pedad, ptalla) == EOF )
     return (EOF);
   else {
      recortarizq (pnom);
      recortarizq (pprov);
      return 0;
   }
       
}

/* ---------------------------------------------------------- */
   int leer_delimitado_aste(FILE *f, char *pnom, char *pprov,
                                     int *pedad, float *ptalla) {
/* ---------------------------------------------------------- */
   char  x_edad[15];
   char  x_talla[15];

   if ( fscanf(f, "%[^*]%*c%[^*]%*c%[^*]%*c%[^\n]%*c",
		  pnom, pprov, x_edad, x_talla) == EOF )
     return (EOF);
   else {
      *pedad = atoi(x_edad);
      *ptalla = atof(x_talla);
      return 0;
   }

/* ---  Otra forma ------------------------------------
   if ( fscanf(f, "%[^*]%*c%[^*]%*c%d%*c%f%*c",
		  pnom, pprov, pedad, ptalla) == EOF )
      return (EOF);
   else
      return 0;
   ---------------------------------------------------- */

       
}


/* ---------------------------------------------------------- */
   int leer_tabulado(FILE *f, char *pnom, char *pprov,
                              int *pedad, float *ptalla) {
/* ---------------------------------------------------------- */
   if ( fscanf(f, "%[^\t]%*c%[^\t]%d%f%*c",
		  pnom, pprov, pedad, ptalla) == EOF )
      return (EOF);
   else
      return 0;
       
}



/* ---------------------------------------------------------- */
   void imprime_lista(Persona *la, int dim) {
/* ---------------------------------------------------------- */
   int i;

   for (i=0; i<dim; i++)
	   printf("#%s#%s#%d#%.2f#\n",
	       la[i].st_nombre,
	       la[i].st_provincia,
	       la[i].st_edad,
	       la[i].st_talla);
}


/* ---------------------------------------------------------- */
   void recortarizq (char *cad) {
/* ---------------------------------------------------------- */
  const char ESPACIO = '\x20';
  long k;

  while (cad[0] == ESPACIO)
  {    k = 0;
       while (cad[k] != '\0')
         { cad[k] = cad[k+1];
           k++;
         }
  } 
}


/* ----------------- Para leer toda la lista de una vez ------------------- 
   void leer_encolumnado(FILE *f, Persona *la, int *dim,
                         float *medad, float *mtalla) {

   *medad = *mtalla = 0;
   *dim = 0;

   while ( fscanf(f, "%44[^\n]%14[^\n]%3d%5f%*c",
		    la[*dim].st_nombre,
		    la[*dim].st_provincia,
		   &la[*dim].st_edad,
		   &la[*dim].st_talla)  != EOF )
       {
	   recortarizq (la[*dim].st_nombre);
	   recortarizq (la[*dim].st_provincia);
	   *med += la[*dim].st_edad;
	   *mpe += la[*dim].st_talla;
	   *dim += 1;
	}
}
-------------------------------------------------------------------------- */
