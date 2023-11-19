#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H

// #include <string>
#include "veiculo.h"

class Automovel : public Veiculo {
    private:
        std::string tipoMotor;
    public:
        Automovel();
        Automovel(std::string concessionaria, std::string marca, float preco, std::string chassi, int ano, std::string tipoMotor);
        ~Automovel();
        friend std::ostream& operator<< (std::ostream &o, Automovel const &automovel); 
        void setTipoMotor(std::string tipoMotor);
        std::string getTipoMotor();
};

#endif