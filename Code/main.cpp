#include <iostream>
#include <string>
#include "instituicao.h"
#include "contacartao.h"
#include "funcionario.h"
#include "docente.h"
#include "secretario.h"

Instituicao inserirInstituicao()
{
    std::cout << "\n-------------------------------\n";
    std::cout << "|   Registo de Instituicoes   |";
    std::cout << "\n-------------------------------\n";
    std::cout << "Nome da instituicao: ";
    std::string nomeInst{};
    std::getline(std::cin >> std::ws, nomeInst);
    // Para  não recriar id
    static int id = 0;
    return { ++id, nomeInst };
}

Docente novoDocente(std::string nomeInst)
{
    std::cout << "Nome do docente: ";
    std::string nome{};
    std::getline(std::cin >> std::ws, nome);
    std::cout << "Idade: ";
    int idade{};
    std::cin >> idade;
    std::cout << "Salario: ";
    double salario{};
    std::cin >> salario;
    std::cout << "Grau academico: ";
    std::string grauAcademico{};
    std::getline(std::cin >> std::ws, grauAcademico);
    std::cout << "Curso: ";
    std::string curso{};
    std::getline(std::cin >> std::ws, curso);
    std::cout << "Estado: \n1. Regente\n2. Assistente\n-> ";
    std::string estado{};
    int opc;
    std::cin >> opc;
    switch (opc)
    {
        case 1:
            estado = "Docente";
        break;
        case 2:
            estado = "Assistente";
        break;
        default:
            std::cout << "Opção inválida";
        break;
    }
    static int id{0};
    return Docente { id++, nomeInst, nome, salario, idade, grauAcademico, curso, estado  };
}

Secretario novoSecretario(std::string nomeInst)
{
    std::cout << "Nome do secretario: ";
    std::string nome{};
    std::getline(std::cin >> std::ws, nome);
    std::cout << "Idade: ";
    int idade{};
    std::cin >> idade;
    std::cout << "Salario: ";
    double salario{};
    std::cin >> salario;
    std::cout << "Departamento: ";
    std::string dep;
    std::getline(std::cin >> std::ws, dep);
    static int id{0};
    return Secretario { id++, nomeInst, nome, salario, idade, dep };
}

void menuCartao()
{
    int op{};
}

void novoFuncionario(std::string nomeInst)
{
    int op{};
    Docente doc;
    Secretario s;
    std::cout << "\n-------------------------------\n";
    std::cout << "|   Registo de Funcionarios   |";
    std::cout << "\n-------------------------------\n";
    std::cout << "1. Inserir docente\n";
    std::cout << "2. Inserir secretario\n";
    std::cout << "3. Voltar\n";
    std::cout << "\n-> ";
    std::cin >> op;
    switch(op)
    {
        case 1:
            doc = novoDocente(nomeInst);
        break;
        case 2:
            s = novoSecretario(nomeInst);
        break;
        case 3:
            return;
        default:
            std::cout << "Opcao invalida.\n";
        break;
    }
    menuCartao();
}

void menuFuncionario(std::string nomeInst)
{
    int op{};
    std::cout << "\n============ Funcionarios ============\n";
    std::cout << "1. Novo funcionario\n";
    std::cout << "2. Visualizar docentes\n";
    std::cout << "3. Visualizar secretarios\n";
    std::cout << "4. Sair\n";
    std::cout << "\n-> ";
    std::cin >> op;

    switch (op)
    {
        case 1:
            novoFuncionario(nomeInst);
        break;
        case 2:
            std::cout << "\nDocentes.\n";
        break;
        case 3:
            std::cout << "\nSecretarios.\n";
        break;
        default:
            std::cout << "\nOpcao invalida!\n";
        break;
    }
}

void entrar()
{
    std::cout << "Nome da instituicao: ";
    std::string nome{};
    std::getline(std::cin >> std::ws, nome);
    menuFuncionario(nome);
}

void exibirMenu()
{
    int op{ 0 };
    do 
    {
        std::cout << "\n============  Instituicoes ============\n";
        std::cout << "1. Registar Instituicao\n";
        std::cout << "2. Entrar em uma Instituicao\n";
        std::cout << "3. Sair\n";
        std::cout << "\n-> ";
        std::cin >> op;
        switch(op) {
            case 1:
                  
            break;
            case 2:
                entrar();
            break;
            case 3: 
                std::cout << "\nSaindo do sistema...Ciao";
            break;
            default:
                std::cout << "Opcao invalida!\n";
            break;
        }
    } while(op != 3);
}

int main()
{
    entrar();
    return 0;
}