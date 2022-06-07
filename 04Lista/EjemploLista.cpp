/*
una lista es una estructura de datos que deriva una secuenciia conectada con nodos y cada uno de los cuales contiene un dato
hay un nodo al comienzo llamado la cabeza o frente
hay un nodo del termino llamado cola o atras

la lista solo puede ser recorrida en secuencia de atras o hacia delante

operaciones de su propia estructura 

añadir o insertar elemento
mover atraves de la lista de pri a fin
buscar elementos

apuntadores 

& memoria
* al dato
-> asigna

ejemplo

nodo *elemento -> &elemento -> valor

en C++ vamos a ocupar list ya que es una clase de tipo templete nos permite crear listas que contengan cualquier tipo de objeto

las operaciones que se pueden incluir en la lista son:

push meter 
pop sacar

begin() 
end()

size()
empty()

*/

#include <iostream>

using namespace std;

//definir la estructura de la lista
struct Nodo{
	//los valores de la lista
	int valor ;
	Nodo *siguiente;
};


//definir los metodos 
void insertarlista(Nodo *&, int);
void mLista(Nodo *);

int main(){
	//declarar mi variable de la lista que apunte a null
	Nodo *lista = NULL;
	//variables
	int op=1, c, i=0, valores;
	cout<<"Trabajando con listas(simples, doblemente enlazadas, circulares y circulares dobles)"<<endl;
	while(op!=3){
		cout<<"Ejemplo de lista simple: "<<endl;
		cout<<"1.- Insertar nuevo valor "<<endl;
		cout<<"2.- Ver la lista "<<endl;
		cout<<"3.- Salir "<<endl;
		cin>>op;
		switch(op){
			case 1:
				cout<<"Indica el numero de valores a introducir\n";
				cin>>valores;
				while(i<valores){
					cout<<"Valor["<<i<<"]\n";
					cin>>c;
					i++;
					//insertar el valor
					insertarlista(lista,c);
					}
					break;
			case 2:
			/*	cout<<"Mostrar los valores de la lista\n";
				cout<<"Imprimir valores\n";*/
				mLista(lista);
				break;
			default:
			         cout<<"Gracias\n";
		}
		
	}
	return 0;
	
}


void insertarlista(Nodo *&lista, int c){
//crear una nueva lista
	Nodo *inslista = new Nodo();
//debo de asigar el valor de la lista
	inslista->valor = c;
//necesitar un auxiliar para encadenar los valores de la lista
	Nodo *aux1= lista;
	Nodo *aux2;
//meter los valores de la forma ordenada 
	while ((aux1 != NULL)&& (aux1->valor < c)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if (lista == aux1){
		lista = inslista;
	}else{
		aux2->siguiente = inslista;
	}
	inslista->siguiente = aux1;

	cout<<"Elemento "<<c<<" insertado\n\n";
}

void mLista(Nodo *lista){
	Nodo *lis = new Nodo();
	lis = lista;
	
	while(lis != NULL){
		cout<<">><<"<<lis->valor<<">><<\n"<<endl;
		lis = lis->siguiente;
	}
	if(lista == NULL){
		cout<<"\nLista vacia\n"<<endl;
	}
}
