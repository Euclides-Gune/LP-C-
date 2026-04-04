#ifndef MENU_H
#define MENU_H

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

struct Menu {

static int numeroDe(std::string f)
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

static void registrarInstituicao()
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

static bool validarInstituicao(std::string str)
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

static void registrarConta(std::string nomeInst, std::string titular, std::string cargo)
{
    std::cout << "\n============= Registro da conta cartao do funcionario " << titular << "=============:\n";
    std::string senha{};
    do
    {
        std::cout << "Defina uma senha(6 digitos): ";
        std::getline(std::cin >> std::ws, senha);
    } while (senha.length() != 6);
    
    double saldo{};
    do
    {
        std::cout << "Saldo: ";
        std::cin >> saldo;
    } while(saldo < 0);

    int id = numeroDe("contas.txt") + 1;
    ContaCartao* cc = new ContaCartao(id, nomeInst, senha, saldo, titular);
    std::ofstream outf { "contas.txt", std::ios::app };
    outf.close();
    outf << cc->getID() << ' ' << cc->getNome() << ' ' << cc->getTitular() << ' ' << cargo << ' ' << cc->getSaldo() << ' ' << cc->getSenha() << '\n';
    delete cc;
}

static void registrarFuncionario(std::string nomeInst, std::vector<Docente>& docs, std::vector<Secretario>& secs)
{
    std::cout << "\n\n========= Registrar Funcionario =========\n\n";
    std::string nome{};
    int idade{};
    double salario{};
    std::cout << "Nome: ";
    std::getline(std::cin >> std::ws, nome);
    do
    {
        std::cout << "Idade: ";
        std::cin >> idade;
    } while (idade > 130 || idade < 18);
    do
    {
        std::cout << "Salario: ";
        std::cin >> salario;
    } while(salario < 0);
    int id = numeroDe("funcionarios.txt") + 1;
    std::string cargo{};
    int op{};
    do
    {
        std::cout << "\nCargo:\n1. Docente\n2. Secretario\n\nopcao: ";
        std::cin >> op;
    } while(op != 1 && op != 2);

    std::ofstream outf { "funcionarios.txt", std::ios::app };

    if(op == 1) {
            cargo = "Docente";
            std::string grau{};
            std::string curso{};
            std::string estado{};
            std::cout << "Grau academico: ";
            std::getline(std::cin >> std::ws, grau);
            std::cout << "Curso: ";
            std::getline(std::cin >> std::ws, curso);
            int opc{};
            do
            {
                std::cout << "\nEstado:\n1. Regente\n2. Assistente\n\nOpcao: ";
                std::cin >> opc;
            } while (opc != 1 && opc != 2);
            switch(opc)
            {
                case 1: estado = "Regente";
                break;
                case 2: estado = "Assistente";
                break;
            }

            Docente* doc = new Docente(id, nomeInst, nome, salario, idade, grau, curso, estado);
            outf << doc->getID() << ' ' << doc->getNome() << ' ' << doc->getNomeFunc() << ' ' << doc->getSalario() << ' ' << doc->getIdade() << ' ' << doc->getGrauAcademico() << ' ' << doc->getCurso() << ' ' << doc->getEstado() << ' ' << cargo << ' ' << '\n';
            docs.push_back(*doc);
            delete doc;
    } else if(op == 2) {
        cargo = "Secretario";
        std::string dep{};
        std::cout << "Departamento: ";
        std::getline(std::cin >> std::ws, dep);
        Secretario* ss = new Secretario(id, nomeInst, nome, salario, idade, dep);
        outf << ss->getID() << ' ' << ss->getNome() << ' ' << ss->getNomeFunc() << ' ' << ss->getSalario() << ' ' << ss->getIdade() << ' ' << ss->getDepartamento() << ' ' << cargo << ' ' << '\n';
        secs.push_back(*ss);
        delete ss;
    }

    outf.close();

    registrarConta(nomeInst, nome, cargo);
}

static void registrarFuncionarios(std::vector<Docente>& docs, std::vector<Secretario>& secs)
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

static ContaCartao dadosDaConta(std::string& cargo)
{
    std::cout << "\n============== Dados da Conta Cartao ==============\n";
    std::cout << "Nome da instituicao: ";
    std::string nomeI{};
    std::getline(std::cin >> std::ws, nomeI);
    std::cout << "Titular: ";
    std::string titular{};
    std::getline(std::cin >> std::ws, titular);
    std::string pass{};
    do
    {
        std::cout << "Senha(6 digitos): ";
        std::getline(std::cin >> std::ws, pass);
    } while (pass.length() != 6);

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

static void entrarNaConta()
{
    std::string cargo{};
    ContaCartao cc = dadosDaConta(cargo);
    if(cc.getID() != 0) {
        std::cout << "\nDados da conta cartao:\n\n"; 
        std::cout << cc;
        std::cout << "Cargo: " << cargo << '\n';
    }  else {
        std::cout << "\nDados invalidos!\n";
    }
}

static void menu(std::vector<Docente>& docs, std::vector<Secretario>& secs)
{
    int op{};
    do
    {
        std::cout << "\n=============== Menu ===============\n\n1. Registrar instituicao\n";
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
                entrarNaConta();
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

};

#endif