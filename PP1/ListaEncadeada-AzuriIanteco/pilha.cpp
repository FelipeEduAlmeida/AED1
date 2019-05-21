#include <iostream>

using namespace std;

template <class Type>

class Pilha
{
private:
	Type * vet;
	int max_tam;
	int topo;
public:
	Pilha(int tam)
	{
		vet = new Type[tam];
		max_tam = tam - 1;
		topo = -1;
	}

	~Pilha()
	{
		delete[] vet;
	}

	void empilhar(Type e)
	{
		if(topo == max_tam)
			cout << "Pilha cheia!" << endl;
		else
			vet[++topo] = e;
	}

	void desempilhar()
	{
		if(topo == -1)
			cout << "Pilha vazia!!" << endl;
		else
			topo--;
	}

	Type getTopo()
	{
		if(topo != -1)
			return vet[topo];
		return NULL;
	}

	int vazia()
	{
		return (topo == -1);
	}
};


int main()
{
	Pilha<const char*> p(100);

	p.empilhar("C");
	p.empilhar("A");
	p.empilhar("B");
	p.empilhar("Z");
	//p.desempilhar();
	if(p.vazia())
		cout << "Pilha vazia!\n";
	else
		cout << "Pilha NAO vazia!\n";
	if(p.getTopo() != NULL)
		cout << "Topo: " << p.getTopo() << endl;
	else
		cout << "A pilha esta vazia!!\n";
	return 0;
}