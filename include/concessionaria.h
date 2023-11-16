#include <string>
#include <ostream>

class Concessionaria {
    private:
        std::string nome;
        std::string cnpj;
        int estoque;

    public:
        Concessionaria(std::string nome, std::string cnpj);
        ~Concessionaria();
        void setNome(std::string nome);
        std::string getNome();   
        void setCnpj(std::string cnpj);
        std::string getCnpj();
        void setEstoque(int estoque);
        int getEstoque();
        friend std::ostream& operator<< (std::ostream &o, Concessionaria const &concessionaria);
};