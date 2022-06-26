/*
ejemplo de una cola 
primeras entradas 
primeras salidas
*/
#include <iostream>

using namespace std;
//definir estructura base 

struct nodo{
	int nro;
	struct nodo *siguiente;
};

//estructura cola
struct cola{
	nodo *delantera;
	nodo *atras;
};

//encolar
void encolar(struct cola &q, int valor){
	//aux del nodo para meterlo a la cola
	struct nodo *aux = new (struct nodo);
	
	aux->nro= valor;
	aux->siguiente= NULL;
	
	if(q.delantera==NULL){
		//es el primero en entrar
		q.delantera=aux;
	}else{
		(q.atras)->siguiente=aux;
	}
	//el puntero debe de apuntar al ultimo
	q.atras = aux;
	
	
}

//desencolar
int desencolar(struct cola &q){
	int num;
	struct nodo *aux;
	
	//aux apunte al inicio de la cola
	aux = q.delantera;
	num = aux->nro;
	q.delantera = (q.delantera)->siguiente;
	//liberar memoria del apuntador 
	delete(aux);
	
	return num;
}

void muestraCola(struct cola q){
	//necesitamos el axiliar
	struct nodo *aux;
	//donde esta el inicio de la cola 
	aux=q.delantera;
	//si la cola esta vacia 
	while(aux!=NULL){
		cout<<" "<<aux->nro;
		aux= aux->siguiente;
	}
}

void vaciaCola(struct cola &q){
	//auxiliar
	struct nodo *aux;
	while(q.delantera !=NULL){
		aux = q.delantera;
		q.delantera = aux->siguiente;
		delete(aux);
	}
	q.delantera = NULL;
	q.atras = NULL;
}

void menu(){
	cout<<"Ejemplo de cola\n";
	cout<<"1.- Encolar\n";
	cout<<"2.- Desencolar\n";
	cout<<"3.- Mostrar cola\n";
	cout<<"4.- Vaciar cola\n";
	cout<<"1.- SALIR\n";
	
}
int main(){
	//definir la cola
	struct cola q;
	q.delantera = NULL;
	q.atras = NULL;
	
	//variables
	int dato, op, x;
	
	do{
		menu();
		cin>>op;
		switch(op){
			case 1:
				cout<<"\nNumero a encolar\n";
				cin>>dato;
				encolar(q, dato);
				cout<<"\n Numero :"<<dato<<" encolado.\n";
				break;
			case 2:
				x = desencolar(q);
				cout<<"\n Numero :"<<x<<" Desencolada\n";
				break;
			case 3:
				cout<<"\n Mostrar cola\:n";
				if(q.delantera != NULL) muestraCola(q);
				else cout<<"\n Cola vacia\n";
				break;
			case 4:
				vaciaCola(q);
				cout<<"\nCola vacia ";
				break;
		}
	}while(op !=5);
	return 0;
}

