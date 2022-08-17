#include <iostream>
#include <stdio.h>


#define MAX 50
#define MAXI 100
#define largo 50

using namespace std;

//un arreglo
struct ordenamiento{
	int elem;
};
struct ordenamient{
	int eleme;
};
//burbuja
void leerarray(int, struct ordenamiento[]);
void burbuja(int, struct ordenamiento[]);
void mostrar(int, struct ordenamiento[]);
//shell
void escribirArreglo(int, struct ordenamient []);
void metodoShell(int, struct ordenamient []);
void leerarray(int, struct ordenamient []);

void seleccion (int  a[], int n) {
    int k,i,j,aux;
        
    for (i=0; i<n-1; i++){
		k=i;
        for(j=i+1; j<n; j++)
            if(a[k] > a[j])
                k=j;
              aux=a[k];
              a[k]=a[i];
              a[i]=aux ;
    }

}
void leerarray(int cant,int n[]){
    for(int i=0;i<cant;i++){
        cout<<"Ingresa numero "<<i+1<<": ";
        cin>>n[i];
    }
     
}

void muestrararray(int cant,int n[]){
    for(int i=0;i<cant;i++){
        cout<<n[i]<<endl;
    }
}

int main (){
	int opc, n;
	
	cout<<"Selecciona un opcion de ordenamiento\n "<<endl;
	cout<<"1) Metodo burbuja\n";
	cout<<"2) Metodo shell\n";
	cout<<"3) Metodo seleccion directa\n ";
	cin>>opc;
	
	switch(opc){
		case 1:
			cout<<"Metodo BURBUJA:\n "<<endl;
			
			struct ordenamiento orden[MAX];
			
			cout<<"Ingresa el limete del arreglo: ";
			cin>>n;
			
			leerarray(n, orden);
			burbuja(n, orden);
			cout<<endl<<"El arreglo ordenano es: \n"<<endl;
			mostrar(n, orden);
			
			break;
		case 2:
			cout<<"Metodo SHELL:\n "<<endl;
			struct ordenamient order[MAXI];
	
			cout<<"Ingreasa la dimension del arreglo: ";
			cin>>n;
			
			leerarray(n, order);
			metodoShell(n, order);
			escribirArreglo(n, order);
			
			break;
		case 3:
			int a[largo],n;
			
			cout<<"Metodo SELECCION:\n "<<endl;
			
			cout<<"Ingreasa la dimension del arreglo: ";
			cin>>n;
			
			leerarray(n, a);
  		    seleccion(a, n);
			muestrararray(n, a);
			break;
		default: 
			cout<<"OPCION INCORRECTA";
		
}
}

void leerarray(int n, struct ordenamiento a[]){
	for(int i = 0; i < n; i++){
		cout<<"Ingrese el elemento: \n";
		cin>>a[i].elem;
	}
}
void burbuja(int n, struct ordenamiento a[]){
	int i, j;
	struct ordenamiento temp;
	
	//aqui aplico burbuja el intercambio del menor
	for(i = 1; i < n; i++){
		for(j = n+1; j<=i; j--){
			//comparacion
			if(a[j-1].elem > a[j].elem){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void mostrar(int n, struct ordenamiento a[]){
	for(int i = 0; i < n; i++){
		cout<<" "<<a[i].elem;
	}
}

//shell
void leerarray(int n, struct ordenamient a[]){
	for(int i=0; i < n; i++){
		cout<<"Ingrese el elemento: \n";
		cin>>a[i].eleme;
	}
}

void escribirArreglo(int n, struct ordenamient a[]){
	cout<<"elementos ordenados por metodo Shell: "<<endl;
	
	for(int i=0; i < n; i++){
		cout<<" "<<a[i].eleme;
	}
}

void metodoShell(int n,  struct ordenamient a[]){
   int i, j, inc;  
   struct ordenamient aux; 

   inc=n/2;
    
    while(inc>0){
        for(i=inc+1;i<=n;i++){
            j=i-inc;
            while(j>0){
                if(a[j].eleme >= a[j+inc].eleme){
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

