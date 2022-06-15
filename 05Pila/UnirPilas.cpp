/*
vamos a programar dos pilas que sirvan para porder unir ambos elementos 
el programa debe de contener ingresar el tama?o de la pila un menu 
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
void unirPilas(pila , pila );
int pop(pila &);

main(){
	//declarar las pilas 
	pila p1 = NULL;
	pila p2 = NULL;
	pila p = NULL;
	
	int opc, n, valor, i;
	
	do{
		cout<<"1.- Apilar\n";
		cout<<"2.- Ver la pila\n";
		cout<<"3.- Unir la pila\n";
		cout<<"4.- Eliminar elementos\n";
		cout<<"5.- Desapilar\n";
		cout<<"6.- Salir\n";
		cout<<"Ingresar la opcion deseada: \n";
		
		cin>>opc;
		
		switch(opc){
			case 1:
				cout<<"Ingrese el limite de la pila 1: \n";
				cin>>n;
				for(i = 0; i<n; i++){
					cout<<"Valor: \n";
					cin>>valor;
					push(p1, valor);
				}
				cout<<"Ingrese el limite de la pila 2: \n";
				cin>>n;
				for(i = 0; i<n; i++){
					cout<<"Valor: \n";
					cin>>valor;
					push(p2, valor);
				}
				break;
			case 2:
				cout<<"Contenido de la pila 1: \n";
				imprimir1(p1);
				cout<<"Contenido de la pila 2: \n";
				imprimir2(p2);
				break;
			case 3:
				cout<<"Pilas unidas"<<endl;
        		unirPilas(p1,p2);
        		break;	
				
			case 4:
				eliminarPila(p1);
				cout<<"Pila uno y dos destruidas\n";
				eliminarPila(p2);
				break;
			case5:
				if(p1!=NULL){
					cout<<"Valor Eliminado";
					n=pop(p1);
					cout<<n<<endl;
				}else
					cout<<"Pila vacia"<<endl;
				break;
		}
	}while(opc!=6);
}
void push(pila &p, int n){
	pila q = new(struct nodo);
	q->nro = n;
	q->siguente =p;
	p = q;
}

int pop(pila &p){
	int n=p->nro;
	pila q=p;
	p=p->siguente;
	delete (q);
	return n;
}

void eliminarPila(pila &p){
pila q;
  while(p!=NULL){
	q=p;
	p=p->siguente;
	delete(q); 
	}
}
void unirPilas(pila p1, pila p2){
  pila q=p1;
  while(q->siguente!=NULL)
  q=q->siguente;
  q->siguente=p2;
}
void imprimir1(pila p1){
	while(p1!=NULL){
		cout<<p1->nro<<endl;
		p1=p1->siguente;
	}
	cout<<endl;
}
void imprimir2(pila p2){
	while(p2!=NULL){
		cout<<p2->nro<<endl;
		p2=p2->siguente;
	}
	cout<<endl;
}
