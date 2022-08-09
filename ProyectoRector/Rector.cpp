#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cctype>
#include <fstream>

#define _CRT_SECURE_NO_WARNINGS
#define USUARIO "people"
#define CONTRA "12345"
#define DOC "admin"
#define PASS "54321"

using namespace std;
//nodo
struct nodo{
	string nombre;
	string aP;
	string aM;
	string calle;
	string calleC;
	string calleCA;
	string lugarN;
	string estadoC;
	string correo;
	string sexo;
	string fechaN;
	string nombreC;
	string nombreCA;
	string parenteC;
	string parenteCA;
	
	string edad;
	string telefonoF;
	string telefonoC;
	string telefonoCA;
	string celular;
	string celularC;
	string celularCA;
	string id_cita;
	
	struct nodo *sig;
};
//cola
struct cola{
	nodo *delante;
	nodo *atras;
};
//crear nodo
struct nodo *crearNodo(string nom, string icita, string apeP, string apeM, string cll, string callC, string callCA, string lN, string estaC, string cor, string sx, string fN, string nC, string nCA, string parenC, string parenCA, string ed, string tf, string tfC, string tfCA, string cel, string celC, string celCA){
	struct nodo *nuevoNodo = new (struct nodo);
	nuevoNodo->nombre=nom;
	nuevoNodo->aP=apeP;
	nuevoNodo->aM=apeM;
	nuevoNodo->calle=cll;
	nuevoNodo->calleC=callC;
	nuevoNodo->calleCA=callCA;
	nuevoNodo->lugarN=lN;
	nuevoNodo->estadoC=estaC;
	nuevoNodo->correo=cor;
	nuevoNodo->sexo=sx;
	nuevoNodo->fechaN=fN;
	nuevoNodo->nombreC=nC;
	nuevoNodo->nombreCA=nCA;
	nuevoNodo->parenteC=parenC;
	nuevoNodo->parenteCA=parenCA;
	nuevoNodo->edad=ed;
	nuevoNodo->telefonoF=tf;
	nuevoNodo->telefonoC=tfC;
	nuevoNodo->telefonoCA=tfCA;
	nuevoNodo->celular=cel;
	nuevoNodo->celularC=celC;
	nuevoNodo->celularCA=celCA;
	nuevoNodo->id_cita=icita;
	
