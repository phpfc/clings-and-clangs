// 8)  Escreva uma função em C com o seguinte protótipo

// int numchrtimes(const char str1[])
// A função recebe um string e  retorna o número de ocorrências de caracteres
// numéricos no string. Por exemplo, a chamada

// numchrtimes("alfa1 bravo2 charlie 5")
// retorna 3.
#include <stdio.h>
#include <string.h>
int numchrtimes(const char str[]) {
  int counter = 0;
  size_t strLen = strlen(str);

  for (int i = 0; i < strLen; i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      counter++;
    }
  }

  return counter;
}
int main() {
  char string[100];
  printf("Digite palavras e números\n");
  fgets(string, sizeof(string), stdin);
  string[strcspn(string, "\n")] = '\0';

  int ocurrences = numchrtimes(string);
  printf("The entered string contains %d numerical charecters", ocurrences);
}
