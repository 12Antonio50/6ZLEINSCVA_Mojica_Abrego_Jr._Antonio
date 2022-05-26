#include <iostream>

using namespace std;

int main(){
	
	int diaN, mesN, anN;
	int diaA, mesA, anA;
	int edadD, edadM, edadA, edadDt;
	
	while(diaN >=32 || mesN >=13 || anN < 1900|| anN > 2022 ){
	
	cout<<"Ingresa la fecha de nacimiento DD/MM/AA"<<endl;
	cin>>diaN;
	cin>>mesN;
	cin>>anN;
	
	
	if(diaN >=32 || mesN >=13 ||anN < 1900|| anN > 2022 ){
		cout<<"Error volver a ingresar datos"<<endl;
	}else if((anN %  4 == 0 && anN % 100 != 0 || anN % 400 == 0)){
			if(diaN >31 || mesN >12 ||anN < 1900 || anN >2023){
			cout<<"";
		}else{
			cout<<"Naciste en un anio bisiesto"<<endl;
		}
	}else if(diaN >28 && mesN == 2){
		cout<<"Error ya que febrero tiene solo 28 dias";
	}
		
	}
	
	do{
	cout<<"Ingresa la fecha actual DD/MM/AA"<<endl;
	cin>>diaA;
	cin>>mesA;
	cin>>anA;
	
	if(diaA >31 || mesA > 12 || anA < 2021 || anA > 2023){
		cout<<"Error volver a ingresar datos"<<endl;
	}
	}while(diaA >31 || mesA > 12|| anA <2021 || anA > 2023);
	
	if((anN %  4 == 0 && anN % 100 != 0 || anN % 400 == 0)){
		edadD= diaA-diaN;
		edadM= mesA-mesN+1;
		edadA= anA-anN;
	}
	
	if(mesN<mesA){
		edadD= (diaA-diaN)+1;
		edadM= mesA-mesN;
		edadA= anA-anN;
	}
	if(mesN==mesA){
		if(diaN<=diaA){
			edadD= diaA-diaN;
			edadM= mesA-mesN;
			edadA= anA-anN;
		}else{
			edadD= (diaA-diaN)+1;
			edadM= mesA-mesN;
			edadA= anA-anN;
			
		}
	}
	if(mesN>mesA){
		edadD= diaA-diaN+1;
		edadM= (12-mesN)+mesA;
		edadA= (anA-anN)-1;
		
	}
	cout<<"La edad es dia "<<edadD<<" mes "<<edadM<<" anios "<<edadA;
	
	return 0;
}
