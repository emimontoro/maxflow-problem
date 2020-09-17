#ifndef __FUNCIONESSTRINGS_H__
#define __FUNCIONESSTRINGS_H__

#include <string.h>
#include "grafo.h"


//dado un nombre y un numero, insertamos en nuestra estructura grafo
//el nombre recibido en la posicion establecida
//la utilizamos para poder recibir strings como nombres de veritices 
//y sin problema trabajar con sus posiciones en vez de comparar 
//strings en cada momento que tengamos conexiones para verificar donde asignarla
struct grafo* agregar_string(struct grafo* grafo ,char* nombre,int posicion);


//recibimos un string y un grafo en el cual buscaremos donde esta posicionado
//el string dentro de nuestra estructura, que posee un array de strings
//a el indice encontrado se le suma una unidad porque en principio 
//desarrolle el programa con posiciones > 0 para ver los indices a partir de 1
int posicion_string(struct grafo* grafo ,char* nombre);


//Recibe un string y cuenta la cantidad de ',' encontradas en el
//En este Trabajo Practico nos sirve porque dado la cantidad de ','
//Podemos adicionarle 3 y ese numero obtenido sera nuestra 
//cantidad total de puntos de interseccion de nuestro grafo
int contar_comas(char* puntos);


#endif /* __FUNCIONESSTRINGS_H__ */