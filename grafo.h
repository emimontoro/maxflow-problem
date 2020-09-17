#ifndef __grafo_H__
#define __grafo_H__


#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct node{
    int vertex; //representa con quien conecta
    int costo; //pertenece a capacidad de coneccion
    int costo_sustraido; //flujo circulante
    struct node* next;
    struct node* last;
};

//Inicializa un nodo con un vertice que conecta a v y un costo determinado
//el costo sustaido le asignamos 0 siempre en la creacion
// y hacemos que su puntero a next sea NULL
struct node* createNode(int v,int costo);

//Eliminamos toda la memoria ocupado por la lista enlazada creada de los nodos
void destruir_Node(struct node* nodo);


//Representa una estructura que posee un array de strings, un entero que representa la cantidad de vertices
//y contiene un array de las listas enlazadas de cada vertice
struct grafo{
	char** nombres;
    int numVertices;
    struct node** adjLists;
};

//Inicializa el grafo con una cantidad de vertices determinada pidiendo la memoria necesaria
struct grafo* creategrafo(int vertices);


//Esta funcion recibe 3 enteros, 2 determinan posiciones y uno para el costo que las une 
//tambien tenemos una estructura grafo donde vamos a agregar el nodo creado con los datos recibidos
//en la ultima posicion con un puntero a la ultima posicion dejando el grafo ordenado 
//al utilizar un puntero al final nos ahorramos de recorrer la lista en cada insercion 
struct grafo* agregarAdj(struct grafo* grafo, int ini, int dest,int costo);


//liberamos toda memoria pedida para la estructura grafo
void destruir_grafo(struct grafo* grafo);


#endif /* __grafo_H__ */