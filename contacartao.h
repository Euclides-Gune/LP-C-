#ifndef CONTACARTAO_H
#define CONTACARTAO_H

#include <iostream>
#include "entidade.h" // Herança

class ContaCartao : public Entidade
{
    int senha{};
    double saldo{};
    std::string tipoDeConta;
public:
    ContaCartao();
    ContaCartao(int id, std::string nome, int idade, int senhaDeAccesso, double saldo, std::string tipo);
    void setSenha(int senha);
    void setSaldo(double saldo);
    void setTipoDeConta(std::string tipo);
    int getSenha();
    double getSaldo();
    std::string getTipoDeConta();
};

#endif