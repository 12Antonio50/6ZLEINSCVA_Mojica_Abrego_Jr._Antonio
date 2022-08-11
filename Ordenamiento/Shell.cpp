#include <iostream>

#define MAX 50

using namespace std;

struct ordenamiento{
	int elem;
};

void escribirArreglo(int, struct ordenamiento []);
void metodoShell(int, struct ordenamiento []);
void leerarray(int, struct ordenamiento []);

int main (){
	int n;
	struct ordenamiento orden[MAX];
	
	cout<<"Ingreasa la dimension del arreglo: ";
	cin>>n;
	
	leerarray(n, orden);
	metodoShell(n, orden);
	
	escribirArreglo(n, orden);
}

void leerarray(int n, struct ordenamiento a[]){
	for(int i=0; i < n; i++){
		cout<<"Ingrese el elemento: \n";
		cin>>a[i].elem;
	}
}

void escribirArreglo(int n, struct ordenamiento a[]){
	cout<<"elementos ordenados por metodo Shell: "<<endl;
	
	for(int i=0; i < n; i++){
		cout<<"\n"<<a[i].elem;
	}
}

void metodoShell(int n,  struct ordenamiento a[]){
   int i, j, k, incremento;  
   struct ordenamiento aux; 

   incremento=n/2;
    
    while(incremento>0){
        for(i=incremento+1;i<=n;i++){
            j=i-incremento;
            while(j>0){
                if(a[j].elem >= a[j+incremento].elem){
                    aux = a[j];
                    a[j] = a[j+incremento];
                    a[j+incremento] = aux;
                }else{
                    j=0;
                    }
					j=j-incremento;
            }
        }
        incremento=incremento/2;
    }

}
