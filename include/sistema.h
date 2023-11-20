#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include "concessionaria.h"
#include "automovel.h"
#include "moto.h"
#include "caminhao.h"

// Sistema deve concentrar todas as operações

class Sistema
{
    private:
        std::vector<Concessionaria> concessionarias; //um vetor com todos as concessionarias
        std::vector<Automovel> automoveis; //um vetor com todos os automoveis
        std::vector<Moto> motos; //um vetor com todos as motos
        std::vector<Caminhao> caminhoes; //um vetor com todos os caminhões
    public:
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

        /* Cria uma moto e retorna uma string de erro/sucesso
            @param linha os dados da motocicleta
            @return uma string contendo uma mensagem de erro ou "Moto Criada"
        */
        std::string add_bike(const std::string linha);

        /* Cria um caminhão e retorna uma string de erro/sucesso
            @param linha os dados do caminhao
            @return uma string contendo uma mensagem de erro ou "Caminhão Criado"
        */
        std::string add_truck(const std::string linha);

        /* Template que mostra os elementos de um dado vetor de objetos genérico T
            @param vetor corresponde a um vetor de objetos do tipo T (Genérico)
        */
        template <class T>
        void exibir(std::vector<T> vetor);

        /* Busca uma determinada concessionária que possui o cnpj dado.
            @param cnpj é o cnpj da concessionária procurada
            @return um ponteiro para a concessionária encontrada ou NULL em caso não seja encontrada
        */
        Concessionaria* buscarConcessionaria(std::string cnpj);

        Veiculo* buscarVeiculo(std::string chassi);

        std::string removerVeiculo(std::string chassi);

};

// Template que mostra os elementos de um dado vetor de objetos genérico T
template <class T>
void Sistema::exibir(std::vector<T> vetor) {
    int tamanho = vetor.size();

    std::cout << "\nTotal de elementos: " << tamanho << std::endl;

    for (int i = 0; i < tamanho; i++) {
        std::cout << vetor[i] << "\n" << std::endl;
    }
}

#endif
