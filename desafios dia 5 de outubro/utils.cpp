#include "utils.h"

bool validarCPF(string cpf){
    return cpf.length() == 11;
}

bool validarData(string data){
    return data.length() == 10;
}

string gerarEmail(string nomeCompleto) {
    string primeiroNome;
    string ultimoNome;

    int posicaoEspaco = nomeCompleto.find(' ');

    primeiroNome = nomeCompleto.substr(0, posicaoEspaco);

    int ultimoEspaco = nomeCompleto.find_last_of(' ');
    ultimoNome = nomeCompleto.substr(ultimoEspaco + 1);

    return primeiroNome + "." + ultimoNome + "@ufn.edu.br";
}