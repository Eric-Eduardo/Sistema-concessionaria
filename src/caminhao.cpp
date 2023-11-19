#include "caminhao.h"

Caminhao::Caminhao(std::string concessionaria_, std::string marca_, float preco_, std::string chassi_, int ano_, std::string tipoCarga_) : Veiculo(concessionaria_, marca_, preco_, chassi_, ano_) {
    tipoCarga = tipoCarga_;
}

Caminhao::Caminhao() {}

Caminhao::~Caminhao() {}

std::ostream& operator<< (std::ostream &o, Caminhao const &caminhao) {
    o << "Concessionaria: " << caminhao.concessionaria << "\nMarca: " << caminhao.marca << "\nPreco: " <<  caminhao.preco << "\nChassi: " << caminhao.chassi << "\nAno: " << caminhao.ano << "\nModelo: " << caminhao.tipoCarga;
    return o;
}

void Caminhao::setTipoCarga(std::string tipoCarga_) {tipoCarga = tipoCarga_;}

std::string Caminhao::getTipoCarga() {return tipoCarga;}