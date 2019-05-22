#include <iostream>
using namespace std;

class NoLetra{
public:
	string letra;
	NoLetra* prim;
	NoLetra* prox;
	NoLetra(){
		prox = NULL;
	}
	NoLetra(string letra){
		this->letra = letra;
		prox = NULL;
	}
};

class Fila{
public:
	NoLetra* frente;
	NoLetra* tras;

	Fila(){
		frente = new NoLetra();
		frente->prox = NULL;
		tras = frente;
	}
	void enfileira(string inserir){
		tras->prox = new NoLetra();
		tras = tras->prox;
		tras->letra = inserir;
		tras->prox = NULL;
	}
	void desenfileira(){
		NoLetra* aux;
		aux = frente;
		frente = frente->prox;
		delete aux;
	}
	void print(){
		NoLetra* p = frente->prox;
		while(p!= NULL){
			cout << p->letra;
			p = p->prox;
		}
	}
};

int main(int argc, const char * arg[]){
	Fila fila;

	fila.enfileira("X");
	fila.enfileira("Q");
	fila.enfileira("A");
	fila.enfileira("T");
	fila.desenfileira();
	fila.enfileira("A");
	fila.enfileira("T");
	fila.enfileira("A");
	fila.enfileira("Q");
	fila.desenfileira();
	fila.desenfileira();
	fila.enfileira("U");
	fila.enfileira("E");
	fila.desenfileira();

	fila.print();
}