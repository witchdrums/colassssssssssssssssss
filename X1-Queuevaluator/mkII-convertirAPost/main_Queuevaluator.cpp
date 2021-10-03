#include <iostream>
#include "Cola.h"
#include "Pila.h"
#include <string.h>
#include <cmath>
using namespace std;

Cola cola;
Pila pila;

void llenarCola(string, int, int);
void pushNumber(string expresion, int position, int &i, int);
void paso3();
void paso4();
void evaluar();
float operar();

int main(){
	cola.inicializar("Postfija");
	pila.inicializar();
	string choice;
	do{
		choice = "";
		system("cls");
		cout<<"Evaluador de Expresiones Aritm"<<char(130)<<"ticas"<<
		"\n--------------------------------\n"<<
		"Ingrese una expresi"<<char(162)<<"n arim"<<char(130)<<"tica sin espacios, o escriba 'n' para salir\n"<<endl;
		cout<<" Expresi"<<char(162)<<"n > ";
		cin>>choice;
		if (choice != "n")
			llenarCola(choice, 0, choice.size());
	}while(choice != "n");
	return 0;
}
void llenarCola( string expresion, int i, int size ){
	if ( i == size ){
		cout<<"\n--------------------------------\n";
		paso4();
		cout<<"Infija = "<<expresion<<endl;
		cola.desplegar();
		pila.desplegar();
		evaluar();
		return;		
	}else{
		if ( expresion[i] > 47 && expresion[i] < 58 || expresion[i] == '.'  ){
			int position = i;
			pushNumber(expresion, position, i, 0);
		}else if (pila.estaVacia()){
			pila.push( expresion.substr(i++,1) );
		}else{
			switch(expresion[i]){
				case '(':
				case '^':
					pila.push( expresion.substr(i++,1) );
					break;
				case '*':
				case '/':
					switch ( pila.getCima()[0] ){
						case '^':
						case '*':
						case '/':
							cola.push( pila.getCima() );
							pila.pop();
							break;
						default:
							pila.push( expresion.substr(i++,1) );
					}
					break;
				case '+':
				case '-':
					if ( pila.getCima()[0] == '('){
						pila.push( expresion.substr(i++,1) );
					}else{
						cola.push( pila.getCima() );
						pila.pop();
					}
					break;				
				case ')':
					paso3();
					++i;
					break;
			}
		}
		llenarCola(expresion, i, size);
	}
}
void pushNumber(string expresion, int position, int &i, int j){
	if ( !(expresion[i] > 47 && expresion[i] < 58 || expresion[i] == '.' ) ){
		cola.push( expresion.substr(position, j));
	}else{
		pushNumber(expresion, position, ++i, ++j);
	}
}
void paso4(){ // pasar contenidos de pila a posfija
	if (pila.estaVacia()){
		return;
	}else{
		if ( pila.getCima()[0] == '(' ){
			pila.pop();
		}else{
			cola.push(pila.getCima());
			pila.pop();	
		}
		paso4();
	}
}
void paso3(){ // pasar contenido de pila hasta topar con (
	if (pila.getCima()[0] == '('){
		pila.pop();
		return;
	}else{
		cola.push(pila.getCima());
		pila.pop();
		paso3();
	}
}
void evaluar(){
	if ( cola.estaVacia() ){
		cout<<"Resultado = "<<stof( pila.getCima() )<<endl;
		pila.pop();
		system("pause");
		return;
	}else{
		switch ( cola.getFrente()[0] ){
			case '^':
			case '/':
			case '*':
			case '+':
			case '-':
				pila.push( to_string( operar( ) ) );
				break;
			default:
				pila.push(cola.getFrente());
		}
		cola.pop();
		evaluar();
	}
}
float operar(){
	float a = stof( pila.getCima() );
	pila.pop();
	float b = stof( pila.getCima() );
	pila.pop();
	switch ( cola.getFrente()[0] ){
		case '^': return pow(b,a);
		case '/': return b/a;
		case '*': return b*a;
		case '+': return b+a;
		case '-': return b-a;
	}
}

