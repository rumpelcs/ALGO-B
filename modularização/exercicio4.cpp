#include <iostream>
#include <string>
#include "util.h"

using namespace std;

int main() {
    string frase;

    cout << "Digite uma frase: ";
    getline(cin, frase);

    cout << "Frase em maiuscula: "
         << paraMaiuscula(frase) << endl;

    return 1;
}