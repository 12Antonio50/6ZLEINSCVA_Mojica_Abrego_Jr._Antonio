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
int da;
int buscar(int d);
void insertar(int dat);
void mostrar(void);
void borrar(void);
void menu(void);
void guardar(void);
void cargar (void);

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
		cout<<"\n1. Buscar dato";
		cout<<"\n2. Insertar dato";
		cout<<"\n3. Mostrar dato";
		cout<<"\n4. Borrar dato";
		cout<<"\n5. Guardar dato en un archivo";
		cout<<"\n6. Cargar dato en un archivo";
		cout<<"\n7. Salir";
		cout<<"\n1. Seleccione la opcion deseada: ";
		cin>>opc;
		
		switch(opc){
			case 1:
				//buscar
				cout<<"\n Ingresa el dato a buscar: ";
				cin>>da;
				if(buscar(da)){
					cout<<"Dato si existe"<<endl;
				}else{
					cout<<"El dato no existe"<<endl;
					getch(); //pausa
				}
				break;
			case 2:
				cout<<"\n Ingresa el dato: ";
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
				break;
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
					cout<<"Opcion invalida"<<endl;
					getch();
		}
	}while(opc);
}

void mostrar(void){
	int cont = 1;
	//saber si hay lista
	if(!i){
		cout<<"No hay lista para mostrar"<<endl;
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
	cout<<"\n Fin de la lista"<<endl;
	getch();
	
}
//buscar
int buscar(int d){
		//saber si hay lista
	if(!i){
		cout<<"No hay en la lista para mostrar"<<endl;
		getch();
		return(0);
	}
	//si hay 
	p = i;
	a = NULL;
	
	while(p ->s  && p ->i < d){
		//recorrer los valoeres de la lista 
		a = p;
		p = p->s;
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
void insertar(int dat){
	//saber si essta vacia la lista
	if(!i){
		i=new(dato);
		i->s=NULL;
		i->i=dat;
		return;
	}
	/*
	supongamos que tenemos los siguentes datos
	nodo1 = -3, nodo2 = 0, nodo3 = 5
	insertar 3
	*/
	if(buscar(dat)){
		cout<<"\t\nDato existente"<<endl;
		getch();
		return;
	}
	e=new(dato);
	e->i=dat;
	if(p==i && p->s){
		e->s=p;
		i=e;
		return;
	}
	if(p==i && !p->s){
		//primero hago la comparacion
		if(p->i < e->i){
			//final
			p->s=e;
			e->s=NULL;
		}else{
			e->s=p;
			i=e;	
		}
		return;
	}
	if(p->s){
		a->s=e;
		e->s=p;
		return;
	}
	if(e->i > p->i){
		e->s=NULL;
		p->s=e;
	}else{
		a->s=e;
		e->s=p;
	}
}
//borrar
void borrar(void){
	cout<<"\n Ingresa el dato que deseas borrar: ";
	cin>>da;
	if(buscar(da)){
		if(a){
		a->s = p->s;
	}else{
		i = p ->s;
	}
	delete (p);
	cout<<"\n Dato eliminado"<<endl;
}else{
	cout<<"\n Dato no encontrado"<<endl;
	getch();
}
}

void guardar(void){
	FILE *archivo;
	archivo =fopen("GUARDAR.TXT","w");
	if(!i){
		cout<<"\nNo se encuentra la lista para guardar"<<endl;
		getch();
		return;
	}
	p = i;
	while(p){
		fprintf(archivo, "%i\n", p->i);
		p = p->s;
	}
	cout<<"\n\n Archivo guardado"<<endl;
	fclose(archivo);
	getch();
}

void cargar (void){
	int c, x;
	FILE *archivo;
	archivo = fopen("GUARDAR.TXT", "r");
	if(!archivo){
		cout<<"\nNo exixte el archivo"<<endl;
		getch();
		return;
	}
	do{
		c=fscanf(archivo,"%i\n",&x);
		if(c!=EOF){
			insertar(x);
		}
	}while(c!=EOF);
	
	cout<<"\nArchivo guardado"<<endl;
	fclose(archivo);
	getch();
	
	}
	












