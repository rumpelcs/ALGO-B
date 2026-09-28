#include <iostream>
#include "util.h"

using namespace std;

int main() {
    string palavra;
    char letra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    cout << "Digite uma letra: ";
    cin >> letra;

    contarLetra(palavra, letra);

    return 1;
}