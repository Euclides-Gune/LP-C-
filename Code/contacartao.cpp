#include <iostream>
#include "contacartao.h"
#include "instituicao.h"
#include "funcionario.h"

//Constructor default/vazio
ContaCartao::ContaCartao() = default;

ContaCartao::ContaCartao(int id, std::string nome, long senhaDeAccesso, double saldo, Funcionario titular): Instituicao(id, nome)
{
    this->senha = senhaDeAccesso;
    this->saldo = saldo;
    this->titular = titular;
}

void ContaCartao::setSenha(long senha)
{
    this->senha = senha;
}

void ContaCartao::setSaldo(double saldo)
{
    this->saldo = saldo;
}

long ContaCartao::getSenha()
{
    return this->senha;
}

double ContaCartao::getSaldo()
{
    return this->saldo;
}

Funcionario ContaCartao::getTitular()
{
    return this->titular;
}
