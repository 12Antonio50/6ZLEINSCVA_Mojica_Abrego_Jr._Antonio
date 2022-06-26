/*
Ejemplo de una pila de alumnos matriculados 
*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

//definir la cola 
struct ICO{
	char nombre[30];
	char clave[30];
	float calificacion;
};
//definir el nodo 
struct Nodo{
	ICO alumnos;
	Nodo *siguiente;
}*i,*p;

//metodos 
void menu();
void agregarDatos(ICO &);
void insertarDatos(Nodo *&, Nodo *&, ICO);
bool c_vacia(Nodo *);
void  buscar(ICO &alumnos, string c_clave);
void guardar(void);
void cargar(void);

int main(){
	
	//definir cola 
	ICO alumnos;
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	string c_clave;
	int opcion;
	
	do{
		menu();
		cin>>opcion;
		//borrar el buffer
		fflush(stdin);
		//nodo auxiliar 
		Nodo *aux = frente;
		
		switch(opcion){
			case 1:	
				agregarDatos(alumnos);
				insertarDatos(frente, fin, alumnos);
				break;
			case 2:
				cout<<"\n CLAVE\t"<<"NOMBRE\t"<<"CALIFICACION\n";
				while(aux != NULL){
					cout<<" "<<aux->alumnos.clave<<"\t"<<aux->alumnos.nombre<<"\t"<<aux->alumnos.calificacion<<"\t"<<endl;
					aux = aux->siguiente;
				}
				break;
			case 3:
				cout<<"\nIngrese la clave del alumno: \n"<<endl;
				cin>>c_clave;
				
				
				buscar(alumnos, c_clave);
				break;
			case 4:
				guardar();
				break;
			case 5:
				//cargar();
			default:
				cout<<"\nOpcion no valida \n";
				break;
				
		}
		
		cout<<"\nPresionar una tecla para continuar\n";
		getch();
		system("cls");
		
	}while(opcion != 6);
	
	return 0;
}

void menu(){
	cout<<"\nMENU DE ALUMNOS MATRICULADOS\n";
	cout<<"\n1.- Agregar datos del alumno\n";
	cout<<"\n2.- Mostrar datos del alumno\n";
	cout<<"\n3.- Buscar alumno\n";
	cout<<"\n4.- Guardar en txt\n";
	cout<<"\n5.- Cargar en txt\n";
	cout<<"\n6.- SALIR\n";
}

void agregarDatos(ICO &alumnos){
	cout<<"\nIngresar nombre del alumno:\n";
	cin.getline(alumnos.nombre, 30, '\n');
	
	cout<<"\nIngresar clave del alumno:\n";
	cin>>alumnos.clave;

	cout<<"\nIngresar calificacion del alumno:\n";
	cin>>alumnos.calificacion;
	
}

void insertarDatos(Nodo *&frente, Nodo *&fin, ICO alumnos){
	//declaramos un nuevo nodo
	Nodo *n_nodo = new Nodo();
	
	//asignar al nuevo nodo el dato a insertar
	n_nodo -> alumnos = alumnos;
	
	
	
	if (c_vacia(frente)){
		//si la cola esta vacia
		frente = n_nodo;
	}else{
		//si la cola no esta vacia siguiente
		fin ->siguiente = n_nodo;
	}
	
	//debemos apuntar a donde el siguiente elemento
	n_nodo -> siguiente= NULL;
	
}

bool c_vacia(Nodo *frente){
	//si frente es igual a null la cola esta vacioa
	return (frente == NULL)? true:false;
}

void buscar(ICO &alumnos, string c_clave){
	struct Nodo *aux = new struct Nodo();
	string a_aux;
	
	a_aux = aux->alumnos.clave;
	
	while(a_aux !=  c_clave) aux = aux->siguiente;
		
	
	agregarDatos(alumnos);
}

void guardar (void){

	FILE *archivo;
	archivo= fopen("GUARDAR.TXT", "w");
	p=i;
	while(p){
		fprintf(archivo, "%i\n", p->alumnos.nombre);
		fprintf(archivo, "%i\n", p->alumnos.clave);
		fprintf(archivo, "%i\n", p->alumnos.calificacion);
		p = p->siguiente;
	}
	cout<<"Archivo guardado"<<endl;
	fclose(archivo);
}
