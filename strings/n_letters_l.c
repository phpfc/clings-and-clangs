// 1)  Fazer um programa que leia uma letra (L) e um número (N), a seguir gere
// uma string contendo N letras L.
#include <stdio.h>
int main() {
  char letra;
  int numero;

  printf("Digite um número\n");
  scanf("%d", &numero);
  printf("Digite uma letra\n");
  scanf(" %c", &letra);

  char string[numero + 1];

  for (int i = 0; i < numero; i++) {
    string[i] = letra;
  }

  string[numero] = '\0';

  // Null terminator is used to mark the end of the string

  printf("%s\n", string);
}
