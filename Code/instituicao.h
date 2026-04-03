#ifndef Instiuicao_H
#define Instiuicao_H

#include <iostream>

class Instituicao {
    int id{};
    std::string nomeDaInstituicao{};

public:
    Instituicao();
    Instituicao(int id, std::string nomeDaInstituicao);
    int getID();
    std::string getNomeDaInstituicao();

};

#endif