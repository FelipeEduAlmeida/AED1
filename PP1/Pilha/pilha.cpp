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

class Procedimento{
	char nome;
	

	void enfileira(string letra){
		Pilha::enfileira(letra);
	}
	void desenfileira(){
		Pilha::desenfileira();
	}
}
class NoProced{
public:
	Procedimento proc;
	NoProced* prim;
	NoProced* prox;
	NoProced(){
		prox = NULL;
	}
	NoProced(Type type){
		this->proc = proc;
		prox = NULL;
	}
};

class Pilha{
public:
	NoProced* topo;
	NoProced* fundo;

	Pilha()
	{
		fundo = new NoProced();
		fundo->prox = NULL;
		topo = fundo;
	}

	void empilhar(Type item)
	{
		aux = new NoProced();
		topo->item = item
		aux->prox = topo;
		topo = aux;
	}

	void desempilhar()
	{
		aux = topo;
		topo = topo->prox;
		item = topo->item;
		delete aux;
	}
};


int main()
{
	Pilha<string> pilha;

	pilha.empilhar("Z");
	pilha.empilhar("B");
	pilha.empilhar("A");
	pilha.empilhar("C");
	
	pilha.desempilhar();
	
	cout << pilha.item;

	return 0;
}
