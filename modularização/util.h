#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Exercício 1
// Conta quantas vezes uma letra aparece em uma palavra
void contarLetra(string palavra, char letra) {
    int contar = 0;

    for (int i = 0; i < palavra.length(); i++) {
        if (palavra[i] == letra) {
            contar++;
        }
    }

    std::cout << "A letra '" << letra << "' aparece "
              << contar << " vez(es)." << std::endl;
}

// Exercício 2
// Verifica se uma data é válida
void validarData(string dia, string mes, string ano) {
    int d = stoi(dia);
    int m = stoi(mes);
    int a = stoi(ano);

    bool valida = true;

    if (a <= 0 || m < 1 || m > 12 || d < 1) {
        valida = false;
    }

    int diasNoMes;

    if (m == 2) {
        // Verifica ano bissexto
        if ((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0)) {
            diasNoMes = 29;
        } else {
            diasNoMes = 28;
        }
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        diasNoMes = 30;
    }
    else {
        diasNoMes = 31;
    }

    if (d > diasNoMes) {
        valida = false;
    }

    if (valida) {
        std::cout << "DATA VALIDA" << std::endl;
    } else {
        std::cout << "DATA INVALIDA" << std::endl;
    }
}

// Exercício 3
// Retorna a quantidade de vogais de uma frase
int contarVogais(string frase) {
    int contador = 0;

    for (int i = 0; i < frase.length(); i++) {
        char letra = tolower(frase[i]);

        if (letra == 'a' ||
            letra == 'e' ||
            letra == 'i' ||
            letra == 'o' ||
            letra == 'u') {
            contador++;
        }
    }

    return contador;
}

// Exercício 4
// Retorna a frase totalmente em maiúsculas
string paraMaiuscula(string frase) {
    for (int i = 0; i < frase.length(); i++) {
        frase[i] = toupper(frase[i]);
    }

    return frase;
}

// Exercício 5
// Verifica se um vetor está ordenado
bool estaOrdenado(vector<int> vetor, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return false;
        }
    }

    return true;
}

// Exercício 6
// Retorna o primeiro nome de um nome completo
string primeiroNome(string nomeCompleto) {
    int posicao = nomeCompleto.find(' ');

    if (posicao == string::npos) {
        return nomeCompleto;
    }

    return nomeCompleto.substr(0, posicao);
}

#endif