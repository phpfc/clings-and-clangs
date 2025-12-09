/*
2) Implemente uma função em C que receba um vetor de estruturas contendo
informações sobre transações bancárias. Cada estrutura possui os seguintes
campos:

typedef struct data {
        int dia;
        int mes;
        int ano;
}DATA;

typedef struct transacao {
        Data data;
        float valor;
        char descricao[100];
}TRANSACAO;
Desenvolva uma função chamada filtrarPorData que receba como parâmetros:

    • Um vetor de estruturas struct  TRANSACAO contendo todas as transações
bancárias. • O tamanho do vetor. • Uma data inicial e uma data final,
representadas por estruturas do tipo DATA

A função filtrarPorData deverá retornar:

    • Um novo vetor contendo as transações que estão dentro do intervalo de
datas especificado. • Modificiar um inteiro com o número de transações
encontradas dentro do intervalo.

A função obrigatoriamente deverá seguir o seguinte protótipo:

TRANSACAO * filtrarPorData(TRANSACAO *transacoes, int n, DATA inicio, DATA fim,
int *nt);

Implemente o programa principal em C que chame a função filtrarPorData para
filtrar as transações entre duas datas específicas e imprime as transações
retornadas pela função.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct data {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct transacao {
  Data data;
  float valor;
  char descricao[100];
} Transacao;

Transacao *criarDadosMock(int *quantidade) {
  *quantidade = 5;
  Transacao *trans = malloc(5 * sizeof(Transacao));

  trans[0] = (Transacao){{10, 1, 2024}, 150.50, "Compra"};
  trans[1] = (Transacao){{15, 1, 2024}, 200.00, "Salario"};
  trans[2] = (Transacao){{20, 2, 2024}, 75.30, "Luz"};
  trans[3] = (Transacao){{5, 3, 2024}, 320.00, "Aluguel"};
  trans[4] = (Transacao){{10, 12, 2023}, 99.90, "Livro"};

  return trans;
}

Transacao *filtrarPorData(Transacao *transacoes, int n, Data inicio, Data fim);

int main() {
  int quantidade;
  Transacao *transacoes = criarDadosMock(&quantidade);

  Data inicio = {.dia = 01, .mes = 02, .ano = 2005};
  Data fim = {.dia = 01, .mes = 02, .ano = 2005};

  Transacao *filtrados = filtrarPorData(filtrados, quantidade, inicio, fim);
}
