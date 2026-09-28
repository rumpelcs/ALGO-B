#include <iostream>
#include "util.h"

using namespace std;

int main() {
    string dia, mes, ano;

    cout << "Digite o dia: ";
    cin >> dia;

    cout << "Digite o mes: ";
    cin >> mes;

    cout << "Digite o ano: ";
    cin >> ano;

    validarData(dia, mes, ano);

    return 1;
}