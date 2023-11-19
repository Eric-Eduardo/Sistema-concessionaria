#ifndef MOTO_H
#define MOTO_H

#include "veiculo.h"

class Moto : public Veiculo {
    private:
        std::string modelo;
    public:
        Moto(std::string concessionaria, std::string marca, float preco, std::string chassi, int ano, std::string modelo);
        ~Moto();
        friend std::ostream& operator<< (std::ostream &o, Moto const &moto); 
        void setModelo(std::string modelo);
        std::string getModelo();
};

#endif