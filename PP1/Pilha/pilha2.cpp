#include <iostream>
using namespace std;

class Letra{
	string letra;
	string chave;
	Letra(){

	}
	Letra(string letra){
		this->letra = letra;
		chave = letra;
	}
};

class Comando{
public:
	string chave;
	string letra;	
	Comando(string chave, string letra){
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

template <class Tipo>
class Fila{
public:
	No<Tipo>* frente;
	No<Tipo>* tras;

	Fila(){
		frente = new No<Tipo>();
		frente->prox = NULL;
		tras = frente;
	}
	void enfileira(Tipo tipo){
		tras->prox = new No<Tipo>();
		tras = tras->prox;
		tras->tipo = tipo;
		tras->prox = NULL;
	}
	void desenfileira(){
		No<Tipo>* aux;
		aux = frente;
		frente = frente->prox;
		delete aux;
	}
	void print(){
		No<Tipo>* p = frente->prox;
		while(p!= NULL){
			cout << p->tipo;
			p = p->prox;
		}
	}
};

class Procedimento{
public:
	string chave;
	Lista<Comando> comandos;
	int cont = 0;
	Procedimento(){
	}
	Procedimento(string chave){
		this->chave = chave;
	}
	void novoComando(Comando comando){
		comandos.insere(comando);
		cont++;
	}
};

template <class Tipo>
class Pilha{
public:
	No<Tipo>* topo;
	No<Tipo>* fundo;

	Pilha()
	{
		fundo = new No<Tipo>();
		fundo->prox = NULL;
		topo = fundo;
	}

	void empilhar(Tipo tipo)
	{
		No<Tipo>* aux = new No<Tipo>();
		topo->tipo = tipo;
		aux->prox = topo;
		topo = aux;
	}

	void desempilhar()
	{
		No<Tipo>* aux = topo;
		topo = topo->prox;
		Procedimento proc = topo->proced;
		delete aux;
	}

	No<Tipo>* getTopo(){
		return topo;
	}
};

class Interpretador{
	Fila<string> mensagem;
	Pilha<Procedimento> p;
	Lista<Procedimento> lista;

	Interpretador(Lista<Procedimento> lista){
		this->lista = lista;
	}

	void executa(){
		p.empilhar(Z)
		while (p != NULL){
			No<Procedimento>* proc_topo = p.getTopo();
			comando = proc_topo->proximoComando(); 
		}
	}
};

int main()
{
	Lista<Procedimento> lista;
	


	Procedimento Main = new Procedimento("Z");
	A.novoComando("ENFILEIRA", "A");
	A.novoComando("DESENFILEIRA");

	lista.insere(A);

	
	cout << pilha.item;
	return 0;
}
