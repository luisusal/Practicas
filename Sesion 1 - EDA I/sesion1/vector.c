int main(void)
{
	int * vector , * ordenado , numElementos , rango ,i;

	numElementos = 1000;
	rango = 100000;

	vector = crearVector(numElementos , rango);
	printf("\nVector  desordenado: \n");
	for(i=0;i<numElementos;i++)
		printf(" %d\t", vector[i]);
	printf("\n");

	ordenado = ordenarBurbuja(vector , numElementos);
	printf("\nVector  ordenado: \n");
	for(i=0;i<numElementos;i++)
		printf(" %d\t", ordenado[i]);
	printf("\n");

	free(ordenado);
	free(vector);

	return  0;
}
