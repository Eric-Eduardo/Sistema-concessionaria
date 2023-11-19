#include "veiculo.h"
using std::string;

Veiculo::Veiculo(string concessionaria_, string marca_, float preco_, string chassi_, int ano_) {
    concessionaria = concessionaria_;
    marca =  marca_;
    preco = preco_;
    chassi = chassi_;
    ano = ano_;
}
Veiculo::Veiculo() {}

Veiculo::~Veiculo() {}

std::ostream& operator<< (std::ostream &o, Veiculo const &veiculo) {
    o << "Concessionaria: " << veiculo.concessionaria << "; marca: " << veiculo.marca << "; preco: " << veiculo.preco << "; chassi: " << veiculo.chassi << "; ano " << veiculo.ano;
    return o;
}