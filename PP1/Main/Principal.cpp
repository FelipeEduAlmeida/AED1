#include<iostream>
using std::cout;
using std::cin;
using std::endl;
using namespace std; 

#include<string>
using std::string;
using std::getline;


typedef string ChaveIanteco;

int main(int argc, const char * arg[]){ 
	
	string linhaEntrada;
	string programaIanteco[1000];
	int numeroLinhas = 0;

	while (linhaEntrada[0] != '~'){
		getline(cin, linhaEntrada);
		programaIanteco[numeroLinhas] = linhaEntrada;
		numeroLinhas++;
	}
	cout << programaIanteco[0][10] << "ok" << endl;
}
