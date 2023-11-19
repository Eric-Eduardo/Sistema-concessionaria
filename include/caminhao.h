#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "veiculo.h"

class Caminhao : public Veiculo {
    private:
        std::string tipoCarga;
    public:
        Caminhao();
        Caminhao(std::string concessionaria, std::string marca, float preco, std::string chassi, int ano, std::string tipoCarga);
        ~Caminhao();
        friend std::ostream& operator<< (std::ostream &o, Caminhao const &caminhao); 
        void setTipoCarga(std::string tipoCarga);
        std::string getTipoCarga();
};

#endif