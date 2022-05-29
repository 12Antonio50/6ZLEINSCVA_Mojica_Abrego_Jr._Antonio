#include <iostream>

using namespace std;

int main(){
	int fila, columna;
	cout<<"MATRIZ TRANSPUESTA"<<endl;
	do{
		cout<<"Ingresa el numero de filas: ";cin>>fila;
		cout<<"Ingresa el numero de columnas: ";cin>>columna;
		
		if(fila <=0 || columna <=0){
			cout<<"Error"<<endl;
		}	
	}while(fila <=0 || columna <=0);
	
	int matriz[fila][columna];
	
	cout<<"Armando la matriz"<<endl;
	for(int i =0; i<fila; i++){
		for(int a =0; a<columna; a++){
		cout<<"Ingresa un numero "<<i+1<<" "<<a+1<<": ";
		cin>>matriz[i][a];
		}
	}
	for(int i=0; i<fila; i++){
		for(int a=0; a<columna; a++){
		cout<<matriz[i][a]<<"  ";
		}
		cout<<endl;
	}
	cout<<"Matriz transpuesta"<<endl;
	for(int i=0; i<fila; i++){
		for(int a=0; a<columna; a++){
		cout<<matriz[a][i]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}
