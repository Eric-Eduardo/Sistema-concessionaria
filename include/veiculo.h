// #include <string>
#include <ostream>

class Veiculo {
    protected:
        std::string marca;
        float preco;
        std::string chassi;
        int ano;
    public:
        Veiculo(std::string marca, float preco, std::string chassi, int ano);
        ~Veiculo();
        friend std::ostream& operator<< (std::ostream &o, Veiculo const &veiculo);
};