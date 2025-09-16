// 2) Fazer um programa que leia uma string e a partir desta gere uma nova
// duplicando cada caracter da string original. Escreva a nova string. Por
// exemplo, para as strings abaixo, o programa deverá escrever:
#include <stdio.h>
#include <string.h>
int main() {
  char string[100];
  char newStr[200];
  int j = 0;
  printf("Digite uma palavra\n");

  fgets(string, sizeof(string), stdin);
  string[strcspn(string, "\n")] = '\0';

  size_t strLen = strlen(string);

  for (int i = 0; i <= strLen; i++) {
    newStr[j] = string[i];
    newStr[j + 1] = string[i];
    j += 2;
  }
  newStr[j] = '\0';
  printf("%s\n", newStr);
  // Zu is the format specifier for printing size_t variables
}
