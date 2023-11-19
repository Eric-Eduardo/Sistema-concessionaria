#include "automovel.h"


Automovel::Automovel(std::string concessionaria_, std::string marca_, float preco_, std::string chassi_, int ano_, std::string tipoMotor_) : Veiculo(concessionaria_, marca_, preco_, chassi_, ano_) {
    tipoMotor = tipoMotor_;
}

Automovel::Automovel() : Veiculo() {
    tipoMotor = "";
}

Automovel::~Automovel() {}

void Automovel::setTipoMotor(std::string tipoMotor_) {tipoMotor = tipoMotor_;}
std::string Automovel::getTipoMotor() {return tipoMotor;}

std::ostream& operator<< (std::ostream &o, Automovel const &automovel) {
    o << automovel.concessionaria << " " << automovel.marca << " " << automovel.preco << " " << automovel.chassi << " " << automovel.ano << " " << automovel.tipoMotor;
    return o;
}