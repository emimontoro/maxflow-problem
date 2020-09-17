#include "grafo.h"

struct node* createNode(int v,int costo){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;//representa a que verice se conecta
    newNode->costo=costo;
    newNode->costo_sustraido=0;//aca vamos a ir modificando el flujo circulante
    newNode->next = NULL;//como siempre agregamos al final ya establecemos que el siguiente es NULL
    return newNode;
}


void destruir_Node(struct node* nodo){
	struct node* Eliminando=NULL;
	while(nodo){
		Eliminando=nodo;//evitamos perder toda la lista enlazada cuando liberamos la memoria
		nodo=nodo->next;
		free(Eliminando);
		
	}
	
}


struct grafo* creategrafo(int vertices){
    struct grafo* grafo = malloc(sizeof(struct grafo));
    grafo->numVertices = vertices;
 	grafo->nombres=malloc(sizeof(char*)*vertices);//cantidad de strings que vamos a guardar
    grafo->adjLists = malloc(vertices * sizeof(struct node*));
 
    int i;
    for (i = 0; i < vertices; i++)
        grafo->adjLists[i] = NULL;
 
    return grafo;
}


struct grafo* agregarAdj(struct grafo* grafo, int ini, int dest,int costo){
    struct node* newNode = createNode(dest,costo);

    
    if (grafo->adjLists[ini]==NULL){
		newNode->last=newNode;//entra unicamente cuando es vacia y por eso determinamos que el nodo que agregamos es el ultimo
    	grafo->adjLists[ini]=newNode;

    	return grafo;

    }
   	struct node* temp=grafo->adjLists[ini]->last;

	temp->next=newNode;
	grafo->adjLists[ini]->last=newNode;//nuestro ultimo nodo agregado sera siempre al que apunte last
	


	return grafo;
 
}


void destruir_grafo(struct grafo* grafo){
	struct node* Eliminando = NULL;
	//primero liberamos los strings
	for(int j = 0;j<grafo->numVertices;j++)
		free(grafo->nombres[j]);
	free(grafo->nombres);
	//liberamos cada elemento del array(listas enlazadas)
	for(int i=0;i<grafo->numVertices;i++){
		Eliminando=grafo->adjLists[i];
		destruir_Node(Eliminando);

	}
	free(grafo->adjLists);
	
	free(grafo);
}

