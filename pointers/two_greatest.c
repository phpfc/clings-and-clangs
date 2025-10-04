
/*
  7) Faça uma função, cujo protótipo é definido por

  void dois_maiores(char str[], int *primeiro, int *segundo)

  que recebe uma string (números positivos separados pelo caracter ‘#’)
  e retorne os dois maiores valores existentes (ordem decrescente)
  na string pelos parâmetros primeiro e segundo.
  Por exemplo, para a string 10#20#191#7#34

  a função deverá retornar 191 no parâmetro primeiro e 34 no parâmetro segundo.
  Note que os valores estão em ordem decrescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void two_greatest(char str[], int *first, int *second) {
  *first = *second = -1;

  char *token = strtok(str, "#");
  while (token != NULL) {
    int num = atoi(token);

    if (num > *first) {
      *first = num;
    } else if (num > *second) {
      *second = num;
    }

    token = strtok(NULL, "#");
  }
}

void write_string(char str[]) {
  srand(time(NULL));
  str[0] = '\0';
  for (int i = 0; i < 10; i++) {
    char buffer[10];
    int num = rand() % 200;

    sprintf(buffer, "%d", num);
    // sprintf() stores values to a character array as a buffer.
    strcat(str, buffer);
    // strcat concatenates the current value of the buffer to the string
    // received as parameter

    if (i < 9)
      strcat(str, "#");
    // Then, we also concatenate the char # after every number, until the last
    // one.
  }
}

int main() {
  char str[100];
  int first = 0;
  int second = 0;
  write_string(str);

  printf("%s\n", str);

  char copy[100];

  strcpy(copy, str);
  two_greatest(copy, &first, &second);

  printf(
      "The first greatest number in the string is: %d, and the second is: %d\n",
      first, second);
}
