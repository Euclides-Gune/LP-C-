#ifndef DOCENTE_H
#define DOCENTE_H
#include <iostream>
#include "funcionario.h" // Herança

class Docente : public Funcionario {
    std::string grauAcademico{};
    std::string curso{};
    std::string estado{};

public:
    Docente();
    Docente(int id, std::string nome, int idade, std::string turno, double salario, std::string contacto, std::string grauAcademico, std::string curso, std::string estado);
    void setGrauAcademico(std::string grau);
    void setCurso(std::string curso);
    void setEstado(std::string estado);
    std::string getGrauAcademico();
    std::string getCurso();
    std::string getEstado();
};

#endif