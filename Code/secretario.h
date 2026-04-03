#ifndef SECRETARIO_H
#define SECRETARIO_H

#include <iostream>
#include "funcionario.h" // Herança

class Secretario : public Funcionario {
    std::string departamento{};

public:
    Secretario();
    Secretario(int id, std::string nome, int idade, std::string turno, double salario, std::string contacto, std::string departamento);

    void setDepartamento(std::string grau);

    std::string getDepartamento();
    
};

#endif