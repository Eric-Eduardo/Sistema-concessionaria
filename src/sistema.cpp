#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <vector>
#include<iterator>
// #include "concessionaria.h"

using namespace std;

/* COMANDOS */
string Sistema::quit()
{
    return "Saindo...";
}

// Criar uma concessionária
string Sistema::create_concessionaria(const string linha)
{

    char * _linha;

    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    char* nome = strtok(_linha, " ");
    char* cnpj = strtok(NULL, " ");
    char* estoque_str = strtok(NULL, " ");

    int estoque;
    estoque = strtol(estoque_str, NULL, 10); // conversão de char* para inteiro

    Concessionaria concessionaria(nome, cnpj);

    concessionarias.push_back(concessionaria);
    // exibir_concessionarias();
    return "Concessionaria criada!";
}

// Exibe o nome, cnpj e estoque das concessionárias existentes
void Sistema::exibir_concessionarias() {
    int totalConcessionarias = concessionarias.size();

    vector<Concessionaria>::iterator it;
	
    cout << totalConcessionarias << " concecionarias encontradas:" << endl;

	for (int i=0; i < totalConcessionarias; i++) {
		cout << i+1 << ". " << concessionarias[i] << endl;
	}
}