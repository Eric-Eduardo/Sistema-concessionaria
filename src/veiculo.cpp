#include "veiculo.h"
using std::string;

Veiculo::Veiculo(string marca_, float preco_, string chassi_, int ano_) {
    marca =  marca_;
    preco = preco_;
    chassi = chassi_;
    ano = ano_;
}

Veiculo::~Veiculo() {}

std::ostream& operator<< (std::ostream &o, Veiculo const &veiculo) {
    o << "marca: " << veiculo.marca << "; preco: " << veiculo.preco << "; chassi: " << veiculo.chassi << "; ano " << veiculo.ano;
    return o;
}