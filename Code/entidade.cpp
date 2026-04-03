#include <iostream>
#include "entidade.h"

//Constructor default/vazio
Entidade::Entidade() = default;

Entidade::Entidade(int id, std::string nome, int idade)
{
    this->id = id;
    this->nome = nome;
    this->idade = idade;
}

void Entidade::setNome(std::string nome)
{
    this->nome = nome;
}

void Entidade::setIdade(int idade)
{
    this->idade = idade;
}

int Entidade::getID()
{
    return this->id;
}

std::string Entidade::getNome()
{
    return this->nome;
}

int Entidade::getIdade()
{
    return this->idade;
}