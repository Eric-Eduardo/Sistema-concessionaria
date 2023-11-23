#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <iterator>
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"
#include <stdexcept>


using namespace std;

/* COMANDOS */
string Sistema::quit()
{
    return "Saindo...";
}


// Criar uma concessionária
string Sistema::create_concessionaria(const string linha) {

    int nArg = numArgumentos(linha); 
    if (nArg != 3) {
        return "ERRO - número de argumentos incorreto \nFormato esperado: create-concessionaria nome cnpj estoque\n";
    }

    char _linha[linha.length() + 1];

    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    char* nome = strtok(_linha, " ");
    char* cnpj = strtok(NULL, " ");
    char* estoque_str = strtok(NULL, " ");


    // Verifica se já existe uma concessionária com o mesmo cnpj. Caso sim, retorna uma mensagem de erro
    if (buscarConcessionaria(nome)!=NULL) {
        string string_nome(nome);
        return "Erro - Concessionária " + string_nome + " já existente!\n";
    }

    int estoque;
    estoque = strtol(estoque_str, NULL, 10); // conversão de char* para inteiro

    Concessionaria concessionaria(nome, cnpj, estoque);
    concessionarias.push_back(concessionaria);
    
    return "Concessionaria " + concessionaria.getNome() + " criada.\n";
}

// Criar um automoveis
string Sistema::add_car(const string linha) {

    if (numArgumentos(linha)!=6) {
        return "ERRO - número de argumentos incorreto \nFormato esperado: add-car nome_concessionaria marca_carro valor_carro chassi ano_carro tipo_do_motor\n";
    }
    if (concessionarias.size()==0) {
        return "ERRO - Ainda não há concessionárias cadastradas!\n";
    }

    char _linha[linha.length() + 1];
    
    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    
    char* concessionaria = strtok(_linha, " ");
    char* marca = strtok(NULL, " ");
    char* preco_str = strtok(NULL, " ");
    char* chassi = strtok(NULL, " ");
    char* ano_str = strtok(NULL, " ");
    char* tipoMotor = strtok(NULL, " ");

    // Verifica se a concessionária passada na string existe
    Concessionaria* conc = buscarConcessionaria(concessionaria);

    // if (buscarConcessionaria(concessionaria)==NULL) {
    //     string tmp_string(concessionaria);
    //     return "ERRO - Concessionária " + tmp_string + " não encontrada!";
    // }

    if (conc==NULL) {
        string tmp_string(concessionaria);
        return "ERRO - Concessionária " + tmp_string + " não encontrada!\n";
    }

    // Verifica se o verículo já foi adicionado
    Veiculo* veiculo_encontrado = buscarVeiculo(chassi);
    if (veiculo_encontrado!=NULL) {
        return "ERRO - Veículo " + (*veiculo_encontrado).getChassi() + " já adicionado à concessionária " + (*veiculo_encontrado).getConcessionaria() + "!\n";
    }

    float preco;
    preco = strtof(preco_str, NULL);

    int ano;
    ano = strtol(ano_str, NULL, 10); // conversão de char* para inteiro
    

    Automovel automovel(concessionaria, marca, preco, chassi, ano, tipoMotor);
    automoveis.push_back(automovel);

    int estoqueAtual = conc->getEstoque();
    conc->setEstoque(++estoqueAtual);
        
    return "Carro " + automovel.getChassi() + " criado!\n";
}

// Criar uma moto
string Sistema::add_bike(const string linha) {

    if (numArgumentos(linha)!=6) {
        return "ERRO - número de argumentos incorreto \nFormato esperado: add-bike nome_concessionaria marca_moto valor_moto chassi ano_moto modelo_moto\n";
    }
    if (concessionarias.size()==0) {
        return "ERRO - Ainda não há concessionárias cadastradas!\n";
    }
    

    char _linha[linha.length() + 1];
    
    // Para que possamos utilizar a função strcpy é necessário usar um dado do tipo char*. Então é feita a conversão de string para char*
    strcpy(_linha, linha.c_str());
    
    char* concessionaria = strtok(_linha, " ");
    char* marca = strtok(NULL, " ");
    char* preco_str = strtok(NULL, " ");
    char* chassi = strtok(NULL, " ");
    char* ano_str = strtok(NULL, " ");
    char* modelo = strtok(NULL, " ");


    Concessionaria* conc = buscarConcessionaria(concessionaria);
    if (conc==NULL) {
        string tmp_string(concessionaria);
        return "ERRO - Concessionária " + tmp_string + " não encontrada!\n";
    }

    Veiculo* veiculo_encontrado = buscarVeiculo(chassi);
    if (veiculo_encontrado!=NULL) {
        return "ERRO - Veículo " + (*veiculo_encontrado).getChassi() + " já adicionado à concessionária " + (*veiculo_encontrado).getConcessionaria() + "!\n";
    }

    float preco;
    preco = strtof(preco_str, NULL);

    int ano;
    ano = strtol(ano_str, NULL, 10); // conversão de char* para inteiro
    

    Moto moto(concessionaria, marca, preco, chassi, ano, modelo);
    motos.push_back(moto);

    int estoqueAtual = conc->getEstoque();
    conc->setEstoque(++estoqueAtual);
    
    return "Moto " + moto.getChassi() + " criada!\n";
}

