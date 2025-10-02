#include <stdio.h>

int main() {
  int a = 3;
  int *p = NULL;

  p = &a;
  // Declaração de pointer:
  // especifica-se o tipo do valor armazenado no endereço
  // Usa-se o * para definir como um pointer

  printf("%d %d\n", &a, p);
  // Mostram o mesmo valor de endereço
  printf("%d %d\n", a, *p);
  // Mostram o mesmo valor da variável
}
