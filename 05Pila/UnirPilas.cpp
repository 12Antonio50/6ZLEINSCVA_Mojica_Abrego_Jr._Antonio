/*
vamos a programar dos pilas que sirvan para porder unir ambos elementos 
el programa debe de contener ingresar el tamaño de la pila un menu 
push, pop y mostrar los elementos de la pila
*/

#include <iostream>
#include <conio.h>

using namespace std;

//vamos a definir una pila dentro de otra pila 

struct nodo{
	int nro;
	struct nodo *siguente;
};

//definir una estructura de la pila 
typedef nodo *pila;

//metodos del programa 
void imprimir1(pila);
void imprimir2(pila);
void eliminarPila(pila &);
void push(pila &, int);
void unir(pila, pila);
int pop(pila &);

main(){
	//declarar las pilas 
	pila p1 = NULL;
	pila p2 = NULL;
	pila p3 = NULL;
	
	int opc, n, valor, i;
	
	do{
		cout<<"1.- Apilar\n";
		cout<<"1.- Ver la pila\n";
		cout<<"1.- Unir la pila\n";
		cout<<"1.- Salir\n";
		cout<<"Ingresar la opcion deseada: \n";
		
		cin>>opc;
		
		switch(opc){
			case 1:
				cout<<"Ingrese el limite de la pila 1: \n";
				for(i = 0; i<n; i++){
					cout<<"Valor: \n";
					cin>>valor;
					push(p1, valor);
				}
				cout<<"Ingrese el limite de la pila 2: \n";
				for(i = 0; i<n; i++){
					cout<<"Valor: \n";
					cin>>valor;
					push(p2, valor);
				}
				break;
			case 2:
				cout<<"Contenido de la pila 1: \n";
				imprimir1(p1);
				cout<<"Contenido de la pila 1: \n";
				imprimir2(p2);
				break;
			case 3:
				cout<<"Pilas unidas ";
					unir(p1, p2);
				break;	
		}
	}while(opc!=4);
}
void push(pila &p, int n){
	pila q = (struct nodo);
	q->nro = n;
	q->siguente =p;
	p = q;
}

void unirPila(pila p1, pila p2){
	pila q = p1;
	while(q->siguente !=NULL){
		q=q->siguente;
		q->siguente=p2;
	}
	while(p1 !=NULL){
		
	}
}
