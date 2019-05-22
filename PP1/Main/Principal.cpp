#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using namespace std; 

#include<string>
using std::string;
using std::getline;

#define BASE 37
#define TAMHASH 7

/*inicio da tabela hash*/
class Par{
public:
	string azuri;
	string ianteco;
	Par(){}
	Par(string ianteco, string azuri){
		this->ianteco = ianteco;
		this->azuri = azuri;
	}
};

class NoPar{
public:
	Par par;
	NoPar* prox;
	NoPar(){
		prox = NULL;
	}
	NoPar(Par par){
		this->par = par;
		prox = NULL;
	}
};

class Lista{
private:
	NoPar* prim;
	NoPar* ult;
public:
	Lista(){
		prim = new NoPar();
		prim->prox = NULL;
		ult = prim;
	}	
	void insere(Par par){
		ult->prox = new NoPar();
		ult = ult->prox;
		ult->prox = NULL;
		ult->par = par;
	}
	NoPar* busca(Par par){
		NoPar* p = prim->prox;
		while (p != NULL && p->par.ianteco != par.ianteco){
			p=p->prox;
		}
		return p;
	}
};

class TabelaHash{
public:
	Lista* vetor[TAMHASH];

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
			vetor[i] = new Lista(); 
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
		NoPar* NoPar = vetor[indice]->busca(aux);
		string saida = NoPar->par.azuri;
		return saida;
	}
};

int main(int argc, const char * arg[]){ 
	
	string linhaEntrada;
	string programaEntrada;
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
}
