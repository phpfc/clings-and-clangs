// 4) Escreva uma função em C com o seguinte protótipo
// int palindromo(const char str[])
// A função deverá retornar 1 caso a string  for palíndromo e 0  caso contrário.
// São exemplos de strings palíndromos:

// ARARA
// ovo

// 5) Idem ao anterior, mas sem distinção de maiúsculas e minúsculas. Por
// exemplo, a função deverá retornar 1 para as strings:

// Arara
// Ovo
// OsSo
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int is_palindrome(const char string[]) {
  char inverted[100];
  int j = 0;
  size_t strLen = strlen(string);
  int is_palindrome = 1;

  for (int i = strLen - 1; i >= 0; i--) {
    inverted[j] = string[i];
    j++;
  }
  inverted[j] = '\0';

  for (int i = 0; i <= strLen; i++) {
    if (tolower(string[i]) != tolower(inverted[i])) {
      is_palindrome = 0;
      break;
    }
  }

  return is_palindrome;
}

int main() {
  char string[100];
  printf("Digite uma palavra\n");

  fgets(string, sizeof(string), stdin);
  string[strcspn(string, "\n")] = '\0';

  int result = is_palindrome(string);

  printf("%s\n", result ? "É palíndromo" : "Não é palíndromo");
}
