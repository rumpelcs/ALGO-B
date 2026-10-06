#include <iostream>
using namespace std;
#include "utils.h"

int main(){

    string cpf;

    cout << "Digite o CPF sem pontuacao: ";
    cin >> cpf;

    if(validarCPF(cpf)){
        cout << "CPF valido.\n";
    } else {
        cout << "CPF invalido.\n";
    }
    return 1;
}