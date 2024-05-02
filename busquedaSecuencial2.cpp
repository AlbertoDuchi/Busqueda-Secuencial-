#include<iostream>
using namespace std;
//prototipos de funciones y procedimientos
void mostraDatos(int A[], string titulo, int tamanio);
bool ordenadatos(int A[], int tamanio, int numBuscar, int &pos);
int main(){
	int A[]={5,6,2,8,9,1,3};
	int numBuscar, tamanio, pos=-1;
	tamanio=sizeof A/ sizeof A[0];
	mostraDatos(A, "Lista de Datos", tamanio);
	cout<<"\nNumero a buscar: ";
	cin>>numBuscar;
	//buscar
	bool encontrado=false;
	encontrado=ordenadatos(A, tamanio, numBuscar, pos);
	if(encontrado){
		cout<<numBuscar<<" Encontrado en la pos: "<<pos+1<<endl;
	}else{
		cout<<numBuscar<<" No encontrado\n";
	}
	return 0;
}
// desarrollo de los prototipos 
void mostraDatos(int A[], string titulo, int tamanio){
	//listar datos
	cout<<" ****** "<< titulo<<" *****\n";
	for(int i=0; i< tamanio; i++){
		cout<<A[i]<<" ";
	}
		
};
bool ordenadatos(int A[], int tamanio, int numBuscar, int &pos){
	bool encontrado=false;
	for(int i=0;i<tamanio;i++){
		if(A[i]==numBuscar){
			encontrado=true;
			pos=i;		
			break;
		}
	}
	return 	encontrado;
};