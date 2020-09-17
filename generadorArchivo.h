#ifndef __GENERADORARCHIVO_H__
#define __GENERADORARCHIVO_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "grafo.h"
#include "funcionesStrings.h"

#define T_renglon 500 


//cargamos en la estructura grafo todo lo que recibimos en el archivo de entrada
struct grafo* entrada(FILE* fp);

//creamos un archivo de salida con los datos pedidos de consigna
void generar_salida(struct grafo* grafo,int flujo,char* nombre);


#endif /* __GENERADORARCHIVO_H__ */