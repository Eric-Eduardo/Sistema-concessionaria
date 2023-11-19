#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <iterator>
#include "automovel.h"
#include <memory>

// #include <stdlib.h>
// #include <stdio.h>

using namespace std;

// Após encerrar o sistema, liberamos todos os veículos criados dinamicamente
Sistema::~Sistema() {
    int totalVeiculos = veiculos.size();

	for (int i = 0; i < totalVeiculos; i++) {
        free(veiculos[i]);
	}
}

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

    return "Concessionaria criada!";
}

// Adicioanr um automóvel no sistema
string Sistema::add_car(const string linha) {
/* 
add-car IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina
add-car ERICOTA Geep 10000 ABB66D7CHK77 2020 eletrico
add-car DANIELE_equipadora Wosksvagen 1500 12ZDGG6HKMD6 2021 eletrico
*/
    char _linha[linha.length() + 1];
    
    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    
    char* concessionaria = strtok(_linha, " ");
    char* marca = strtok(NULL, " ");
    char* preco_str = strtok(NULL, " ");
    char* chassi = strtok(NULL, " ");
    char* ano_str = strtok(NULL, " ");
    char* tipoMotor = strtok(NULL, " ");

    float preco;
    preco = strtof(preco_str, NULL);

    int ano;
    ano = strtol(ano_str, NULL, 10); // conversão de char* para inteiro
    

    Automovel* automovel = new Automovel(concessionaria, marca, preco, chassi, ano, tipoMotor);
    /*
    Atribuímos o automovel a um ponteiro para veículo para que seja possívle adicionar no vetor de veículos.
    Essa conversão é possível pois todo automovel é um veiculo.
    */
    Veiculo* veiculo = automovel; 
    veiculos.push_back(veiculo);

    return "Carro criado!";
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

void Sistema::exibir_veiculos() {
    int totalVeiculos = veiculos.size();
	
    cout << totalVeiculos << " veiculos encontradas:" << endl;

    Automovel* automovel;
	for (int i = 0; i < totalVeiculos; i++) {
        automovel = (Automovel*)(veiculos[i]);        
		cout << i+1 << ". " << *automovel << endl;
	}
}