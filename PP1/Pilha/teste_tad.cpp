#include <iostream>
#include <cstring>
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
	char letra = '\0';	
	Comando(){

	}
	Comando(string chave, char letra){
		this->chave = chave;
		this->letra = letra;
	}
	Comando(string chave){
		this->chave = chave;
	}
	void print(){
		cout << chave << " = ";
		cout << letra;
	}
};


class NoComando{
public:
	Comando comando;
	NoComando* prim;
	NoComando* prox;
	NoComando(){
		prox = NULL;
	}
	NoComando(Comando comando){
		this->comando = comando;
		prox = NULL;
	}
};


class ListaComando{
public:
	NoComando* prim;
	NoComando* ult;

	ListaComando(){
		prim = new NoComando();
		prim->prox = NULL;
		ult = prim;
	}	
	void insere(Comando comando){
		ult->prox = new NoComando();
		ult = ult->prox;
		ult->prox = NULL;
		ult->comando = comando;
	}
	NoComando* busca(Comando comando){
		NoComando* p = prim->prox;
		while (p != NULL && p->comando.chave != comando.chave){
			p=p->prox;
		}
		return p;
	}
	void print(){
		NoComando* p = prim->prox;
		while (p != NULL){
			p->comando.print();
			p = p->prox;
			cout << endl;
		}
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


class Fila{
public:
	No<char>* frente;
	No<char>* tras;

	Fila(){
		frente = new No<char>();
		frente->prox = NULL;
		tras = frente;
	}
	void enfileira(char letra){
		tras->prox = new No<char>();
		tras = tras->prox;
		tras->tipo = letra;
		tras->prox = NULL;
	}
	void desenfileira(){
		No<char>* aux;
		aux = frente;
		frente = frente->prox;
		delete aux;
	}
	void print(){
		No<char>* p = frente->prox;
		while(p != NULL){
			cout << p->tipo;
			p = p->prox;
		}
	}
};

class Procedimento{
public:
	string chave;
	ListaComando comandos;
	NoComando* cabecote = comandos.prim;
	int cont = 0;
	Procedimento(){
	}
	Procedimento(string chave){
		this->chave = chave;
	}
	void novoComando(Comando comando){
		comandos.insere(comando);
	}
	
	NoComando* proximoComando(){
		cabecote = cabecote->prox;
		NoComando* proximo = cabecote;
		return proximo;
	}
};

class NoProcedimento{
public:
	Procedimento proc;
	NoProcedimento* prim;
	NoProcedimento* prox;
	NoProcedimento(){
		prox = NULL;
	}
	NoProcedimento(Procedimento proc){
		this->proc = proc;
		prox = NULL;
	}
};

class ListaProcedimento{
public:
	NoProcedimento* prim;
	NoProcedimento* ult;

	ListaProcedimento(){
		prim = new NoProcedimento();
		prim->prox = NULL;
		ult = prim;
	}	
	void insere(Procedimento proc){
		ult->prox = new NoProcedimento();
		ult = ult->prox;
		ult->prox = NULL;
		ult->proc = proc;
	}
	NoProcedimento* busca(Procedimento proc){
		NoProcedimento* p = prim->prox;
		while (p != NULL && p->proc.chave != proc.chave){
			p=p->prox;
		}
		return p;
	}
};

class Pilha{
public:
	NoProcedimento* topo;
	NoProcedimento* fundo;

	Pilha()
	{
		fundo = new NoProcedimento();
		fundo->prox = NULL;
		topo = fundo;
	}

	void empilhar(Procedimento proc)
	{
		NoProcedimento* aux = new NoProcedimento();
		topo->proc = proc;
		aux->prox = topo;
		topo = aux;
	}

	void desempilhar()
	{
		NoProcedimento* aux = topo;
		topo = topo->prox;
		Procedimento proc = topo->proc;
		delete aux;
	}

	bool vazia()
	{
		if (fundo == topo){
			return true;
		}
		else{
			return false;
		}
	}

	NoProcedimento* getTopo(){
		return topo;
	}
};


class Interpretador{
public:
	Fila mensagem = Fila();
	Pilha p =  Pilha();
	ListaProcedimento lista;

	Interpretador(){

	}

	Interpretador(ListaProcedimento lista){
		this->lista = lista;
	}

	void executa(){
		Procedimento aux = Procedimento("Z");
		NoProcedimento* px = lista.busca(aux);
		p.empilhar(px->proc);
	
		while (p.vazia() != true){
			NoProcedimento* proc_topo = p.getTopo();
			NoComando* comando = proc_topo->proc.proximoComando();
			cout << "eaei";

			if (comando->comando.chave == "ENFILEIRA"){
				mensagem.enfileira(comando->comando.letra);
			}
			if (comando->comando.chave == "DESEMFILEIRA")
			{	
				mensagem.desenfileira();	
			}
			if (comando->comando.chave.length() == 2)
			{
				NoProcedimento* busca = lista.busca(Procedimento(comando->comando.chave));
				p.empilhar(busca->proc);
			}
			else{
				p.desempilhar();
			}

		}
	}
};

int main()
{
	Pilha pilha;
	ListaProcedimento lista;

	Procedimento Z = Procedimento("Z");
	Comando comando = Comando("ENFILEIRA", 'A');
	Z.novoComando(comando);
	Comando comando2 = Comando("DESEMPILHA");
	Z.novoComando(comando2);

	NoComando* x = Z.proximoComando();

	lista.insere(Z);

	Interpretador i = Interpretador(lista);
	i.executa();

	i.mensagem.print();
	return 0;
}
