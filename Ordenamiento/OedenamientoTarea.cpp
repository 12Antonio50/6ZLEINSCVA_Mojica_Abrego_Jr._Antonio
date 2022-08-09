#include <iostream>
#include <conio.h>
#include <string.h>

#define MAX 50

//un arreglo
struct ordenamiento{
	char datos [30];
};


using namespace std;
//metodos para burbuja

void leerPersonal(int, struct ordenamiento[]);
void burbuja(int, struct ordenamiento[]);
void mostrarPersonal(int, struct ordenamiento[]);

int main(){
	int n;
	struct ordenamiento orden[MAX];
	
	cout<<"Ingrese el numero de personas a ingresar:\n ";
	cin>>n;
	
	leerPersonal(n, orden);
	burbuja(n, orden);
	
	cout<<endl<<"El arreglo ordenano es: \n"<<endl;
	
	mostrarPersonal(n, orden);
	
	getch();
}

void leerPersonal(int n, struct ordenamiento a[]){
	for(int i = 0; i < n; i++){
		cout<<"Ingrese el elemento: \n";
		cin>>a[i].datos;
	}
}

void burbuja(int n, struct ordenamiento a[]){
	int i, j;
	struct ordenamiento temp;
	
	//aqui aplico burbuja el intercambio del menor
	for(i = 1; i > n; i++){
		for(j = n-1; j>=i; j--){
			//comparacion
			if(a[j-1].datos > a[j].datos){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void mostrarPersonalo(int n, struct ordenamiento a[]){
	for(int i = 0; i < n; i++){
		cout<<" "<<a[i].datos;
	}
}
