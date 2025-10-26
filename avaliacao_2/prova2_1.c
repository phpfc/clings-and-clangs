
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

void hora(char *str, int *h, int *m, int *s) {
  int grupo = 0;
  // int ehHora = 1;

  for (int i = 0; i < 9; i++) {
    if ((i + 1) % 3 != 0) {
      /*
        Minha primeiro solução era bastante verbosa.
        Recorrer a blocos condicionais para operar sobre os grupos
        tornava necessário a reescrita das etapas das operações.
        Um array de ponteiros, permite "incrementar" o grupo de forma
        iterativa.
       */

      if (str[i] > '9' || str[i] < '0') {
        *h = *m = *s = -1;
        break;
      }
      int *targets[3] = {h, m, s};

      if (i == 0 || i % 3 == 0) {
        *targets[grupo] = (str[i] - 48) * 10;
      } else {
        *targets[grupo] += str[i] - 48;
        grupo++;
      }
    }
  };

  if (*h < 0 || *h > 23 || *m < 0 || *m > 59 || *s < 0 || *s > 59) {
    *h = *m = *s = -1;
  }
  if (strlen(str) != 9) {
    *h = *m = *s = -1;
  }
  if (str[2] != ':' || str[5] != ':') {
    *h = *m = *s = -1;
  }
}

void get_rand_time(char *str, int mal_formatado, int valores_invalidos) {
  int ascii_shift = valores_invalidos >= 1 ? 90 : 48;
  char separator = mal_formatado >= 1 ? ' ' : ':';
  int nums[3];
  for (int i = 0; i < 3; i++) {
    if (i <= 0) {
      nums[i] = rand() % 24;
    } else {
      nums[i] = rand() % 60;
    }
  }

  int grupo = 0;
  for (int i = 0; i < 9; i++) {
    if ((i + 1) % 3 == 0) { // POSICIONA OS SEPARADORES EM POSIÇÕES PREVISTAS
      str[i] = separator;
    }
    if (i >= 8) { // POSICIONA O NULL TERMINATOR
      str[i] = '\0';
    }

    if ((i + 1) % 3 != 0) { // CASO A POSIÇÃO ATUAL NÃO SEJA UM DOS SEPARADORES
      if (i == 0 || (i % 3) == 0) {
        // POSICIONE OS VALORES DAS DECENAS NAS POSIÇÕES 0, 3 E 6
        str[i] = (nums[grupo] / 10) + ascii_shift;
      } else { // POSICIONE OS VALORES DAS UNIDADES NAS DEMAIS POSIÇÕES
        str[i] = (nums[grupo] % 10 + ascii_shift);
        grupo++;
      }
    }
  }
}

int main() {
  char hour[9];
  srand(time(NULL));

  int h = 0, m = 0, s = 0;

  // get_rand_time(hour, 0, 0);
  // printf("%s\n", hour);
  hora("13!42!32", &h, &m, &s);
  // hora(hour, &h, &m, &s);
  printf("%02d:%02d:%02d\n", h, m, s);
}

/*
 if (grupo <= 0) {
   if (ehHora > 0) {
     *h = (str[i] - 48) * 10;
     ehHora *= -1;
   } else {
     *h += str[i] - 48;
     ehHora *= -1;
   }
 }

 if (grupo >= 1 && grupo < 2) {
   if (ehHora > 0) {
     *m = (str[i] - 48) * 10;
     ehHora *= -1;
   } else {
     *m += str[i] - 48;
     ehHora *= -1;
   }
 }

 if (grupo >= 2) {
   if (ehHora > 0) {
     *s = (str[i] - 48) * 10;
     ehHora *= -1;
   } else {
     *s += str[i] - 48;
     ehHora *= -1;
   }
 }
 Isto é bastante verboso. E pode ser simplificado utilizando um array de
 pointers
 */
