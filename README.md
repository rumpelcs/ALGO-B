# ALGO-B
repositório de algoritmos e programação B


## DIA 27/07/2026

	- Apresentação da disciplina;
	- Explicação de como vai funcionar (notas de aula, GitHub);
	- Revisão Algoritmos A;
	 - estrutura de programa,
	 - instruções (primitivas e contable),
	 - variáveis,
	 - lógica;
	- Alexandre Zamberlan - alexz@ufn.edu.br;
	- https://github.com/alexandrezamberlan/algoritmos;
	- KISS (KEEP IT SIMPLE, STUPID!);
	- ALGO B {
		- STRUCTS
		- MODULARIZAÇÃO = MÉTODOS
		- ARQUIVOS TEXTO
		- PONTEIROS ≅ ALOCAÇÃO DINÂMICA DE MEMÓRIA
		}
	- Exercicios de anos dormindo e doses de insulina;

## DIA 03/08/2026

	- programa com MENU
	   - C
	   - C++
	- Programa com VETOR com n elementos sortidos
	   - C
	   - C++ 
	- lista de exercícios

## DIA 10/08/2026

	- revisão de vetores com push_back
	- explicação de locações em vetores
	- apresentação de struct
	- Atividade sobre Garagem em C++

## DIA 17/08/2026

	- continuação de struct
	- lista com 10 exercicios


## DIA 24/08/2026

	- ler arquivos de outro endereço para usar no codigo com #include <fstream> - ifstream

## DIA 31/08/2026
	- primeira avaliação:
		2 exercícios de struct
		1 código para uma biblioteca

## DIA 14/09/2026
	- arquivos -> conversação entre sistemas

	- sistema computacional:
		programa -> variáveis	 |	arquivo (json, csv, sgbd)
		_________________________|____________________
		memória principal/RAM	 |  memória secundaria (HD, SSD...)
					procurador ----> arquivo
				file ---endereço fisico---> arquivo
						    ponteiro

		- procurador_leitor
		- procurador_escritor

	- ler
	- escrever -> write (novo)
			   -> append (adiciona na fila)

	- correção da prova

## DIA 21/09/2026

	- IA generativa
	- código que lê arquivo de stop words, e escreve em outro
	

## DIA 28/09/2026
	# Desenvolvimento de programas:
	## Uso de structs combinados com listas ou arrays ou vetores

	## Manipulação de arquivos texto (plain texto: csv, xml, json, toon)

	## Organização do código em módulos ou modularização
    	- métodos sem retorno - há presença da palavra void
       		- procedimentos ou procedure
        	- linguagens como C, C++, Java, C#

        	void nomeProcedimento(tipo param1, tipo param2, tipo param3, ...) {
            	//codigos
        	}

        	ou 

        	void nomeProcedimento() {
            	//codigos
        	}


    	- métodos com retorno - há presença da palavra return
        	- funções ou function
        	- linguagens como C, C++, Java, C#

        	tipo nomeFuncao(tipo param1, tipo param2, tipo param3, ...) {
            	//codigos

            	return valor_daquele_tipo;
        	}

        	ou

        	tipo nomeFuncao() {
            	//codigos

            	return valor_daquele_tipo;
        	}


    	IMPORTANTE:
            	- parâmetro (param) ou argumento (arg)
                	- é uma referência para dentro do código

            	- operação é o conjunto de ações desejadas no programa
                	- método é uma forma particular de resolver aquela operação

            	- Sistema ou um programa composto por N funcionalidades
                	- Alternativa atual
                    	- uma funcionalidade abaixo da outra (programação sequencial e a la script)
                	- Decomposição funcional
                    	- criar módulo para um conjunto de funcionalidades
                        	- possibilidade de reuso
                        	- facilidade de manutenção
            	- como identificar no meio de um código se um método é SEM RETORNO

                	metodo()
                	metodo(3,x)


            	- como identificar no meio de um código se um método é COM RETORNO

                	var = metodo()
                	var = metodo(3, x)
                	if (metodo(3,x) == true) {
                    
                	}
