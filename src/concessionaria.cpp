#include "concessionaria.h"

Concessionaria::Concessionaria(std::string _nome, std::string _cnpj, int estoque_): nome(_nome), cnpj(_cnpj), estoque(estoque_) {}

Concessionaria::~Concessionaria() {}

void Concessionaria::setNome(std::string _nome) {
    nome = _nome;
}

std::string Concessionaria::getNome() {
    return nome;
}

void Concessionaria::setCnpj(std::string _cnpj) {
    cnpj = _cnpj;
}

std::string Concessionaria::getCnpj() {
    return cnpj;
}

void Concessionaria::setEstoque(int _estoque){
    estoque = _estoque;
}

int Concessionaria::getEstoque() {
    return estoque;
}   

std::ostream& operator<< (std::ostream &o, Concessionaria const &_concessionaria) {
	o << "Nome: " << _concessionaria.nome << "; CNPJ: " << _concessionaria.cnpj << "; Estoque: " << _concessionaria.estoque;
	return o;
}

