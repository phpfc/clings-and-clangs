// 7)  Escreva uma função em C com o seguinte protótipo

// int int2str(int n, char str[])
// que receba um número inteiro positivo e armazene os dígitos do mesmo em uma
// string recebida por parâmetro.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void int2str(int n, char str[]) {
  int sinal = n;
  int i = 0;

  if (n == 0) {
    str[i++] = '0';
    str[i] = '\0';
    return;
  } // Se o número em questão for 0, o loop não executará, portanto um
    // tratamento específico é necessário

  if (n < 0) {
    n = -n;
  } // Da mesma forma, se o número for negativo, o loop não executará. De forma
  // que possa a ser tratado, invertemos seu sinal.

  while (n > 0) {
    str[i++] = n % 10 + '0';
    n /= 10;
  }

  // str[i++] atribui o valor da operação àquela posição da string.
  // n % 10 pega o último caractere do número e com o + '0' faz a conversão para
  // seu valor ASCII n /= 10 retira o último dígito, de forma que o próximo
  // valor seja correto

  if (sinal < 0) {
    str[i++] = '-';
  }

  str[i] = '\0';

  int inicio = 0, fim = i - 1;
  while (inicio < fim) {
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    inicio++;
    fim--;
  }

  printf("%s\n", str);
}

int main() {
  srand(time(NULL));
  int n = rand() % 10000;
  char str[100];

  int2str(n, str);
}
