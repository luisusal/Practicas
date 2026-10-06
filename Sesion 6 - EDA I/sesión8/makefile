# Sesión 8 - RadixSort: Ejemplo de Algoritmo de Ordenación por Distribución. Análisis

	# Prueba RadixSort
pruebaRadix: pruebaRadix.c lista.o ordenacion.o
	gcc -g pruebaRadix.c lista.o ordenacion.o -o pruebaRadix

	# Analisis RadixSort
sesion8: medirTyContar.c lista.o ordenacion.o
	gcc -g medirTyContar.c lista.o ordenacion.o -o sesion8

ordenacion.o: ordenacion.c ordenacion.h
	gcc -c -g ordenacion.c

lista.o: lista.c lista.h
	gcc -c -g lista.c

# Varios
clean:
	rm *.o

