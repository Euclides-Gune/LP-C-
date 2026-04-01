#include <iostream>
#include "entidade.h"
#include "contacartao.h"
#include "funcionario.h"
#include "docente.h"
#include "secretario.h"

int main()
{
    Entidade ent { 1, "Euclides", 19 };
    ContaCartao ct { 1, "Euclides", 19, 1122, 1000, "Poupança" };
    Funcionario f { 1, "Euclides", 19, "laboral", 2000, "871112222" };
    Docente dc {  1, "Euclides", 19, "laboral", 2000, "871112222", "Licenciado", "Engenheiro civil", "assistente" };
    Secretario s {  1, "Euclides", 19, "laboral", 2000, "871112222", "Engenharia Electrotécnica" };
    std::cout << ent.getNome() << '\n';
    std::cout << ct.getSaldo() << '\n';
    std::cout << f.getContacto() << '\n';
    std::cout << dc.getGrauAcademico() << '\n';
    std::cout << s.getDepartamento() << '\n';
    return 0;
}