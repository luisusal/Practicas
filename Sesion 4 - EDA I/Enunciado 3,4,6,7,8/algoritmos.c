/*
 * algoritmos.c
 *
 *  Created on:
 *      Author:
 */

#include <stdlib.h>
#include "algoritmos.h"

// ------ ENUNCIADO 2 ------

// Orden cuadrático
void algA(int n)
{
	int i,j,c;
	c = 1;

	for (i=1;i<=n;i++)
		{
		contadorExterno++; // Contador Iteraciones
		for (j=1;j<=n;j++)
			{
			contadorInterno++; // Contador Iteraciones
			c = c + 1;
			}
	  	}
}

// 
void algB(int n)
{
	int i,j,k,c;
	c = 1;
	
	for(i=1;i<=n;i++)
	{
		contadorExterno++; // Contador Iteraciones
		for(j=1;j<=n;j++)
		{
			contadorInterno++; // Contador Iteraciones
			for(k=1;k<=2;k++)
			{
				contadorK++; // Contador Iteraciones
				c = c + 1;
			}
		}
	}

}

//
void algC(int n)
{
	int i,j,k,c;
	int n2 = n*n,n3=n*n*n;
	c = 1;

	for(i=1;i<=n;i++)
	{
		contadorExterno++; // Contador Iteraciones
		for(j=1;j<=n2;j++)
		{
			contadorInterno++; // Contador Iteraciones
			for(k=1;k<=n3;k++)
			{
				contadorK++; // Contador Iteraciones
				c = c + 1;
			}
		}
	}
}

//
void algD(int n)
{
	int i,j,c;
	c = 1;

	for(i=1;i<=n;i++)
	{
		contadorExterno++; // Contador Iteraciones
		for(j=1;j<=i;j++)
		{
			contadorInterno++; // Contador Iteraciones
			c = c +1;
		}	
	}
}

//
void algE(int n)
{
	int i,j,k,c;
	c = 1;

	for(i=1;i<=n;i++)
	{
		contadorExterno++; // Contador Iteraciones
		for(j=1;j<=n;j++)
		{
			contadorInterno++; // Contador Iteraciones
			for(k=1;k<=j;k++)
			{
				contadorK++; // Contador Iteraciones
				c = c + 1;
			}
		}
	}
}

//
void algF(int n)
{
	int i,j,k,c;
	c = 1;

	for(i=1;i<=n;i++)
	{
		contadorExterno++; // Contador Iteraciones
		for(j=1;j<=i;j++)
		{
			contadorInterno++; // Contador Iteraciones
			for(k=1;k<=j;k++)
			{
				contadorK++; // Contador Iteraciones
				c = c + 1;

			}
		}
	}
}

//
void algG(int n)
{
	int x,j;
	x = 0;
	j = n;

	
	while(j>=1)
	{
		contadorExterno++; // Contador Iteraciones
		x = x + 1;
		j = j/2;
	}
}

//
void algH(int n)
{
	int x,j;
	x = 0;
	j = n;

	while(j>=1)
	{
		contadorExterno++; // Contador Iteraciones
		x = x + 1;
		j = j/3;
	}
}

//
void algI(int n)
{
	int i,j,x;
	i = 1;
	x = 0;

	do
	{
		contadorExterno++; // Contador Iteraciones
 		j = 1;
		while(j<=i)
		{
			contadorInterno++; // Contador Iteraciones
			x = x + 1;
			j = j * 2;
		}
		i = i + 1;
	}
	while(i<=n);	
}

//
void algJ(int n)
{
	int i,j,x;
	i = 1;
	x = 0;

	do
	{
		contadorExterno++; // Contador Iteraciones
		j = 1;
		while(j<=i)
		{
			contadorInterno++; // Contador Iteraciones
			x = x + 1;
			j = j + 2;
		}
		i = i + 1;
	}
	while(i<=n);
}

//
int algK(int n)
{
	int i,j,x;
	i = 1;
	x = 0;

	while(i<n)
	{
		contadorExterno++; // Contador Iteraciones
		for(j=1;j<=i;j++)
		{
			contadorInterno++; // Contador Iteraciones
			x = x + 1;
		}
		i = i * 10;
	}
return x;
}

// ------ ENUNCIADO 3 ------

// Factorial - Forma Recursiva
double factorialR(int n)
{
	if (n<=0)
	{
		contadorInterno++; // Contador Iteraciones
		return n;
	}	
	else
	{
		contadorInterno++; // Contador Iteraciones
		return n * factorialR(n-1);	
	}
}

// Factorial - Forma Iterativa
double factorialI(int n)
{
	double factorial =1;
	int i;
	
	for (i=2;i<=n;i++)
	{
		contadorInterno++; // Contador Iteraciones
		factorial = factorial * i;

	}

	return factorial;	
}

// ------ ENUNCIADO 4 ------

// Fibonnacci - Forma Recursiva
int fibonnacciR(int n)
{
	if (n<=0)
	{
		contadorInterno++; // Contador Iteraciones
		return 0;
	}	
	else if (n == 1)
		{			
			contadorInterno++; // Contador Iteraciones
			return 1;
		}		
		else
		{
			contadorInterno++; // Contador Iteraciones
			return fibonnacciR(n-1) + fibonnacciR(n-2);
		}
}

// Fibonnacci - Forma Iterativa
int fibonnacciI(int n)
{
	int i,a,b,fibonnacci;
	a = 0;
	b = 1;

	for (i=2;i<=n;i++)
	{
		contadorInterno++; // Contador Iteraciones
		fibonnacci = a + b;
		a = b;
		b = fibonnacci;
	}

	return fibonnacci;
}

// ------ ENUNCIADO 6 ------

// Potencia - Forma Recursiva
double potR(int x,int n)
{
	double potencia;

	if(n==0){
		contadorExterno++; // Contador Iteraciones
		return 1;
		}

	else if(n==1){
			contadorExterno++; // Contador Iteraciones
			return x;
			}

		else{
			contadorInterno++; // Contador Iteraciones
			potencia = x * potR(x,n-1);
			}
	return potencia;
}

// Potencia - Forma Iterativa
double potI(int x,int n)
{
	int i;
	double potencia=x;

	for(i=1;i<=n;i++)
	{
		contadorInterno++; // Contador Iteraciones
		potencia = potencia * x;
	}

	return potencia;
}

// ------ ENUNCIADO 7 ------

// Busqueda maximo

int busquedaMaximo(int *vector, int base, int tope)
{
	int aux1, aux2;

	if (base==tope){
		contadorExterno++; // Contador Iteraciones
		return (vector[base]);
		}
	else{
		contadorExterno++; // Contador Iteraciones
		aux1=busquedaMaximo(vector,base,(base+tope)/2);
		aux1=busquedaMaximo(vector,((base+tope)/2)+1,tope);
		if (aux1 > aux2){
			contadorInterno++; // Contador Iteraciones
			return (aux1);
			}
		else{
			contadorInterno++;
			return (aux2);
			}
	}
}

// ------ ENUNCIADO 8 ------

// Busqueda picos

//int busquedaPicos(int *vector,int base,int tope, int numElementos)
int busquedaPicos(int *vector, int numElementos)
{
	int k;
	//k=(base+tope)/2;
	k=(vector[0]+vector[numElementos-1])/2;

	if((k==1 || vector[k-1]>vector[k]) && (k == numElementos || vector[k+1] <= vector[k]))
		return k;
	else if (k > 1 && vector[k-1] > vector[k])
			return busquedaPicos(vector, numElementos); // debe haber mas argumentos
		else
			return busquedaPicos(vector, numElementos);
}































