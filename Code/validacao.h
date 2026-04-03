#ifndef VALIDACAO_H
#define VALIDACAO_H

#include <iostream>

class Validacao {
public:
    Validacao() = default;
    std::string validarString(std::string msg);
    int validarIntPositivo(int msg);
    int validarInterValo(std::string msg, int min, int max);
    char validarChar(std::string msg, char op1, char op2);
};

#endif