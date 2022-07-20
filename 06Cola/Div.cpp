#include <iostream>
#include <stdlib.h>

using namespace std;


int main(){
	float num;
	
	cout<<("Ingresa un numero real")<<endl;
	cin>>num;
	
	if(num>0 && num<=9){
		cout<<("Eres listo\n");
	}else{
		cout<<("Eres pendejo\n");
	}
}
