#include<iostream>
using namespace std;
int main(){
	int A[]={5,6,2,8,9,1,3};
	int numBuscar, tamanio, pos=-1;
	tamanio=sizeof A/ sizeof A[0];
	//listar datos
	for(auto i: A){
		cout<<i<<" ";
	}
	cout<<"\nNumero a buscar: ";
	cin>>numBuscar;
	//buscar
	bool encontrado=false;
	for(int i=0;i<tamanio;i++){
		if(A[i]==numBuscar){
			encontrado=true;
			pos=i;
			break;
		}
	}
	if(encontrado){
		cout<<numBuscar<<" Encontrado en la pos: "<<pos+1<<endl;
	}else{
		cout<<numBuscar<<" No encontrado\n";
	}
	return 0;
}