// Cria um caminhão
string Sistema::add_truck(const string linha) {
    if (numArgumentos(linha)!=6) {
        return "ERRO - número de argumentos incorreto \nFormato esperado: add-truck nome_concessionaria marca_caminhao valor_caminhao chassi ano_caminhao tipo_de_carga\n";
    }
    if (concessionarias.size()==0) {
        return "ERRO - Ainda não há concessionárias cadastradas!\n";
    }

    char _linha[linha.length() + 1];
    
    strcpy(_linha, linha.c_str());
    
    char* concessionaria = strtok(_linha, " ");
    char* marca = strtok(NULL, " ");
    char* preco_str = strtok(NULL, " ");
    char* chassi = strtok(NULL, " ");
    char* ano_str = strtok(NULL, " ");
    char* tipoCarga = strtok(NULL, " ");

    Concessionaria* conc = buscarConcessionaria(concessionaria);
    if (conc==NULL) {
        string tmp_string(concessionaria);
        return "ERRO - Concessionária " + tmp_string + " não encontrada!";
    }

    Veiculo* veiculo_encontrado = buscarVeiculo(chassi);
    if (veiculo_encontrado!=NULL) {
        return "ERRO - Veículo " + (*veiculo_encontrado).getChassi() + " já adicionado à concessionária " + (*veiculo_encontrado).getConcessionaria() + "!\n";
    }

    float preco;
    preco = strtof(preco_str, NULL);

    int ano;
    ano = strtol(ano_str, NULL, 10); // conversão de char* para inteiro

    Caminhao caminhao(concessionaria, marca, preco, chassi, ano, tipoCarga);
    caminhoes.push_back(caminhao);

    int estoqueAtual = conc->getEstoque();
    conc->setEstoque(++estoqueAtual);
    
    
    return "Caminhão " + caminhao.getChassi() + " criado!\n";
}

// Retorna um ponteiro para a concessionária encontrado
Concessionaria* Sistema::buscarConcessionaria(std::string nome) {
    for (int i = 0; i < concessionarias.size(); i ++) {
        if (nome == concessionarias[i].getNome()) {
            return &concessionarias[i];
        }
    } 

    return NULL;
}

// Returna um pontieor para o veículo encontrado
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

// Remove um veículo do arry de veículos e retorna uma mensagem de erro/sucesso.
string Sistema::removerVeiculo(std::string chassi) {
    string concessionaria = "";
    string mensagem = "Veículo ";
    mensagem.append(chassi);
    
    // Busca pelo chassi em cada vector (automoveis, motos e caminhoes)
    vector<Automovel>::iterator itCarro;
    for (itCarro = automoveis.begin(); itCarro != automoveis.end(); itCarro++) {
        if (chassi == (*itCarro).getChassi()) {
            concessionaria = (*itCarro).getConcessionaria();
            automoveis.erase(itCarro);

            Concessionaria* conc = buscarConcessionaria(concessionaria);
            int estoque = conc->getEstoque();
            conc->setEstoque(--estoque);
            
            mensagem.append(" removido da concessionária ");
            mensagem.append((*itCarro).getConcessionaria());
            mensagem.append("\n");
            return mensagem;
        }  
    }
    vector<Moto>::iterator itMoto;
    for (itMoto = motos.begin(); itMoto != motos.end(); itMoto++) {
        if (chassi == (*itMoto).getChassi()) {
            concessionaria = (*itMoto).getConcessionaria();
            motos.erase(itMoto);
            
            Concessionaria* conc = buscarConcessionaria(concessionaria);
            int estoque = conc->getEstoque();
            conc->setEstoque(--estoque);

            mensagem.append(" removido da concessionária ");
            mensagem.append((*itMoto).getConcessionaria());
            mensagem.append("\n");
            return mensagem;
        }
    }
    vector<Caminhao>::iterator itCaminhao;
    for (itCaminhao = caminhoes.begin(); itCaminhao != caminhoes.end(); itCaminhao++) {
        if (chassi == (*itCaminhao).getChassi()) {
            concessionaria = (*itCaminhao).getConcessionaria();
            caminhoes.erase(itCaminhao);

            Concessionaria* conc = buscarConcessionaria(concessionaria);
            int estoque = conc->getEstoque();
            conc->setEstoque(--estoque);
            
            mensagem.append(" removido da concessionária ");
            mensagem.append((*itCaminhao).getConcessionaria());
            mensagem.append("\n");
            return mensagem;
        }
    }
    mensagem.append(" não encontrado\n");
    return mensagem;
}

int Sistema::numArgumentos(std::string comando) {
    int contNumArgumentos = 0; // Conta o número de argumentos
    char charAnterior = ' ';
    for (int i = 0; i < comando.length(); i++) {
        if (i!=0 && charAnterior != ' ') {
            if (comando[i] == ' ') contNumArgumentos++;
        }
        charAnterior = comando[i];
    }

    return contNumArgumentos+1;
}