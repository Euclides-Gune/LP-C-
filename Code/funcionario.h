#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <iostream>
#include "entidade.h" // Herança

class Funcionario : Entidade {
	std::string turno;
	double salario;
	std::string contacto;

public:
	Funcionario();
	Funcionario(int id, std::string nome, int idade, std::string turno, double salario, std::string contacto);
	void setContacto(std::string contacto);
	void setTurno(std::string turno);
	void setSalario(double salario);
	double getSalario();
	std::string getTurno();
	std::string getContacto();

};

#endif