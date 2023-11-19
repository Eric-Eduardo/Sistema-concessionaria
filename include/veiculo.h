#ifndef VEICULO_H
#define VEICULO_H
#include <string>
#include <ostream>
#include "concessionaria.h"

class Veiculo {
    protected:
        std::string marca;
        float preco;
        std::string chassi;
        int ano;
        std::string concessionaria;
    public:
        Veiculo();
        Veiculo(std::string concessionaria, std::string marca, float preco, std::string chassi, int ano);
        ~Veiculo();
        friend std::ostream& operator<< (std::ostream &o, Veiculo const &veiculo);
};

#endif