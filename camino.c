#include "camino.h"


struct Camino* crear_caminos(){//lo utilizamos para agregar al principio 
	return NULL;
}

struct Camino* camino_agregar_al_inicio(struct Camino* caminos, int costo,int posicion){

  struct Camino* nuevoCamino = malloc(sizeof(struct Camino));

  nuevoCamino->next = caminos;
  nuevoCamino->posicion = posicion;
  nuevoCamino->costo = costo;
  
  return nuevoCamino;
}

void destruir_Camino(struct Camino* caminos){
	struct Camino* Eliminando = NULL;
	while(caminos){
		Eliminando=caminos;
		caminos=caminos->next;

		free(Eliminando);//liberamos el temporal para no perder la lista enlazada


	}
	free(caminos);
}