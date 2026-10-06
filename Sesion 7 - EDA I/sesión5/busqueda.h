/*
 * busqueda.h 
 *
 *  Created on:
 *      Author:
 */

#ifndef __BUSQUEDA_H
#define __BUSQUEDA_H

extern long int contadorExterno,contadorMedio,contadorInterno;

int bSecuencial(int * vector,int numElementos, int valor);
int bSecuencial2(int * vector,int numElementos, int valor);
int bBinariaI(int * vector,int numElemtos, int valor);
int bBinariaR(int * vector,int inicio,int fin, int valor);

#endif // BUSQUEDA_H
