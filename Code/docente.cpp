#include <iostream>
#include "docente.h"

//Constructor default/vazio
Docente::Docente() = default;

Docente::Docente(int id, std::string nome, std::string nomeFunc, double salario, int idade, std::string grauAcademico, std::string curso, std::string estado): Funcionario(id,nome, nomeFunc, salario, idade)
{
    this->grauAcademico = grauAcademico;
    this->curso = curso;
    this->estado = estado;
}

void Docente::setGrauAcademico(std::string grau)
{
    this->grauAcademico = grau;
}

void Docente::setCurso(std::string curso)
{
    this->curso = curso;
}

void Docente::setEstado(std::string estado)
{
    this->estado = estado;
}

std::string Docente::getGrauAcademico() const
{
    return this->grauAcademico;
}

std::string Docente::getCurso() const
{
    return this->curso;
}

std::string Docente::getEstado() const
{
    return this->estado;
}