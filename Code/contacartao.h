#ifndef CONTACARTAO_H
#define CONTACARTAO_H

#include <iostream>
// Herança
#include "instituicao.h"
#include "funcionario.h"

class ContaCartao : public Instituicao
{
    std::string senha{};
    double saldo{};
    std::string titular;
public:
    ContaCartao();
    ContaCartao(int id, std::string nome, std::string senhaDeAccesso, double saldo, std::string titular);
    void setSenha(std::string senha);
    void setSaldo(double saldo);
    std::string getSenha() const;
    double getSaldo() const;
    std::string getTitular() const;
};

#endif