#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void gera_matriz(int m[N][N]) {
  int i, j;

  srand(time(NULL));
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      m[i][j] = rand() % 100;
    }
  }
}

int is_col_mag(int m[N][N]) {
  // LEIA AS COLUNAS, REGISTRA A SOMA E DEFINE FALSO ASSIM QUE A PRIMEIRA SOMA
  // DIFERIR
  int i, j, soma = 0, aux = 0;
  int is_mag = 1;
  for (j = 0; j < N; j++) {
    aux = soma;
    soma = 0;
    for (i = 0; i < N; i++) {
      soma += m[i][j];
    }
    if (j != 0) {
      if (soma != aux) {
        is_mag = 0;
      }
    }
  }

  return is_mag;
}

int is_lin_mag(int m[N][N]) {
  int i, j, soma = 0, aux = 0;
  int is_mag = 1;
  for (i = 0; i < N; i++) {
    aux = soma;
    soma = 0;
    for (j = 0; j < N; j++) {
      soma += m[i][j];
    }
    if (i != 0) {
      if (soma != aux) {
        is_mag = 0;
      }
    }
  }

  return is_mag;
}

int are_diag_mag(int m[N][N]) {
  int i, j, soma_prin = 0, soma_second = 0;
  int is_mag = 1;
  for (i = 0; i < N; i++) {
    soma_second += m[i][N - 1 - i];
    soma_prin += m[i][i];
  }

  if (soma_prin != soma_second) {
    is_mag = 0;
  }

  return is_mag;
}

void eh_magico(int m[N][N]) {
  int eh_magico = is_col_mag(m) && is_lin_mag(m) && are_diag_mag(m);
  if (eh_magico != 1) {
    printf("Este quadrado não é mágico");
  } else {
    printf("Este quadrado é mágico!");
  }
}

int main() {
  // int m[N][N];

  int m[N][N] = {{11, 24, 7, 20, 3},
                 {4, 12, 25, 8, 16},
                 {17, 5, 13, 21, 9},
                 {10, 18, 1, 14, 22},
                 {23, 6, 19, 2, 15}};

  // gera_matriz(m);
  eh_magico(m);

  return 0;
}
