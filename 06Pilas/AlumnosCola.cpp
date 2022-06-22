/*
Ejemplo de una pila de alumnos matriculados 
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

//definir la cola 
struct ICO{
	char clave[20];
	char nombre[30];
	float calificacion;
};
//definir el nodo 
struct Nodo{
	ICO alumnos;
	Nodo *siguiente;
};

//metodos 
void menu();
void agregarDatos(ICO &);
void insertarDatos(Nodo *&, Nodo *&, ICO);
bool c_vacia(Nodo *);

int main(){
	
	//definir cola 
	ICO alumnos;
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	char opcion;
	
	do{
		menu();
		cin>>opcion;
		//borrar el buffer
		fflush(stdin);
		//nodo auxiliar 
		Nodo *aux = frente;
		
		switch(opcion){
			case '1':	
				agregarDatos(alumnos);
				insertarDatos(frente, fin, alumnos);
				break;
			case '2':
				cout<<"\n La clave \t"<<"NOMBRE\t"<<"CALIFICACION\n";
				while(aux != NULL){
					cout<<aux->alumnos.clave<<"\t"<<aux->alumnos.nombre<<"\t"<<aux->alumnos.calificacion<<"\t"<<endl;
					aux = aux->siguiente;
				}
				break;
			case '3':
				cout<<"\nAdios\n";
				break;
			default:
				cout<<"\nOpcion no valida \n";
				break;
				
		}
		
		getch();
		cout<<"Presionar una tecla para continuar\n";
		system("cls");
	}while(opcion != '3');
	
	return 0;
}

void menu(){
	cout<<"\nMENU DE ALUMNOS MATRICULADOS\n";
	cout<<"\n1.- Agregar datos del alumno\n";
	cout<<"\n2.- Mostrar datos del alumno\n";
	cout<<"\n3.- SALIR\n";
}

void agregarDatos(ICO &alumnos){
	cout<<"\nIngresar clave del alumno:\n";
	cin.getline(alumnos.clave, 20, '\n');
	
	cout<<"\nIngresar nombre del alumno:\n";
	cin.getline(alumnos.nombre, 30, '\n');
	
	cout<<"\nIngresar calificacion del alumno:\n";
	cin>>alumnos.calificacion;
	
}

void insertarDatos(Nodo *&frente, Nodo *&fin, ICO alumnos){
	//declaramos un nuevo nodo
	Nodo *n_nodo = new Nodo();
	
	//asignar al nuevo nodo el dato a insertar
	n_nodo -> alumnos = alumnos;
	
	//debemos apuntar a donde el siguiente elemento
	n_nodo -> siguiente= NULL;
	
	if (c_vacia(frente)){
		//si la cola esta vacia
		frente = n_nodo;
	}else{
		//si la cola no esta vacia siguiente
		fin ->siguiente = n_nodo;
	}
	
}

bool c_vacia(Nodo *frente){
	//si frente es igual a null la cola esta vacioa
	return (frente == NULL)? true:false;
}



