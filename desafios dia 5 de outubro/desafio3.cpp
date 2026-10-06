#include <iostream>
using namespace std;
#include "utils.h"

int main(){
    string nome;

    

    cout << "\nDigite o nome completo: ";
    getline(cin, nome);

    cout << "Email: " << gerarEmail(nome) << endl;
    return 1;
}