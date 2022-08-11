#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cctype>
#include <fstream>
#include <cstring>

using namespace std;

struct nodoPaciente{
	char nombre[60];
	int edad;
	string fechaRegistro;
	string tipoSangre;
	double estatura;
	double peso;
	double imc;
	string clasificacionImc;
	char enfermedadesCronicas[60];
	char enfermedadesCongenitas[60];
	char alergias[50];
	char discapacidad[50];
	int idPaciente;
	
	struct nodoPaciente *siguientePaciente;
}*inicioPaciente, *finalPaciente;

struct nodoCita{
	char nombre[60];
	char citaFecha[15];
	char hora[10];
	char consultorio[5];
	int idPaciente;
	
	struct nodoCita *siguienteCita;
}*inicioCita, *finalCita;

void insertarPacienteyCita();
void buscarPacienteExpediente();
void buscarCitaID();
void buscarCitaFecha();
void modificarPaciente();
void modificarCita();
void desplegarListaPaciente();
void desplegarListaCita();
void eliminarPacienteyCita();
void eliminarCita();
void calculadoraImc();

int menuInicio();
int menuPaciente();
int menuDoctor();
int menuCitas();
int menuExpediente();
int menuBuscarCita();

int main(){
	
	menuInicio();
	
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void insertarPacienteyCita(){
	
	char nombree[60];
	int idPaciente;
	char citaFecha[15];
	double imc;
	double peso;
	double estatura;
	string clasificacionImc;
	
	
	//ingreso datos del nodo paciente
	nodoPaciente* nuevoPaciente = new nodoPaciente();
	
	cout << "\nIngrese nombre completo: ";
	cin>>nombree;
	memcpy(nuevoPaciente->nombre, nombree, 60);
	
	cout<<"\nIngrese edad: ";
	cin >> nuevoPaciente->edad;
	cout << "\nIngrese la fecha de hoy: ";
	cin >> nuevoPaciente->fechaRegistro;
	cout << "\nIngrese su tipo de sangre: ";
	cin >> nuevoPaciente->tipoSangre;
	cout << "\nIngrese su estatura: ";
	cin >> estatura;
	nuevoPaciente->estatura = estatura;
	cout << "\nIngrese su peso: ";
	cin >> peso;
	nuevoPaciente->peso = peso;
	
	imc = peso/estatura;
	
	if(imc < 18.5){
		clasificacionImc = "Peso bajo";
	}
	if(imc >= 18.5 && imc < 25){
		clasificacionImc = "Peso normal";
	}
	if(imc >= 25 && imc < 30){
		clasificacionImc = "Sobrepeso";
	}
	if(imc >= 30 && imc < 35){
		clasificacionImc = "Obesidad grado 1";
	}
	if(imc >= 35 && imc < 40){
		clasificacionImc = "Obesidad grado 2";
	}
	if(imc >= 40){
		clasificacionImc = "Obesidad grado 3";
	}
	
	nuevoPaciente->imc = imc;
	nuevoPaciente->clasificacionImc = clasificacionImc;
	
	
	cout << "\nIngrese enfermedades cronicas del paciente: ";
	cin>>nuevoPaciente->enfermedadesCronicas;
	cout << "\nIngrese enfermedades congenitas del paciente: ";
	cin>>nuevoPaciente->enfermedadesCongenitas;
	cout << "\nIngrese alergias del paciente: ";
	cin>>nuevoPaciente->alergias;
	cout << "\nIngrese discapacidades del paciente: ";
	cin>>nuevoPaciente->discapacidad;
	cout << "\nIngrese ID del paciente: ";
	cin >> idPaciente;
	nuevoPaciente->idPaciente = idPaciente;
	
	cout << "\nIngrese la fecha de la proxima cita del paciente (DD/MM/AAAA): ";
	cin>>citaFecha;
	//memcpy(nuevoPaciente->citaFecha, citaFecha, 60);

	

	if(inicioPaciente==NULL){
		inicioPaciente = nuevoPaciente;
		inicioPaciente->siguientePaciente = NULL;
		finalPaciente = inicioPaciente;
	}else{
		finalPaciente->siguientePaciente = nuevoPaciente;
		nuevoPaciente->siguientePaciente = NULL;
		finalPaciente = nuevoPaciente;
	}
	
	//insertar datos del nodo cita
	nodoCita* nuevoCita = new nodoCita();
	
	//cout << "\nIngrese nombre completo: ";
	memcpy(nuevoCita->nombre, nombree, 60);
	
	//cout << "\nIngrese la fecha de la proxima cita: ";
	memcpy(nuevoCita->citaFecha, citaFecha, 60);
	
	cout << "\nIngrese la hora de la proxima cita (HH:MM): ";
	cin>>nuevoCita->hora;
	cout << "\nIngrese el consultorio asignado: ";
	cin>>nuevoCita->consultorio;
	//cout << "\nIngrese ID del paciente: ";
	nuevoCita->idPaciente = idPaciente;
	

	

	if(inicioCita==NULL){
		inicioCita = nuevoCita;
		inicioCita->siguienteCita = NULL;
		finalCita = inicioCita;
	}else{
		finalCita->siguienteCita = nuevoCita;
		nuevoCita->siguienteCita = NULL;
		finalCita = nuevoCita;
	}
}



void buscarPacienteExpediente(){
	
	//busqueda en el nodo paciente
	nodoPaciente* actualPaciente = new nodoPaciente();
	actualPaciente = inicioPaciente;
	bool encontradoPaciente = false;
	
	//variable para buscar al nodo de acuerdo al id
	int nodoBuscado = 0;
	cout <<"\nIngrese el ID del paciente a buscar: ";
	cin >> nodoBuscado;
	
	
	if(inicioPaciente != NULL){
		while(actualPaciente != NULL && encontradoPaciente != true){
			
			if(actualPaciente->idPaciente == nodoBuscado){
				
				cout<<"\nNombre: "<<actualPaciente->nombre;
				cout<<"\nEdad: "<<actualPaciente->edad;
				cout<<"\nFecha de registro: "<<actualPaciente->fechaRegistro;
				cout<<"\nTipo de sangre: "<<actualPaciente->tipoSangre;
				cout<<"\nEstatura: "<<actualPaciente->estatura;
				cout<<"\nPeso: "<<actualPaciente->peso;
				cout<<"\nIMC: "<<actualPaciente->imc;
				cout<<"\nClasificacion segun su IMC: "<<actualPaciente->clasificacionImc;
				cout<<"\nEnfermedades cronicas: "<<actualPaciente->enfermedadesCronicas;
				cout<<"\nEnfermedades congenitas: "<<actualPaciente->enfermedadesCongenitas;
				cout<<"\nAlergias: "<<actualPaciente->alergias;
				cout<<"\nDiscapacidad: "<<actualPaciente->discapacidad;
				cout<<"\nID del paciente: "<<actualPaciente->idPaciente;
				
				
				encontradoPaciente = true;
			}
			
			actualPaciente = actualPaciente->siguientePaciente;
		}
		if(!encontradoPaciente){
			cout << "\n Nodo No Encontrado";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}	
	
	
	
	
	
}



void buscarCitaID(){
	
	int nodoBuscado = 0;
	cout <<"\nIngrese el ID del paciente de la cita buscar: ";
	cin >> nodoBuscado;
	
	//busqueda en el nodo cita
	nodoCita* actualCita = new nodoCita();
	actualCita = inicioCita;
	bool encontradoCita = false;
	
	if(inicioCita != NULL){
		while(actualCita !=NULL && encontradoCita != true){
			
			if(actualCita->idPaciente == nodoBuscado){
				
				
				cout<<"Fecha de la cita: "<<actualCita->citaFecha;
				cout<<"Hora: "<<actualCita->hora;
				cout<<"Consultorio: "<<actualCita->consultorio;
				cout<<"Nombre del paciente: "<<actualCita->nombre;
				cout<<"ID del paciente: "<<actualCita->idPaciente;
				
				
				encontradoCita = true;
			}
			
			actualCita = actualCita->siguienteCita;
		}
		if(!encontradoCita){
			cout << "\n Nodo No Encontrado";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
}



void buscarCitaFecha(){
	
	char nodoBuscado[15];
	cout <<"\nIngrese fecha de la cita a buscar: ";
	cin.getline(nodoBuscado, 15);
	
	//busqueda en el nodo cita
	nodoCita* actualCita = new nodoCita();
	actualCita = inicioCita;
	bool encontradoCita = false;
	
	if(inicioCita != NULL){
		while(actualCita !=NULL && encontradoCita != true){
			
			if(actualCita->citaFecha == nodoBuscado){
				
				
				cout<<"Fecha de la cita: "<<actualCita->citaFecha;
				cout<<"Hora: "<<actualCita->hora;
				cout<<"Consultorio: "<<actualCita->consultorio;
				cout<<"Nombre del paciente: "<<actualCita->nombre;
				cout<<"ID del paciente: "<<actualCita->idPaciente;
				
				
				encontradoCita = true;
			}
			
			actualCita = actualCita->siguienteCita;
		}
		if(!encontradoCita){
			cout << "\n Nodo No Encontrado";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
}



void modificarPaciente(){
	
	nodoPaciente* actualPaciente = new nodoPaciente();
	actualPaciente = inicioPaciente;
	bool encontrado = false;
	char nombre[60];
	int idPaciente;
	char citaFecha[15];
	int nodoBuscado = 0;
	double estatura;
	double peso;
	double imc;
	string clasificacionImc;
	
	cout << " Ingrese el ID del paciente: ";
	cin >> nodoBuscado;
	if(inicioPaciente != NULL){
		while(actualPaciente !=NULL && encontrado != true){
			
			if(actualPaciente->idPaciente == nodoBuscado){
				cout << "\nIngrese nuevamente los datos del paciente";
				
				cout << "\nIngrese nombre completo: ";
				cin.getline(nombre, 60);
				memcpy(actualPaciente->nombre, nombre, 60);
				
				cout<<"\nIngrese edad: ";
				cin >> actualPaciente->edad;
				cout << "\nIngrese la fecha de hoy: ";
				cin >> actualPaciente->fechaRegistro;
				cout << "\nIngrese su tipo de sangre: ";
				cin >> actualPaciente->tipoSangre;
				cout << "\nIngrese su estatura: ";
				cin >> estatura;
				actualPaciente->estatura = estatura;
				cout << "\nIngrese su peso: ";
				cin >> peso;
				actualPaciente->peso = peso;
				
				imc = peso/estatura;
	
				if(imc < 18.5){
					clasificacionImc = "Peso bajo";
				}
				if(imc >= 18.5 && imc < 25){
					clasificacionImc = "Peso normal";
				}
				if(imc >= 25 && imc < 30){
					clasificacionImc = "Sobrepeso";
				}
				if(imc >= 30 && imc < 35){
					clasificacionImc = "Obesidad grado 1";
				}
				if(imc >= 35 && imc < 40){
					clasificacionImc = "Obesidad grado 2";
				}
				if(imc >= 40){
					clasificacionImc = "Obesidad grado 3";
				}
				
				actualPaciente->imc = imc;
				actualPaciente->clasificacionImc = clasificacionImc;
				
				cout << "\nIngrese enfermedades cronicas del paciente: ";
				cin.getline(actualPaciente->enfermedadesCronicas, 60);
				cout << "\nIngrese enfermedades congenitas del paciente: ";
				cin.getline(actualPaciente->enfermedadesCongenitas, 60);
				cout << "\nIngrese alergias del paciente: ";
				cin.getline(actualPaciente->alergias, 50);
				cout << "\nIngrese discapacidades del paciente: ";
				cin.getline(actualPaciente->discapacidad, 50);
	
				encontrado = true;
			}
			
			actualPaciente = actualPaciente->siguientePaciente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}		
}



void modificarCita(){
	
	nodoCita* actualCita = new nodoCita();
	actualCita = inicioCita;
	bool encontrado = false;
	char nombre[60];
	int idPaciente;
	char citaFecha[15];
	int nodoBuscado = 0;
	cout << "Ingrese el ID del paciente: ";
	cin >> nodoBuscado;
	if(inicioCita != NULL){
		while(actualCita!=NULL && encontrado != true){
			
			if(actualCita->idPaciente == nodoBuscado){
				cout << "\nIngrese nuevamente los datos del paciente: ";
				
				cout << "\nIngrese nombre completo: ";
				cin>>nombre;
				memcpy(actualCita->nombre, nombre, 60);
				
				cout << "\nIngrese la fecha de la proxima cita: ";
				cin>>citaFecha;
				memcpy(actualCita->citaFecha, citaFecha, 60);
				
				cout << "\nIngrese la hora de la proxima cita (HH:MM): ";
				cin>>actualCita->hora;
				cout << "\nIngrese el consultorio asignado: ";
				cin>>actualCita->consultorio;
	
				encontrado = true;
			}
			
			actualCita = actualCita->siguienteCita;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}		
}



void desplegarListaPaciente(){
	nodoPaciente* actual = new nodoPaciente();
	actual = inicioPaciente;
	if(inicioPaciente !=NULL){
		cout<<"\nLista de pacientes registrados: ";
		while(actual!=NULL){
			
				cout<<"\nNombre: "<<actual->nombre;
				cout<<"\nEdad: "<<actual->edad;
				cout<<"\nFecha de registro: "<<actual->fechaRegistro;
				cout<<"\nTipo de sangre: "<<actual->tipoSangre;
				cout<<"\nID del paciente: "<<actual->idPaciente;
				cout<<"\n";
			
			actual = actual->siguientePaciente;
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
}



void desplegarListaCita(){
	nodoCita* actual = new nodoCita();
	actual = inicioCita;
	if(inicioCita !=NULL){
		cout<<"\nLista de citas: ";
		while(actual!=NULL){
			
				cout<<"\nFecha de la cita: "<<actual->citaFecha;
				cout<<"\nHora: "<<actual->hora;
				cout<<"\nConsultorio: "<<actual->consultorio;
				cout<<"\nID del paciente: "<<actual->idPaciente;
				cout<<"\n";
			
			actual = actual->siguienteCita;
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
}



void eliminarPacienteyCita(){
	
	int nodoBuscado = 0;
	cout << "Ingrese el folio de la cita a eliminar: ";
	cin >> nodoBuscado;
	
	//eliminar paciente
	nodoPaciente* actualPaciente = new nodoPaciente();
	actualPaciente = inicioPaciente;
	bool encontradoPaciente = false;
	
	if(inicioPaciente != NULL){
		while(actualPaciente !=NULL && encontradoPaciente != true){
			
			if(actualPaciente->idPaciente == nodoBuscado){
				
				delete(actualPaciente);
				
				cout << "\nPaciente eliminado ";
				encontradoPaciente = true;
			}
			
			actualPaciente = actualPaciente->siguientePaciente;
		}
		if(!encontradoPaciente){
			cout << "\n Nodo No Encontrado";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
	
	//eliminar Cita
	nodoCita* actualCita = new nodoCita();
	actualCita = inicioCita;
	bool encontradoCita = false;
	
	if(inicioCita != NULL){
		while(actualCita!=NULL && encontradoCita != true){
			
			if(actualCita->idPaciente == nodoBuscado){
				
				delete(actualCita);
				
				cout << "\nCita eliminada ";
				encontradoCita = true;
			}
			
			actualCita = actualCita->siguienteCita;
		}
		if(!encontradoCita){
			cout << "\n Nodo No Encontrado";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}

	
	
}


void eliminarCita(){
	
	nodoCita* actual = new nodoCita();
	actual = inicioCita;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << "Ingrese el folio de la cita a eliminar: ";
	cin >> nodoBuscado;
	if(inicioCita != NULL){
		while(actual!=NULL && encontrado != true){
			
			if(actual->idPaciente == nodoBuscado){
				
				delete(actual);
				
				cout << "\nCita eliminada ";
				encontrado = true;
			}
			
			actual = actual->siguienteCita;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado";
		}
	}else{
		cout << endl << " La cola se encuentra Vacia " << endl << endl;
	}
}



void calculadoraImc(){
	
	double peso;
	double estatura;
	double imc;
	string clasificacionImc;
	
	cout<<"Ingrese su peso: ";
	cout<<"Ingrese su estatura: ";
	
	imc = peso/estatura;
	
	if(imc < 18.5){
		clasificacionImc = "Peso bajo";
	}
	if(imc >= 18.5 && imc < 25){
		clasificacionImc = "Peso normal";
	}
	if(imc >= 25 && imc < 30){
		clasificacionImc = "Sobrepeso";
	}
	if(imc >= 30 && imc < 35){
		clasificacionImc = "Obesidad grado 1";
	}
	if(imc >= 35 && imc < 40){
		clasificacionImc = "Obesidad grado 2";
	}
	if(imc >= 40){
		clasificacionImc = "Obesidad grado 3";
	}
	
	cout<<"Su IMC es de "<<imc<<", lo cual lo clasifica como una persona con "<<clasificacionImc;
	
	
	
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int menuInicio (){
	int opc;
	
	cout<<"|_________________________|\n";
	cout<<"|          INICIO         |\n";
	cout<<"|-------------------------|\n";
	cout<<"|1). Doctor               |\n";
	cout<<"|-------------------------|\n";
	cout<<"|2). Paciente             |\n";
	cout<<"|_________________________|\n";
	cin>>opc;
	
	switch(opc){
		case 1:
			cout<<"Bienvenido "<<endl;
			menuDoctor();
			break;
		case 2:
			cout<<"Bienvenido "<<endl;
			menuPaciente();
			break;
		default:
			cout<<"Opcion incorrecta\n";
	}
}



int menuPaciente(){
	int op;
	cout<<"|_________________________|\n";
	cout<<"|        PACIENTES        |\n";
	cout<<"|-------------------------|\n";
	cout<<"|1). Consultar expediente |\n";
	cout<<"|-------------------------|\n";
	cout<<"|2). Consultar cita       |\n";
	cout<<"|-------------------------|\n";
	cout<<"|3). Regresar al inicio   |\n";
	cout<<"|_________________________|\n";
	cin>>op;
	switch(op){
		case 1:
			buscarPacienteExpediente();
			break;
		case 2:
			buscarCitaID();
			break;
		case 3:
			menuInicio();
			break;
		default:
			cout<<"Opcion incorrecta\n";	
	}
}



int menuDoctor(){
	int opcion;
	cout<<"|_________________________|\n";
	cout<<"|          DOCTOR         |\n";
	cout<<"|-------------------------|\n";
	cout<<"|1). Registrar paciente   |\n";
	cout<<"|-------------------------|\n";
	cout<<"|2). Citas                |\n";
	cout<<"|-------------------------|\n";
	cout<<"|3). Expediente clinico   |\n";
	cout<<"|-------------------------|\n";
	cout<<"|4). Calculadora          |\n";
	cout<<"|_________________________|\n";
	cin>>opcion;
	switch(opcion){
		case 1:
			insertarPacienteyCita();
			menuInicio();
			break;
		case 2:
			menuCitas();
			break;
		case 3:
			menuExpediente();
			break;
		case 4:
			calculadoraImc();
			break;
		default:
			cout<<"Opcion incorrecta\n";
	}
}



int menuCitas(){
	int opcion;
	cout<<"|_________________________|\n";
	cout<<"|          CITAS          |\n";
	cout<<"|-------------------------|\n";
	cout<<"|1). Agregar nueva cita   |\n";
	cout<<"|-------------------------|\n";
	cout<<"|2). Consultar cita Gral  |\n";
	cout<<"|-------------------------|\n";
	cout<<"|3). Eliminar cita        |\n";
	cout<<"|-------------------------|\n";
	cout<<"|4). Editar cita          |\n";
	cout<<"|-------------------------|\n";
	cout<<"|5). Regresar             |\n";
	cout<<"|_________________________|\n";
	cin>>opcion;
	switch(opcion){
		case 1:
			modificarCita();
			menuCitas();
			break;
		case 2:
			menuBuscarCita();
			system("PAUSE");
			menuDoctor();
			break;
		case 3:
			eliminarCita();
			break;
		case 4:
			modificarCita();
			break;
		case 5:
			menuDoctor();
			break;
		default:
			cout<<"Opcion incorrecta\n";
	}
}



int menuBuscarCita(){
	int opcion;
	cout<<"|_____________________________|\n";
	cout<<"|       BUSCAR CITAS          |\n";
	cout<<"|-----------------------------|\n";
	cout<<"|1). Buscar cita por fecha    |\n";
	cout<<"|-----------------------------|\n";
	cout<<"|2). Buscar cita por paciente |\n";
	cout<<"|-----------------------------|\n";
	cout<<"|3). Ver todas las citas      |\n";
	cout<<"|-----------------------------|\n";
	cout<<"|4). Regresar a citas         |\n";
	cout<<"|-----------------------------|\n";
	cout<<"|5). Regresar a expedientes   |\n";
	cout<<"|_____________________________|\n";
	cin>>opcion;
	switch(opcion){
		case 1:
			buscarCitaFecha();
			break;
		case 2:
			buscarCitaID();
			break;
		case 3:
			desplegarListaCita();
			break;
		case 4:
			menuCitas();
			break;
		case 5:
			menuExpediente();
			break;
		default:
			cout<<"Opcion incorrecta\n";
	}
}



int menuExpediente(){
	int opcion;
	cout<<"|_____________________________________|\n";
	cout<<"|            EXPEDIENTE               |\n";
	cout<<"|-------------------------------------|\n";
	cout<<"|1). Buscar expediente del paciente   |\n";
	cout<<"|-------------------------------------|\n";
	cout<<"|2). Consultar todos los expedientes  |\n";
	cout<<"|-------------------------------------|\n";
	cout<<"|3). Regresar                         |\n";
	cout<<"|_____________________________________|\n";
	cin>>opcion;
	switch(opcion){
		case 1:
			buscarPacienteExpediente();
			system("PAUSE");
			menuDoctor();
			break;
		case 2:
			desplegarListaPaciente();
			system("PAUSE");
			menuDoctor();
			break;
		case 3:
			menuDoctor();
			break;
		default:
			cout<<"Opcion incorrecta\n";	
	}
}
