#include "funcionesFlujo.h"

int minimo_costo(struct Camino* camino){
	int menor=camino->costo;
	for (;camino!=NULL;camino=camino->next){
		if (camino->costo<menor) menor=camino->costo;
	}
	return menor;
}

struct grafo* modificar_grafo(struct grafo* grafo,struct Camino* camino_original, int menor){
	struct node* temp;//uso un puntero temporal para no perder la memoria
	struct Camino* camino=camino_original;//uso un puntero temporal para no perder la memoria
	
	for (;camino->next!=NULL;camino=camino->next){
		temp = grafo->adjLists[camino->next->posicion];
        
        while (temp){
            if(temp->vertex==camino->posicion){//una vez encontrado la posicion modificamos el flujo circulante
            	temp->costo_sustraido+=menor;
            	break;
            }
            
            temp = temp->next;
        }
	} 
	temp = grafo->adjLists[1];
	while (temp){
		if (temp->vertex==camino->posicion){

	            	temp->costo_sustraido+=menor;
	           
	            }
	            temp = temp->next;
	        }
	destruir_Camino(camino_original);
	return grafo;
} 


int buscar_caminos(struct grafo* grafo){
	int max;
	int posicion=0;
	int v = 1;
	struct Camino* path=crear_caminos();
	int pasado[grafo->numVertices];//nos va a servir para los vertices ya recorridos
	for (int j=0;j<grafo->numVertices;j++)
		pasado[j]=1;//cuando el camino sea decidido este valor decrementa a 0 en dicha posicion
	while (posicion != grafo->numVertices){
		max=0;
		struct node* temp = grafo->adjLists[v];

		while (temp->next) {//recorro la adyacencia
			if ((temp->costo - temp->costo_sustraido >= max)&&(pasado[temp->vertex])){//salvo la posicion con mayor costo de las adyacencias
				posicion=temp->vertex;
				max=temp->costo - temp->costo_sustraido;
			}
			if (temp->vertex==grafo->numVertices){
				printf("llego\n");
				break;
			}
			temp=temp->next;
		}
		if (temp->costo - temp->costo_sustraido >= max){
				posicion=temp->vertex;
				max=temp->costo - temp->costo_sustraido;
		
		}
		if (max==0){//max va a ser unicamente 0 cuando no podamos conectar mas vertices			
				destruir_Camino(path);
				return 0;
				
		}
		v=posicion;
		pasado[v]=0;//para que le avise que por ese lugar ya estuvo
		path=camino_agregar_al_inicio(path,max,v);
		
	}
	struct Camino* camino=path;

	int menor=minimo_costo(path);
	grafo=modificar_grafo(grafo,camino, menor);

	return menor;
}

