#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

//Estructura del nodo
struct nodo{
	string dato;
	float dinero;
	int prioridad;
	int turno;
	struct nodo *siguiente;
};

//Estructura de la cola
struct cola{
	nodo *delante;
	nodo *atras;
};

//Crear un nuevo nodo
struct nodo *crearNodo(string dat , float dine, int pri, int tur){
	struct nodo *nuevoNodo = new (struct nodo);
	nuevoNodo->dato=dat;
	nuevoNodo->dinero=dine;
	nuevoNodo->prioridad=pri;
	nuevoNodo->turno=tur;
	return nuevoNodo;
}

void encolar(struct cola &q, string valor, int priori, float din, int turn){
	//Auxiliar
	struct nodo *aux = crearNodo(valor, din, priori, turn);
	aux->siguiente=NULL;
	
	if(q.delante == NULL){
		//Primero en encolar
		q.delante=aux;
	}else{
		(q.atras)->siguiente = aux;
	}
	//Aux apunta al final
	q.atras = aux;
}

void mostrarCola(struct cola q){
	//Auxilir
	struct nodo *aux;
	aux = q.delante;
	cout<<"\nDatos con prioridad\n";
	cout<<"1.- VIP"<<endl;
	cout<<"2.- EMPRESARIAL"<<endl;
	cout<<"3.- NORMAL"<<endl;
	cout<<"4.- NINGUNA"<<endl;
	while(aux != NULL){
		//Hay datos
		cout<<"Nombre: "<<aux->dato<<" Prioridad: "<<aux->prioridad<<" Dinero $"<<aux->dinero<<" Su turno es: "<<aux->turno<<endl;
		aux = aux->siguiente;
	}
}

void ordenarPrioridad(struct cola &q){
	//criterio de 0 como prioridad
	//el numero mayor es la mas alta
	
	struct nodo *aux1, *aux2;
	int p_aux;
	string c_aux;
	float d_aux;
	
	aux1 = q.delante;
	
	while(aux1->siguiente != NULL){
		aux2 = aux1->siguiente;
		while(aux2!=NULL){
			if(aux1->prioridad > aux2->prioridad){
				p_aux = aux1->prioridad;
				c_aux = aux1->dato;
				d_aux = aux1->dinero;
				
				aux1->prioridad = aux2->prioridad;
				aux1->dato = aux2->dato;
				aux1->dinero = aux2->dinero;
				
				aux2->prioridad = p_aux;
				aux2->dato = c_aux;
				aux2->dinero = d_aux;
			}
			aux2=aux2->siguiente;
		}
		aux1 = aux1->siguiente;
	}
}
void insertar(struct cola &q, string c, int diner, int pri, int turn){
	//Encolar
	encolar(q, c, diner, pri, turn);
	ordenarPrioridad(q);
}
void menu(){
	cout<<"\t\t\t\t\t|****Ejemplo de colas de prioridad***|"<<endl;
	cout<<"\t\t\t\t\t|1.- Asignar turno                   |"<<endl;
	cout<<"\t\t\t\t\t|2.- Realizar la operacion           |"<<endl;
	cout<<"\t\t\t\t\t|3.- Mostrar tarjetahabientes en fila|"<<endl;
	cout<<"\t\t\t\t\t|4.- Salir                           |"<<endl;
	cout<<"\t\t\t\t\t|************************************|\n";
}
void menu2(){
	cout<<"\t\t\t\t\t|*****TIPOS DE CUENTAS******|"<<endl;
	cout<<"\t\t\t\t\t|1.- VIP                    |"<<endl;
	cout<<"\t\t\t\t\t|2.- EMPRESARIAL            |"<<endl;
	cout<<"\t\t\t\t\t|3.- NORMAL                 |"<<endl;
	cout<<"\t\t\t\t\t|4.- NINGUNA                |"<<endl;
	cout<<"\t\t\t\t\t|***************************|\n";
}
int main(){
	system("color 5F");
	struct cola q;
	
	q.delante = NULL;
	q.atras = NULL;
	
	string c;
	int priori;
	float diner;
	int turn;
	int op, op2;
	int x;
	
	do{
		menu();
		cin>>op;
		switch(op){
			case 1:
				cout<<"\nIngreses su nombre: \n";
				cin>>c;
				do{
				menu2();
				cin>>priori;
				if(priori<0||priori>4) cout<<"Error ingresa una opcion correcta\n";
				}while(priori<0||priori>4);
				
				cout<<"Ingresar turno: \n";
				cin>>turn;
				cout<<"\n Usuario: "<<c<<" ingresado\n";
				break;
				
			case 2:
				do{
				cout<<"\nIngreses una cantidad de dinero a su cuenta $\n";
				cin>>diner;
				if(diner<0||diner>5000) cout<<"Error ingresa una opcion correcta\n";
				}while(diner<0||diner>5000);
				
				insertar(q, c, priori, diner, turn);
				
				break;
				
			case 3:
				cout<<"\n Mostrar elementos de la cola: \n";
				if(q.delante!=NULL){
					mostrarCola(q);
				}else{
					cout<<"\n La cola esta vacia\n";
				}
				break;
				
			default:
				cout<<"Ingrese una opcion valida\n";
				system("pause");
				exit(0);
			}
		system("pause");
	system("cls");
	}while(op!=4);
	return 0;
}
