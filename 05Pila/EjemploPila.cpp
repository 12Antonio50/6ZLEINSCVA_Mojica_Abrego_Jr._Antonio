/*
crear una pila como elemento basico 
para poder demostrar que las 
primeras entradas son las ultimas salidas
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

//definir pila 
struct Nodo{
	int valor;
	Nodo *siguente;
};

//metodos 
void insertarPila(Nodo *&, int);
void mostrarPila(Nodo *&);
void eliminarPila(Nodo *&, int);


int main(){
	/*
	el primero en entrar es el ultimo de salir y el ultimo
	es elprimero en salir
	*/
	int cantidad, i=0, op=1, v=0;
	//primera definicion de la pila 
	Nodo *pila = NULL;
	while(op=4){
		cout<<"selecciona la opcion deseada"<<endl;
		cout<<"1.-Insertar dato:"<<endl;
		cout<<"2.-Mostrar valores:"<<endl;
		cout<<"3.-Eliminar valores:"<<endl;
		cout<<"4.-SALIR"<<endl;
		cin>>op;
		
		switch(op){
			case 1:
				cout<<"Ingresar la cantidad de datos: "<<endl;
				cin>>cantidad;
			while(i<cantidad){
				cout<<"Ingresa el valor: "<<endl;
				cin>>v;
				insertarPila(pila, v);
				i++;	
			}	
			break;
			case 2:
				mostrarPila(pila);
				break;
			case 3:
				//saber si esta vacia la pila
				if(pila==NULL){
					cout<<"No se puede eliminar la pila esta vacia"<<endl;	
				}else{
					cout<<"Eliminar dato\n";
					while(pila!=NULL){
						eliminarPila(pila, v);
						if(pila!=NULL){
							cout<<" | "<<endl;	
						}else{
						cout<<" * "<<endl;
						}
					}
				}
				break;
			default:
				cout<<"Opcion incorrecta\n";
		}
	}
	return 0;
}

void insertarPila(Nodo *&, int v){
	Nodo *insPila = new Nodo();
	insPila->valor= v;
//	insPila->siguente=pila;
	pila = insPila;
}

void mostarPila(Nodo *&pila){
	//necesistamos un elemento que almacene valores
	Nodo *aux;
	
	if(pila==NULL){
		cout<<"La pila esta vacia\n";
	}else{
		aux = pila;
		while(aux!=NULL){
			cout<<"Valor: "<<aux->valor<<endl;
			aux = aux->siguente;
		}
	}
}

void eliminarPila(Nodo *&pila, int &v){
	Nodo *aux = pila;
	v = aux->valor;
	pila = aux->siguente;
	delete aux;
}

