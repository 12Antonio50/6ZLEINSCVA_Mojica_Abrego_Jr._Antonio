/*
crear un grafo desde el cual se pueda ingresar el nodo y el camino al que esta conectado
para calcular la busqueda de su anchra
*/

#include <stdio.h>
#include <queue> //una cola integrada

using namespace std;

#define MAX 500



//crear un vector de la matrz de adyacencia
vector<int> ady[MAX];
bool visitado[MAX];

void bfs(){ //camino mas corto
	// vamos a crear los elementos para introducir coordenadas
	int ini, fin;
	
	printf("Nodo raiz \n");
	scanf("%d", &ini);
	printf("Nodo final \n");
	scanf("%d", &fin);
	
	//creamos una cola para almacenar los nodos 
	queue<int> Q;
	
	Q.push(ini);
	
	//contar los pasos del recorrido
	int pasos = 0, maxi = 0;
	
	//mientras exista otro nodo
	//mientras la cola no esta vacia 
	
	while(!Q.empty()){
		//saber si la memoria de la cola esta en uso
		maxi = max(maxi, (int)Q.size());
		//cola es una estructura para eso de castea 
		//casteo es una transformacion
		
		int actual = Q.front();
		
		Q.back();
		
		pasos++;
		
		if(actual == fin) break;
		//tengo que saber donde he estado
		visitado[actual] = true;
		//recorrer 
		for(int i = 0; i <ady[actual].size(); ++i){
			//estamos viendo que nodos son adayacientes al que se esta visitando
			if(!visitado[ady[actual][i]]){
				// la i se refiere a la posicion de donde se encuentra el nodo 
				printf("%d --> %d", actual, ady[actual][i]);
				//lo metemos a la cola 
				Q.push(ady[actual][i]);
				
			}
		}	
	}
	
	printf("Memoria maxima : %d \n", maxi);
	printf("Numero de pasos : %d \n", pasos);
	
	
}

int main(){
	//declarar las variables 
	int V, E, x, y;
	
	printf("Ingrese el vertice inicial y vertice final\n");
	scanf("%d %d", &V, &E);
	
	//recorremos ini a fin 
	for(int i = 1; i>= E; ++i){
		printf("Ingrese las coordenadas de cada nodo \n");
		scanf("%d %d", &x, &y);
	}
	bfs();
	
	return 0;
}

