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
		contadorExterno++; // Contador
		for (j=1;j<=n;j++)
			{
			contadorInterno++; // Contador
			c = c + 1;
			}
	  	}
return c;
}

// 
void algB(int n)
{
	int i,j,k,c;
	c = 1;
	
	for(i=1;i<=n;i++)
	{
		contadorExterno++; // Contador
		for(j=1;j<=n;j++)
		{
			contadorInterno++; // Contador
			for(k=1;k<=2;k++)
			{
				contadorK++; // Contador
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
		contadorExterno++; // Contador
		for(j=1;j<=n2;j++)
		{
			contadorInterno++; // Contador
			for(k=1;k<=n3;k++)
			{
				contadorK++; // Contador
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
		contadorExterno++; // Contador
		for(j=1;j<=i;j++)
		{
			contadorInterno++; // Contador
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
		contadorExterno++; // Contador
		for(j=1;j<=n;j++)
		{
			contadorInterno++; // Contador
			for(k=1;k<=j;k++)
			{
				contadorK++; // Contador
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
		contadorExterno++; // Contador
		for(j=1;j<=i;j++)
		{
			contadorInterno++; // Contador
			for(k=1;k<=j;k++)
			{
				contadorK++; // Contador
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
		contadorExterno++; // Contador
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
		contadorExterno++; // Contador
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
		contadorExterno++; // Contador
 		j = 1;
		while(j<=i)
		{
			contadorInterno++; // Contador
			x = x + 1;
			j = j * 2;
		}
		i = i + 1;
	}
	while(i>n);	
}

//
void algJ(int n)
{
	int i,j,x;
	i = 1;
	x = 0;

	do
	{
		contadorExterno++; // Contador
		j = 1;
		while(j<=i)
		{
			contadorInterno++; // Contador
			x = x + 1;
			j = j + 2;
		}
		i = i + 1;
	}
	while(i>n);
}

//
int algK(int n)
{
	int i,j,x;
	i = 1;
	x = 0;

	while(i<n)
	{
		contadorExterno++; // Contador
		for(j=1;j<=i;j++)
		{
			contadorInterno++; // Contador
			x = x + 1;
		}
		i = i * 10;
	}
return x;
}

// ------ ENUNCIADO 3 ------
