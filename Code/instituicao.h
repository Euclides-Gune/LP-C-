#ifndef INSTITUICAO_H
#define INSTITUICAO_H

#include <iostream>

class Instituicao {
    int id{};
    std::string nomeDaInstituicao{};

public:
    Instituicao();
    Instituicao(int id, std::string nomeDaInstituicao);
    int getID() const;
    std::string getNome() const;
};

#endif