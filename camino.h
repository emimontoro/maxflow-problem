#ifndef __CAMINO_H__
#define __CAMINO_H__

#include <stdlib.h>
#include <stdio.h>



//esta estructura la vamos a utilizar para almacenar los costos y posiciones del camino posible formado por el grafo
struct Camino{	
	int costo;
	int posicion;
	struct Camino* next;

};

//Inicializamos la estructura
struct Camino* crear_caminos();

//como no nos interesa si esta ordenado, agregamos todo al inicio
struct Camino* camino_agregar_al_inicio(struct Camino* caminos, int costo,int posicion);

//liberamos la memoria utilizada por la estructura
void destruir_Camino(struct Camino* caminos);








#endif /* __CAMINO_H__ */