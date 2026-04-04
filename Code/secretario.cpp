#include <iostream>
#include "secretario.h"
#include "funcionario.h"

//Constructor default/vazio
Secretario::Secretario() = default;

Secretario::Secretario(int id, std::string nome, std::string nomeFunc, double salario, int idade, std::string departamento):
Funcionario(id, nome, nomeFunc, salario, idade)
{
    this->departamento = departamento;
}

void Secretario::setDepartamento(std::string departamento)
{
    this->departamento = departamento;
}

std::string Secretario::getDepartamento() const
{
    return this->departamento;
}