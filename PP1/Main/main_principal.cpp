#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using namespace std; 
#include<cstring>
#include<string>
using std::string;
using std::getline;

#define BASE 37
#define TAMHASH 7

/*inicio da tabela hash*/
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
			cout << "";

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

//principal
class Par{
public:
	string azuri;
	string ianteco;
	string chave;

	Par(){}
	Par(string ianteco, string azuri){
		this->ianteco = ianteco;
		this->azuri = azuri;
		chave = ianteco;
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

class TabelaHash{
public:
	Lista<Par>* vetor[TAMHASH];

	TabelaHash(){
	};

	int funcaoHash(string ianteco){
		
		int peso = 0;
		int aux = ianteco.length();
		for(int i = 0; i < ianteco.length(); i++){
			peso += ianteco[i] * (BASE^aux);
			aux--;
		}
		int hash;
		hash = peso % 7;
		return hash;
	}

	void inicializador(){
		for (int i=0; i<TAMHASH; i++){
			vetor[i] = new Lista<Par>(); 
		}

		Par a(":::", "A");
		vetor[funcaoHash(":::")]->insere(a);

		Par b(".::", "B");
		vetor[funcaoHash(".::")]->insere(b);

		Par c(":.:", "C");
		vetor[funcaoHash(":.:")]->insere(c);

		Par d("::.", "D");
		vetor[funcaoHash("::.")]->insere(d);

		Par e(":..", "E");
		vetor[funcaoHash(":..")]->insere(e);

		Par f(".:.", "F");
		vetor[funcaoHash(".:.")]->insere(f);

		Par g("..:", "G");
		vetor[funcaoHash("..:")]->insere(g);

		Par h("...", "H");
		vetor[funcaoHash("...")]->insere(h);

		Par i("|::", "I");
		vetor[funcaoHash("|::")]->insere(i);

		Par j(":|:", "J");
		vetor[funcaoHash(":|:")]->insere(j);

		Par k("::|", "K");
		vetor[funcaoHash("::|")]->insere(k);

		Par l("|.:", "L");
		vetor[funcaoHash("|.:")]->insere(l);

		Par m(".|:", "M");
		vetor[funcaoHash(".|:")]->insere(m);

		Par n(".:|", "N");
		vetor[funcaoHash(".:|")]->insere(n);

		Par o("|:.", "O");
		vetor[funcaoHash("|:.")]->insere(o);

		Par p(":|.", "P");
		vetor[funcaoHash(":|.")]->insere(p);

		Par q(":.|", "Q");
		vetor[funcaoHash(":.|")]->insere(q);

		Par r("|..", "R");
		vetor[funcaoHash("|..")]->insere(r);

		Par s(".|.", "S");
		vetor[funcaoHash(".|.")]->insere(s);

		Par t("..|", "T");
		vetor[funcaoHash("..|")]->insere(t);

		Par u(".||", "U");
		vetor[funcaoHash(".||")]->insere(u);

		Par v("|.|", "V");
		vetor[funcaoHash("|.|")]->insere(v);

		Par w("||.", "W");
		vetor[funcaoHash("||.")]->insere(w);

		Par x("-.-", "X");
		vetor[funcaoHash("-.-")]->insere(x);

		Par y(".--", "Y");
		vetor[funcaoHash(".--")]->insere(y);

		Par z("--.", "Z");
		vetor[funcaoHash("--.")]->insere(z);

		Par branco("---", " ");
		vetor[funcaoHash("---")]->insere(branco);

		Par til("~", "~");
		vetor[funcaoHash("~")]->insere(til);

		Par doispontos(":  ", ":");
		vetor[funcaoHash(":  ")]->insere(doispontos);

	}
	
	string buscaHash(string ianteco){
		int indice = funcaoHash(ianteco);
		Par aux(ianteco, "");
		No<Par>* no = vetor[indice]->busca(aux);
		string saida = no->tipo.azuri;
		return saida;
	}
};

int main(int argc, const char * arg[]){ 
	
	string linhaEntrada;
	string programaIanteco[1000];
	string programaAzuri[1000];
	int numeroLinhas = 0;
	TabelaHash th;
	th.inicializador();
	int auxtres = 0;

	do{
		getline(cin, linhaEntrada);
		programaIanteco[numeroLinhas] = linhaEntrada;
		numeroLinhas++;
	}while (linhaEntrada[0] != '~');

	numeroLinhas = 0;
	
	
	do{
		for (int i = 0; i < programaIanteco[numeroLinhas].length(); i+=3){	
			string letraIanteco = "";
			if (programaIanteco[numeroLinhas][0] == '~'){
				letraIanteco += "~";
				programaAzuri[numeroLinhas] += th.buscaHash(letraIanteco);
				break;
			}
			else{
				for(int j = 0; j < 3; j++){
					letraIanteco += (programaIanteco[numeroLinhas][i+j]);
				}
			}
			programaAzuri[numeroLinhas] += th.buscaHash(letraIanteco);
			
		}
		numeroLinhas++;
	}while (programaIanteco[numeroLinhas-1][0] != '~');



	for (int i=0; i < numeroLinhas; i++){
		cout << programaAzuri[i] << endl;
	}
	//pilha

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
}