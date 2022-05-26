#include <iostream>

using namespace std;
/*iostream sirve para determinar la entrada de sistema por parte del teclado 
os del sistema es la salida estandar que es la pantalla */

int main(){
	
	int edad;
	//salida pantalla 
	cout<<"Ingresa tu edad";cin>>edad;
	
	if(edad>=18){
		cout<<"Es mayor de edad";
	}else
		cout<<"Es menor de edad";
	
}
