#include <iostream>
#include "Cola.h"
#include "Pila.h"
#include <string.h>
using namespace std;


Cola cola;
Pila pila;

string expresiones[10] = {
	"1+3",
	"12+3/(4*2)", //12342*/+
	"(1/2)^3+4*(5-6)",
	"1.432-(22^2*14)/(12+37/21^2)",
	
};

void llenarCola(string, int, int);
void pushNumber(string expresion, int position, int &i, int);

int main(){
	cola.inicializar();
	pila.inicializar();
	string expresion = expresiones[2];
	int size = expresion.size();
	

	llenarCola(expresion, 0, size);
	
	return 0;
}

void llenarCola( string expresion, int i, int size ){
	if ( i == size ){
		cola.desplegar();
		return;		
	}else{
		switch(expresion[i]){
			case '(':
			case ')':
			case '^':
			case '*':
			case '/':
			case '+':
			case '-':
				cola.push( expresion.substr(i++,1) );
				break;				
			default:
				int position = i;
				pushNumber(expresion, position, i, 0);
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

/*
void llenarCola(
	string expresion, 
	int i, 
	int Li, 
	int Ls,
	int size, 
	string help)
{
	if ( i == size ){
		cola.desplegar();
		return;		
	}else{
		switch(expresion[i]){
			case '^':
			case '*':
			case '/':
			case '+':
			case '-':{
				cola.push( expresion.substr(Li, Ls) );
				Li = i;
				//help = "";
				//string s(1, expresion[i]);
				cola.push( expresion.substr(Li,1) );
				break;				
			}default:
				++Ls;
		}
		llenarCola(expresion, ++i, Li, Ls, size, help)
	}
}


*/


//use substring to recursively extract numbers??
