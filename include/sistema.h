#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include "concessionaria.h"
#include "automovel.h"

// Sistema deve concentrar todas as operações
class Sistema
{
    private:
        std::vector<Concessionaria> concessionarias; //um vetor com todos as concessionarias
        std::vector<Automovel> automoveis; //um vetor com todos os automoveis
    public:
        ~Sistema();
        /*Encerra o funcionamento do programa.
            @return uma string com a mensagem "Saindo.."
        */
        std::string quit();

        /* Cria uma concessionaria e retorna uma string de erro/sucesso
            @param nome o nome da concessionaria
            @return uma string contendo uma mensagem de erro ou "Concessionaria Criada"
        */
        std::string create_concessionaria(const std::string nome);
      
        /* Cria um automovel e retorna uma string de erro/sucesso
            @param linha os dados do automovel
            @return uma string contendo uma mensagem de erro ou "Automovel Criada"
        */
        std::string add_car(const std::string linha);

        // Mostra as informações das concessionárias no vector "concessionarias"
        void exibir_concessionarias();

        // Mostra as informações dos veiculos no vector "veiculos"
        void exibir_automoveis();
};

#endif
