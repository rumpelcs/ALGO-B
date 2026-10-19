#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void receberPalavraLetra(string palavra, char letra){ // nao retorna. conta e mostra quantas vezes uma letra aparece na palavra
    int contador = 0;
    for (int i=0; i < palavra.size(); i++){
        if(palavra[i] == letra){
            contador++;
        }
    }

    cout << "A letra '" << letra << "' aparece " << contador << " vez(es) na palavra \"" << palavra << "\".\n";
}

void receberdata(string sdia, string smes, string sano){ // nao retorna. recebe dia, mes e ano como texto e mostra se a data e valida
    
    int dia = stoi(sdia); // stoi serve para converter string para inteiro
    int mes = stoi(smes);
    int ano = stoi(sano);

    if(dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)){
        cout << "data invalida";
    } else if (dia >= 29 && mes == 2) {
        cout << "Data invalida" << endl;
    } else {
        cout << "Data valida" << endl;
    }
}


string extrairPrimeiroNome(string nomeCompleto) { // retorna so o primeiro nome (tudo antes do primeiro espaco)
    string primeiroNome = "";

    for (int i = 0; i < nomeCompleto.size(); i++) {
        if (nomeCompleto[i] == ' ') {
            break; 
        }
        primeiroNome = primeiroNome + nomeCompleto[i];
    }

    return primeiroNome;
}



int contarVogais(string frase){ // retorna para o codigo. conta quantas vogais (maiusculas e minusculas) tem na frase
    int contador = 0;

    for(int i = 0; i < frase.size(); i++){
        if (frase[i] == 'a' || frase[i] == 'A') {
            contador++;
        }
        else if (frase[i] == 'e' || frase[i] == 'E') {
            contador++;
        }
        else if (frase[i] == 'i' || frase[i] == 'I') {
            contador++;
        }
        else if (frase[i] == 'o' || frase[i] == 'O') {
            contador++;
        }
        else if (frase[i] == 'u' || frase[i] == 'U') {
            contador++;
        }
    }
    return contador;
}


string converter_para_maiusculo(string frase){ // retorna a frase toda em letras maiusculas
    for (int i = 0; i < frase.size(); i++) {
        frase[i] = toupper(frase[i]);
    }   
    
    return frase;
}

bool estaOrdenado(int vetor[], int tamanho){ // retorna true se o vetor estiver em ordem crescente, false se nao
    for(int i = 0; i < tamanho - 1; i++){
        if (vetor[i] > vetor[i + 1]) {
            return false; 
        }
    }
    return true;
}

bool existeArquivo(string nomeArquivo) { // retorna true se o arquivo existe (consegue abrir), false se nao
    ifstream arquivo;
    arquivo.open(nomeArquivo);
    if(!arquivo) { // se arquivo nao existe, retorna falso
        return false;
    }
    arquivo.close();
    return true;
}

void exibirQuantasPalavrasArquivo(string palavra, string nomeArquivo) { // nao retorna. mostra quantas vezes uma palavra exata aparece no arquivo
    ifstream arquivo;
    int contador = 0;
    string palavraAtual;
    arquivo.open(nomeArquivo);

    while (arquivo >> palavraAtual) {
        if (palavraAtual == palavra) {
            contador++;
        }
    }
    cout << "Quantidade de " << palavra << " localizadas no arquivo: " << contador << endl;

    arquivo.close();
}



bool validarCPF(string CPF){ // retorna true se o CPF tiver exatamente 11 caracteres
    return CPF.length() == 11;
}

bool retorneData(string data) { // retorna true se a data tiver exatamente 8 caracteres (ex: 01012025)
    if (data.length() != 8) {
        return false;
    } else {
        return true;
    }
}

string gerarEmail(string nomeCompleto) { // monta um email no formato primeiro.ultimo@ufn.edu.br
    string primeiroNome;
    string ultimoNome;

    int posicaoEspaco = nomeCompleto.find(' '); // procura o primeiro espaço
    primeiroNome = nomeCompleto.substr(0, posicaoEspaco); // substr recorta uma string

    int ultimoEspaco = nomeCompleto.find_last_of(' '); // procura o ultimo espaço
    ultimoNome = nomeCompleto.substr(ultimoEspaco + 1); 

    return primeiroNome + "." + ultimoNome + "@ufn.edu.br";
}

// daqui pra baixo, apenas feitos em casa, nao em aula

