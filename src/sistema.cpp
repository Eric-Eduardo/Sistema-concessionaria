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

using namespace std;

// Após encerrar o sistema, liberamos todos os veículos criados dinamicamente


/* COMANDOS */
string Sistema::quit()
{
    return "Saindo...";
}

// Criar uma concessionária
string Sistema::create_concessionaria(const string linha) {

    char _linha[linha.length() + 1];

    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    char* nome = strtok(_linha, " ");
    char* cnpj = strtok(NULL, " ");
    char* estoque_str = strtok(NULL, " ");

    //Verifica se já existe uma concessionária com o mesmo cnpj
    if (buscarConcessionaria(cnpj)!=NULL) {
        std::string textoErro = "ERRO - CNPJ ";
        textoErro += cnpj;
        textoErro += " já existente";
        return textoErro;
    }

    int estoque;
    estoque = strtol(estoque_str, NULL, 10); // conversão de char* para inteiro

    Concessionaria concessionaria(nome, cnpj);
    concessionarias.push_back(concessionaria);
    
    exibir(concessionarias);
    return "Concessionaria criada!";
}

// Criar um automoveis
string Sistema::add_car(const string linha) {

    char _linha[linha.length() + 1];
    
    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    
    char* concessionaria = strtok(_linha, " ");
    char* marca = strtok(NULL, " ");
    char* preco_str = strtok(NULL, " ");
    char* chassi = strtok(NULL, " ");
    char* ano_str = strtok(NULL, " ");
    char* tipoMotor = strtok(NULL, " ");


    Veiculo* veiculo_encontrado = buscarVeiculo(chassi);
    if (veiculo_encontrado!=NULL) {
        std::string textoErro = "ERRO - Veículo ";
        textoErro += chassi;
        textoErro += " já adicionado à concessionária ";
        textoErro += (*veiculo_encontrado).getConcessionaria();
        return textoErro;
    }
    


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

    char _linha[linha.length() + 1];
    
    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    
    char* concessionaria = strtok(_linha, " ");
    char* marca = strtok(NULL, " ");
    char* preco_str = strtok(NULL, " ");
    char* chassi = strtok(NULL, " ");
    char* ano_str = strtok(NULL, " ");
    char* modelo = strtok(NULL, " ");

    Veiculo* veiculo_encontrado = buscarVeiculo(chassi);
    if (veiculo_encontrado!=NULL) {
        std::string textoErro = "ERRO - Veículo ";
        textoErro += chassi;
        textoErro += " já adicionado à concessionária ";
        textoErro += (*veiculo_encontrado).getConcessionaria();
        return textoErro;
    }

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

    char _linha[linha.length() + 1];
    
    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    
    char* concessionaria = strtok(_linha, " ");
    char* marca = strtok(NULL, " ");
    char* preco_str = strtok(NULL, " ");
    char* chassi = strtok(NULL, " ");
    char* ano_str = strtok(NULL, " ");
    char* tipoCarga = strtok(NULL, " ");

    Veiculo* veiculo_encontrado = buscarVeiculo(chassi);
    if (veiculo_encontrado!=NULL) {
        std::string textoErro = "ERRO - Veículo ";
        textoErro += chassi;
        textoErro += " já adicionado à concessionária ";
        textoErro += (*veiculo_encontrado).getConcessionaria();
        return textoErro;
    }

    float preco;
    preco = strtof(preco_str, NULL);

    int ano;
    ano = strtol(ano_str, NULL, 10); // conversão de char* para inteiro

    Caminhao caminhao(concessionaria, marca, preco, chassi, ano, tipoCarga);
    caminhoes.push_back(caminhao);
    
    exibir(caminhoes);
    return "Caminhão criado!";
}

Concessionaria* Sistema::buscarConcessionaria(std::string cnpj) {
    for (int i = 0; i < concessionarias.size(); i ++) {
        if (cnpj == concessionarias[i].getCnpj()) {
            return &concessionarias[i];
        }
    } 

    return NULL;
}

Veiculo* Sistema::buscarVeiculo(std::string chassi) {
    for (int i = 0; i < automoveis.size(); i++) {
        if (chassi == automoveis[i].getChassi()) {
            return &automoveis[i];
        }
    }
    for (int i = 0; i < motos.size(); i++) {
        if (chassi == motos[i].getChassi()) {
            return &motos[i];
        }
    }
    for (int i = 0; i < caminhoes.size(); i++) {
        if (chassi == caminhoes[i].getChassi()) {
            return &caminhoes[i];
        }
    }

    return NULL;
}


string Sistema::removerVeiculo(std::string chassi) {
    string concessionaria = "";
    string mensagem = "Veículo ";
    mensagem.append(chassi);
    
    vector<Automovel>::iterator itCarro;
    for (itCarro = automoveis.begin(); itCarro != automoveis.end(); itCarro++) {
        if (chassi == (*itCarro).getChassi()) {
            concessionaria = (*itCarro).getConcessionaria();
            automoveis.erase(itCarro);
            
            mensagem.append(" removido da concessionária ");
            mensagem.append((*itCarro).getConcessionaria());
            exibir(automoveis);
            return mensagem;
        }  
    }
    vector<Moto>::iterator itMoto;
    for (itMoto = motos.begin(); itMoto != motos.end(); itMoto++) {
        if (chassi == (*itMoto).getChassi()) {
            concessionaria = (*itMoto).getConcessionaria();
            motos.erase(itMoto);
            
            mensagem.append(" removido da concessionária ");
            mensagem.append((*itMoto).getConcessionaria());
            exibir(motos);
            return mensagem;
        }
    }
    vector<Caminhao>::iterator itCaminhao;
    for (itCaminhao = caminhoes.begin(); itCaminhao != caminhoes.end(); itCaminhao++) {
        if (chassi == (*itCaminhao).getChassi()) {
            caminhoes.erase(itCaminhao);
            
            mensagem.append(" removido da concessionária ");
            mensagem.append((*itCaminhao).getConcessionaria());
            exibir(caminhoes);
            return mensagem;
        }
    }
    mensagem.append(" não encontrado");
    return mensagem;
}

/*
Testes
create-concessionaria ERIC_SA 11.111.111/0001-12 0
create-concessionaria IMD_SA 11.111.111/0001-11 0

add-car IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina
add-car ERIC_teste Geep 10000 ABB66D7CHK77 2020 eletrico
add-car DANIELE_equipadora Wosksvagen 1500 12ZDGG6HKMD6 2021 eletrico


add-bike IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 classico
add-bike ERIC_teste Geep 10000 ABB66D7CHK77 2020 esportivo
add-bike DANIELE_equipadora Wosksvagen 1500 12ZDGG6HKMD6 2021 esportivo

add-truck IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 comum
add-truck ERIC_teste Geep 10000 ABB66D7CHK77 2020 perigosa
add-truck DANIELE_equipadora Wosksvagen 1500 12ZDGG6HKMD6 2021 perigosa

remove-vehicle 9BRBLWHEXG0107721
remove-vehicle ABB66D7CHK77
remove-vehicle 12ZDGG6HKMD6
*/