#include <iostream>
#include "instituicao.h"
#include "contacartao.h"
#include "funcionario.h"
#include "docente.h"
#include "secretario.h"

int main()
{
    Instituicao i { 1, "UEM" };
    Funcionario f { 1, "UEM", "Euclides", 450000, 19 };
    ContaCartao cc { 1, "UEM", 777555, 500000, f };
    Docente dc { 1, "UEM", "Euclides", 450000, 19, "PHD", "Ciência da Computação", "Regente" };
    Secretario s { 1, "UEM", "Wendy", 10000000, 18, "Engenharia Informatica" };

    std::cout << "Docente: \n";
    std::cout << "Nome: " << dc.getNomeFunc() << '\n';
    std::cout << "Instituicao: " << dc.getNomeDaInstituicao() << '\n'; 
    std::cout << "Idade: " << dc.getIdade() << '\n'; 
    std::cout << "Salario: " << dc.getSalario() << '\n'; 
    std::cout << "Grau academico: " << dc.getGrauAcademico() << '\n'; 
    std::cout << "Curso: " << dc.getCurso() << '\n'; 
    std::cout << "Estado: " << dc.getEstado() << '\n'; 
    std::cout << "Secretario: " << '\n';
    std::cout << "Nome: " << s.getNomeFunc() << '\n';
    std::cout << "Instituicao: " << s.getNomeDaInstituicao() << '\n'; 
    std::cout << "Idade: " << s.getIdade() << '\n'; 
    std::cout << "Salario: " << s.getSalario() << '\n'; 
    std::cout << "Departamento: " << s.getDepartamento() << '\n';
 
    return 0;
}