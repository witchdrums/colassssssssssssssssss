#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iostream>
#include <unistd.h>
#include "Cola.h"
using namespace std;


string randomClient();
int getNumeroAleatorio(int i, int j);
void segundoPasa();
void cajero();
Cola cola;

int seconds, segundosParaLlegar, segundosParaDespachar, clientCount;
string cliente;

string names[25] = {
	"a", "b", "c", "d", "e",
	"f", "g", "h", "i", "j",
	"k", "l", "m", "n", "o",
	"p", "q", "r", "s", "t",
	"u", "v", "w", "x", "y",
};

int main(){
	srand(time(NULL));
	cola.inicializar();
	
	cajero();

	return 0;
}

void cajero(){
	if (seconds == 60){
		cout<<"\n--------------------------------\n";
		cout<<"Clientes despachados: "<<clientCount<<endl;
		cout<<"Clientes en cola: "<<cola.getSize()<<endl;
		cout<<"Cliente por despachar: "<<cliente<<endl;
		cout<<"Frente de la cola: "<<cola.getFrente()<<endl;
		cout<<"Final de la cola: "<<cola.getFinal()<<endl;
		return;
	}else{
		system("cls");
		cout<<"\t\tSegundos: "<<seconds<<"\n\n";
			
		if (segundosParaLlegar == 0){
			cola.push(randomClient());
			segundosParaLlegar = getNumeroAleatorio(4,2);
		}
		
		if (cliente == ""){
			cliente = cola.getFrente();
			cola.pop();
			segundosParaDespachar = getNumeroAleatorio(5,3);
			segundosParaLlegar = getNumeroAleatorio(4,2);
		}
		if (segundosParaDespachar == 0){
			cliente = cola.getFrente();
			cola.pop();
			segundosParaDespachar = getNumeroAleatorio(5,3);
			++clientCount;
		}
		cout<<"Despachando: "<<cliente<<endl;
		cout<<"Despachar: "<<segundosParaDespachar<<endl;
		cout<<"Despachados: "<<clientCount<<"\n\n";
		cout<<"Cola: ";
		cola.desplegar();
		cout<<"\nLlegar: "<<segundosParaLlegar<<endl;
		sleep(1);
		segundoPasa();
		cajero();
	}
}

void segundoPasa(){
	++seconds; 
	--segundosParaLlegar;
	--segundosParaDespachar;
}

string randomClient(){
	return names[ getNumeroAleatorio(25,0) ];
}


int getNumeroAleatorio(int i, int j){ // max-1, min
	return (rand() % (--i) + j);
}


