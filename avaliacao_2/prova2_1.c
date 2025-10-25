
/*
    1.1) Implemente a função
void hora(char *str, int *h, int *m, int *s);
que receba um horário no formato de string, onde a hora, o minuto e o
segundo podem ter um ou dois dígitos, separados por dois pontos (:), e retorne
os valores correspondentes de hora, minuto e segundo. Caso o horário seja
inválido (valores fora dos limites permitidos ou formato incorreto), a
função deverá atribuir - 1 para hora, minuto e segundo. Faça também o programa
principal que chama essa função e exibe os resultados.
    1.2) Implemente o programa principal que leia a string contendo o horário,
chame a função que extrai a hora, o minuto a o segundo, e exiba os valores
retornados. incluindo os casos em que o horário seja inválido
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void hora(char *str, int *h, int *m, int *s);

void get_rand_time(char *str) {
  int nums[3];
  for (int i = 0; i < 3; i++) {
    if (i <= 0) {
      nums[i] = rand() % 23;
    } else {
      nums[i] = rand() % 59;
    }
  }

  int grupo = 0;
  for (int i = 0; i < 9; i++) {
    if ((i + 1) % 3 == 0) { // POSICIONA OS SEPARADORES EM POSIÇÕES PREVISTAS
      str[i] = ':';
    }
    if (i >= 8) { // POSICIONA O NULL TERMINATOR
      str[i] = '\0';
    }

    if ((i + 1) % 3 != 0) { // CASO A POSIÇÃO ATUAL NÃO SEJA UM DOS SEPARADORES
      if (i == 0 || (i % 3) == 0) {
        // POSICIONE OS VALORES DAS DECENAS NAS POSIÇÕES 0, 3 E 6
        str[i] = (nums[grupo] / 10) + 48;
      } else { // POSICIONE OS VALORES DAS UNIDADES NAS DEMAIS POSIÇÕES
        str[i] = (nums[grupo] % 10 + 48);
        grupo++;
      }
    }
  }
}

int main() {
  char hora[9];
  srand(time(NULL));

  get_rand_time(hora);
  printf("%s\n", hora);
}
