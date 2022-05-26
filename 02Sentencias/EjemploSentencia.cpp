#include <iostream>

using namespace std;

int main(){
	
	//uso de sentencias de control
	//do while
	/*int i =1;
	do{
		//crear un programa que imprima hasta al 10
		cout<<i<<endl;
		i++;
	}while(i<11);*/
	/*int cont = 1;
	
	while(cont <=10){
		cout<<cont<<endl;
		cont++;
	}
	cout<<"se acabo";*/
	//for
	/*for(int i =1; i<=10; i++)
	
		cout<<i<<endl;*/
		
	int  seleccion;
	
	do{
		cout<<"\n menu 1, 2, 3 otra opcion salir \n";
		cout<<"\1.- opcion 1 \n";
		cout<<"\2.- opcion 2 \n";
		cout<<"\3.- opcion 3 \n";
		cin>>seleccion;
		
		switch(seleccion){
			case 1:
				cout<<"Opcion 1";
				break;
			case 2:
				cout<<"Opcion 2";
				break;
			case 3:
				cout<<"Opcion 3";
				break;
			default:
				cout<<"adios";
				break;
		}
	}while((seleccion >0)&&(seleccion <4));
}
