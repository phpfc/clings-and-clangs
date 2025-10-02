#include <stdio.h>

void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

int main() {
  int a = 3, b = 5;
  troca(&a, &b);

  printf("%d %d\n", a, b);
}