bool ehPar(int numero) { // retorna true se o numero for par
    if(numero % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

int contarCaracteres(string texto) { // conta quantos caracteres tem no texto, sem contar os espacos
    int contador = 0;
    for(int i = 0; i < texto.size(); i++) {
        if(texto[i] != ' ') {
            contador++;
        }
    }
    return contador;
    // se quiser retornar tudo que tem no texto, com pontos e espaços, apenas colocar return texto.size();
}

int contarLinhasArquivo(string nomeArquivo) { // retorna quantas linhas o arquivo tem (-1 se nao abrir)
    ifstream arquivo;
    int contador = 0;
    string linhalida;
    arquivo.open(nomeArquivo);
    if(!arquivo) {
        return -1; // Retorna -1 se o arquivo não puder ser aberto
    } else {
        while (getline(arquivo, linhalida)) {
            contador++;
        }
        arquivo.close();
    }
    return contador;
}

int somarNumerosArquivo(string nomeArquivo) { // retorna a soma de todos os numeros do arquivo (-1 se nao abrir)
    ifstream arquivo;
    int soma = 0;
    int numero_atual = 0;
    arquivo.open(nomeArquivo);
    if(!arquivo) {
        return -1; // Retorna -1 se o arquivo não puder ser aberto
    } else {
        while (arquivo >> numero_atual) { // extraçao de dados, procura numeros inteiros dentro do texto, ignorando os demais caracteres.
            soma += numero_atual;
        }
        arquivo.close();
    }
    return soma;
}

string retornaFrase(string frase, char caractere){ // troca todas as ocorrencias do caractere por '@' e retorna a frase
    int i;
    for(i = 0; i < frase.size(); i ++){
        if(frase[i] == caractere){
            frase[i] = '@';
        }
    }
    return frase;
}

int vezesPalavra(string nomeArquivo, string buscaPalavra) { // quantas linhas do arquivo contem a palavra (-1 se nao abrir)
    ifstream arquivo;
    int contador = 0;

    arquivo.open(nomeArquivo);
    if (!arquivo) {
        return -1;
    } else {
        string linhaLida;

        while (getline(arquivo, linhaLida)) {
            int tamanhoLinha = linhaLida.length();
            int tamanhoPalavra = buscaPalavra.length();
            bool encontrou = false;

            // Percorre cada posição possível da linha
            for (int i = 0; i <= tamanhoLinha - tamanhoPalavra; i++) {
                bool bateu = true;

                // Compara caractere por caractere a partir da posição 'i'
                for (int j = 0; j < tamanhoPalavra; j++) {
                    if (linhaLida[i + j] != buscaPalavra[j]) {
                        bateu = false;
                        break; // Se um caractere for diferente, para de testar essa posição
                    }
                }

                // Se todos os caracteres bateram, encontramos a palavra na linha!
                if (bateu) {
                    encontrou = true;
                    break; // Passa para a próxima linha
                }
            }

            if (encontrou) {
                contador++;
            }
        }

        arquivo.close();
    }

    return contador;
}

int contaMaioresQueDez(string nomeArquivo){ // conta quantos numeros do arquivo sao maiores que 10 (-1 se nao abrir)
    int i;
    int contador = 0;
    int numero_atual= 0;
    ifstream arquivo;

    arquivo.open(nomeArquivo);
    if(!arquivo){
        return -1;
    } else{

        while(arquivo >> numero_atual){
            if(numero_atual > 10){
                contador++;
            }
        }
    }

    arquivo.close();
    return contador;
}

bool retornaSeMaiorQueCinco(string palavra){ // retorna true se a palavra tiver mais de 5 letras
    return palavra.length() > 5; // se for verdadeiro retorna isso, se nao, retorna falso.
}

char PrimeiraLetra_(string palavra){ // retorna a primeira letra da palavra
   return palavra[0];
}

bool ehNegativo(int numero){ // retorna true se o numero for menor que zero
    if(numero < 0){
        return true;
    } else {
        return false;
    }
}

int contarNumerosArquivo(string nomeArquivo){ // conta quantos numeros existem no arquivo (-1 se nao abrir)
    ifstream arquivo;
    int contador = 0;
    int numeroAtual = 0;
    arquivo.open(nomeArquivo);
    if(!arquivo) {
        return -1; 
    } else {
        while (arquivo >> numeroAtual) {
            contador++;
        }
    }
    arquivo.close();
    return contador;
}

int retornaQuadrado(int numero){ // retorna o numero ao quadrado (numero * numero)
    return numero * numero;
}

void saudacao(string nome){ // nao retorna. mostra uma mensagem de boas vindas com o nome
    cout << "ola " << nome << ", seja bem vindo(a)!\n";
}

int devolveSoma(int numero){ // somar 1+2+3+4+5... ate o numero e retorna o total
    int soma = 0;
    for(int i = 1; i<= numero; i++){
        soma = soma + i;
    }
    return soma;
}

bool apareceNaPalavra(string palavra, char letra){ // retorna true se a letra aparecer pelo menos uma vez na palavra
    for(int i = 0; i < palavra.size(); i ++){
        if(palavra[i] == letra){
            return true;
        }
    }
    return false;
}

void gravaSequencia(int numero){ // nao retorna. grava os numeros de 1 ate numero no arquivo sequencia.txt
    ofstream arquivo("sequencia.txt");   // 1. abre

    for(int i = 1; i <= numero; i++){
        arquivo << i << "\n";            // 2. escreve
    }

    arquivo.close();                     // 3. fecha (depois do laço)
}

void escreveNumero(int numero){ // nao retorna. grava os numeros de 1 ate numero no arquivo numero.txt
    ofstream arquivo("numero.txt");
    for(int i = 1; i <= numero; i ++){
        arquivo << i << "\n";
    }
    arquivo.close();
}

void voltaNomeIdade(string nome, int idade){ // nao retorna. grava nome e idade no arquivo pessoa.txt
    ofstream arquivo("pessoa.txt");
    arquivo << "Nome: " << nome << ". Idade: " << idade;

    arquivo.close();
}

int escreveNumero2(int numero){ // grava de 1 ate numero em numeros.txt e retorna a soma deles
    int soma = 0;
    ofstream arquivo("numeros.txt");

    for(int i = 1; i <= numero; i++){
        arquivo << i << "\n";
        
        soma = soma + i;
    }
    arquivo.close();
    return soma;
}

string converterMaiusculo(string frase){ // retorna a frase toda em letras maiusculas
    for(int i = 0; i < frase.size(); i++){
        frase[i] = toupper(frase[i]);
    }

    return frase;
}

string lerArquivo(string nomeArquivo){ // função usada muito para ler o arquivo e depois fazer a operação que precisar. retorna todo o conteudo do arquivo
    ifstream arquivo(nomeArquivo);
    string conteudo = "";
    string linha;

    while(getline(arquivo, linha)){
        conteudo = conteudo + linha + "\n";
    }

    arquivo.close();
    return conteudo;
}

bool arquivoExiste(string nomeArquivo){ // daqui. retorna true se o arquivo conseguir ser aberto
    ifstream arquivo(nomeArquivo);

    if(arquivo.is_open()){
        arquivo.close();
        return true;
    }

    return false;
}

string substituirLetra(string texto, char letra){ // troca todas as ocorrencias da letra por '@' e retorna o texto
    for(int i = 0; i < texto.size(); i++){
        if(texto[i] == letra){
            texto[i] = '@';
        }
    }

    return texto;
}

string substituirLetraArquivo(string nomeArquivo, char letra){ // le o arquivo e retorna o conteudo com a letra trocada por '@'
    string conteudo = lerArquivo(nomeArquivo);
    return substituirLetra(conteudo, letra);
}
 
// ate aqui, um exercicio apenas

int contarPalavras(string texto){ // conta quantas palavras tem no texto (aceita varios espacos, quebras de linha e tab)
    int contador = 0;
    bool dentroDePalavra = false;

    for(int i = 0; i < texto.size(); i++){
        bool separador = (texto[i] == ' ' || texto[i] == '\n' || texto[i] == '\t');

        if(!separador){
            if(!dentroDePalavra){
                contador++;
                dentroDePalavra = true;
            }
        } else {
            dentroDePalavra = false;
        }
    }

    return contador;
}

string maiusculoArquivo(string nomeArquivo){ // le o arquivo e retorna todo o conteudo em maiusculo
    string conteudo = lerArquivo(nomeArquivo);
    return converterMaiusculo(conteudo);
}

int contarPalavrasArquivo(string nomeArquivo){ // le o arquivo e retorna quantas palavras ele tem
    string conteudo = lerArquivo(nomeArquivo);
    return contarPalavras(conteudo);
}

// =====================================================================
// PONTEIROS E ENDERECOS
// &variavel -> pega o endereco da variavel na memoria
// *ponteiro -> acessa (ou altera) o valor que esta naquele endereco
// int *p    -> declara um ponteiro que guarda o endereco de um int
// =====================================================================

void mostrarEndereco(int &variavel){ // nao retorna. mostra o valor e o endereco de memoria da variavel original
    cout << "Valor: " << variavel << endl;
    cout << "Endereco: " << &variavel << endl; // & na frente mostra o endereco
}

void mostrarPonteiro(int *ponteiro){ // nao retorna. mostra o endereco guardado no ponteiro e o valor que tem la
    cout << "Endereco guardado no ponteiro: " << ponteiro << endl;
    cout << "Valor apontado: " << *ponteiro << endl; // * na frente pega o valor
}

void trocarValores(int *a, int *b){ // nao retorna. troca os valores de duas variaveis usando ponteiros
    int auxiliar = *a; // guarda o valor de a
    *a = *b;           // a recebe o valor de b
    *b = auxiliar;     // b recebe o valor antigo de a
}

void dobrarValor(int *numero){ // nao retorna. dobra o valor da variavel original pelo ponteiro
    *numero = *numero * 2;
}

void dobrarPorReferencia(int &numero){ // nao retorna. mesma coisa do dobrarValor, mas usando referencia (&) em vez de ponteiro
    numero = numero * 2;
}

void zerarValor(int *numero){ // nao retorna. coloca 0 na variavel original
    *numero = 0;
}

void incrementar(int *numero){ // nao retorna. soma 1 na variavel original
    (*numero)++; // os parenteses sao importantes, senao anda o ponteiro em vez do valor
}

int somarComPonteiro(int *a, int *b){ // retorna a soma dos valores apontados por a e b
    return *a + *b;
}

int* maiorPonteiro(int *a, int *b){ // retorna o ENDERECO da variavel que tem o maior valor
    if(*a > *b){
        return a;
    } else {
        return b;
    }
}

bool ehNulo(int *ponteiro){ // retorna true se o ponteiro nao aponta para nada (nullptr)
    return ponteiro == nullptr;
}

void calcularSomaEMedia(int vetor[], int tamanho, int *soma, float *media){ // nao retorna. devolve soma e media pelos ponteiros (jeito de "retornar" mais de um valor)
    *soma = 0;
    for(int i = 0; i < tamanho; i++){
        *soma = *soma + vetor[i];
    }
    *media = (float)*soma / tamanho;
}

void exibirEnderecosVetor(int *vetor, int tamanho){ // nao retorna. mostra o valor e o endereco de cada posicao do vetor
    for(int i = 0; i < tamanho; i++){
        cout << "vetor[" << i << "] = " << *(vetor + i) << " | endereco: " << (vetor + i) << endl;
    }
}

int somarVetorPonteiro(int *vetor, int tamanho){ // retorna a soma do vetor andando com aritmetica de ponteiro (vetor + i)
    int soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma = soma + *(vetor + i); // *(vetor + i) e a mesma coisa que vetor[i]
    }
    return soma;
}

int maiorDoVetor(int *vetor, int tamanho){ // retorna o maior valor do vetor usando ponteiro
    int maior = *vetor; // comeca pelo primeiro elemento
    for(int i = 1; i < tamanho; i++){
        if(*(vetor + i) > maior){
            maior = *(vetor + i);
        }
    }
    return maior;
}

void dobrarVetor(int *vetor, int tamanho){ // nao retorna. dobra todos os elementos do vetor original
    for(int i = 0; i < tamanho; i++){
        *(vetor + i) = *(vetor + i) * 2;
    }
}

void inverterVetor(int *vetor, int tamanho){ // nao retorna. inverte a ordem do vetor original usando dois ponteiros
    int *inicio = vetor;              // aponta para o primeiro elemento
    int *fim = vetor + tamanho - 1;   // aponta para o ultimo elemento

    while(inicio < fim){
        trocarValores(inicio, fim);   // reaproveita a funcao de troca
        inicio++;                     // anda para frente
        fim--;                        // anda para tras
    }
}

int tamanhoTexto(const char *texto){ // retorna o tamanho de um texto estilo C, contando ate achar o '\0'
    int contador = 0;
    while(*texto != '\0'){
        contador++;
        texto++; // anda o ponteiro para o proximo caractere
    }
    return contador;
}

int contarLetraPonteiro(const char *texto, char letra){ // retorna quantas vezes a letra aparece no texto, percorrendo com ponteiro
    int contador = 0;
    while(*texto != '\0'){
        if(*texto == letra){
            contador++;
        }
        texto++;
    }
    return contador;
}

int* criarVetor(int tamanho){ // cria um vetor na memoria dinamica (new) preenchido com 0 e retorna o endereco dele
    int *vetor = new int[tamanho];
    for(int i = 0; i < tamanho; i++){
        vetor[i] = 0;
    }
    return vetor; // lembrar de liberar depois com liberarVetor
}

void liberarVetor(int *vetor){ // nao retorna. libera a memoria criada com new (sempre usar depois do criarVetor)
    delete[] vetor;
}

bool somarArquivoNoPonteiro(string nomeArquivo, int *resultado){ // soma os numeros do arquivo e coloca em *resultado. retorna false se o arquivo nao abrir
    ifstream arquivo(nomeArquivo);
    if(!arquivo){
        return false;
    }

    int numeroAtual = 0;
    *resultado = 0;
    while(arquivo >> numeroAtual){
        *resultado = *resultado + numeroAtual;
    }

    arquivo.close();
    return true;
}
