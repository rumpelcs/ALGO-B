#include <iostream>
#include <string>
#include "util.h"

using namespace std;

int main() {
    string nome;

    cout << "Digite seu nome completo: ";
    getline(cin, nome);

    cout << "Primeiro nome: "
         << primeiroNome(nome) << endl;

    return 1;
}