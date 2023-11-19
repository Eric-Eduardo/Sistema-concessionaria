#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <iterator>
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"
// #include <stdlib.h>
// #include <stdio.h>

using namespace std;

// Após encerrar o sistema, liberamos todos os veículos criados dinamicamente
Sistema::~Sistema() {
    // int totalVeiculos = veiculos.size();

	// for (int i = 0; i < totalVeiculos; i++) {
    //     free(veiculos[i]);
	// }
}

/* COMANDOS */
string Sistema::quit()
{
    return "Saindo...";
}

// Criar uma concessionária
string Sistema::create_concessionaria(const string linha)
{

    char _linha[linha.length() + 1];

    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    char* nome = strtok(_linha, " ");
    char* cnpj = strtok(NULL, " ");
    char* estoque_str = strtok(NULL, " ");

    int estoque;
    estoque = strtol(estoque_str, NULL, 10); // conversão de char* para inteiro

    Concessionaria concessionaria(nome, cnpj);
    concessionarias.push_back(concessionaria);
    
    exibir(concessionarias);
    return "Concessionaria criada!";
}

// Criar um automoveis
string Sistema::add_car(const string linha) {
/* Testes
add-car IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina
add-car ERIC_teste Geep 10000 ABB66D7CHK77 2020 eletrico
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
    

    Automovel automovel(concessionaria, marca, preco, chassi, ano, tipoMotor);
    automoveis.push_back(automovel);
    
    exibir(automoveis);
    return "Carro criado!";
}

// Criar uma moto
string Sistema::add_bike(const string linha) {
/* Testes
add-bike IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 classico
add-bike ERIC_teste Geep 10000 ABB66D7CHK77 2020 esportivo
add-bike DANIELE_equipadora Wosksvagen 1500 12ZDGG6HKMD6 2021 esportivo
*/
    char _linha[linha.length() + 1];
    
    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    
    char* concessionaria = strtok(_linha, " ");
    char* marca = strtok(NULL, " ");
    char* preco_str = strtok(NULL, " ");
    char* chassi = strtok(NULL, " ");
    char* ano_str = strtok(NULL, " ");
    char* modelo = strtok(NULL, " ");

    float preco;
    preco = strtof(preco_str, NULL);

    int ano;
    ano = strtol(ano_str, NULL, 10); // conversão de char* para inteiro
    

    Moto moto(concessionaria, marca, preco, chassi, ano, modelo);
    motos.push_back(moto);

    exibir(motos);

    return "Moto criada!";
}

// Cria um caminhão
string Sistema::add_truck(const string linha) {
/* Testes
add-truck IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 comum
add-truck ERIC_teste Geep 10000 ABB66D7CHK77 2020 perigosa
add-truck DANIELE_equipadora Wosksvagen 1500 12ZDGG6HKMD6 2021 perigosa
*/
    char _linha[linha.length() + 1];
    
    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    
    char* concessionaria = strtok(_linha, " ");
    char* marca = strtok(NULL, " ");
    char* preco_str = strtok(NULL, " ");
    char* chassi = strtok(NULL, " ");
    char* ano_str = strtok(NULL, " ");
    char* tipoCarga = strtok(NULL, " ");

    float preco;
    preco = strtof(preco_str, NULL);

    int ano;
    ano = strtol(ano_str, NULL, 10); // conversão de char* para inteiro

    Caminhao caminhao(concessionaria, marca, preco, chassi, ano, tipoCarga);
    caminhoes.push_back(caminhao);
    
    exibir(caminhoes);
    return "Caminhão criado!";
}
