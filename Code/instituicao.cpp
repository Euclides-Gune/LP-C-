#include <iostream>
#include "instituicao.h"

//Constructor default/vazio
Instituicao::Instituicao() = default;

Instituicao::Instituicao(int id, std::string nomeDaInstituicao)
{
    this->id = id;
    this->nomeDaInstituicao = nomeDaInstituicao;
}

int Instituicao::getID() const
{
    return this->id;
}

std::string Instituicao::getNome() const
{
    return this->nomeDaInstituicao;
}