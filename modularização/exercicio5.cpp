#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

int main() {
    int tamanho;

    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    vector<int> vetor(tamanho);

    for (int i = 0; i < tamanho; i++) {
        cout << "Digite o valor " << i + 1 << ": ";
        cin >> vetor[i];
    }

    if (estaOrdenado(vetor, tamanho)) {
        cout << "O vetor esta ordenado." << endl;
    } else {
        cout << "O vetor esta desordenado." << endl;
    }

    return 1;
}