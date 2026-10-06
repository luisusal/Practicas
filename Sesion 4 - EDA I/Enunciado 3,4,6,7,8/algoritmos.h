/*
 * auxiliares.h
 *
 *  Created on:
 *      Author:
 */

#ifndef __AUXILIARES_H
#define __AUXILIARES_H
#define MIN_T 10 * CLOCKS_PER_SEC
#define MIN_REP 5
extern long int contadorInterno, contadorExterno, contadorK;

// ------ ENUNCIADO 2 ------

void algA(int n);
void algB(int n);
void algC(int n);
void algD(int n);
void algE(int n);
void algF(int n);
void algG(int n);
void algH(int n);
void algI(int n);
void algJ(int n);
int algK(int n);

// ------ ENUNCIADO 3 ------

double factorialR(int n);
double factorialI(int n);

// ------ ENUNCIADO 4 ------

int fibonnacciR(int n);
int fibonnacciI(int n);

// ------ ENUNCIADO 6 ------

double potR(int x,int n);
double potI(int x,int n);

// ------ ENUNCIADO 7 ------

int busquedaMaximo(int *vector,int base,int tope);

// ------ ENUNCIADO 8 ------

int busquedaPicos(int *vector, int numElementos);
//int busquedaPicos(int *vector,int base,int tope, int numElementos);
void verSubvector(int *vector, int base, int tope);

#endif
