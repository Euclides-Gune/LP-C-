#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "instituicao.h"
#include "docente.h"
#include "secretario.h"
#include "contacartao.h"

std::ostream& operator<<(std::ostream& out, const ContaCartao& cc)
{
    out << "ID: " << cc.getID()
    << "\nNome da instituicao: " << cc.getNome() << "\nTitular: " << cc.getTitular() << "\nSaldo: " << cc.getSaldo() << '\n';
    return out;
}

int numeroDe(std::string f)
{
    std::ifstream inf { f };
    std::string line{};
    int count = 0;
    while(std::getline(inf, line))
    {
        count++;
    }
    inf.close();
    return count;
}

void registrarInstituicao()
{
    int id = numeroDe("insts.txt") + 1;
    std::cout << "Nome da instituicao: ";
    std::string nomeInst{};
    std::getline(std::cin >> std::ws, nomeInst);

    Instituicao* inst = new Instituicao(id, nomeInst);

    std::ofstream outf { "insts.txt", std::ios::app };

    outf << id << ' ' << nomeInst << '\n';

    delete inst;
    outf.close();
}

bool validarInstituicao(std::string str)
{
    std::ifstream inf { "insts.txt" };
    std::string input{};
    int id = 0;
    int count = 1;
    while(inf >> input) 
    {
        switch(count)
        {
            case 1:
                count++;
            break;
            case 2:
                if(str == input)
                    return 1;
                count = 1;
            break;
        }
    }
    return 0;
}

void registrarConta(std::string nomeInst, std::string titular, std::string cargo)
{
    std::cout << "Registro da conta cartao do funcionario " << titular << ":\n";
    std::cout << "Defina uma senha: ";
    std::string senha{};
    std::getline(std::cin >> std::ws, senha);
    std::cout << "Saldo: ";
    double saldo{};
    std::cin >> saldo;

    int id = numeroDe("contas.txt") + 1;
    ContaCartao* cc = new ContaCartao(id, nomeInst, senha, saldo, titular);
    std::ofstream outf { "contas.txt", std::ios::app };
    outf << cc->getID() << ' ' << cc->getNome() << ' ' << cc->getTitular() << ' ' << cargo << ' ' << cc->getSaldo() << ' ' << cc->getSenha() << '\n';
    outf.close();
    delete cc;
}

void registrarFuncionario(std::string nomeInst, std::vector<Docente>& docs, std::vector<Secretario>& secs)
{
    std::cout << "Nome: ";
    std::string nome{};
    std::getline(std::cin >> std::ws, nome);
    std::cout << "Idade: ";
    int idade{};
    std::cin >> idade;
    std::cout << "Salario: ";
    double salario{};
    std::cin >> salario;
    int id = numeroDe("funcionarios.txt") + 1;
    std::cout << "\nCargo:\n1. Docente\n2. Secretario\n\nopcao: ";
    std::string cargo{};
    int op{};
    std::cin >> op;

    std::ofstream outf { "funcionarios.txt", std::ios::app };

    if(op == 1) {
            cargo = "Docente";
            std::cout << "Grau academico: ";
            std::string grau{};
            std::getline(std::cin >> std::ws, grau);
            std::cout << "Curso: ";
            std::string curso{};
            std::getline(std::cin >> std::ws, curso);
            std::cout << "\nEstado:\n1. Regente\n2. Assistente\n\nOpcao: ";
            std::string estado{};
            int opc{};
            std::cin >> opc;
            switch(opc)
            {
                case 1: estado = "Regente";
                break;
                case 2: estado = "Assistente";
                break;
                default:
                    std::cout << "\nInvalido!\n";
                break;
            }

            Docente* doc = new Docente(id, nomeInst, nome, salario, idade, grau, curso, estado);
            outf << doc->getID() << ' ' << doc->getNome() << ' ' << doc->getNomeFunc() << ' ' << doc->getSalario() << ' ' << doc->getIdade() << ' ' << doc->getGrauAcademico() << ' ' << doc->getCurso() << ' ' << doc->getEstado() << ' ' << cargo << ' ' << '\n';
            docs.push_back(*doc);
            delete doc;
    } else if(op == 2) {
        cargo = "Secretario";
        std::cout << "Departamento: ";
        std::string dep{};
        std::getline(std::cin >> std::ws, dep);
        Secretario* ss = new Secretario(id, nomeInst, nome, salario, idade, dep);
        outf << ss->getID() << ' ' << ss->getNome() << ' ' << ss->getNomeFunc() << ' ' << ss->getSalario() << ' ' << ss->getIdade() << ' ' << ss->getDepartamento() << ' ' << cargo << ' ' << '\n';
        secs.push_back(*ss);
        delete ss;
    }

    outf.close();

    registrarConta(nomeInst, nome, cargo);
}

