#include "camino.h"
#include "grafo.h"
#include "generadorArchivo.h"
#include "funcionesStrings.h"
#include "funcionesFlujo.h"


int main(int argc,char** argv){
	
	FILE* fp = fopen(argv[1], "r"); //abrimos el archivo en formato lectura pasado como argumento al ejecutar
	int fuente=0;
	int costo;
	int conectado=1;

	struct grafo* grafo=entrada(fp);//cargamos el grafo para poder ir despues a buscar los caminos y sacar costos
	fclose(fp);
	
	while (conectado){//una vez que no tenga mas flujo para pasar termina de encontrar caminos y modificar grafos
		costo=buscar_caminos(grafo);		
		fuente+=costo;
		if (costo==0)
			conectado=0;
		
	}

	generar_salida(grafo,fuente,argv[2]);//creamos el archivo de salida con el nombre pasado de argumento al ejecutar el programa

	destruir_grafo(grafo);

	return 0;
}


/*

COMPILACION


gcc -c camino.c grafo.c funcionesStrings.c  funcionesFlujo.c generadorArchivo.c
gcc -o main main.c camino.o grafo.o funcionesStrings.o funcionesFlujo.o generadorArchivo.o
./main entrada.txt salida.txt

*/