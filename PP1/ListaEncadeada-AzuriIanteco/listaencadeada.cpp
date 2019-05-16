#include <iostream>
using namespace std;


class Par{
public:
	string azuri;
	string ianteco;
	Par(){}
	Par(string ianteco, string azuri){
		this->ianteco = ianteco;
		this->azuri = azuri;
	}
	void print(){
		cout << ianteco << " = ";
		cout << azuri;
	}
};

class No{
public:
	Par par;
	No* prox;
	No(){
		prox = NULL;
	}
	No(Par par){
		this->par = par;
		prox = NULL;
	}
};

class Lista{
private:
	No* prim;
	No* ult;
public:
	Lista(){
		prim = new No();
		prim->prox = NULL;
		ult = prim;
	}	
	bool vazia(){
		return prim == ult;
	}
	void insere(Par par){
		ult->prox = new No();
		ult = ult->prox;
		ult->prox = NULL;
		ult->par = par;
	}
	No* predecessor(No* r){
		No* p = prim->prox;
		while (p->prox != r){
			p = p->prox;
		}
		return p;
	}
	bool remove(No* r, Par& par){
		if (vazia() || r == NULL || r == prim){
			return 0;
		}else{
			par = r->par;
			No* p = predecessor(r);
			p->prox = r->prox;
			if (p->prox == NULL) ult = p;
			delete r;
			return 1;
		}
	}
	No* busca(Par par){
		No* p = prim->prox;
		while (p != NULL && p->par.ianteco != par.ianteco){
			p=p->prox;
		}
		return p;
	}
	void print(){
		No* p = prim->prox;
		while (p != NULL){
			p->par.print();
			p = p->prox;
			cout << endl;
		}
	}
};

int main(int argc, const char * arg[]){
	Lista lista;
	Par a(":::", "A");
	Par b(".::", "B");
	Par c(":.:", "C");
	lista.insere(a);
	lista.insere(b);
	lista.insere(c);
	lista.print();

	Par x(".::", "");
	No* px = lista.busca(x);
	if(px == NULL){
		cout << "Nao encontrado";
	}
	else{
		px->par.print();
	}
	cout << "\n\n";
    cout << "----------------------\n";

    Par y;
    lista.remove(px, y);
    lista.print();
    cout << "removido: ";
    y.print();

    cout <<"\n\n";
    return 0;

}