	return nuevoNodo;
}
//encolar
void encolar(struct cola &q, string nombre, string id_cita, string aP, string aM, string calle, string calleC, string calleCA, string lugarN, string estadoC, string correo, string sexo, string fechaN, string nombreC, string nombreCA, string parenteC, string parenteCA, string edad, string telefonoF, string telefonoC, string telefonoCA, string celular, string celularC, string celularCA){
	struct nodo *aux = crearNodo(nombre, aP, aM, id_cita, calle, calleC, calleCA, lugarN, estadoC, correo, sexo, fechaN, nombreC, nombreCA, parenteC, parenteCA, edad, telefonoF, telefonoC, telefonoCA, celular, celularC, celularCA);
	aux->sig=NULL;
	if(q.delante == NULL){
		q.delante=aux;
	}else{
		(q.atras)->sig = aux;
	}
	q.atras = aux;
	
}
//insertar
void insertar(struct cola &q, string no, string idcita, string pa, string ma, string cal, string calC, string calCA, string lugN, string estC, string coeo, string sex, string feN, string nomC, string nomCA, string parC, string parCA, string e, string telF, string telC, string telCA, string clv, string clC, string clCA){
	encolar(q, no, pa, idcita, ma, cal, calC, calCA, lugN, estC, coeo, sex, feN, nomC, nomCA, parC, parCA, e, telF, telC, telCA, clv, clC, clCA);
}
//mostrar cola
void mostrarCola(struct cola q){
	struct nodo *aux;
	aux = q.delante;
	while(aux != NULL){
		cout<<"\nNombre: "<<aux->nombre;
		cout<<"\nApellido paterno: "<<aux->aP;
		cout<<"\nApellido materno: "<<aux->aM;
		cout<<"\nCalle donde vive: "<<aux->calle;
		cout<<"\nLugar de nacimiento: "<<aux->lugarN;
		cout<<"\nEdad: "<<aux->edad;
		cout<<"\nSexo: "<<aux->sexo;
		cout<<"\nFecha de nacimiento: "<<aux->fechaN;
		cout<<"\nEstado civil: "<<aux->estadoC;
		cout<<"\nCorreo: "<<aux->correo;
		cout<<"\nNumero de telefono: "<<aux->telefonoF;
		cout<<"\nNumero de celular: "<<aux->celular;
		cout<<"\nNombre Persona de contacto: "<<aux->nombreC;
		cout<<"\nParentesco: "<<aux->parenteC;
		cout<<"\nNumero de telefono: "<<aux->telefonoC;
		cout<<"\nNumero de celular: "<<aux->celularC;
		cout<<"\nNombre Persona de contacto: "<<aux->nombreCA;
		cout<<"\nParentesco: "<<aux->parenteCA;
		cout<<"\nNumero de telefono: "<<aux->telefonoCA;
		cout<<"\nNumero de celular: "<<aux->celularCA;
		cout<<"\nID_cita: "<<aux->id_cita;
		aux = aux->sig;
	}
}
//insertarTXT
void insertarTxt(struct cola &q){
	struct nodo *aux;
	aux = q.delante;
	ofstream file;
	file.open("ABB");
	file<<"\nNombre: "<<aux->nombre;
	file<<"\nApellido paterno: "<<aux->aP;
	file<<"\nApellido materno: "<<aux->aM;
	file<<"\nCalle donde vive: "<<aux->calle;
	file<<"\nLugar de nacimiento: "<<aux->lugarN;
	file<<"\nEdad: "<<aux->edad;
	file<<"\nSexo: "<<aux->sexo;
	file<<"\nFecha de nacimiento: "<<aux->fechaN;
	file<<"\nEstado civil: "<<aux->estadoC;
	file<<"\nCorreo: "<<aux->correo;
	file<<"\nNumero de telefono: "<<aux->telefonoF;
	file<<"\nNumero de celular: "<<aux->celular;
	file<<"\nNombre Persona de contacto: "<<aux->nombreC;
	file<<"\nParentesco: "<<aux->parenteC;
	file<<"\nNumero de telefono: "<<aux->telefonoC;
	file<<"\nNumero de celular: "<<aux->celularC;
	file<<"\nNombre Persona de contacto: "<<aux->nombreCA;
	file<<"\nParentesco: "<<aux->parenteCA;
	file<<"\nNumero de telefono: "<<aux->telefonoCA;
	file<<"\nNumero de celular: "<<aux->celularCA;
	file<<"\nID_cita: "<<aux->id_cita;
	aux = aux->sig;
}
//main
int main(){
	char usuario[25];
	char pass[25];
	int c = 1, op;
	bool f = false;
	
	struct cola q;
	q.delante = NULL;
	q.atras = NULL; 
	system("CLS");
	
	cout<<"BIENVENIDO SELECCIONE LA OPCION CORRECTAS SEGUN SEA EL CASO\n";
	cout<<"1.-DOCTOR\n";
	cout<<"2.-PACIENTE\n";
	cin>>op;
	
	switch(op){
		case 1:
			while(c<=3 && f ==false){
				cin.getline(usuario, 25);
				cout<<"Ingresar usuario: ";
				cin.getline(usuario, 25);
	
				cout<<"\nIngresa la contrasenia: \n ";
				cin.getline(pass, 25);
				c++;
		
				if((strcmp(pass,PASS)==0) && (strcmp(usuario, DOC)==0)){
					f=true;	
				}
				else{
					cout<<"USUARIO O CONTASENIA INCORRECTAS\n";
					system("PAUSE");
				}
	
			}
			
			if(f==true){
				cout<<"\nBIENVENIDO \n" ;
			}else{
				cout<<"Tres intentos fallidos, intentar mas tarde";
			}
			break;
	case 2:
		while(c<=3 && f ==false){
			cin.getline(usuario, 25);
			cout<<"Ingresar usuario: ";
			cin.getline(usuario, 25);
	
			cout<<"\nIngresa la contrasenia: \n ";
			cin.getline(pass, 25);
			c++;
	
			if((strcmp(pass,CONTRA)==0) && (strcmp(usuario, USUARIO)==0)){
				f=true;	
			}
			else{
				cout<<"USUARIO O CONTASENIA INCORRECTAS\n";
				system("PAUSE");
			}
	
		}
			if(f==true){
				cout<<"\nBIENVENIDO \n" ;
			}else{
				cout<<"Tres intentos fallidos, intentar mas tarde";
			}
			cout<<"\nIngresa un opcion\n";
			int opc;
			cout<<"\n1) Registro nuevo\n";
			cout<<"2) Consultar expedinete\n";
			cout<<"3) Consultar cita\n";
			cout<<"4) Salir\n";
			cin>>opc;
			switch (opc){
				do{
					case 1:
							string  no, idcita, pa, ma, cal, calC, calCA, lugN, estC, coeo, sex, feN, nomC, nomCA, parC, parCA, e, telF, telC,telCA, clv, clC, clCA;
	
							cout<<"\n\nIngresa los siguente valores\n";
							
							cout<<"Apellido paterno: ";
							cin>>pa;
							cout<<"\nApellido materno: ";
							cin>>ma;
							cout<<"\nNombre: ";
							cin>>no;
							cout<<"\nEdad: ";
							cin>>e;
							cout<<"\nSexo: ";
							cin>>sex;
							cout<<"\nFecha de nacimiento DD/MM/AA: ";
							cin>>feN;
							cout<<"\nLugar de nacimiento: ";
							cin>>lugN;
							cout<<"\nEstado civil: ";
							cin>>estC;
							cout<<"\nCorreo electronico: ";
							cin>>coeo;
							cout<<"Direccion residencial: \n";
							cin>>cal;
							cout<<"\nTelefono de casa: ";
							cin>>telF;
							cout<<"\nCelular: ";
							cin>>clv;
							cout<<"Ingresar ID_cita: ";
							cin>>idcita;
							cout<<"\n\nContacto de emergencias \n";
							cout<<"Nombre: ";
							cin>>nomC;
							cout<<"\nParentesco: ";
							cin>>parC;
							cout<<"\nNumero de telefono: ";
							cin>>telC;
							cout<<"\nNumero de celular: ";
							cin>>clC;
							
							cout<<"\n\nSegindo contacto de emergencias \n";
							cout<<"Nombre: ";
							cin>>nomCA;
							cout<<"\nParentesco: ";
							cin>>parCA;
							cout<<"\nNumero de telefono: ";
							cin>>telCA;
							cout<<"\nNumero de celular: ";
							cin>>clCA;
							
							insertar(q, no, idcita, pa, ma, cal, calC, calCA, lugN, estC, coeo, sex, feN, nomC, nomCA, parC, parCA, e, telF, telC, telCA, clv, clC, clCA );
						
							if(q.delante!=NULL){
								mostrarCola(q);
								insertarTxt(q);
								
							}else{
								cout<<"\n La cola esta vacia\n";
							}
							break;
							case 2:
								cout<<"hola";
							break;	
			}while(opc==4);
		}
	}
	
}
	
