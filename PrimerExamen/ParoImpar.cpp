#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int num, n;
	
	cout<<"Ingresa un numero para que el programa te diga si es par o inpar :";
	cin>>num;
	n=num%2;
	
	if(n==0){
		cout<<"Felicidades el numero: "<<num<<" es par\n";
	}else{
		cout<<"Oh no el nuemro: "<<num<<" es inpar\n";
	}
	cout<<"Adios buen dia";
	
	return 0;
		
}
