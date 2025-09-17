// 6) Escreva uma função em C com o seguinte protótipo

// int str2int(const char str[])
// que receba uma string com um número válido, após converta o número lido para
// decimal, armazenando-o em uma variável inteira e a retorne.
#include <stdio.h>
#include <string.h>

int str2int(const char str[]) {
  int num = 0;
  int sinal = 1;
  int i = 0;

  while (str[i] == ' ') {
    i++;
  }

  if (str[i] == '-') {
    sinal = -1;
  } else if (str[i] == '+') {
    i++;
  }

  while (str[i] >= '0' && str[i] <= '9') {
    num = num * 10 + (str[i] - '0');
    i++;
  }

  /*
    Uma vez que operadores matemáticos não lidam com char em C, aqui ocorre
    Integer Promotion
    Subtrair um charactere numérico por '0' é a forma padrão de encontrar o
    valor inteiro em C. A operação matemática será a de subtração do
    correspondente valor ASCII de '0' (48), pelo caractere. Sendo assim, uma vez
    obtido o valor int, multiplica-se por 10 cada número, de forma a organizar
    nas bases decimais
   */

  return sinal * num;
}

int main() {
  char number[10];

  printf("Digite um número\n");
  fgets(number, sizeof(number), stdin);
  number[strcspn(number, "\n")] = '\0';

  int response = str2int(number);
  printf("%d", response);
}
