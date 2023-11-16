#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <iterator>
#include "veiculo.h"
// #include <stdlib.h>
// #include <stdio.h>

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

    cout << nome << " " << cnpj << " " << estoque << endl;

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

// Adicioanr um automóvel no sistema
string Sistema::add_car(const string linha)
{

    char * _linha;

    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    char* marca = strtok(_linha, " ");
    char* preco_str = strtok(NULL, " ");
    char* chassi = strtok(NULL, " ");
    char* ano_str = strtok(NULL, " ");


    float preco;
    preco = strtof(preco_str, NULL);

    int ano;
    ano = strtol(ano_str, NULL, 10); // conversão de char* para inteiro

    cout << marca << " " << preco+1 << " " << chassi << " " << ano+1 << endl;

    Veiculo v = Veiculo(marca, preco, chassi, ano);

    return "Carro criado!";
}