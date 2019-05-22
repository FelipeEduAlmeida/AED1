#include <iostream>

class No{
public:
	String letra;
	No* prox;
	No(){
		prox = NULL;
	}
	No(Letra letra){
		this->letra = letra;
		prox = NULL;
	}
};

class Fila{
public:
	No* frente;
	No* tras;
	Item item[]
	fila();
	~fila();

	cria(Fila fila){
		fila.frente = new No();
		fila.frente.prox = NULL;
		fila.tras = fila.frente;
	}
	enfileira(Fila fila, String letra){
		fila.tras.prox = new No();
		fila.tras = fila.tras.prox;
		fila.tras.letra = letra;
		fila.tras.prox = NULL;
	}
	desenfileira(Fila fila, String letra){
		No* aux;
		fila.frente = fila.frente.item;
		item = fila.frente.item;
		delete aux;
	}
	print(Fila fila){
		No* p = prim->prox;
		while(p!= NULL){
			cout << p->letra;
			p = p->prox;
		}
	}
};

int main(int argc, const char * arg[]){
	Fila fila = new fila();

	enfileira(fila, "X");
	enfileira(fila, "Q");
	enfileira(fila, "A");
	enfileira(fila, "T");
	desenfileira(fila);
	enfileira(fila, "A");
	enfileira(fila, "T");
	enfileira(fila, "A");
	enfileira(fila, "Q");
	desenfileira(fila);
	desenfileira(fila);
	enfileira(fila, "U");
	enfileira(fila, "E");
	desenfileira(fila);

	print(fila);
}