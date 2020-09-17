Trabajo práctico Estructura de datos y Algoritmos 1
Alumno: Emiliano Montoro

Archivos entregados:

Makefile
camino.c
camino.h
grafo.c
grafo.h
funcionesFlujo.c
funcionesFlujo.h
funcionesStrings.c
funcionesStrings.h
generadorArchivo.c
generadorArchivo.h
main.c

Una carpeta llamada ArchivosPrueba que contiene:
entrada.txt //un ejemplo de un grafo con 50 conexiones
entrada2.txt //un ejemplo con un grafo que posee strings y puntos intermedios doblemente conectados
entrada3.txt //el ejemplo del grafo encontrado en el enunciado del tp


Para compilar hay que ubicarse en el directorio donde se encuentren los archivos y ejecutar el comando: 

make all
esto compilara todo lo que necesitamos para luego generar el ejecutable main

para ejecutar el programa debemos elegir el archivo de entrada y decidir el nombre del archivo de salida
ejemplo:

	./main ArchivosPrueba/NOMBRE DEL TXT ArchivosGenerados/NOMBRE DE SALIDA DESEADO

en *NOMBRE DEL TXT* hay que colocar algun ejemplo encontrado en la carpera de ArchivosPrueba
en *NOMBRE DE SALIDA DESEADO* se le puede colocar cualquier nombre por ejemplo salida.txt



en caso de querer deshacernos de los archivos con la extencion .o de nuestra carpeta ejecutamos el comando

make clean


El programa esta preparado para recibir strings como nombre de punto de conexion, fue probado con un grafo de 50 conexiones
el cual adjuntamos como "entrada.txt", se puede utilizar la cantidad de nodos deseados, en caso que la linea de puntos
intermedios exceda a 500 caracteres, unicamente hay que modificar la macro T_renglon, ubicada en el archivo "generadoArchivo.h"
agrandando al tamaño deseado y el programa podra ejecutar la cantidad de conexiones deseadas sin ningun problema.
Tambien verifique la situacion de un grafo donde los puntos intermedios se conecten entre si en los puntos intermedios,
y siendo estas conexiones entre ambos el maximo camino posible, aun asi el programa no se queda rebotando entre esos puntos,
sino que sigue y busca la conexion hacia el sumidero, se puede ver este ejemplo claro en el archivo entregado "entrada2.txt"

Para buscar los caminos de mi grafo lo que yo hago es desde el vertice que estoy parado busco la conexion con mayor valor restante al realizar la operacion del costo menos el flujo circulante hacia ese vertice, una vez que obtengo el mayor resultado posible  voy a ese vertice y realizo lo mismo. Los vertices pasados y costos los guardo en una lista enlazada para despues determinar el minimo costo entre todo el camino que hice asi modifico mi grafo sumandole el valor obtenido al flujo circulante en cada posicion pisada.

