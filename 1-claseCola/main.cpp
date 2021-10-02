#include <iostream>
#include "Cola.h"
using namespace std;

Cola cola;

void leerOpcion(int&);
void gestionError(int&);

int main(){
	int opcion;
	do{
		system("CLS");
		cout<<
		"[1] Inicializar\n"<<
		"[2] Push\n"<<
		"[3] Pop\n"<<
		"[4] Desplegar\n"<<
		"[5] Limpiar\n"<<
		"[6] Salir\n\n"<<
		" > ";
		cin>>opcion;
		leerOpcion(opcion);
	}while(opcion != 6);
	return 0;
}

void leerOpcion(int &opcion){
	cout<<"\n--------------------------------\n";
	int dato, salida;
	switch(opcion){
		case 1:
			cola.inicializar();
			cout<<"\nestructura inicializada"<<endl;
			break;
		case 2:
			cout<<" dato > ";
			cin>>dato;
			salida = cola.push(dato);
			if (salida < 0){
				gestionError(salida);
			}else{
				cout<<"\nEl numero "<<salida<<" ingreso correctamente"<<endl;
				cola.desplegar();
			}
			break;
		case 3:
			salida = cola.pop();
			if (salida < 0){
				gestionError(salida);
			}else{
				cout<<"\nEl numero "<<salida<<" salio correctamente"<<endl;
				cola.desplegar();
			}
			break;
		case 4:
			salida = cola.desplegar();
			if (salida < 0){
				gestionError(salida);
			}else{
				cout<<"";
			}
			break;
		case 5:
			salida = cola.vaciar();
			if (salida < 0){
				gestionError(salida);
			}else{
				cout<<"\nLa estructura ha sido vaciada"<<endl;
				cola.desplegar();
			}
			break;
		case 6: cout<<"\nEjecucion terminada"<<endl;
			break;
		default:
			cout<<"\nOpcion "<< opcion <<" no existe"<<endl;
	}
	cout<<"\n--------------------------------\n";
	system("pause");
}

void gestionError(int &error){
	switch ( error ){
		case -1: cout<<"\nERROR: La estructura no esta inicializada"<<endl;
			break;
		case -2: cout<<"\nERROR: La estructura esta llena (OVERFLOW)"<<endl;
			break;
		case -3: cout<<"\nERROR: La estructura esta vacia (UNDERFLOW)"<<endl;
	}
	return;
}


