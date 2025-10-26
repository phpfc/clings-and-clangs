/*
1) Faça uma função que receba uma string com valores inteiros separados por
vírgulas e retorne um vetor com esses valores. A função implementada deverá
obrigatoriamente seguir o protótipo que é definido abaixo.

int * separa(char str[])

Exemplo:

String	Vetor
“10,15,245,11,5,1243”
10	15	245	11	5	1243
Faça ainda o programa principal que leia a string e chame a função implementada.
Após, esse programa deverá escrever o vetor com todos os valores retornados.

OBSERVAÇÃO: não é permitida a utilização de funções de manipulação de strings.
 */
#include <stdio.h>
#include <stdlib.h>

int *separa(char str[]) {
  int numeric_items = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ',') {
      numeric_items++;
    }
  }
  numeric_items++;

  int *vector = malloc((numeric_items + 1) * sizeof(int));

  int acc = 0;
  int j = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      acc = acc * 10 + (str[i] - 48);
    }
    if (str[i] == ',') {
      vector[j] = acc;
      j++;
      acc = 0;
    }
  }
  vector[j] = acc;
  vector[j + 1] = -1;

  return vector;
}

int main() {
  char *values = "12,23,34,404,505,6";

  int *vector = separa(values);
  for (int i = 0; vector[i] != -1; i++) {
    printf("%d\n", vector[i]);
  }
  free(vector);
}
