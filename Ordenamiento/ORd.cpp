#include <iostream>
#include <string.h>
#include <string>
#include <fstream>


#define MAX 100

using namespace std;

struct date{
	int dia;
	int mes;
	int anio;
};



struct lista{
	string nom;
	string apellido;
	int codigo;
};


void leerPersona(int, struct lista [], struct date []);
void ordenarPersonal(int, struct date []);
void mostrarPersonal(int, struct lista [], struct date []);
void insertarTxt(int, struct lista [], struct date []);

int main(){
	int n;
	struct lista orden[MAX];
	struct date order[MAX];
	
	cout<<"Ingrese el limite de personas:\n ";
	cin>>n;
	
	leerPersona(n, orden, order);
	ordenarPersonal(n,order);
	
	cout<<endl<<"El arreglo ordenano es: \n"<<endl;
	
	mostrarPersonal(n, orden, order);
	insertarTxt(n, orden, order);
}



void leerPersona(int n, struct lista a[], struct date b[]){
	for(int i = 0; i < n; i++){
		cout<<"Ingrese el nombre: "<<endl;
		cin>>a[i].nom;
		cout<<"Ingrese el primer apellido: "<<endl;
		cin>>a[i].apellido;
		cout<<"Ingrese el codigo: "<<endl;
		cin>>a[i].codigo;
		cout<<"Ingrese el dia de nacimiento: "<<endl;
		cin>>b[i].dia;
		cout<<"Ingrese el mes de nacimiento: "<<endl;
		cin>>b[i].mes;
		cout<<"Ingrese el anio de nacimiento: "<<endl;
		cin>>b[i].anio;
	}
}

void ordenarPersonal(int n, struct date b[]){
	struct date temp;
	int i,j;
	
	for(i = 1; i < n; i++){
		for(j = n-1; j>=i; j--){
			//comparacion
			if(b[j-1].anio > b[j].anio){
				temp = b[j-1];
				b[j-1] = b[j];
				b[j] = temp;
			}
		}
	}
}

void insertarTxt(int n, struct lista a[], struct date b[]){
	ofstream file;
	file.open("Burbuja");
	for(int i = 0; i < n; i++){
	file<<" \n"<<a[i].nom;
	file<<" "<<a[i].apellido;
	file<<" "<<a[i].codigo;
	file<<" "<<b[i].dia;
	file<<" "<<b[i].mes;
	file<<" "<<b[i].anio;
	
	}
}

void mostrarPersonal(int n, struct lista a[], struct date b[]){
	for(int i = 0; i < n; i++){
		cout<<" \n"<<a[i].nom;
		cout<<" "<<a[i].apellido;
		cout<<" "<<a[i].codigo;
		cout<<" "<<b[i].dia;
		cout<<" "<<b[i].mes;
		cout<<" "<<b[i].anio;
	}
}
