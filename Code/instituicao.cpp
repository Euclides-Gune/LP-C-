#include <iostream>
#include "instituicao.h"

//Constructor default/vazio
Instituicao::Instituicao() = default;

Instituicao::Instituicao(int id, std::string nomeDaInstituicao)
{
    this->id = id;
    this->nomeDaInstituicao = nomeDaInstituicao;
}

int Instituicao::getID()
{
    return this->id;
}

std::string Instituicao::getNomeDaInstituicao()
{
    return this->nomeDaInstituicao;
}