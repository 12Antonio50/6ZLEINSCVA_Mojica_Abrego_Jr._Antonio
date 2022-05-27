//Arreglos
#include <iostream>

using namespace std;

int main(){
	float vector1[3];
	float vector2[3];
	float vectorSuma[3];
	int i;
	
	
	//Vamos a llenar los valores de los vectores
	for( i = 0; i<3; i++){
		cout<<"Ingresa el valor "<<i<<" del primer verctor";
		cin>>vector1[i];
	}
	for(i = 0; i<3; i++){
		cout<<"Ingresa el valor "<<i<<"del segundo verctor";
		cin>>vector2[i];
	}
	//calcular la suma 
	for (i = 0; i<3 ; i++){
		vectorSuma[i]= vector1[i]+vector2[i];
	}
	cout<<"El vector Suma es de: "<<vectorSuma;
	for (i = 0; i<3 ; i++){
		cout<<vectorSuma[i]<<"  ";
	}
	return 0;
}
