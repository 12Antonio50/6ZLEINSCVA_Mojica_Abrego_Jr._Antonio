#include <iostream>

#define MAX 100

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
		cout<<" "<<a[i].elem;
	}
}

void metodoShell(int n,  struct ordenamiento a[]){
   int i, j, inc;  
   struct ordenamiento aux; 

   inc=n/2;
    
    while(inc>0){
        for(i=inc+1;i<=n;i++){
            j=i-inc;
            while(j>0){
                if(a[j].elem >= a[j+inc].elem){
                    aux = a[j];
                    a[j] = a[j+inc];
                    a[j+inc] = aux;
                }else{
                    j=0;
                }
					j=j-inc;
            }
        }
        inc=inc/2;
    }

}
