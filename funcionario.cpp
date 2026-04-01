#include<iostream>
#include "funcionario.h"

//Constructor default/vazio
Funcionario::Funcionario() = default;

Funcionario::Funcionario(int id, std::string nome, int idade, std::string turno, double salario, std::string contacto): Entidade(id, nome, idade)
{
	this->turno = turno;
	this->salario = salario;
	this->contacto = contacto;
}
void Funcionario::setContacto(std::string contacto)
{
	this->contacto = contacto;
}
void Funcionario::setTurno(std::string turno)
{
	this->turno = turno;
}
void Funcionario::setSalario(double salario)
{
	this->salario = salario;
}
double Funcionario::getSalario()
{
	return this->salario;
}
std::string Funcionario::getTurno()
{
	return this->turno;
}
std::string Funcionario::getContacto()
{
	return this->contacto;
}