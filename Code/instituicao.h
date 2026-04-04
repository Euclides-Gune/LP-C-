#ifndef Instiuicao_H
#define Instiuicao_H

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