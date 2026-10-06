#include <iostream>
using namespace std;
#include "utils.h"

int main(){

    string data;

    cout << "\nDigite a data (dd/mm/aaaa): ";
    cin >> data;

    if (validarData(data)){
        cout << "Data valida" << endl;
    } else {
        cout << "Data invalida" << endl;
    }
    return 1;
}