#include <iostream>
using namespace std;

class Comando{
public:
	string chave;
	string letra;	
	Comando(){

	}
	Comando(string chave, char letra){
		this->chave = chave;
		this->letra = letra;
	}
	Comando(string chave){
		this->chave = chave;
	}
};

template <class Tipo>
class No{
public:
	Tipo tipo;
	No<Tipo>* prim;
	No<Tipo>* prox;
	No(){
		prox = NULL;
	}
	No(Tipo tipo){
		this->tipo = tipo;
		prox = NULL;
	}
};

template <class Tipo>
class Lista{
public:
	No<Tipo>* prim;
	No<Tipo>* ult;

	Lista(){
		prim = new No<Tipo>();
		prim->prox = NULL;
		ult = prim;
	}	
	void insere(Tipo tipo){
		ult->prox = new No<Tipo>();
		ult = ult->prox;
		ult->prox = NULL;
		ult->tipo = tipo;
	}
	No<Tipo>* busca(Tipo tipo){
		No<Tipo>* p = prim->prox;
		while (p != NULL && p->tipo.chave != tipo.chave){
			p=p->prox;
		}
		return p;
	}
};

class Procedimento{
public:
	string chave;
	Lista<Comando> lista;
	Procedimento(){

	}
	Procedimento(string chave){
		this->chave = chave;
	}
};

int main()
{
	string entrada[1000];
	int cont;

	do{
		cin >> entrada[cont];
		cont++;
	}while(entrada[cont-1] != "~");

	cont = 0;

	Procedimento proc("Z");

	while(entrada[cont] != "~"){
		if (entrada[cont] >= "ENFILEIRA"){
			Comando a("ENFILEIRA", entrada[cont][11]);
			proc.lista.insere(a);
		}
		else if(entrada[cont] == "DESENFILEIRA"){
			Comando b("DESENFILEIRA");
			proc.lista.insere(b);
		}
		cont++;
	};
	Comando x("ENFILEIRA", entrada[0][11]);
	No<Comando>* aux = proc.lista.busca(x);
	cout << aux->tipo.letra;
	return 0;
}