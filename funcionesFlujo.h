#ifndef __FUNCIONESFLUJO_H__
#define __FUNCIONESFLUJO_H__

#include <stdlib.h>
#include "camino.h"
#include "grafo.h"


//Recibimos una lista enlazada y verificamos cual tiene el menor entero guardado de costo
//Nos sirve para poder sacar el numero que vamos a modificar al grafo con el camino que tengamos almacenado
int minimo_costo(struct Camino* camino);

//Dado un camino que contiene las posiciones donde se genero la busqueda de conexion de la fuente
//hacia el sumidero, y un entero que representa el minimo costo encontrado entre esas conexiones
//vamos a aumentar el costo sustraido, que representa el flujo circulante, en cada posicion del grafo que corresponda 
struct grafo* modificar_grafo(struct grafo* grafo,struct Camino* camino, int menor);

//Esta funcion nos encuentra los caminos parandoce desde los vertices y buscando el que tenga mayor o igual resultado 
//entre restar el flujo original y el flujo circulante que seria lo que puede seguir dando de flujo desde ese punto
//una vez que termina de encontrar el camino posible nos modifica el grafo y devuelve el entero con el cual lo modifico
//la devolucion nos sirve para saber cuanto va almacendando de flujo maximo
int buscar_caminos(struct grafo* grafo);



#endif /* __FUNCIONESFLUJO_H__ */