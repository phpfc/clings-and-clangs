/*
Você deve escrever um programa em C que:
Leia um arquivo texto chamado entrada.txt.
Esse arquivo contém vários casos de teste.
Cada caso é formado por duas linhas:
Linha 1: Dois inteiros N e K
– N: quantidade de elementos do vetor
– K: quantidade de maiores valores que devem ser somados

Linha 2: N inteiros contendo os elementos do vetor.
Para cada caso:
Ordene o vetor em ordem decrescente.
Selecione os K maiores valores.
Calcule a soma desses K valores.
O programa deve gerar um arquivo texto chamado saida.txt, contendo:
uma linha para cada caso,
cada linha com a soma dos K maiores elementos do respectivo caso.
📌 Exemplo
entrada.txt

10 5
1 2 3 4 5 6 7 8 9 10
5 2
1 5 2 4 3
17 5
17 15 11 11 9 7 5 3 3 1 2 4 6 8 10 12 14
Processamento:

Caso 1 → maiores 5: 10 + 9 + 8 + 7 + 6 = 40
Caso 2 → maiores 2: 5 + 4 = 9
Caso 3 → maiores 5: 17 + 15 + 14 + 12 + 11 = 69

saida.txt
40
9
69
*/

#include <stdio.h>
#include <stdlib.h>

void sumNValuesFromVector(FILE *fp) {
  int N, K;
  FILE *output = fopen("saida.txt", "w");

  while (fscanf(fp, "%d %d", &N, &K) == 2) {
    int *vector = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
      fscanf(fp, "%d", &vector[i]);
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N - 1; j++) {
        if (vector[j] < vector[j + 1]) {
          int aux = vector[j];
          vector[j] = vector[j + 1];
          vector[j + 1] = aux;
        }
      }
    }

    int sum = 0;

    for (int i = 0; i < K; i++) {
      sum += vector[i];
    }

    free(vector);
    fprintf(output, "%d \n", sum);
  }

  fclose(output);
}

int main() {
  FILE *fptr = fopen("./entrada.txt", "r");
  if (fptr != NULL) {
    sumNValuesFromVector(fptr);
  } else {
    perror("Erro ao abrir entrada.txt");
  }

  fclose(fptr);
}
