#include "moto.h"

Moto::Moto(std::string concessionaria_, std::string marca_, float preco_, std::string chassi_, int ano_, std::string modelo_) : Veiculo(concessionaria_, marca_, preco_, chassi_, ano_) {
    modelo = modelo_;
}

Moto::~Moto() {};

std::ostream& operator<< (std::ostream &o, Moto const &moto) {
    o << "Concessionaria: " << moto.concessionaria << "\nMarca: " << moto.marca << "\nPreco: " <<  moto.preco << "\nChassi: " << moto.chassi << "\nAno: " << moto.ano << "\nModelo: " << moto.modelo;
    return o;
}

void Moto::setModelo(std::string modelo_) {modelo = modelo_;}

std::string Moto::getModelo() {return modelo;}