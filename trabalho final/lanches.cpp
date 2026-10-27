#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define ARQUIVO "base.csv"

struct Lanche {
    string tipo;
    string lugar;
    float nota;
};

// por referência (&): os lanches lidos do arquivo ficam no vetor do main
void carregarArquivo(vector<Lanche> &lanches) {
    ifstream arquivo(ARQUIVO);
    string campoNota;
    Lanche lanche;

    if (!arquivo.is_open()) {
        return;
    }

    // lê cada campo direto do arquivo: tipo e lugar até o ';', nota até o fim da linha
    while (getline(arquivo, lanche.tipo, ';')) {
        getline(arquivo, lanche.lugar, ';');
        getline(arquivo, campoNota);
        lanche.nota = stof(campoNota);

        lanches.push_back(lanche);
    }

    arquivo.close();
}

// reescreve o arquivo inteiro com o que está no vetor
void salvarArquivo(const vector<Lanche> &lanches) {
    ofstream arquivo(ARQUIVO);

    for (int i = 0; i < lanches.size(); i++) {
        arquivo << lanches[i].tipo << ";" << lanches[i].lugar << ";" << lanches[i].nota << endl;
    }

    arquivo.close();
}

void cadastrarLanche(vector<Lanche> &lanches) {
    Lanche lanche;

    cin.ignore();

    cout << "\nTipo do lanche: ";
    getline(cin, lanche.tipo);

    cout << "Lugar: ";
    getline(cin, lanche.lugar);

    do {
        cout << "Nota (0 a 10): ";
        cin >> lanche.nota;

        if (lanche.nota < 0 || lanche.nota > 10) {
            cout << "Nota invalida. Redigite.\n";
        }
    } while (lanche.nota < 0 || lanche.nota > 10);

    lanches.push_back(lanche);
    salvarArquivo(lanches);

    cout << "Lanche salvo em " << ARQUIVO << "\n\n";
}

void listarLanches(const vector<Lanche> &lanches) {
    if (lanches.empty()) {
        cout << "\nNenhum lanche cadastrado.\n\n";
        return;
    }

    cout << "\nTIPO\tLUGAR\tNOTA\n";
    for (int i = 0; i < lanches.size(); i++) {
        cout << lanches[i].tipo << "\t" << lanches[i].lugar << "\t" << lanches[i].nota << endl;
    }
    cout << endl;
}

// método com retorno: devolve a posição do lanche com maior nota
int melhorLanche(const vector<Lanche> &lanches) {
    int posicao = 0;

    for (int i = 1; i < lanches.size(); i++) {
        if (lanches[i].nota > lanches[posicao].nota) {
            posicao = i;
        }
    }
    return posicao;
}

int main() {
    vector<Lanche> lanches;
    int opcao;
    int posicao;

    carregarArquivo(lanches);

    do {
        cout << "MENU PRINCIPAL\n";
        cout << "1 - Cadastrar lanche\n";
        cout << "2 - Listar lanches\n";
        cout << "3 - Melhor lanche\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";

        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarLanche(lanches);
                break;

            case 2:
                listarLanches(lanches);
                break;

            case 3:
                if (lanches.empty()) {
                    cout << "\nNenhum lanche cadastrado.\n\n";
                } else {
                    posicao = melhorLanche(lanches);
                    cout << "\nMelhor lanche: " << lanches[posicao].tipo << " - " << lanches[posicao].lugar
                         << " (nota " << lanches[posicao].nota << ")\n\n";
                }
                break;

            case 4:
                cout << "\nSaindo do programa...\n";
                break;

            default:
                cout << "\nOpcao invalida. Redigite.\n\n";
        }

    } while (opcao != 4);

    return 0;
}
