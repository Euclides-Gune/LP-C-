#include <iostream>
#include "contacartao.h"
#include "instituicao.h"

//Constructor default/vazio
ContaCartao::ContaCartao() = default;

ContaCartao::ContaCartao(int id, std::string nome, std::string senhaDeAccesso, double saldo, std::string titular): Instituicao(id, nome)
{
    this->senha = senhaDeAccesso;
    this->saldo = saldo;
    this->titular = titular;
}

void ContaCartao::setSenha(std::string senha)
{
    this->senha = senha;
}

void ContaCartao::setSaldo(double saldo)
{
    this->saldo = saldo;
}

std::string ContaCartao::getSenha() const
{
    return this->senha;
}

double ContaCartao::getSaldo() const
{
    return this->saldo;
}

std::string ContaCartao::getTitular() const
{
    return this->titular;
}
