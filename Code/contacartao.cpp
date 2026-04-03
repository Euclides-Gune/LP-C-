#include <iostream>
#include "contacartao.h"

//Constructor default/vazio
ContaCartao::ContaCartao() = default;

ContaCartao::ContaCartao(int id, std::string nome, int idade, int senhaDeAccesso, double saldo, std::string tipo): Entidade(id, nome, idade)
{
    this->senha = senhaDeAccesso;
    this->saldo = saldo;
    this->tipoDeConta = tipo;
}

void ContaCartao::setSenha(int senha)
{
    this->senha = senha;
}

void ContaCartao::setSaldo(double saldo)
{
    this->saldo = saldo;
}

void ContaCartao::setTipoDeConta(std::string tipo)
{
    this->tipoDeConta = tipo;
}

int ContaCartao::getSenha()
{
    return this->senha;
}

double ContaCartao::getSaldo()
{
    return this->saldo;
}

std::string ContaCartao::getTipoDeConta()
{
    return this->tipoDeConta;
}
