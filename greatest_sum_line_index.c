#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
M00000800 -
https://avaucs.grupoa.education/plataforma/course/3644210/content/46177802
    Faça um programa que leia uma matriz M[5][5] e escreva o número da linha que
    contenha a maior soma de seus elementos. Considere que a matriz só contem
    valores positivos.
*/

#define N 5

void gera_matriz(int m[N][N]) {
  int i, j;

  srand(time(NULL));
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      m[i][j] = rand() % 10;
    }
  }
}

void escreve_matriz(int m[N][N]) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("% 3d", m[i][j]);
    }
    printf("\n");
  }
}

int linha_maior_soma(int m[N][N]) {
  int i, j, soma_atual = 0, maior_soma, index = 0;

  for (i = 0; i < N; i++) {
    soma_atual = 0;
    for (j = 0; j < N; j++) {
      soma_atual += m[i][j];
    }
    if (i == 0 || soma_atual > maior_soma) {
      maior_soma = soma_atual;
      index = i;
    }
  }

  return index;
}

int main() {
  int m[N][N];
  gera_matriz(m);
  escreve_matriz(m);

  int lin = linha_maior_soma(m);

  printf("%d", lin);
  return 0;
}
