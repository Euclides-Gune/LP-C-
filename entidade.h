#ifndef Entidade_H
#define Entidade_H

#include <iostream>

class Entidade {
    int id{};
    std::string nome{};
    int idade{};

public:
    Entidade();
    Entidade(int id, std::string nome, int idade);

    void setNome(std::string nome);

    void setIdade(int idade);

    int getID();

    std::string getNome();

    int getIdade();

};

#endif