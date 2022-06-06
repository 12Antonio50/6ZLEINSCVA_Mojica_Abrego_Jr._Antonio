//lista con apuntadores
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>

/*
stdio es la libreria estandar de ++
para manejo de entradas y salidas en consola 

stdlib es la libreria estandar de estructuras 
de datos en c++ ára listas, pilas, cilas, árbol y grafos 

conio es la libreria estandar para el manejo de manipulacion de la pantalla, pausar, colores,
manipulacion de ventanas
*/

using namespace std;
//definicion de la lita 

struct dato{
	int i;
	dato *s;//nodo siguiente
}*a, *i, *p, *e;

//metodos
int buscar(int d);
void insertar(void);
void mostrar(void);
void borrar(void);
void menu(void);
//void guardar(void);
//void cargar (void);

//principal
main(){
	menu();
}
//menu

void menu(void){
	int opc, da;
	do{
		
		//imprimir menu
		cout<<"Ejemplo de una lista con apuntadores"<<endl;
		cout<<"\n1. buscar dato";
		cout<<"\n2. insertar dato";
		cout<<"\n3. mostrar dato";
		cout<<"\n4. borrar dato";
		cout<<"\n5. guardar dato en un archivo";
		cout<<"\n6. cargar dato en un archivo";
		cout<<"\n7. salir";
		cout<<"\n1. Seleccione la opcion deseada";
		cin>>opc;
		
		switch(opc){
			case 1:
				//buscar
				cout<<"\n Ingresa el dato a buscar";
				cin>>da;
				if(buscar(da)){
					cout<<"Dato si existe";
				}else{
					cout<<"El dato no existe";
					getch(); //pausa
				}
				break;
			case 2:
				cout<<"\n Ingresa el dato";
				cin>>da;
				insertar(da);
				break;
			case 3:
				//mostrar
				mostrar();
				break;
			case 4:
				//borrar
				borrar();
				break:
			case 5:
				//guardar
				guardar();
				break;
			case 6:
				//cargar
				cargar();
				break;
			case 7:
				//salir
				cout<<"Adios";
				getch;
				//antes de salir del progroma hay que borrar todos los datos de la lita
			
				p = i;
				while(p){
					a = p;
					p = p->s;
					delete(a);	
				}
				//salir 
				exit(0);
				
			default:
					cout<<"Opcion invalida";
					getch();
		}
	}while(opc);
}

void mostrar(void){
	int cont = 1;
	//saber si hay lista
	if(!i){
		cout<<"No hay lista para mostrar";
		getch();
		return;
	}
	p = i;
	cout<<"\n\n";
	/*como si ecxiste un dato para la lista tenemos que empezar a recorrerla 
	por cada uno de los elementos 
	*/
	while(p){
		cout<<cont++<<"\nValor : "<<p->i<<endl;
		p = p -> s;
	}
	cout<<"\n Fin de la lista";
	getch();
	
}
//buscar
int buscar(int d){
		//saber si hay lista
	if(!i){
		cout<<"No hay en la lista para mostrar";
		getch();
		return;
	}
	//si hay 
	p = i;
	a = NULL;
	
	while(p ->s  && p ->i < d){
		//recorrer los valoeres de la lista 
		a = p;
		p = P->s;
	}
	return (p->i == d?1:0);
}
/*
 para insertar cuantos caminos hay?
 1. la primera vez que se inserta un dato
  se debe de crear el nodo y verificar los apuntadores 
2. enmedio 
 se debe de buscar donde se va a ingresar debe de acomodar el 
 apuntador anterior y el apuntador siguiente (apuntador que apunta)
3. final solo se apunta y se ajusta el apuntador 

*/
void insertar(int da){
	//saber si esta vacia la lista
	if(!i){
		
		//es la primera vez que se mete un dato
		i= new(dato);
		i->s=NULL;
		i->i = dat;
		return;
	}
	if(buscar(dat)){
		//porque si existe 
		cout<<"El dato existe";
		getch();
		return;
	}
	/*
	supongamos que tenemos lo sig. 
	nodo1 = -3, nodo2 =0, nodo3 = 5
	insertar 3
	
	*/
	
	e = new (dato);
	
	e->i =dato;
	
	
	if(p == i && p -> s){
		//promero hago la comparacion
		if (p ->i < e->i){
		//fina 	
			p->s =e;
			e->s = NULL;
		}else{
			e->s = p;
			i=e;
		}
		return;
	}
	if(p->s ){
		a ->s =e;
		e ->s P;
		return;
	}
	if (e ->i > p->i ){
		e -> s =NULL;
		p->s = e;
	}else{
		a->s = e;
		e->s= p;
		
	}
}
//borrar
void borrar(void){
	cout<<"\n Ingresa el dato que deseas borrar";
	cin>>da;
	if(buscar(da)){
		if(a){
		a->s = p->s;
	}else{
		i = p ->s;
	}
	delete (p);
	cout<<"\n Dato eliminado";
}else{
	cout<<"\n Dato no encontrado";
	getch();
}
}










