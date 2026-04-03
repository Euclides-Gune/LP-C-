#ifndef CONTACARTAO_H
#define CONTACARTAO_H

#include <iostream>
// Herança
#include "instituicao.h"
#include "funcionario.h"

class ContaCartao : public Instituicao
{
    long senha{};
    double saldo{};
    Funcionario titular;
public:
    ContaCartao();
    ContaCartao(int id, std::string nome, long senhaDeAccesso, double saldo, Funcionario titular);
    void setSenha(long senha);
    void setSaldo(double saldo);
    long getSenha();
    double getSaldo();
    Funcionario getTitular();
};

#endif