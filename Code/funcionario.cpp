#include<iostream>
#include "funcionario.h"

//Constructor default/vazio
Funcionario::Funcionario() = default;

Funcionario::Funcionario(int id, std::string nome, std::string nomeFunc, double salario, int idade): Instituicao(id, nome)
{
	this->nomeFunc = nomeFunc;
	this->salario = salario;
	this->idade = idade;
}
void Funcionario::setIdade(int idade)
{
	this->idade = idade;
}
void Funcionario::setNomeFunc(std::string nomeFunc)
{
	this->nomeFunc = nomeFunc;
}
void Funcionario::setSalario(double salario)
{
	this->salario = salario;
}
double Funcionario::getSalario()
{
	return this->salario;
}
std::string Funcionario::getNomeFunc()
{
	return this->nomeFunc;
}
int Funcionario::getIdade()
{
	return this->idade;
}