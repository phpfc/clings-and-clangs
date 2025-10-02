#include <stdio.h>

void troca_copia(int a, int b) {
  int aux = a;
  a = b;
  b = aux;
  // As operações são feitas apenas durante a execução,
  // e não tem efeito para fora do escopo da função
}

void troca_ref(int a[2]) {
  int aux = a[0];
  a[0] = a[1];
  a[1] = aux;
}

int main() {
  int a = 3, b = 5;
  int v[2] = {3, 5};
  // Passa os valores por cópia
  troca_copia(a, b);
  troca_ref(v);
  printf("A = %d B= %d \n", a, b);
  printf("A = %d, B= %d \n", v[0], v[1]);
}
