#include <iostream>
#include "secretario.h"

//Constructor default/vazio
Secretario::Secretario() = default;

Secretario::Secretario(int id, std::string nome, int idade, std::string turno, double salario, std::string contacto, std::string departamento):
Funcionario(id,nome, idade,turno,salario,contacto)
{
    this->departamento = departamento;
}

void Secretario::setDepartamento(std::string departamento)
{
    this->departamento = departamento;
}

std::string Secretario::getDepartamento()
{
    return this->departamento;
}