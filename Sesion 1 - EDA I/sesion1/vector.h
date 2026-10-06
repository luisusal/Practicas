int *crearVector(int  numElementos , int  rango)
{
	int *matriz , i;

	matriz = malloc(numElementos * sizeof(int));
	for (i = 0; i < numElementos; i++)
		matriz[i] = rand()  % rango;
	
	return  matriz;
}

int *ordenarBurbuja(int *matriz , int  numElementos)
{
	int * nuevo , i, j, aux;

	nuevo = (int *) malloc(numElementos * sizeof(int));

	for (i = 0; i < numElementos; i++)
		nuevo[i] = matriz[i];

	for (i = 0; i < numElementos; i++)
	{
		for (j = 0; j < numElementos -1-i; j++)
		{
			if (nuevo[j] > nuevo[j+1])
			{
				intercambiar  (&( nuevo[j]) ,&(nuevo[j+1]));
			}
		}

	}

	return  nuevo;
}


void intercambiar (int *x, int *y)
{

	int  temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