void registrarFuncionarios(std::vector<Docente>& docs, std::vector<Secretario>& secs)
{
    std::cout << "Digite o nome da instituicao: ";
    std::string nomeInst{};
    std::getline(std::cin >> std::ws, nomeInst);
    if(validarInstituicao(nomeInst)) {
        registrarFuncionario(nomeInst, docs, secs);
    } else {
        std::cout << "\nNome de instituicao invalido!\n";
    }
}

ContaCartao getConta(std::string& cargo)
{
    std::cout << "\n============== Entrar Com Conta Cartao ==============\n";
    std::cout << "Nome da instituicao: ";
    std::string nomeI{};
    std::getline(std::cin >> std::ws, nomeI);
    std::cout << "Titular: ";
    std::string titular{};
    std::getline(std::cin >> std::ws, titular);
    std::cout << "Senha: ";
    std::string pass{};
    std::getline(std::cin >> std::ws, pass);

    std::ifstream inf { "contas.txt" };
    std::string input{};
    int count = 1;

    int id = 0;
    std::string nomeInst{};
    std::string nome{};
    std::string senha{};
    double saldo = 0;

    ContaCartao cc;

    while(inf >> input) {
        switch(count)
        {
            case 1:
            id = std::stoi(input);
            count++;
            break;
            case 2: nomeInst = input;
            count++;
            break;
            case 3: nome = input;
            count++;
            break;
            case 4:
            cargo = input;
            count++;
            break;
            case 5: 
            saldo = std::stod(input);
            count++;
            break;
            case 6:
            senha = input;
            count++;
            count = 1;
            break;
        }
        if(nomeI == nomeInst && nome == titular && senha == pass) {
            cc = ContaCartao(id, nomeInst, senha, saldo, nome);
            return cc;
            break;
        }
    }

    return ContaCartao();
}

void entrarConta()
{
    std::string cargo{};
    ContaCartao cc = getConta(cargo);
    if(cc.getID() != 0) {
        std::cout << "\nDados da conta cartao:\n\n"; 
        std::cout << cc;
        std::cout << "Cargo: " << cargo << '\n';
    }  else {
        std::cout << "\nDados invalidos!\n";
    }
}

void menu(std::vector<Docente>& docs, std::vector<Secretario>& secs)
{
    int op{};
    do
    {
        std::cout << "\n1. Registrar instituicao\n";
        std::cout << "2. Registrar funcionarios\n3. Entrar com conta cartao\n4. Sair\nOpcao: ";
        std::cin >> op;
        switch(op)
        {
            case 1:
                registrarInstituicao();
            break;
            case 2:
                registrarFuncionarios(docs, secs);
            break;
            case 3:
                entrarConta();
            break;
            case 4:
                std::cout << "\nSaindo do programa...\nCiao\n";
                break;
            default:
                std::cout << "Opc invalida!\n";
                break;
        }
    } while(op != 4);
}

std::ostream& operator<<(std::ostream& out, const Docente& doc)
{
    out << "ID: " << doc.getID() << "\nNome da instituicao: " << doc.getNome() << "\nNome do funcionario: " << doc.getNomeFunc() << "\nIdade: " << doc.getIdade() << "\nSalario: " << doc.getSalario() << "\nGrau academico: " << doc.getGrauAcademico() << "\nCurso: " << doc.getCurso() << "\nEstado: " << doc.getEstado() << '\n';
    return out;
}

std::ostream& operator<<(std::ostream& out, const Secretario& sec)
{
    out << "ID: " << sec.getID() << "\nNome da instituicao: " << sec.getNome() << "\nNome do funcionario: " << sec.getNomeFunc() << "\nIdade: " << sec.getIdade() << "\nSalario: " << sec.getSalario() << "\nGrau academico: " << sec.getDepartamento() << '\n';
    return out;
}
 
int main()
{
    std::vector<Docente> docs;
    std::vector<Secretario> secs;
    menu(docs, secs);

    std::cout << "\nDados dos funcionarios adicionados:\n";
    std::cout << "\nDocentes: \n\n";
    for(int i = 0; i < docs.size(); i++) {
        std::cout << docs[i] << '\n';
    }
    std::cout << "\n\nSecretarios: \n\n";
    for(int i = 0; i < secs.size(); i++) {
        std::cout << secs[i] << '\n';
    }

    return 0;
}