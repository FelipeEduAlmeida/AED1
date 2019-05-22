#include <iostream>
using namespace std;

class Procedimento{
public:
	char nome;
	
	Procedimento(){}
	void enfileira(string letra){
		
	}
	void desenfileira(){
		
	}
};
class NoProced{
public:
	Procedimento proc;
	NoProced* prim;
	NoProced* prox;
	NoProced(){
		prox = NULL;
	}
	NoProced(Procedimento proc){
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

	void empilhar(Procedimento proc)
	{
		NoProced* aux = new NoProced();
		topo->proc = proc;
		aux->prox = topo;
		topo = aux;
	}

	void desempilhar()
	{
		NoProced* aux = topo;
		topo = topo->prox;
		Procedimento proc = topo->proc;
		delete aux;
	}
};


int main()
{
	/*
	Pilha<string> pilha;

	pilha.empilhar();
	pilha.empilhar();
	pilha.empilhar();
	pilha.empilhar();
	
	pilha.desempilhar();
	
	cout << pilha.item;
	*/
	return 0;
}
