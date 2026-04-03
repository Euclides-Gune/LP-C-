#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <iostream>
#include "Instituicao.h" // Herança

class Funcionario : public Instituicao {
	std::string nomeFunc;
	double salario;
	int idade;

public:
	Funcionario();
	Funcionario(int id, std::string nome, std::string nomeFunc, double salario, int idade);
	void setIdade(int idade);
	void setNomeFunc(std::string nomeFunc);
	void setSalario(double salario);
	double getSalario();
	std::string getNomeFunc();
	int getIdade();

};

#endif