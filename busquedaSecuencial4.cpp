#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
class Persona{
	private:
		string nombre;
		bool casado;
	public:
		Persona();
		void setNombre(string nombre);
		void setCasado(bool casado);
		string getNombre();
		bool getCasado();
};
Persona::Persona(){
	nombre="S/N";
	casado=false;
};
void Persona::setNombre(string nombre){
	this->nombre=nombre;
};
void Persona::setCasado(bool casado){
	this->casado=casado;
};
string Persona::getNombre(){
	return nombre;
};
bool Persona::getCasado(){
	return casado;
};
void menu();
void ingresoDatos(vector<Persona> &lista);
void buscarDato(vector<Persona> lista, string nombreBuscar);
void mostrarDatos(vector<Persona> lista, string titulo);
int main(){
	vector<Persona> lista;
	string nombreBuscar;
	int op;
	system("color 97");
	do{
		system("cls");
		menu();	
		cin>>op;
		switch (op){
			case 1:
				system("cls");
				cout<<"\n***** Ingreso de Datos ********\n\n";
				ingresoDatos(lista);
				system("pause");
				break;
			case 2:
				system("cls");
				mostrarDatos(lista, "Listado de Datos");
				system("pause");
				break;
			case 3: 
				system("cls");
				buscarDato(lista, nombreBuscar);
				system("pause");
				break;			
			case 4:
				system("cls");
				cout<<"Programa finalizado\n";
				system("pause");
				break;
			default:
				break;				
		}
	}while(op!=4);
	return 0;
}
void menu(){
	cout<<"1.- Ingreso datos\n";
	cout<<"2.- Mostrar datos\n";
	cout<<"3.- Buscar datos\n";
	cout<<"4.- Salir\n";
	cout<<"Seleccione una opcion....: ";	
};
void ingresoDatos(vector<Persona> &lista){
	string nombre;
	int bandera;
	bool casado;
	Persona objPersona;
	cout<<"Ingrese el nombre: ";
	getline(cin>>ws,nombre);
	do{
	    bandera=0;
	    cout<<"Casado: NO (0) Si(1): ";
		cin>>casado;
		if (cin.fail()){
			cin.clear();
			cout<<"\tError\n";
			bandera=1;
		};					
	}while(bandera==1);
	//guardar
	objPersona.setNombre(nombre);
	objPersona.setCasado(casado);
	lista.push_back(objPersona);	
};
void buscarDato(vector<Persona> lista, string nombreBuscar){
	bool  encontrado=false;
	int contador=0, pos=-1;
	if(lista.size()>0){
		cout<<"Nombre a Buscar: ";
		getline(cin>>ws,nombreBuscar);
		for(auto i: lista){
			if(i.getNombre()==nombreBuscar){
				encontrado=true;
				pos=contador;		
				break;
			}
			contador++;						
		}
		if(encontrado){
			cout<<nombreBuscar<<" Encontrado en la pos: "<<pos+1<<endl;
		}else{
			cout<<nombreBuscar<<" No encontrado\n";
		}
	}else{
		cout<<"Lista vacia\n";
	}	
};
void mostrarDatos(vector<Persona> lista, string titulo){
	cout<<"\n***** "<<titulo<<" *****\n";
	if(lista.size()>0){
		cout<<setw(15)<<left<<"Nombres"<<setw(15)<<left<<"Apellidos"<<endl;
		for(auto i: lista){
			string estado=(i.getCasado())?"Casado":"No Casado";
			cout<<setw(15)<<left<<i.getNombre()<<setw(50)<<left<<estado<<endl;
		}
	}else{
		cout<<"Lista vacia\n";
	}	
};