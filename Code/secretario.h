#ifndef SECRETARIO_H
#define SECRETARIO_H

#include <iostream>
#include "funcionario.h" // Herança

class Secretario : public Funcionario {
    std::string departamento{};
    std::string formacao{};
    int tempExperiencia{};

public:
    Secretario();
    Secretario(int id, std::string nome, std::string nomeFunc, double salario, int idade, std::string departamento);
    void setDepartamento(std::string grau);
    std::string getDepartamento() const;
};

#endif