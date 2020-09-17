#include "generadorArchivo.h"


struct grafo* entrada(FILE* fp){
	char renglon[T_renglon];
	char inicio[20]; //fuente
	char final[20]; //sumidero

	char* temporal;
	char* temporalRecovery;//para no perderlo cuando lo desplazamos
	int longitud;

	//posiciones 
	int ladoInicio;
	int ladoDestino;
	//costo
	int costo;


	while ((fscanf(fp, "%[^\n]s", renglon) != EOF)&&(strcmp(renglon,"Sumidero") != 0)){
      fscanf(fp,"%[^\n]", renglon);
      
  
  if ((strcmp(renglon,"Fuente")!=0)&& (strcmp(renglon,"Sumidero") != 0))
  		strcpy(inicio,renglon);//aca obtenemos el string que representa a la fuente

  	fgetc(fp);

  }
  	fgetc(fp);
  	fscanf(fp,"%[^\n]", renglon); //cargamos a renglon el string que representa a el sumidero
  	strcpy(final,renglon);

	fgetc(fp);
	fscanf(fp,"%[^\n]", renglon);
	
	fgetc(fp);
	if ((strcmp(renglon,"Puntos Intermedios")!=0)&& (strcmp(renglon,"Conexiones") != 0))
  		strcpy(inicio,renglon);

	  	
	fscanf(fp,"%[^\n]", renglon);
	
	longitud=contar_comas(renglon);//contamos las ',' para sumarle 3 y esa seria nuestra cantidad de puntos totales del grafo

	struct grafo* grafo = creategrafo(longitud);//ya inicializamos el grafo una vez obtenida la cantidad de conexiones totales

	temporal=malloc(sizeof(char)*(T_renglon));
	temporalRecovery=temporal;//para no perder el temporal al ir desplasandolo
	temporal = strtok(renglon, ",");	//separamos las , en el array

	int pos=1;

	agregar_string(grafo,inicio,0);
	
	while (temporal!=NULL){//mando los strings a un array en el grafo para manejarme mas facil a mi en posiciones
;
		agregar_string(grafo,temporal,pos);

		temporal=strtok(NULL,","); 

		pos+=1;

	}
	free(temporalRecovery);
	agregar_string(grafo,final,pos);

	fgetc(fp);
	fscanf(fp,"%[^\n]", renglon);


	fgetc(fp);
	fscanf(fp,"%[^\n]", renglon);

	while (fscanf(fp, "%[^\n]s", renglon) != EOF){
		temporal=malloc(sizeof(char)*(longitud*2));
		temporalRecovery=temporal;
		temporal = strtok(renglon, ",");
		while (temporal != NULL){
			ladoInicio=posicion_string(grafo,temporal);

			temporal = strtok(NULL, ",");

			ladoDestino =posicion_string(grafo,temporal);

			temporal=strtok(NULL,",");

			costo=atoi(temporal);

			temporal = strtok(NULL, ",");

			agregarAdj(grafo, ladoInicio,ladoDestino,costo); //cargamos al grafo la conexion al tenerla
		}
		free(temporalRecovery);

		fgetc(fp);

	}
	
	//free(temporal);
	//fclose(fp);

	return grafo;
}



void generar_salida(struct grafo* grafo,int flujo,char* nombre){
	FILE* salida = fopen(nombre, "w");
	fprintf(salida,"Flujo maximo\n%d\nFlujos\n",flujo);
	for (int i = 1;i < grafo->numVertices;i++){
		struct node* temp = grafo->adjLists[i];

		while (temp){// devolvemos de la forma: conexionA,conexionB,costo,flujo circulante
			fprintf(salida,"%s,%s,%d,%d\n",grafo->nombres[i-1],grafo->nombres[temp->vertex -1],temp->costo,temp->costo_sustraido);
			temp=temp->next;
		}	
	}
	fclose(salida);
}