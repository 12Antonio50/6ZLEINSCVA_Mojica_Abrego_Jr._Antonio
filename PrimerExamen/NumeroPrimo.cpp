#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int num, contador=0;
	
	cout<<"Ingresa un numero para saber si es primo: ";
	cin>>num;
	
	for(int i=1; i<=num; i++){
		contador=0;
		for(int j=1;j<=num;j++){
			if(i%j==0){
				contador++;
			}else{
				cout<<"No es un numero primo\n";
			}
		}
		if(contador==2){
			cout<<i<<"<<";
		}
	}

}
