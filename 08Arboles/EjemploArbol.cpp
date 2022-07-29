//ejemplo de un arbol

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//vampos a crear la estructuctura base de un arbol binario

struct nodo{
	//el dato
	char dato;
	//nodo der
	struct nodo *der;
	//nodo izq
	struct nodo *izq;
};

//ahora vamos a poder operar las ramas
typedef struct nodo _nodo;

//vamos a crear una definicion de como operar
//cada una de las ramas izq y der

_nodo *crear(char dato){
	//declaro el nodo
	_nodo *nuevo;
	//vamos a ocupar sizeof para solicitar el tamaño
	//de la estructra del arbol
	
	nuevo = (_nodo *)malloc(sizeof(_nodo));//obtiene la memoria malloc
	nuevo ->dato = dato;
	nuevo ->der = NULL;
	nuevo ->izq = NULL;
	return nuevo;
}

//metodo para agregar al a derecha 
_nodo *agregarDerecha(_nodo *nuevo, _nodo *raiz){
	raiz -> der = nuevo;
	return raiz;
}

_nodo *agregarIzquierda(_nodo *nuevo, _nodo *raiz){
	raiz -> izq = nuevo;
	return raiz;
}

//vamos a imprimir el arbol
void imprimir(_nodo *nodo){
	//tenemos que saber si el nodo esta vacio 
	if(nodo != NULL){
		printf(" %c ", nodo->dato);
	}
}

//recorrido:

//preorden
void preOrden(_nodo *raiz){
	//nodo actual, rama izq, rama der
	if(raiz!=NULL){
		imprimir(raiz);
		//recurrsividad
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

//inorden
void inOrden(_nodo *raiz){
	//nodo izquierda, raiz , rama der
	if(raiz!=NULL){
		inOrden(raiz->izq);
		//recurrsividad
		imprimir(raiz);
		inOrden(raiz->der);
	}
}

//postorden
void postOrden(_nodo *raiz){
	//nodo izquierda, derecha , raiz
	if(raiz!=NULL){
		postOrden(raiz->izq);
		//recurrsividad
		postOrden(raiz->der);
		imprimir(raiz);
	}
}

int main(){
	
	_nodo *raiz;
	
	raiz = crear('+');
	raiz->izq = crear('*');
	raiz->der = crear('=');
	
	raiz->izq->izq = crear('A');
	raiz->izq->der = crear('B');
	
	raiz->der->izq = crear('/');
	raiz->der->izq = crear('C');
	raiz->der->izq = crear('D');
	
	raiz->der->der = crear('2');
	
	//vamos a impriomir el arbol
	printf("\n Preorden (RDI): \n");
	preOrden(raiz);
	printf("\n Inorden (IRD): \n");
	inOrden(raiz);
	printf("\n Postorden (IDR): \n");
	postOrden(raiz);
	
	printf("\n");
	return 0;
	
}
