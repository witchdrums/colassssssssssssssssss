#include <iostream>
using namespace std;

class Cola {
	private:
		int cola[5];
		int fondo, tope, cima;
		bool inicializada = false;
		
		bool estaLlena() {
			if ( cima > tope) {
				return true;
			}
			else{
				return false;
			}
		}
		
		bool estaVacia() {
			if( cima == fondo ){
				return true;
			} else{
				return false;
			}
		}
		
		void reorganizarCola(int i ){
			if(i == cima){
				cola[cima] = -1;
				return;
			}else {
				cola[i] = cola[i+1];
				reorganizarCola(++i);
			}
		}
		void desplegarR(int i){
			if (i == -1){
				return;
			}else{
				cout<<*(cola + i);
				if ( i > 0 ) cout<<", ";
				desplegarR(--i);
			}
		}
		void vaciarR(){
			if ( estaVacia() ){
				return;
			}else{
				pop();
				vaciarR();
			}
		}
	public: 
		void inicializar() {
			inicializada = true;
			cima = 0;
			fondo = 0;
			tope = sizeof(cola)/sizeof(*cola) - 1;
		}
		
		int push(int n) {
			if ( !inicializada ){
				return -1;
			}else if( estaLlena() ) {
				return -2;
			}else{
				cola[cima++] = n;
				return n;
			}
		}
		
		int pop() {
			if ( !inicializada ){
				return -1;
			}else if( estaVacia() )	{
				return -3;
			} else {
				int dato = cola[fondo];
				*(cola + fondo) = -1;
				--cima;
				reorganizarCola(0);
				return dato;
			}
		}
		
		int desplegar(){
			if (!inicializada){
				return -1;
			}else{
				cout<<"Cola = [";
				desplegarR(cima-1);
				cout<<"]"<<endl;
				return 4;
			}
		}
		
		int vaciar(){
			if (!inicializada){
				return -1;
			} else if ( estaVacia() ){
				return -3;
			} else {
				vaciarR();
				return 1;
			}
		}
};
