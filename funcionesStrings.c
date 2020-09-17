#include "funcionesStrings.h"


struct grafo* agregar_string(struct grafo* grafo ,char* nombre,int posicion){
	grafo->nombres[posicion]=malloc(sizeof(char)*strlen(nombre)+1);//+1 por el \0
	strcpy(grafo->nombres[posicion],nombre);
	return grafo;
}

int posicion_string(struct grafo* grafo ,char* nombre){
	int i;
	for (i=0;i<grafo->numVertices;i++){
		if(strcmp(nombre,grafo->nombres[i])==0) break;

	}
	return i+1;
}

int contar_comas(char* puntos){
	int longitud=strlen(puntos);
	int comas=0;
	if(longitud == 0)return 2;//caso de no puntos intermedios
	for (int i=0;i<longitud;i++){
		if (puntos[i]==',')
			comas+=1;
	}
	
	return comas+3;
}
