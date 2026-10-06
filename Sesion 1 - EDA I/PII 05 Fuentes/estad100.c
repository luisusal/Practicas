/* Fuente: estad100.c
   Programa: ESTADISTICAS SOBRE FICHERO lista100.txt
   Descripción: Lee el fichero encolumnado lista100.txt y genera distintas estadísticas
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ---------------------------------------------------------- */
/* Prototipos                                                 */
/* ---------------------------------------------------------- */
   void presentacion     (void);
   int  leer_encolumnado (FILE *, char *, int *, float *, float *, char *);
   void recortarizq (char *);

/* ---------------------------------------------------------- */
   int main (void) {
/* ---------------------------------------------------------- */
     FILE *fp;
     const char FICHERO[] = "c:\\temp\\lista100.txt";
   
     float media_edad, media_peso, media_talla;
     float max_peso, min_peso;
     float max_talla, min_talla;
     int   max_edad, min_edad;
     char  nombre_edad_minima[21] = "";
     char  nombre_talla_maxima[21] = "";
     long  sobre_media_peso, en_media_peso, bajo_media_peso;
     long  cuantos;
     char  fnombre[21];
     int   fedad;
     float fpeso;
     float ftalla;
     char  fciudad_nac[13];
   
     system ("cls");
     presentacion();
     
     if ( (fp=fopen(FICHERO, "r")) == NULL )
        { printf("ERROR. NO se puede leer el fichero %s\n", FICHERO);
          printf ("\n\n");
          system ("pause");
          return 1; /* Salimos de la función main. Terminamos el programa */
        }	 
   	 
     /* Primera lectura fichero encolumnado */
     /* =================================== */
     cuantos = 0;
     media_edad = media_peso = media_talla = 0;
     
     while ( leer_encolumnado(fp, fnombre, &fedad, &fpeso,
                                 &ftalla,  fciudad_nac) != EOF ) {
   	  cuantos++;
   	  media_edad  += fedad;
   	  media_peso  += fpeso;
   	  media_talla += ftalla;
   		  
   	  if (cuantos == 1)
   	  {  max_edad = min_edad = fedad;
   	     strcpy(nombre_edad_minima, fnombre);
   	     max_peso = min_peso = fpeso;
   	     max_talla = min_talla = ftalla;
   	     strcpy(nombre_talla_maxima, fnombre);
   	  }
   	  else
   	  {   if (fedad > max_edad) max_edad = fedad;
   	      if (fedad < min_edad)
   	         { min_edad = fedad;
   	           strcpy(nombre_edad_minima, fnombre);
   	         }
   	      if (fpeso > max_peso) max_peso = fpeso;
   	      if (fpeso < min_peso) min_peso = fpeso;
   	      if (ftalla > max_talla)
   	         { max_talla = ftalla;
   	           strcpy(nombre_talla_maxima, fnombre);
   	         }
   	      if (ftalla < min_talla) min_talla = ftalla;
   	  }
     } /* Fin del while */
   
     media_edad  /= cuantos;
     media_peso  /= cuantos;
     media_talla /= cuantos;
   
     fclose(fp);
   	     
   
     /* Segunda lectura fichero encolumnado */
     /* =================================== */
   
     if ( (fp=fopen(FICHERO, "r")) == NULL )
        {  printf("ERROR. NO se puede leer el fichero %s\n", FICHERO);
          printf ("\n\n");
          system ("pause");
          return 1; /* Salimos de la función main. Terminamos el programa */
        }	 
   
     sobre_media_peso = en_media_peso = bajo_media_peso = 0;
     
     while ( leer_encolumnado(fp, fnombre, &fedad, &fpeso,
                                 &ftalla,  fciudad_nac) != EOF ) {
   	  if (fpeso >  media_peso) sobre_media_peso++;
   	  if (fpeso <  media_peso) bajo_media_peso++;
   	  if (fpeso == media_peso) en_media_peso++;
     } /* Fin del while */
   
     fclose(fp);
   
   
     /* Presentamos resultados */
     /* ====================== */
     
     printf("Resultados tratamiento del fichero %s\n", FICHERO);
     printf("==========================================================\n");
     printf("Registros leidos............: %3ld\n", cuantos);
     printf("Edad media..................: %6.2f\n", media_edad);
     printf("Edad máxima.................: %3d\n", max_edad);
     printf("Edad mínima.................: %3d\n", min_edad);
     printf("Persona con edad mínima.....: %s\n", nombre_edad_minima);
     printf("Peso medio..................: %7.3f\n", media_peso);
     printf("Peso máximo.................: %7.3f\n", max_peso);
     printf("Peso mínimo.................: %7.3f\n", min_peso);
     printf("Estatura media..............: %6.2f\n", media_talla);
     printf("Estatura máxima.............: %6.2f\n", max_talla);
     printf("Persona con estatura máxima.: %s\n", nombre_talla_maxima);
     printf("Estatura mínima.............: %6.2f\n", min_talla);
     printf("Personas por encima de la media del peso...: %3ld\n",
	      sobre_media_peso);
     printf("Personas en la media del peso..............: %3ld\n",
	      en_media_peso);
     printf("Personas por debajo de la media del peso...: %3ld\n",
	      bajo_media_peso);
	      
     printf("\n\n");
     system ("pause");
     return 0;
}

/* ---------------------------------------------------------- */
int leer_encolumnado(FILE *f, char  *pnom,
                              int   *pedad,
                              float *ppeso,
                              float *ptalla,
                              char  *pciudad ) {
/* ---------------------------------------------------------- */
     int   t_edad;
     float t_peso;
     float t_talla;
  
     if ( fscanf(f, "%20[^\n]%4d%8f%6f%12[^\n]%*c",
  		  pnom, &t_edad, &t_peso, &t_talla, pciudad) == EOF )
          return (EOF);
     else
     {  recortarizq (pnom);
        recortarizq (pciudad);
       *pedad  = t_edad;
       *ppeso  = t_peso;
       *ptalla = t_talla;
        return 0;
     }
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


/* ---------------------------------------------------------- */
void presentacion (void) {
/* ---------------------------------------------------------- */
     puts("ESTADISTICAS FICHERO LISTA100.TXT");
     puts("=================================");
     puts("");
     puts("El programa presenta distintas estadísticas del fichero LISTA100.TXT");
     puts("");
}
