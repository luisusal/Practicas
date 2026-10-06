int main(void )
{
	int * vector , * ordenado , numElementos , rango ,i;
	clock_t  tiempoInicial , tiempoFinal;

	numElementos = 1000;
	rango = 100000;

	vector = crearVector(numElementos , rango);
	printf("\nVector  desordenado: \n");
	for(i=0;i<numElementos;i++)
		printf(" %d\t", vector[i]);
	printf("\n");

	tiempoInicial = clock();
	ordenado = ordenarBurbuja(vector , numElementos);
	tiempoFinal = clock ();

	printf("\nVector  ordenado: \n");
	for(i=0;i<numElementos;i++)
		printf(" %d\t", ordenado[i]);
	printf("\n");

	printf("Tiempo  ejecucion  de la  burbuja =  %ld/ %ld =  %f\n",
		tiempoFinal  - tiempoInicial , CLOCKS_PER_SEC ,
		(( tiempoFinal  - tiempoInicial) / (double)CLOCKS_PER_SEC ));

	free(ordenado);
	free(vector);

	return  0;

}
