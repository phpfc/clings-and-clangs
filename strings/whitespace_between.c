// 3) Fazer um programa que leia uma string e a partir desta gere uma nova
// contendo um espaço em branco entre cada caracter da string original. Escreva
// a nova string. Por exemplo, para a string
#include <stdio.h>
#include <string.h>
int main() {
  char string[100];
  char newString[200];
  int j = 0;

  printf("Digite uma palavra\n");
  fgets(string, sizeof(string), stdin);
  string[strcspn(string, "\n")] = '\0';

  size_t strLen = strlen(string);

  for (int i = 0; i < strLen; i++) {
    newString[j] = string[i];
    newString[j + 1] = ' ';
    j += 2;
  }

  newString[j] = '\0';

  printf("%s", newString);
}
