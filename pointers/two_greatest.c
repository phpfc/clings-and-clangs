
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
  /*
    strtok separa uma string de acordo com um delimitador.
    Ele insere um '\0' antes do delimitador, e retorna um
    pointer para o início do token
   */

  while (token != NULL) {
    int num = atoi(token);
    /*
        Aqui, o atoi, enxerga o token como uma string,
        e percorre cada caractere convertendo como inteiro, até que
        encontre o '\0' inserido pelo strtok
     */

    if (num > *first) {
      *first = num;
    } else if (num > *second) {
      *second = num;
    }

    token = strtok(NULL, "#");
    /*
        Passar null nesta chamada, instrui que o strtok
        continue a percorrer a string original de onde parou,
        aqui ele retorna para o início do while, e o procedimento se repete
        até que token seja NULL, ou seja, ao terminar a string.
     */
  }
}

void write_string(char str[]) {
  srand(time(NULL));
  str[0] = '\0';
  for (int i = 0; i < 10; i++) {
    char buffer[10];
    int num = rand() % 200;

    sprintf(buffer, "%d", num);
    // sprintf() guarda o valor em um array de chars como buffer
    strcat(str, buffer);
    // concatena a string armazenada no buffer à string passada como parametro.

    if (i < 9)
      strcat(str, "#");
    // Concatena # ao final de cada número, enquanto não for o último
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
