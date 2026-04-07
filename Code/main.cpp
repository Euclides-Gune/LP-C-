#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "instituicao.h"
#include "docente.h"
#include "secretario.h"
#include "contacartao.h"
#include "Menu.h"

std::ostream& operator<<(std::ostream& out, const Docente& doc)
{
    out << "ID: " << doc.getID() << "\nNome da instituicao: " << Menu::cleanString('-', ' ', doc.getNome()) << "\nNome do funcionario: " << Menu::cleanString('-', ' ', doc.getNomeFunc()) << "\nIdade: " << doc.getIdade() << "\nSalario: " << doc.getSalario() << "\nGrau academico: " << doc.getGrauAcademico() << "\nCurso: " << Menu::cleanString('-', ' ', doc.getCurso()) << "\nEstado: " << doc.getEstado() << '\n';
    return out;
}

std::ostream& operator<<(std::ostream& out, const Secretario& sec)
{
    out << "ID: " << sec.getID() << "\nNome da instituicao: " << Menu::cleanString('-', ' ', sec.getNome()) << "\nNome do funcionario: " << Menu::cleanString('-', ' ', sec.getNomeFunc()) << "\nIdade: " << sec.getIdade() << "\nSalario: " << sec.getSalario() << "\nGrau academico: " << Menu::cleanString('-', ' ', sec.getDepartamento()) << '\n';
    return out;
}
 
int main()
{
    std::vector<Docente> docs;
    std::vector<Secretario> secs;
    Menu::menu(docs, secs);

    std::cout << "\n------------ Dados dos funcionarios adicionados ------------\n";
    
    if(docs.size() > 0 && secs.size() > 0) {
        std::cout << "\nDocentes: \n\n";
        for(int i = 0; i < docs.size(); i++) {
            std::cout << docs[i] << '\n';
        }
        std::cout << "Secretarios: \n\n";
        for(int i = 0; i < secs.size(); i++) {
            std::cout << secs[i] << '\n';
        }
    } else if(docs.size() > 0 && secs.size() == 0) {
        std::cout << "\nDocentes: \n\n";
        for(int i = 0; i < docs.size(); i++) {
            std::cout << docs[i] << '\n';
        }
    } else if(docs.size() == 0 && secs.size() > 0) {
        std::cout << "Secretarios: \n\n";
        for(int i = 0; i < secs.size(); i++) {
            std::cout << secs[i] << '\n';
        }
    } else {
        std::cout << "Nenhum funcionario adicionado!\n";
    }

    return 0;
}