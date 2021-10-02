#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <iostream>
#include <unistd.h>
#include "Cola.h"
using namespace std;

int secondsToArrive();
string randomClient();
int secondsToLeave();

Cola cola;

string names[25] = {
	"a", "b", "c", "d", "e",
	"f", "g", "h", "i", "j",
	"k", "l", "m", "n", "o",
	"p", "q", "r", "s", "t",
	"u", "v", "w", "x", "y",
};

int main(){
	srand(time(NULL));
	int timer = 0;
	int timer2 = secondsToLeave();
	int clientCount = 0;
	string cliente;
	cola.inicializar();
	
	for (int i = 0; i<61; i++){
		system("cls");
		cout<<"TIME: "<<i<<endl;
		
		
		if (timer == 0){
			cola.push(randomClient());
			timer = secondsToArrive();
		}
		
		if (cola.estaVacia()){
			cliente = cola.getFrente();
			cola.pop();
			timer2 = secondsToLeave();
		}
		if (timer2 == 0){
			cliente = cola.getFrente();
			cola.pop();
			timer2 = secondsToLeave();
			++clientCount;
		}
		--timer;
		--timer2;
		cout<<"Cliente siendo despachado: "<<cliente<<endl;
		/*
		cout<<"CLIENTE: "<<cliente<<endl;
		cout<<"Siguiente: "<<cola.getFrente();
		cout<<"Ultimo en llegar: "<<cola.getFinal();
		*/
		cout<<"QUEUE: ";
		cola.desplegar();
		cout<<
		"\nTIMER1: "<<timer<<"\n"<<
		"TIMER2: "<<timer2<<"\n"<<
		"clientCount: "<<clientCount<<endl;
		
		//clientTime(rand() % 3 + 2);
		sleep(1);
	}
	cout<<"\n--------------------------------\n";
	cout<<"Clientes despachados: "<<clientCount<<endl;
	cout<<"Clientes en cola: "<<cola.getSize()<<endl;
	cout<<"Cliente que por despachar: "<<cliente<<endl;
	cout<<"Frente de la cola: "<<cola.getFrente()<<endl;
	cout<<"Final de la cola: "<<cola.getFinal()<<endl;
	return 0;
}

string randomClient(){
	return names[rand() % 9 + 0];
}

int secondsToArrive(){
	return (rand() % 3 + 2);
}

int secondsToLeave(){
	return (rand() % 4 + 3);
}




/*
--120 second timer:--
for (int i = 0; i<121; i++){
	system("cls");
	cout<<i<<endl;
	sleep(1);
}



*/
